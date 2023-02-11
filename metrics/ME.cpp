#include "ME.h"

void calcularME(int x, int *M1, int *M2, int *M3, int *M4)
{
    float precision = 0.0;
    float accuracy_model = 0.0;
    float similitud;
    float TN = 0.0, FN = 0.0, TP = 0.0, FP = 0.0;

    for(int i = 0; i < x; i++){
        TN += (*(M1+i)) / x;
        FN += (*(M2+i)) / x;
        TP += (*(M3+i)) / x;
        FP += (*(M4+i)) / x;
    }

    precision = (float)TP / (TP + FP);
    accuracy_model = (float)(TP + TN) / (TP + TN + FP + FN);
    printf("Valor de exactitud del modelo: %f\n", precision);
    printf("Precision del modelo: %f\n\n", accuracy_model);
}
