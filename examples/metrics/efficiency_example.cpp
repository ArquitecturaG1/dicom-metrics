#include "efficiency.h"

using namespace std;
unsigned t0=0,t1=0;
double tim=0;
void ordenar_numeros(int arreglo[], int lon, unsigned t0, unsigned t1){
    t0=clock();
    int Temp;
    for(int i=0;i<lon;i++){
            for(int q=0;q<lon-1;q++) {
                if(arreglo[q]<arreglo[q+1]){
                    Temp=arreglo[q];
                    arreglo[q]=arreglo[q+1];
                    arreglo[q+1]=Temp;}
            }
    }
    for(int i=0;i<lon;i++){
        cout<<arreglo[i]<<endl;
    }
    t1=clock();
}


int main(){

    int lon,n;
    //cout<<"Escriba el numero de numeros a ordenar: ";
    //cin>>lon;
    lon = 10;
    cout<<"Numeros a ordenar: 10";
    int arr[10];
    for(int i=0;i<10;i++){
        cout<<"Escriba el numero "<<i+1<<": ";
        cin>>n;
        arr[i]=n;
    }
    cout<<endl<<"Numeros ordenados: "<<endl;
    ordenar_numeros(arr,lon,t0,t1);
    tim=tiempo(t0,t1);
    eficaz(tim);
}
