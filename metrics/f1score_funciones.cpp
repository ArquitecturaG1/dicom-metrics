#include "f1score_funciones.h"

void F1_score(int tam, float *p,float *r){
float num;
float mul[tam];
float suma[tam];
float div[tam];
float f1[tam];


#pragma omp parallel num_threads(8)
{



    int in =0;
    int tr = tam;



    for(int x=in;x<tr;x++){
        mul[x]=((*(p+x))*(*(r+x)));
    }

    for(int x=in;x<tr;x++){
        suma[x]=(*(p+x))+(*(r+x));
    }
    for(int x=in;x<tr;x++){
        div[x]=((mul[x])/(suma[x]));
    }
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
