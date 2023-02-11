#include <stdio.h>
#include <stdlib.h>

// Metricas a usar
#include "ME.h"
#include "NRM.h"
#include "jaccard.h"

#define SIZE 30000

FILE *fichero;
int M1[SIZE+1], M2[SIZE+1], M3[SIZE+1], M4[SIZE+1];
int x, aux;
char path1[] = "/home/kevgcastillo/Proyecto/data/DB1_GA.txt",
     path2[] = "/home/kevgcastillo/Proyecto/data/DB2_GA.txt",
     path3[] = "/home/kevgcastillo/Proyecto/data/DB3_GA.txt",
     path4[] = "/home/kevgcastillo/Proyecto/data/DB4_GA.txt";

void llenar_vector(int vector[], char file_name[])
{
    fichero = fopen(file_name,"r");
    if (fichero==NULL){
        printf("No se ha podido abrir el archivo %s",file_name);
    }else{
        for (int i=0; i<x; i++){
            fscanf(fichero,"%d;" , &vector[i]);
        }
    }
    fclose(fichero);
}

void size_array(int vector[], char file_name[])
{
    int c;
    x = -1;
    fichero = fopen(file_name,"r");

    do{
        x++;
        c = fscanf(fichero,"%d;",&vector[x]);
    }while(c != EOF);

    fclose(fichero);
}

void iniciar()
{
    int i, j;

    double time_spent = 0.0;
    clock_t begin = clock();

    size_array (M1, path1);

    llenar_vector(M1, path1);
    llenar_vector(M2, path2);
    llenar_vector(M3, path3);
    llenar_vector(M4, path4);

    #pragma omp parallel for private (i,j,M1,M2,M3,M4) num_threads(16)
    for(i = 0; i < SIZE; i++){

        for(j = 0; j < SIZE; j++){
            if(M1[i] > M1[j+1]){
                aux = M1[j];
                M1[j] = M1[j+1];
                M1[j+1] = aux;
            }
            if(M2[i] > M2[j+1]){
                aux = M2[j];
                M2[j] = M2[j+1];
                M2[j+1] = aux;
            }
            if(M3[i] > M3[j+1]){
                aux = M3[j];
                M3[j] = M3[j+1];
                M3[j+1] = aux;
            }
            if(M4[i] > M4[j+1]){
                aux = M4[j];
                M4[j] = M4[j+1];
                M4[j+1] = aux;
            }
        }
    }

    // Metodo prueba local metrica Jaccard Similarity
    calcularJaccard(x, (int *)M1, (int *)M2);
    // Metodo prueba local metrica Negative Rate Metric
    calcularNRM(x, (int *)M1, (int *)M2, (int *)M3, (int *)M4);
    // Metodo prueba local metrica Misclassification Error
    calcularME(x, (int *)M1, (int *)M2, (int *)M3, (int *)M4);

    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\nTiempo en procesar el programa:  %f segundos\n", time_spent);
}

int main()
{
    iniciar();
    return 0;
}
