#include "hausdorff.h"

#define MAX_POINTS 10000
#define MAX_LINE_LENGTH 10000

int main(int argc, char *argv[]) {

    // para almacenar el tiempo de ejecución del código
    double time_spent = 0.0;

    clock_t begin = clock();

    Point set1[MAX_POINTS];
    int size1 = read_points_from_csv("/home/kevgcastillo/Proyecto/data/vecA_GH.csv", set1, MAX_POINTS);
    Point set2[MAX_POINTS];
    int size2 = read_points_from_csv("/home/kevgcastillo/Proyecto/data/vecB_GH.csv", set2, MAX_POINTS);

    if (size1 > 0 && size2 > 0) {
        double distance = hausdorff_distance(set1, size1, set2, size2);
        printf("Distancia de Hausdorff: %f\n", distance);
        clock_t end = clock();
        time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
        //printf("\nTiempo de ejecucion: %f s\n", time_spent);

        //printf("Numeros de hilos: %d de %d", omp_get_thread_num());
        //printf("Numeros de hilos: %d de %d", omp_get_thread_num(), omp_get_num_threads());
    } else {
        printf("Error al leer los puntos de los archivos\n");
    }
    return 0;
}

