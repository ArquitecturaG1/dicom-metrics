#include "NRM.h"

void calcularNRM(int x, int *M1, int *M2, int *M3, int *M4)
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

    float NRFP = (FP) / (TN + FP);
    // Tasa negativa de falsos negativos
    float NRFN = (FN) / (TP + FN);
    // Calculo de metrica de tasa negativa
    float NRM = (NRFN + NRFP) / (2);
    // Imprimir valores calculados
    printf("NRFP (Negative rate false positive): %f\n", NRFP);
    printf("NRFN (Negative rate false negative): %f\n", NRFN);
    printf("NRM (Negative rate metric): %f\n", NRM);
}
