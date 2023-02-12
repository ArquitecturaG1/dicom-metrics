#include "fppr.h"

float fppr(int w, int h, int *ref, int *det){

    int false_positives = 0;
    int t_pixels = w * h;
    float false_positive_pixel_rate = 0;
    int num_threads = 8;
    omp_set_num_threads(num_threads);
    #pragma omp for collapse(2)
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            if (*((ref+i*h)+j) == 0 && *((det+i*h)+j) == 1)
                false_positives++;
        }
    }
    false_positive_pixel_rate = false_positives/(float)t_pixels;
    return false_positive_pixel_rate;
}
