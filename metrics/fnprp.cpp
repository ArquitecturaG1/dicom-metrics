#include "fnprp.h"

float fnprp(int width, int height, int *img_reference, int *img_detected){
    /*
     * Suponemos que las imagenes son representadas con una matriz de width x height pixeles
     *
     * CASOS POSIBLES DE COMPARACION:
     * True positive -> reference=1 & detected=1
     * False positive -> reference=0 & detected=1
     * True negative -> reference=0 & detected=0
     * False negative -> reference=1 & detected=0 -> CASO REQUERIDO
     *
     *
     */

    // Obtencion del numero de pixeles falsos negativos y el numero total de pixeles
    int false_negatives = 0;
    int total_pixels = width * height;
    float false_negative_rate_percentage = 0;
    int num_threads = 4;
    omp_set_num_threads(num_threads);
    #pragma omp for collapse(2)
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            if (*((img_reference+i*height)+j) == 1 && *((img_detected+i*height)+j) == 0)
                false_negatives++;
        }
    }
    fflush(stdout);
    // Obtencion del porcentaje de tasa de pixeles falsos negativos
    false_negative_rate_percentage = false_negatives/(float)total_pixels * 100;
    return false_negative_rate_percentage;
}
