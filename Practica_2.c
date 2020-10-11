#include<stdio.h>
#include<stdlib.h>
#define p printf 
#define s scanf 

void proCal(float *, int );
void proEdad(float *, int );
void imprimir(int *, float *, float *, int );


int main(){
    int alu=0, YO, cal;
    printf("Ingresa la cantidad de alumnos a registrar (Maximo 30): ");
    scanf("%i", &alu);
    if (alu<=0){
        p("El numero ingresado es invalido.");
    }
    else{
         YO=alu;
        cal=alu;
        float dat[cal], edad[YO];
        int numC[alu], aprobados=0 ;
        for (int i = 0; i < alu; i++){
            p("Ingresa el numero de cuenta del alumno %d: ", i+1);
            s("%i", &numC[i]);
            p("\n");
            p("Ingresa la calificacion del alumno: " );
            s("%f", &dat[i]);
            if (dat[i]<0 || dat[i]>10){
                p("Califcacion invalida. La calificacion se tomara como 0");
                dat[i]=0;    
            }
            if (dat[i]>=6){
                    aprobados+=1;
                }
            p("\n");
            p("Ingresa la edad del alumno: " );
            s("%f", &edad[i]);
            p("\n");
        }
        proCal(dat, alu);
        proEdad(edad, aprobados);
        imprimir(numC, edad, dat, alu );
        system("pause");
    }
   return 0; 
}

void proCal(float *datos, int estudiantes){
    float suma=0, promedio=0;
    for (int i = 0; i < estudiantes ; i++)
    {
        suma += *(datos+i);
    }
    promedio = ((suma)/(estudiantes));
    p("Promedio de calificaciones: %.2f\n", promedio);
}

void proEdad(float *edades, int estudiantes){
    float suma=0, promedio=0;
    for (int i = 0; i < estudiantes ; i++)
    {
        suma += *(edades+i);
    }
    promedio = ((suma)/(estudiantes));
    p("Numero de APROBADOS: %i \nPromedio de edades de los estudiantes aprobados: %.2f\n", estudiantes, promedio);
}

void imprimir(int *id, float *edad, float *calif, int alu ){
    char datos[3][15] = {"N. alu","edad", "Cal"};
    for (int i = 0; i < 3 ; i++)
    {
        p("%14s ", datos[i]);
    }
    p("\n");
    for (int i = 0; i < alu; i++){
        p(" %i \t ", *(id+i));
        p("\t %2.f \t ", *(edad+i));
        p("\t %.2f ", *(calif+i));
        p("\n");
    }
    
}