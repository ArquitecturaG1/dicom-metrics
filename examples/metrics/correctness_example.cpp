#include <stdio.h>
#include <stdlib.h>
#include "correctness.h"
#define hilo 6
int main(){

    float resul;

    printf("Métrica correctnes\n");
#pragma omp parallel num_threads(hilo)
    {
        resul = correctness(8,9);
    }
    printf("=%d\n",resul);

    return 0;
}







