#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#define THREAD_COUNT 8


static int N = 8;

int main()
{
    int i;
    double avrg, sum=0.0;
    double local_sum[THREAD_COUNT];

    omp_set_num_threads(THREAD_COUNT);

    #pragma omp parallel
    {
        int thread_id = omp_get_thread_num();
        local_sum[thread_id] = 0;

        #pragma omp for
        for (i=1; i<N+1; i++) {
            local_sum[thread_id] += i;
        }
    }

    for(i=0; i<THREAD_COUNT; i++){
        sum+= local_sum[i];
    }
    avrg = sum/N;
    printf("Average sum is %.1lf", avrg);
}
