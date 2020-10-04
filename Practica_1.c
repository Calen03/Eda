/*
Practica 1. Temperatura maxima


Casique Corona Luis Enrique 


*/

#include<stdio.h>
#include<stdlib.h>

int main(){
    int edo=3,mm=3,aa=2;
    int esMax,moMax;
    float sumE,aMax;
    float temp[edo][mm][aa];
    char year[5][5] = {"2005","2010"};
    char estados[3][20]={"Aguas cal", "Baja cal", "Baja cal sur"};
    char mes[3][5]={"Oct", "Nov", "Dic"};
        for (int i=0; i<aa; i++){
            for (int j=0; j<edo; j++){
                for (int k=0; k<mm; k++){
                    printf("ingresa la temperatura de %s en %s del %s \n", estados[j],mes[k],year[i]);
                    scanf("%f", &temp[j][k][i]);
                }
            }
        }
        printf("\tTemperatura maxima del ultimo trimestre de 3 estados\n");
        for (int i=0; i<aa; i++){
            printf("Temperaturas del año %s\n\n", year[i]);
            aMax=0;
            sumE=0;
            for (int m = 0; m < edo; m++){
                printf("\t %12s", mes[m]);
            }
            printf("\t\tPromedio anual\n");
            for (int j=0; j<edo; j++){
                printf("%15s\t ",estados[j]);
                for (int k=0; k<mm; k++){
                    printf("%.2f\t\t  ", temp[j][k][i]);
                    sumE+=temp[j][k][i];
                    if (temp[j][k][i]>aMax){
                        aMax=temp[j][k][i];
                        esMax=j;
                        moMax=k;
                    }
                }
                sumE/=edo;
                printf(" **%.2f**", sumE);
                sumE=0;
                printf("\n");
            }
            printf("La temperatura más alta registrada del año %s fue del estado de %s en el mes de %s con una maxima de %.2f\n\n", year[i],estados[esMax],mes[moMax], aMax );
        }
    system("pause");
    return 0;
}
