#include "jaccard.h"

void calcularJaccard(int x, int *M1, int *M2)
{
    float precision = 0.0;
    float accuracy_model = 0.0;
    float similitud;
    float TN = 0.0, FN = 0.0, TP = 0.0, FP = 0.0;
    int cuenta=0;
    for (int i = 0; i < x; i++){
        //condición para comprobar la similitud
        if (*(M1+i) == *(M2+i)){
            cuenta += 1;
        }
    }

    similitud = ((float)cuenta)/x;
    printf("Similitud es %f\n", similitud);
}
