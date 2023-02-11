#ifndef CANNY_H
#define CANNY_H

#include <iostream>
#include <omp.h>

/*
 * ESTRUCTURA ESTANDAR:
 * Todas las funciones reciben una altura, ancho y la matriz a revisar
 * para poder realizar los calculos necesitados
 *
 */

bool comprobacion(int altura, int largo, int *imagen);
float original(int altura, int largo, int *imagen);
float canny(int altura, int largo, int *imagen);

#endif // CANNY_H
