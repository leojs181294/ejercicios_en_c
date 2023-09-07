#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANIO 20
#define CANTIDAD 10

int main(){
    char nombres[CANTIDAD][TAMANIO];
    char savep1[TAMANIO];
    char cadena[TAMANIO*CANTIDAD];

    for (int i=0; i < CANTIDAD; i++){
        strcpy(nombres[i],"  ");
    }

    for (int i = 0; i < CANTIDAD; i++){
        printf("\nIngrese nombre %i:\t",(i+1));
        gets(nombres[i]);
        while(strlen(nombres[i]) > 20){
            printf("\nEl nombre ingreasado sobrepasa la cantidad de caracteres permitidos, vuelva a intentar...\n");
            printf("\nIngrese nombre %i:\t",(i+1));
            gets(nombres[i]);
        }
        printf("\nel nombre agregado al array es: %s\n", nombres[i]);
    }
    strcpy(cadena," ");
    for(int i = 0; i < CANTIDAD; i++){
        strcat(cadena, nombres[i]);
    }
    for(int i=0;i<CANTIDAD;i++){
        for(int i=0;i<CANTIDAD-1;i++){
            if (strcasecmp(nombres[i], nombres[i+1])>0){
                strcpy(savep1, nombres[i]);
                strcpy(nombres[i], nombres[i+1]);
                strcpy(nombres[i+1], savep1);
            }
        }
    }
    system("cls");
    system("pause");
    for(int i=0;i<CANTIDAD;i++){
        printf("\nEl elemento %i", (i+1));
        printf(" del vector contiene el nombre de: %s\n", nombres[i]);
    }
    
    printf("\nElementos del vector original concatenados: %s", cadena);
}