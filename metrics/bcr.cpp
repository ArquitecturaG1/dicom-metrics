#include "bcr.h"

float TP1=0, TN1=0, FP1=0, FN1=0;
int j1, n1=4;


float tn1(int Ytrue[], int Yhat[],int t)
{
#pragma omp parallel for private (j1) num_threads(n1)

        for(j1=0; j1<t; j1++){
            if(Ytrue[j1]==0 && Yhat[j1]==0){
            #pragma omp atomic

                TN1++;
            }
        }
    return TN1;
}

float fn1(int Ytrue[], int Yhat[],int t)
{
#pragma omp parallel for private (j1) num_threads(n1)

        for(j1=0; j1<t; j1++){
            if(Ytrue[j1]==1 && Yhat[j1]==0){
            #pragma omp atomic

                FN1++;
            }
        }
    return FN1;
}

float tp1(int Ytrue[], int Yhat[],int t)
{
#pragma omp parallel for private (j1) num_threads(n1)

        for(j1=0; j1<t; j1++){
            if(Ytrue[j1]==1 && Yhat[j1]==1){
            #pragma omp atomic

                TP1++;
            }
        }
    return TP1;
}

float fp1(int Ytrue[], int Yhat[],int t)
{
#pragma omp parallel for private (j1) num_threads(n1)

        for(j1=0; j1<t; j1++){
            if(Ytrue[j1]==0 && Yhat[j1]==1){
#pragma omp atomic
                FP1++;
            }
        }
    return FP1;
}

float BCR_F(int Ytrue[], int Yhat[], int t)
{
    //Obtener TN
    float TN = tn1(Ytrue, Yhat,t);

    //Obtener FN
    float FN = fn1(Ytrue, Yhat,t);

    //Obtener TP
    float TP = tp1(Ytrue, Yhat,t);

    //Obtener FP
    float FP = fp1(Ytrue, Yhat,t);

     //Obtener sensibiliadad y espicificidad
    float sensibilidad=0, especificidad=0;

    sensibilidad = TP/(TP+FN);
    especificidad = TN/(TN+FP);

    return ((sensibilidad+especificidad)/2);
}
