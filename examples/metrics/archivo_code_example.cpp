#include <iostream>
#include "archivo.h"
#define t 10
using namespace std;

int main()
{
    int img[t][t],img2[t][t];

   //lectura
    char c;
    FILE* archivo1 = fopen("/home/grupoc/Escritorio/project/dicom-classifier/data/img_GC.csv", "r");
    int i=0,j=0;
    while ((c = fgetc(archivo1)) != EOF) {

        if (c == ';') {
            // Haz algo cuando encuentres una coma
            if(j==t){
                i++;
                j=0;
            }
        } else {
            if(c=='0'){
                img[i][j]=0;
            }
            else if(c=='1'){
                img[i][j]=1;
            }
            j++;
        }

    }
    fclose(archivo1);
    //m2
    FILE* archivo2 = fopen("/home/grupoc/Escritorio/project/dicom-classifier/data/img2_GC.csv", "r");
    int b=0,v=0;
    while ((c = fgetc(archivo2)) != EOF) {

        if (c == ';') {
            // Haz algo cuando encuentres una coma
            if(v==t){
                b++;
                v=0;
            }
        } else {
            if(c=='0'){
                img2[b][v]=0;
            }
            else if(c=='1'){
                img2[b][v]=1;
            }
            v++;
        }

    }
    fclose(archivo2);

    calcularTot(t,(int *)img,(int *)img2,t);


    return 0;
}


