#ifndef FNR_H
#define FNR_H
#include <iostream>
#include <omp.h>

/* Definicion:
 *     fnr() se refiere a la fracción de casos negativos
 *           que son incorrectamente etiquetados como positivos.
 * Sintaxis:
 *     float fnr(int width, int height, int **img_reference, int **img_detected)
 * Parametros:
 *     + width:  ancho en pixeles de la matriz de imagen.
 *     + height: altura en pixeles de la matriz de imagen.
 *     + img_reference: matriz que representa a la imagen
 *                      tomada como base, esta matriz varia
 *                      segun la profundidad utilizada
 *                      en su obtencion.
 *     + img_detected: matriz que representa a la imagen
 *                     tomada a comparar, esta matriz varia
 *                     segun la profundidad utilizada
 *                     en su obtencion.
 *     - No aplica para esta funcion.
 * Valor de retorno:
 *     *Tasa de falsos negativos (FNR)
 */

float fnr(int width, int height, int *img_reference, int *img_detected);

#endif // FNR_H


