#ifndef HAUSDORFF_H_INCLUDED
#define HAUSDORFF_H_INCLUDED


#include <stdio.h> // Biblioteca para operaciones de entrada/salida
#include <math.h>
#include <stdlib.h> // Biblioteca para funciones generales
#include <float.h> // Biblioteca para constantes con valores máximos y mínimos de tipos flotantes
#include <string.h> // Biblioteca para funciones de manejo de cadenas de caracteres
#include <omp.h> // Biblioteca para programación paralela con OpenMP
#include <time.h> // Biblioteca para funciones de manejo de tiempo
#include <unistd.h>

// Define la estructura Point para representar un punto en el espacio
typedef struct {
    double x;
    double y;
} Point;
// Calcula la distancia euclídea entre dos puntos
double euclidean_distance(Point a, Point b);

// Calcula la distancia de Hausdorff entre dos conjuntos de puntos
double hausdorff_distance(Point set1[], int size1, Point set2[], int size2);

// Lee los puntos de un archivo CSV y los guarda en un arreglo de puntos
int read_points_from_csv(const char *file_name, Point set[], int max_size);


#endif // HAUSDORFF_H_INCLUDED
