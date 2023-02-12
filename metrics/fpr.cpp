#include "fpr.h"

float fpr(int w, int h, int *ref, int *det){

    int false_positives = 0;
    int true_negatives = 0;
    int num_threads = 8;
    omp_set_num_threads(num_threads);
    #pragma omp for collapse(2)
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            if (*((ref+i*h)+j) == 0 && *((det+i*h)+j) == 0)
                true_negatives++;
            if (*((ref+i*h)+j) == 0 && *((det+i*h)+j) == 1)
                false_positives++;
        }
    }
    return (float)false_positives / (true_negatives + false_positives);
}
