#include "cdr.h"
#include <stdio.h>
float TP2=0, TN2=0, FP2=0, FN2=0;
int j2, n2=4;

float CDR_F(int Ytrue[], int Yhat[],int t)
{
    float DR = DetectionRate(tp2(Ytrue, Yhat, t),fn2(Ytrue, Yhat,t));
    float FAR = FalseAlertRate(fp2(Ytrue, Yhat,t),tn2(Ytrue, Yhat,t));

    double CDR=0;
    CDR= DR-FAR;
    if (CDR>=0.5){
        printf("Umbral de la tasa de deteccion correcta positivo detectado");

    }
    else if(CDR<0.5){
        printf("Umbral de la tasa de deteccion correcta negativo detectado\n");
    }
    return CDR;
}

double DetectionRate(int a, int b)
{
    double DR=0;
    DR=a/(a+b);
    return DR;
}

double FalseAlertRate(int a, int b)
{
    double FAR=0;
    FAR=a/(a+b);
    return FAR;
}

float tn2(int Ytrue[], int Yhat[],int t)
{
#pragma omp parallel for private (j2) num_threads(n2)

        for(j2=0; j2<t; j2++){
            if(Ytrue[j2]==0 && Yhat[j2]==0){
            #pragma omp atomic

                TN2++;
            }
        }
    return TN2;
}

float fn2(int Ytrue[], int Yhat[],int t)
{
#pragma omp parallel for private (j2) num_threads(n2)

        for(j2=0; j2<t; j2++){
            if(Ytrue[j2]==1 && Yhat[j2]==0){
            #pragma omp atomic

                FN2++;
            }
        }
    return FN2;
}

float fp2(int Ytrue[], int Yhat[],int t)
{
#pragma omp parallel for private (j2) num_threads(n2)

        for(j2=0; j2<t; j2++){
            if(Ytrue[j2]==0 && Yhat[j2]==1){
#pragma omp atomic
                FP2++;
            }
        }
    return FP2;
}

float tp2(int Ytrue[], int Yhat[],int t)
{
#pragma omp parallel for private (j2) num_threads(n2)

    for(j2=0; j2<t; j2++){
        if(Ytrue[j2]==1 && Yhat[j2]==1){
        #pragma omp atomic

            TP2++;
        }
    }
return TP2;
}
