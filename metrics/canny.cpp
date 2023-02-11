#include "canny.h"

/*
 * TEORIA:
 * - Si los valores de la matriz son entre 0 y 1 demuestran que la imagen esta en blanco y negro
 *   eso quiere decir que los bordes son optimos
 *
 * - Si los valores de la matriz son entre 2 y 10 demuestran que estan en escala de grises
 *   eso quiere decir que hay ruido en la imagen
 *
 * - Si los valores de la matriz son entre 10 y 16.7millones demuestra que l< imagen esta a color
 *   eso quiere decir que no se encuentra a escala de grises
 *
 * FUNCIONES:
 * - La funcion COMPROBACION devuelve si la funcion esta en escala de grises o no porque es
 *   necesario esta confirmacion para identificar el porcentaje de error en los bordes
 *
 * - La funcion ORIGINAL demuestra el porcentaje de error que tiene por la escalas de grises
 *   en los bordes de la imagen
 *
 * - La funcion CANNY se encarga de devolver un decimal correspondiente al porcentaje de
 *   error que demuestran los bordes
 *
 * NOTA:
 * Nuestro fuerte es la programacion, mas no la comprobacion total del metodo, se emplea solo
 * el algoritmo funcional de como deberia funcionar correctamente el metodo CANNY EDGE DETECTION
 * por ello la escala de grises se dara por numeros randomicos dentro del main.cpp
 *
 */

bool comprobacion(int altura, int largo, int *imagen){
    int grises=0;
    int color=0;
    bool bandera=false;
    int hilos = 32;
    omp_set_num_threads(hilos);
    #pragma omp for collapse(2)
    for(int i=0;i<altura;i++){
        for (int j=0;j<largo;j++){
                if(*((imagen+i*largo)+j)==0||*((imagen+i*largo)+j)==1)
                    grises++;
                else
                    color++;
        }
    }
    fflush(stdout);
    if(color==0)
        bandera=true;

    return bandera;
}

float original(int altura, int largo, int *imagen){
    if(comprobacion(altura,largo,imagen))
        return 0.0;
    int color=0;
    int grises=0;
    float porcentaje=0.0;
    int hilos = 32;
    omp_set_num_threads(hilos);
    #pragma omp for collapse(2)
    for(int i=0;i<altura;i++){
        for (int j=0;j<largo;j++){
                if(*((imagen+i*largo)+j)==0||*((imagen+i*largo)+j)==1)
                    grises++;
                else
                    color++;
        }
    }
    fflush(stdout);
    return porcentaje = (color*100)/(altura*largo);
}

float canny(int altura, int largo, int *imagen){
    if(comprobacion(altura,largo,imagen)){
        int color=0;
        int grises=0;
        float porcentaje=0.0;
        int hilos = 32;
        omp_set_num_threads(hilos);
        #pragma omp for collapse(2)
        for(int i=0;i<altura;i++){
            for (int j=0;j<largo;j++){
                    if(*((imagen+i*largo)+j)==0||*((imagen+i*largo)+j)==1)
                        grises++;
                    else
                        color++;
            }
        }
        fflush(stdout);
        return porcentaje = ((grises*100)/(altura*largo));
    }
    return 0,0;
}
