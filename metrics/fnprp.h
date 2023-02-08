#ifndef FNPRP_H
#define FNPRP_H
#include <iostream>
#include <omp.h>

/* Definicion:
 *     fnprp() se usa para devolver el porcentaje que contempla a los
 *             pixeles que estan dentro del limite de la region de referencia,
 *             pero fuera del limite de la region detectada.
 * Sintaxis:
 *     float fnprp(int width, int height, int **img_reference, int **img_detected)
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
 *     * Porcentaje de tasa de pixeles falsos negativos (FNPRP)
 */

float fnprp(int width, int height, int *img_reference, int *img_detected);

#endif // FNPRP_H
