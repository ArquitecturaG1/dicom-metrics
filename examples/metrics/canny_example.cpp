#include "canny.h"

void imagen_color();
void imagen_grises();

using namespace std;

int main(){
    cout << "\t\t - - PROYECTO - - " << endl;
    cout << "\t*EFs: ERROR*" << endl;
    // Quitar los slash para probar el metodo en sus dos formas

    imagen_color();
    imagen_grises();
    return 0;
}

void imagen_color(){
    int matriz[480][520];
    for(int i=0;i<480;i++){
        for(int j=0;j<520;j++){
            matriz[i][j]=rand()%16700001;
        }
    }
    cout << "\nEl porcentaje de ruido en la foto es: " << original(480,520,(int *)matriz) << endl;
    cout << "El porcentaje de error en los bordes es: " << canny(480,520,(int *)matriz) << endl;
}

void imagen_grises(){
    int matriz[480][520];
    for(int i=0;i<480;i++){
        for(int j=0;j<520;j++){
            matriz[i][j]=rand()%2;
        }
    }
    cout << "\nEl porcentaje de ruido en la foto es: " << original(480,520,(int *)matriz) << endl;
    cout << "El porcentaje de error en los bordes es: " << canny(480,520,(int *)matriz) << endl;
}
