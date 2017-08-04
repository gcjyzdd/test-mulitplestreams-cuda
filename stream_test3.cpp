#include <pthread.h>
#include <cstdio>
#include <cmath>

#include "cudaArray.h"

int main()
{
    cudaArray arr(3.14,20);

    arr.process();
    arr.process();

    return 0;
}
