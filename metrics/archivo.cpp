#include "archivo.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>
#define nt 4
int tn=0,tp=0,fp=0,fn=0;

double auc,sensibilidad,especificidad,ro;
void calcularTot(int height,int *m1,int *m2,int t){
   //  double start_time = omp_get_wtime();
    //  int cores = omp_get_num_procs();
    //#pragma omp for
    for (int i = 0; i < t; i++)
    {
        for (int j = 0; j < t; j++)
        {
            if (*((m1+i*height)+j)==1 && *((m2+i*height)+j)==1)
            {
                tp++;

            }
            else if (*((m1+i*height)+j)==0 && *((m2+i*height)+j)==0)//00
            {
                tn++;
            }
            else if (*((m1+i*height)+j)==0 && *((m2+i*height)+j)==1)//01
            {
                fn++;
            }
            else if (*((m1+i*height)+j)==1 && *((m2+i*height)+j)==0)//10
            {
                fp++;
            }
        }
    }
    printf("La cantidad de Verdaderos Positivos: %d\n",tp);
    printf("La cantidad de Verdaderos Negativos: %d\n",tn);
    printf("La cantidad de Falsos Negativos: %d\n",fn);
    printf("La cantidad de Falsos Positivos: %d\n",fp);
    //   double end_time = omp_get_wtime();
    // Calcula restando el fin - inicio y dividiendo la diferencia por CLOCKS_PER_SEC para convertir a segundos
    //  double total = end_time - start_time;
    //TRUE NEGATIVE
    especificidad= (double)tn / (tn + fp);
    printf("\nLa Especificidad: %lf", especificidad);
    //TRUE POSITIVE
        sensibilidad = (double) tp / (tp + fn);

    printf("\nLa Sensibilidad: %f",sensibilidad);
    //AUC
    auc = double(((1.0 + sensibilidad) - (especificidad)) / 2.0);
    printf("\nEl valor de AUC=%lf\n",auc);
    //ROC
    ro=sensibilidad+especificidad-1;

    printf("\nEl valor de ROC=%lf\n",ro);


}

