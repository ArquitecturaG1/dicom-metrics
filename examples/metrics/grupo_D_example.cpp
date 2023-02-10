#include <iostream>

#include "ber.h"
#include "bcr.h"
#include "cdr.h"

using namespace std;

int main()
{
    int t = 1000000;
    int v1[t];
    int v2[t];

    srand (time(NULL));
    for(int i=0; i<t; i++){
        v1[i] = rand() % 2;
        v2[i] = rand() % 2;
    }


    printf("El BER es: %f\n", BER_F(v1, v2, t));
    printf("El BCR es: %f\n", BCR_F(v1,v2, t));
    printf("Suma: %f\n", (BER_F(v1,v2, t) + BCR_F(v1,v2, t)));
    CDR_F(v1, v2, t);
    return 0;
}
