#ifndef BCR_H
#define BCR_H


float fn1(int Ytrue[], int Yhat[],int t);
float tp1(int Ytrue[], int Yhat[],int t);
float fp1(int Ytrue[], int Yhat[], int t);
float tn1(int Ytrue[], int Yhat[], int t);
float BCR_F(int Ytrue[], int Yhat[],int t);
#endif // BCR_H
