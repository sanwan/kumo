/*
 * trianglemesh.h
 *
 *  Created on: 2016年7月8日
 *      Author: Administrator
 */

#ifndef SHAPE_TRIANGLEMESH_H_
#define SHAPE_TRIANGLEMESH_H_

#include "global.h"
#include "shape.h"
//三角网格
class TriangleMesh:public Shape{
protected:
	 int ntris, nverts;
	 int *vertexIndex; //索引数组
	 Point *p; //顶点数组
	 Normal *n; //法线数组
	 Vector *s; //切向量数组
	 float *uvs; //纹理坐标数组
public:
	TriangleMesh(const Transform *o2w, const Transform *w2o, bool ro, int ntris/*三角个数*/, int nverts/*顶点个数*/,
			const int *vptr/*索引数据*/,const Point *P/*顶点位置数组*/,const Normal *N/*法线数组*/, const Vector *S/*切向量数组*/,
            const float *uv/*纹理坐标数组*/);
	virtual ~TriangleMesh(){};

	friend class Triangle;
};


//三角形
class Triangle:public Shape{
private:
	Reference<TriangleMesh> mMesh;
	int *mIndex;
public:
	Triangle(const Transform *o2w, const Transform *w2o, bool ro, TriangleMesh *m, int n);

	//获取三个顶点的纹理坐标
	 void GetUVs(float uv[3][2]) const {
	        if (mMesh->uvs) {
	            uv[0][0] = mMesh->uvs[2*mIndex[0]];
	            uv[0][1] = mMesh->uvs[2*mIndex[0]+1];
	            uv[1][0] = mMesh->uvs[2*mIndex[1]];
	            uv[1][1] = mMesh->uvs[2*mIndex[1]+1];
	            uv[2][0] = mMesh->uvs[2*mIndex[2]];
	            uv[2][1] = mMesh->uvs[2*mIndex[2]+1];
	        }
	        else {
	            uv[0][0] = 0.; uv[0][1] = 0.;
	            uv[1][0] = 1.; uv[1][1] = 0.;
	            uv[2][0] = 1.; uv[2][1] = 1.;
	        }
	    }
};

#endif /* SHAPE_TRIANGLEMESH_H_ */
