//
// Created by 诸谦 on 16/7/1.
//

#ifndef RAYTRACER_INTEGRATOR_H
#define RAYTRACER_INTEGRATOR_H
#include "global.h"
//积分器
class Integrator {
public:
	virtual ~Integrator() {
	}
	virtual void RequestSamples(Sampler *sampler, Sample *sample,
			const Scene *scene) {
		//assert(false);
	}
};

class SurfaceIntegrator: public Integrator {
public:
	virtual RGB Li(const Scene *scene, const Renderer *renderer,
			const RayDifferential &ray,const Sample *sample, const Intersection &isect, Random &rnd,
			MemoryArena& arena) const = 0;
	virtual ~SurfaceIntegrator() {
	}
};

//通过light的能量来计算light的CDF
Distribution1D *ComputeLightSamplingCDF(const Scene *scene);
#endif //RAYTRACER_INTEGRATOR_H
