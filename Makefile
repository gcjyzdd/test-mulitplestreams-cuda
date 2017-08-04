
all:
	nvcc -arch=sm_30 --default-stream per-thread ./stream_test2.cu -o stream_per-thread2

test3: stream_test3.cpp cudaArray.h kernel.o
	g++ stream_test3.cpp kernel.o -o test  -I/usr/local/cuda/include -L/usr/local/cuda/lib64 -lcudart  -I/usr/local/cuda/samples/common/inc


kernel.o: kernel.cu
	nvcc --default-stream per-thread -c -arch=sm_30 kernel.cu 

clean:
	rm *.o


