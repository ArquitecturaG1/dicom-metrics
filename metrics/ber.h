#ifndef BER_H
#define BER_H


float fn(int Ytrue[], int Yhat[],int t);
float tp(int Ytrue[], int Yhat[],int t);
float fp(int Ytrue[], int Yhat[], int t);
float tn(int Ytrue[], int Yhat[], int t);
float BER_F(int Ytrue[], int Yhat[], int t);

#endif // BER_H
