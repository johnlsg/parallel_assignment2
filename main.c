#include <stdio.h>
#include <stdlib.h>

static int N = 8;

int main()
{
    int i;
    double avrg, sum=0.0;
    for (i=1; i<N+1; i++) {
        sum += i;
    }
    avrg = sum/N;
    printf("Average sum is %.1lf", avrg);
}
