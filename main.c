#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#define THREAD_COUNT 8


static int N = 1000000;

int main()
{
    int i;
    double avrg, sum=0.0;

    omp_set_num_threads(THREAD_COUNT);

    #pragma omp parallel
    {
        #pragma omp for reduction(+:sum)
        for (i=1; i<N+1; i++) {
            sum += i;
        }
    }

    avrg = sum/N;
    printf("Average sum is %.1lf", avrg);
}
