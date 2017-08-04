#include "cudaArray.h"

__global__ void kernel(float *x, int n)
{
	int tid = threadIdx.x + blockIdx.x * blockDim.x;
	for (int i = tid; i < n; i += blockDim.x * gridDim.x) {
		x[i] = sqrt(pow(3.14159,i));
	}
}

void cudaArray::process()
{
	for(int i=0;i<8;++i)
	{
		cudaMemcpyAsync(d_data[i],data[i],Size,cudaMemcpyHostToDevice,cS[i]);
		kernel<<<1, 32, 0, cS[i]>>>(d_data[i], Len);
		cudaMemcpyAsync(h_data[i],d_data[i],Size,cudaMemcpyDeviceToHost,cS[i]);
	}
	cudaDeviceSynchronize();

}
