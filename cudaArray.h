#ifndef _ccc_
#define _ccc_

#include <cuda.h>
#include <cuda_runtime.h>

struct cudaArray
{
    int Len;
    int Size;
    float *data[8];
    float *d_data[8];
    float *h_data[8];

	cudaStream_t cS[8];

    cudaArray(float a, int N)
    {
        Len=1 << N;
        Size=Len*sizeof(float);
        for(int i=0;i<8;++i)
        {
			cudaStreamCreate( &( cS[i]));
        	cudaMallocHost((void**)&data[i],Len*sizeof(float));
        	cudaMallocHost((void**)&h_data[i],Len*sizeof(float));
        	cudaMalloc((void**)&d_data[i],Len * sizeof(float));
        }
        for(int j=0;j<8;++j)        
        for(int i=0;i<Len;++i)
        {
            {
                data[j][i]=a;
            }
        }
    }
    void process();
    ~cudaArray()
    {
        for(int i=0;i<8;++i)
        {
            cudaFreeHost(data[i]);
            cudaFreeHost(h_data[i]);
            cudaFree(d_data[i]);
        }
    }
};
#endif
