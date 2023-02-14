#ifndef F1SCORE_FUNCIONES_H
#define F1SCORE_FUNCIONES_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

void F1_score(int nt, int tam, float *p,float *r);
void imprimir_datos(int n, float *v);

#endif // F1SCORE_FUNCIONES_H
