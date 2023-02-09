#include "Accuracy.h"

   //Variables de matriz de confusion
	float vp[TAM];
	float vn[TAM];
	float fn[TAM];
	float fp[TAM];

//vectores para las operaciones entre matrices
	float C[TAM];
	float A[TAM];
	float B[TAM];


//variables para operaciones necesarias
	float sumatoriaV=0,sumatoriaT=0;
	float totalC,totalA,accuracy;
	int i,numH,id1;
	double time_spent = 0.0;
    float a=0,b=0;
    FILE *f;

Accuracy::Accuracy()
{
    	for (i = 0; i < TAM; i++) {
        vp[i] = rand()%100;
		vn[i] = rand()%100;
		fp[i] = rand()%100;
		fn[i] = rand()%100;
	}
     clock_t begin = clock();

     f=fopen("datosParalelo.csv","a");
     if (f==NULL){
        printf("No se pudo leer el archivo.\n");
        exit(1);
     }
     fprintf( f,"\n  ValoreslCoincidentes;NumeroObservaciones;Accuracy\n ");


	#pragma omp parallel num_threads(12)
	{
		int id = omp_get_thread_num();
		int nt = omp_get_num_threads();
		numH=nt;
		id1=id;
		//cantidad de elementos a trabajar en cada hilo
		int size = (int) TAM / nt;
		int ini = id * size;
		int fin = ini + size - 1;
		int j;
		for (j = ini; j <= fin; j++) {
			C[j] = vp[j] + vn[j];
		}
		for (j = ini; j <= fin; j++) {
			B[j] = fp[j] + fn[j];
		}
        for (j = ini; j <= fin; j++) {
			A[j] = C[j] + B[j];
		}

        for (j = ini; j <= fin; j++) {
            int numeroAcutal= C[j];
            sumatoriaV = sumatoriaV+numeroAcutal;
		}
		for (j = ini; j <= fin; j++) {
            int numeroAcutal= A[j];
            sumatoriaT = sumatoriaT+numeroAcutal;
		}

	}


/*	for (i = 0; i < TAM; i++) {

		printf("B[%d] = %f \n", i, B[i]);
	}
        printf( "\n\n");
		for (i = 0; i < TAM; i++) {
		printf("C[%d] = %f \n", i, C[i]);

	}
	    printf( "\n\n");
		for (i = 0; i < TAM; i++) {
		printf("A[%d] = %f \n", i, A[i]);
	}*/


    float c=0;
     c=(sumatoriaV*100)/sumatoriaT;
     float tot=c;

    clock_t end = clock();

    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;


         f=fopen("datosTiempoParalelo.csv","a");
     if (f==NULL){
        printf("No se pudo leer el archivo.\n");
        exit(1);
     }

    fprintf(f,"El tiempo de ejecucion; %f trabajando con %d hlos; desde el hilo %d \n",time_spent,numH,id1);

     f=fopen("datosParalelo.csv","a");
     if (f==NULL){
        printf("No se pudo leer el archivo.\n");
        exit(1);
     }

     fprintf( f,"\n  %.0f%;            %.0f;                 %.0f",sumatoriaV,sumatoriaT,tot);


     printf( "\n  Sumatoria de valores coincidentes  %.0f",sumatoriaV);

     printf( "\n  Numero de observaciones en el ejemplo %.0f",sumatoriaT);

     printf( "\n  El porcentaje de Accuracy es: %.2f (porciento) \n ",tot );
}

Accuracy::~Accuracy()
{
    //dtor
}


