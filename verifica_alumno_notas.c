/* Alumno: Salamone Leonardo
   Curso: 1c turno tarde*/
//Generamos un programa para verificar si un alumno promociona la materia, rinde final o recursa la materia 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main(void) {
  //Definimos las variables que vamos a utilizar
  int Faltas,TP1,TP2;
  float Parcial1,Parcial2,Final;
  int opc = 1;
  char DNI[8];

  //Generamos un bucle para ingresar las veces que sea necesario los datos de distintos alumnos 
  while (opc == 1)
  {
    printf("Ingrese DNI del Alumno:\t");
    scanf("%s",DNI);
    
    int i;
    for (i=0; i<strlen(DNI); i++)
    {
      while (0==(isdigit(DNI[i])))
      {
        printf("\n Ingrese solo numeros \n Ingrese DNI del Alumno:\t");
        scanf("%s",DNI);
      }
      
    }
       while ( strlen(DNI)>8)
      {
        printf("\n Longitud de DNI invalida \n Ingrese DNI del Alumno:\t");
        scanf("%s",DNI);
      }  
    //Se ingresan las faltas del alumno, si no tuvo faltas se continua caso contrario, va a final
    printf("Ingrese el numero de Faltas del alumno:\t");
    scanf("%i",&Faltas);
    if (Faltas == 0)
    {
      //validamos si entrego el tp1 a tiempo 
      printf("Se entrego el TP1 en termino? \n Opcion 1 entregado a termino \n Opcion 2 entregado fuera de termino \n Ingrese opcion:\t");
      scanf("%i",&TP1);
      while (TP1!=1 && TP1!=2)
        {
            printf("Opcion no valida \n Ingrese una opcion valida:\t");
            scanf("%i",&TP1);
          }
      if (TP1 == 1)
      {
        //Ingresamos la nota del primer parcial, segun su puntuacion rinde final, recursa o sigue con la cursada
        printf("Ingrese la nota del primer parcial: \t");
        scanf("%f",&Parcial1);
        while (Parcial1>10 && Parcial1<0)
        {
            printf("Error de nota \n Ingrese la nota del primer parcial:\t");
            scanf("%f",&Parcial1);
          }
        if (Parcial1>=6)
        {
          //validamos si entrego el tp2 a tiempo 
          printf("Se entrego el TP2 en termino?\n Opcion 1 entregado a termino \n Opcion 2 entregado fuera de termino \n Ingrese opcion:\t");
          scanf("%i",&TP2);
          while (TP2!=1 && TP2!=2)
            {
              printf("Opcion no valida \n Ingrese una opcion valida:\t");
              scanf("%i",&TP2);
            }
          if (TP2 == 1)
          {
            //Ingresamos la nota del segundo parcial, segun su puntuacion rinde final,recursa  o promociono la materia
            printf("Ingrese la nota del segundo parcial: \t");
            scanf("%f",&Parcial2);
            while (Parcial2>10 && Parcial2<0)
            {
              printf("Error de nota \n Ingrese la nota del primer parcial:\t");
              scanf("%f",&Parcial2);
            }
            if (Parcial2>=6)
            {
              printf("Felicitaciones promociono la materia!!");
            }
            else if (Parcial2>=4)
            {
              //Rinde final se verifica la nota, si aprueba la cursada o recursa
              printf("Rinde final. \n Ingrese la nota del final:\t");
              scanf("%f",&Final);
              while (Final>10 && Final<0)
              {
              printf("Error de nota \n Ingrese la nota del primer parcial:\t");
              scanf("%f",&Final);
            }
              if (Final>=7)
              {
                printf("Felicidades aprobo la Materia");
              }
              else
              {
                printf("Lo siento mucho, pero, recursas la materia.");
              }
            }
            else
            {
              printf("Lo siento mucho, pero, recursas la materia.");
            }
          }
          else
          {
            printf("Lo siento mucho, pero, recursas la materia.");
          }
        }
        else if (Parcial1>=4)
        {
          //Rinde final se verifica la nota, si aprueba la cursada o recursa
           printf("Rinde final. \n Ingrese la nota del final:\t");
              scanf("%f",&Final);
              while (Final>10 && Final<0)
              {
              printf("Error de nota \n Ingrese la nota del primer parcial:\t");
              scanf("%f",&Final);
            }
              if (Final>=7)
              {
                printf("Felicidades aprobo la Materia");
              }
              else{printf("Lo siento mucho, pero, recursas la materia.");}
        }
        else{printf("Lo siento mucho, pero, recursas la materia.");}
      }
      else
      {
        //Rinde final se verifica la nota, si aprueba la cursada o recursa
        printf("Rinde final. \n Ingrese la nota del final:\t");
        scanf("%f",&Final);
        while (Final>10 && Final<0)
        {
          printf("Error de nota \n Ingrese la nota del primer parcial:\t");
          scanf("%f",&Final);
        }
          if (Final>=7)
          {
            printf("Felicidades aprobo la Materia");
          }
          else{printf("Lo siento mucho, pero, recursas la materia.");}
      }
    }
    else
    {
      //Rinde final se verifica la nota, si aprueba la cursada o recursa
      printf("Rinde final. \n Ingrese la nota del final:\t");
      scanf("%f",&Final);
      while (Final>10 || Final<0)
      {
        printf("Error de nota \n Ingrese la nota del primer parcial: \t");
        scanf("%f",&Final);
      }
      if (Final>=7)
      {printf("\n Felicidades aprobo la Materia");}
      else
      {printf("Lo siento mucho, pero, recursas la materia.");}
    }
    //Generamos la opcion para poder seguir cargando otros alumnos
    printf(" \n\n Desea ingresar los datos de otro alumno? \n opcion 1= SI \n opcion 2= NO \n");
    scanf("%i",&opc);
    while(opc != 1 && opc != 2)
    {
      printf("opcion no valida \n Desea ingresar los datos de otro alumno? \n opcion 1= SI \n opcion 2= NO \n");
      scanf("%i",&opc);
    } 
  }
  return 0;
}