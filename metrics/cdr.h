#ifndef CDR_H
#define CDR_H

float fn2(int Ytrue[], int Yhat[],int t);
float tp2(int Ytrue[], int Yhat[],int t);
float fp2(int Ytrue[], int Yhat[], int t);
float tn2(int Ytrue[], int Yhat[], int t);

double DetectionRate (int a,int b);
double FalseAlertRate (int a,int b);

float CDR_F(int Ytrue[], int Yhat[],int t);

#endif // CDR_H
