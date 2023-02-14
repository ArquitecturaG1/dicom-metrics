#include "f1score_funciones.h"

void F1_score(int nt, int tam, float *p,float *r){
float num;
float mul[tam];
float suma[tam];
float div[tam];
float f1[tam];


    int in =0;
    int tr = tam;

    omp_set_num_threads(nt);
#pragma omp parallel default (none) shared(in, tr, p, r, num, mul,suma, div, f1)
{
    #pragma omp for
     for(int x=in;x<tr;x++){
        mul[x]=((*(p+x))*(*(r+x)));
    }

    #pragma omp for
    for(int x=in;x<tr;x++){
        suma[x]=(*(p+x))+(*(r+x));
    }

    #pragma omp for
    for(int x=in;x<tr;x++){
        div[x]=((mul[x])/(suma[x]));
    }

    #pragma omp for
    for(int x=in;x<tr;x++){
        f1[x]=(2*(div[x]));
    }

}

//Esta linea de codigo fue usada para verificar
//el vector final de los calculo de F1 - score
    imprimir_datos(tam,(float *)f1);

}

void imprimir_datos(int n, float *v){
    int i;
    printf("v = [");
    for(i = 0; i < n; i++)
    {
        if(i > 0)
        {
            printf(", ");
        }
        printf("%.2f", *(v+i));
    }
    printf("]");

}
