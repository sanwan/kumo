//
// Created by 诸谦 on 15/12/24.
//

#include <math.h>
#include "NRookSampler.h"


NRookSampler::NRookSampler(int _sampleNum,int _setNum) : Sampler(_sampleNum, _setNum) {
    generateSamples();
}

void NRookSampler::generateSamples() {
    int n =sqrt(mSampleNum);
    for(int i=0;i<mSetNum;++i)
        for(int j=0;j<mSampleNum;++j){
            Vector2 v=Vector2((j+drand48())/mSampleNum,(j+drand48())/mSampleNum);
            mSamples.push_back(v);
        }
    _shuffleXCoordinates();
    _shuffleYCoordinates();
}


void NRookSampler::_shuffleXCoordinates(){
    for(int p=0;p<mSetNum;++p)
        for(int i=0;i<mSampleNum-1;++i){
            int target=rand()%mSampleNum+p*mSampleNum;
            float temp=mSamples[i+p*mSampleNum+1].x;
            mSamples[i+p*mSampleNum+1].x=mSamples[target].x;
            mSamples[target].x=temp;
        }
}
void NRookSampler::_shuffleYCoordinates(){
    for(int p=0;p<mSetNum;++p)
        for(int i=0;i<mSampleNum-1;++i){
            int target=rand()%mSampleNum+p*mSampleNum;
            float temp=mSamples[i+p*mSampleNum+1].y;
            mSamples[i+p*mSampleNum+1].y=mSamples[target].y;
            mSamples[target].y=temp;
        }
}