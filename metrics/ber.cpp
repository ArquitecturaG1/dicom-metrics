#include "ber.h"

float TP=0, TN=0, FP=0, FN=0;
int j, n=4;

float tn(int Ytrue[], int Yhat[], int t)
{
#pragma omp parallel for private (j) num_threads(n)

        for(j=0; j<t; j++){
            if(Ytrue[j]==0 && Yhat[j]==0){
            #pragma omp atomic

                TN++;
            }
        }
    return TN;
}

float fn(int Ytrue[], int Yhat[], int t)
{
#pragma omp parallel for private (j) num_threads(n)

        for(j=0; j<t; j++){
            if(Ytrue[j]==1 && Yhat[j]==0){
            #pragma omp atomic

                FN++;
            }
        }
    return FN;
}

float tp(int Ytrue[], int Yhat[],int t)
{
#pragma omp parallel for private (j) num_threads(n)

        for(j=0; j<t; j++){
            if(Ytrue[j]==1 && Yhat[j]==1){
            #pragma omp atomic

                TP++;
            }
        }
    return TP;
}

float fp(int Ytrue[], int Yhat[], int t)
{
#pragma omp parallel for private (j) num_threads(n)

        for(j=0; j<t; j++){
            if(Ytrue[j]==0 && Yhat[j]==1){
#pragma omp atomic
                FP++;
            }
        }
    return FP;
}
float BER_F(int Ytrue[], int Yhat[], int t)
{
    //Obtener TN

    float TN = tn(Ytrue, Yhat,t);

    //Obtener FN
    float FN = fn(Ytrue, Yhat, t);

    //Obtener TP
    float TP = tp(Ytrue, Yhat, t);

    //Obtener FP
    float FP = fp(Ytrue, Yhat, t);

    //Obtener b1 y b2
    float b1=0, b2=0;


    b1 = FP/(TN+FP);
    b2 = FN/(FN+TP);

    return (0.5*(b1+b2));
}
