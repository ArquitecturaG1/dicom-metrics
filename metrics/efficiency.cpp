#include "efficiency.h"

/* TEORIA:
 * La eficiencia de un programa se define si esque el tiempo de ejecucion es bajo
 * y si es bajo quiere decir que consume pocos recursos del CPU, caso contrario
 * no es eficaz.
 *
 * FUNCIONES:
 * - La funcion TIEMPO se encarga de calcular el tiempo total de ejecucion del
 *   programa, utilizando un tiempo inicial y final
 * - La funcion EFICAZ se encarga de comparar el tiempo de ejecucion con un tiempo
 *   estandar de ejecucion, definiendo asi si el programa es eficaz o no
 *
 */

double tiempo(unsigned t0, unsigned t1){
    double tiempo;
    int hilos = 32;
    omp_set_num_threads(hilos);
    #pragma omp for collapse(2)
    return tiempo = (double (t1-t0)/CLOCKS_PER_SEC);
}

void eficaz(double tiempo){
    if(tiempo>0.5)
        cout<<"EL PROGRAMA NO ES EFICAZ"<<endl;
    else
        cout<<"EL PROGRAMA SI ES EFICAZ"<<endl;
    fflush(stdout);
}
