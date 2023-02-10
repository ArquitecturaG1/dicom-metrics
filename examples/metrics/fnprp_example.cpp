#include "fnprp.h"

#include "time.h"

#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "sys/times.h"
#include "sys/vtimes.h"
#include <string.h>

int parseLine(char* line){
    // This assumes that a digit will be found and the line ends in " Kb".
    int i = strlen(line);
    const char* p = line;
    while (*p <'0' || *p > '9') p++;
    line[i-3] = '\0';
    i = atoi(p);
    return i;
}

int get_Mem_Value(){ //Note: this value is in KB!
    FILE* file = fopen("/proc/self/status", "r");
    int result = -1;
    char line[128];

    while (fgets(line, 128, file) != NULL){
        if (strncmp(line, "VmRSS:", 6) == 0){
            result = parseLine(line);
            break;
        }
    }
    fclose(file);
    return result;
}

static clock_t lastCPU, lastSysCPU, lastUserCPU;
static int numProcessors;

void init(){
    FILE* file;
    struct tms timeSample;
    char line[128];

    lastCPU = times(&timeSample);
    lastSysCPU = timeSample.tms_stime;
    lastUserCPU = timeSample.tms_utime;

    file = fopen("/proc/cpuinfo", "r");
    numProcessors = 0;
    while(fgets(line, 128, file) != NULL){
        if (strncmp(line, "processor", 9) == 0) numProcessors++;
    }
    fclose(file);
}

double getCurrent_CPU_Value(){
    struct tms timeSample;
    clock_t now;
    double percent;

    now = times(&timeSample);
    if (now <= lastCPU || timeSample.tms_stime < lastSysCPU ||
        timeSample.tms_utime < lastUserCPU){
        //Overflow detection. Just skip this value.
        percent = -1.0;
    }
    else{
        percent = (timeSample.tms_stime - lastSysCPU) +
            (timeSample.tms_utime - lastUserCPU);
        percent /= (now - lastCPU);
        percent /= numProcessors;
        percent *= 100;
    }
    lastCPU = now;
    lastSysCPU = timeSample.tms_stime;
    lastUserCPU = timeSample.tms_utime;

    return percent;
}

using namespace std;

int main()
{
    // Suponemos que la imagen es una matriz de WIDTH x HEIGHT pixeles
    fflush(stdin);
    FILE* archivo = fopen("/home/kevgcastillo/Proyecto/data/datosMatriz1_GF.csv", "r");
    if (!archivo) {
        printf("Error al abrir el archivo\n");
        return 1;
    }

    char buffer[1024];
    int i=0, j=0;
    int image_ref[512][512];
    while (fgets(buffer, sizeof(buffer), archivo)) {
        char* celda = strtok(buffer, ";");
        while (celda) {
            if (i < 512){
                if (j < 512){
                    image_ref[i][j]=atoi(celda);
                    j++;
                }
                else{
                    j=0;
                    i++;
                }
            }
            celda = strtok(NULL, ";");
        }
    }

    fclose(archivo);
    archivo = fopen("/home/kevgcastillo/Proyecto/data/datosMatriz2_GF.csv", "r");
    if (!archivo) {
        printf("Error al abrir el archivo\n");
        return 1;
    }

    char buffer_2[1024];
    i=0, j=0;
    int image_det[512][512];
    while (fgets(buffer_2, sizeof(buffer_2), archivo)) {
        char* celda = strtok(buffer_2, ";");
        while (celda) {
            if (i < 512){
                if (j < 512){
                    image_det[i][j]=atoi(celda);
                    j++;
                }
                else{
                    j=0;
                    i++;
                }
            }
            celda = strtok(NULL, ";");
        }
    }

    fclose(archivo);
    //CPU inicio

    init();

    //Tiempo
    clock_t start, end;
    //Iniciamos el reloj
    start = clock();
    // Imprimimos el resultado
    printf("Porcentaje de tasa de pixeles falsos negativos: %f%%\n", fnprp(512, 512, (int *)image_ref, (int *)image_det));
    //Paramos el reloj
    end = clock();
    //Data
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    //Creamos archivo datosSecuencial.csv
    FILE *fp;
    fp  = fopen ("/home/kevgcastillo/Documents/datosParalelo_FNPRP.csv", "a");
    fprintf(fp, "%f sec;", time_taken);
    fprintf(fp, "%d KB;", get_Mem_Value());
    fprintf(fp, "%f %%;\n", getCurrent_CPU_Value());
    fclose (fp);
    fflush(stdout);
    return 0;
}
