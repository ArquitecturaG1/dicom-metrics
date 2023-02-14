//Proyecto
//Zelena Jimenez
//Metrica: F1 - score

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>
#include "f1score_funciones.h"

#define tam 299000
#define nt 1

int main(){
    int tamanio = 299000;
    //Para medir tiempo de ejecucion
    double time_spent=0.0;

    clock_t begin = clock();

    float P[tam];
    float R[tam];

    float tn, fn, tp, fp;
    float precision, recall;

    //Definir matriz de confusion
    int MC[2][2];

    //Bucle de repeticiones general
    for(int i=0; i<tam; i++){
            precision=0;
            recall=0;


        //Rellenar matriz
        for(int i=0; i<2; i++){
            for(int j=0; j<2; j++){
                MC[i][j]= rand() % 101;
            }
        }
        //Imprimir matriz
        /*for (int i=0; i<2; i++){
                for(int j=0; j<2; j++){
                    printf("MC[%i][%i]= %i \n", i, j, MC[i][j]);
                }
        }*/

        //Obtener posiciones para los calculos
        tp = MC[1][1];
        fp = MC[0][1];
        fn = MC[1][0];

        //Calcular presicion
        precision=tp/(tp+fp);
        P[i] = precision;

        //Calcular recall
        recall=tp/(tp+fn);
        R[i]=recall;


    }

    //Las siguientes lineas de codigo se usaron para verificar los calculos correctos
    //de precision, recall y F1-score con solo 1 repeticion.
    /*
    printf("El valor de la precision es: %f \n", precision);
    printf("El valor de recall es: %f \n", recall);
    // Formula de F1 - score
    F1=2*((precision*recall)/(precision+recall));
    printf("El valor de F1 es: %f \n", F1);
    */

    //POr ultimo estas lineas se usaron para verificar que los resultados
    //se guarden en los vectores correspodientes.
    /*
    imprimir_datos(tam, P);
    imprimir_datos(tam, R);
    */

    //Se invoca a la funcion de la metrica
    omp_set_num_threads(nt);
    #pragma omp parallel
    {
      F1_score(nt,tamanio,(float *)P,(float *)R);
    }
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\nEl tiempo de ejecucion del proceso es %f segundos\n", time_spent);

    return 0;
}

