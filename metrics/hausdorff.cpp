#include "hausdorff.h"

// Define la cantidad máxima de puntos que se pueden leer de los archivos y la longitud máxima de una línea en el archivo
#define MAX_POINTS 10000
#define MAX_LINE_LENGTH 10000

int numHilos=1;

// Calcula la distancia euclídea entre dos puntos
double euclidean_distance(Point a, Point b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    // Calcula la distancia euclídea como la raíz cuadrada de la suma de las diferencias cuadradas
    return sqrt(dx*dx + dy*dy);
}

// Calcula la distancia de Hausdorff entre dos conjuntos de puntos
double hausdorff_distance(Point set1[], int size1, Point set2[], int size2) {
    double max_distance = 0;
    // Usa OpenMP para calcular la distancia de Hausdorff en paralelo
    #pragma omp parallel num_threads(4)
    {
        printf("Num de Hilos: %d\n",omp_get_thread_num());
        for (int i = 0; i < size1; i++) {
            double min_distance = DBL_MAX;
            for (int j = 0; j < size2; j++) {
                double distance = euclidean_distance(set1[i], set2[j]);
                if (distance < min_distance) {
                    min_distance = distance;
                }
            }
            if (min_distance > max_distance) {
                max_distance = min_distance;
            }
        }

    }
    return max_distance;
}

// Lee los puntos de un archivo CSV y los guarda en un arreglo de puntos
int read_points_from_csv(const char *file_name, Point set[], int max_size) {
     // Abre el archivo para lectura
    FILE *file = fopen(file_name, "r");
    if (file == NULL) {
        printf("Error al abrir el archivo %s\n", file_name);
        return 0;
    }

    char line[MAX_LINE_LENGTH];
    int size = 0;
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL && size < max_size) {
        double x, y;
        if (sscanf(line, "%lf,%lf", &x, &y) == 2) {
            set[size].x = x;
            set[size].y = y;
            size++;
        }
    }

    fclose(file);
    return size;
}
