# include <stdlib.h>
# include <stdio.h>
# include <string.h>
#include <ctype.h>

# define MAX_ALUMNOS 100

struct Alumnos{
 	char n_legajo[10];
 	char apellido_nombre[30];
  	float promedio;
};

//Funcion que chequea si existe el archivo, si no existe lo crea y si existe toma los datos del archivo para el array de estructuras.
int chequeo_lectura(struct Alumnos alumnos[]){
    int iterativo=0;
    FILE *archivo;
    archivo = fopen("alumnos.dat", "rb");
    if(archivo == NULL){
        fclose(archivo);
        archivo = fopen("alumnos.dat", "wb");
        fclose(archivo);
        printf("Archivo creado...");
    }
    else{
		fclose(archivo);
		archivo = fopen("alumnos.dat", "rb");
        while(!feof(archivo)){
		   fread(&alumnos[iterativo], sizeof(alumnos[iterativo]),1, archivo);
            iterativo++;
        }
		fclose(archivo);
		iterativo--;
		printf("\nLectura realizada elemento: %i\n", iterativo);         
    }
	return iterativo;
}
//Funcion para guardar elementos del array en un archivo, en este caso el archivo se va a llamar "PAPF.dat"
void guardado(struct Alumnos alumnos[],int numAlumnos){
    FILE *archivo;
    archivo = fopen("alumnos.dat", "ab");
    if (archivo == NULL){
        printf("\nEl archivo no existe...");
    }
    else{
        fwrite(&alumnos[numAlumnos], sizeof(alumnos[numAlumnos]),1, archivo);
    }
    fclose(archivo); 
}
void agregar_alumno(struct Alumnos alumnos[], int* numAlumnos) {
   	struct Alumnos nuevo_alumno;
    printf("Ingrese N de legajo del alumno:\t");
    scanf("%s",nuevo_alumno.n_legajo);
    for (int i=0; i<strlen(nuevo_alumno.n_legajo); i++){
      while (0==(isdigit(nuevo_alumno.n_legajo[i]))){
        printf("\n Ingrese solo numeros \n Ingrese N de legajo del Alumno:\t");
        scanf("%s",nuevo_alumno.n_legajo);
      }
	}
    printf("Ingrese Apellido y nombre del alumno:\t");
    getchar();
    gets(nuevo_alumno.apellido_nombre);
	while(strlen(nuevo_alumno.apellido_nombre)==0){
		printf("El campo no puede estar vacio\n");
		printf("Ingrese Apellido y nombre del alumno:\t");
		gets(nuevo_alumno.apellido_nombre);
	}
    printf("Ingrese el promedio del alumno:\t");
    scanf("%f",&nuevo_alumno.promedio);
    alumnos[*numAlumnos] = nuevo_alumno;
    (*numAlumnos)++;
    guardado(alumnos,*numAlumnos);
    system("cls");
}
void mostrar_struc(struct Alumnos alumnos[],int maximo){
	for(int i=0;i<maximo;i++){
	 	printf("\nN de legajo:\t%s",alumnos[i].n_legajo);
	 	printf("\nApellido y nombre:\t%s",alumnos[i].apellido_nombre);
	 	printf("\nPromedio:\t%.2f",alumnos[i].promedio);
	 	printf("\t--------------------------------------\n");
	 }
}
void esp_limp(){	
	system("pause");
	system("cls");
}
void menu1(){
	printf("1. Agregar Alumno\n");
    printf("2. Lista de Alumnos\n");
    printf("3. Fechas segun promedio\n");
    printf("4. Salir\n");
    printf("Ingrese la opcion deseada: ");
}
void menu2(){
	printf("1. Alumnos aprobados\n");
    printf("2. Alumnos que rinden en diciembre\n");
    printf("3. Alumnos que rinden en marzo\n");
    printf("4. Alumnos con mejor promedio\n");
    printf("5. Cantidades de alumnos segun cuando rinden\n");
	printf("6. Regresar al menu anterior\n");
    printf("Ingrese la opcion deseada: ");
}
int valid_aprobados(struct Alumnos alumnos[],struct Alumnos aprobaron[]){
	int contador=0;
	for(int i=0;i<MAX_ALUMNOS;i++){
		if (alumnos[i].promedio>=7){
			aprobaron[contador]=alumnos[i];
			contador++;
		}
	}
	return contador;
}
int valid_diciembre(struct Alumnos alumnos[],struct Alumnos diciembre[]){
	int contador=0;
	for(int i=0;i<MAX_ALUMNOS;i++){
		if (alumnos[i].promedio<7 && alumnos[i].promedio>=4){
			diciembre[contador]=alumnos[i];
			contador++;	
		}
	}
	return contador;
}
int valid_marzo(struct Alumnos alumnos[],struct Alumnos marzo[]){
	int contador=0;
	for(int i=0;i<MAX_ALUMNOS;i++){
		if (alumnos[i].promedio<4){
			marzo[contador]=alumnos[i];
			contador++;		
		}
	}
	return contador;
}

void main(void)
{
	struct Alumnos alumnos[MAX_ALUMNOS];
	int cant_aprobados=0;
	struct Alumnos aprobaron[cant_aprobados];	// prom mayor o == a 7
	int cant_diciembre=0;
	struct Alumnos diciembre[cant_diciembre];	// prom < 7 y mayor o igual a 4
	int cant_marzo=0;
	struct Alumnos marzo[cant_marzo];	//promedio menor a 4
	float max_prom=0;
	int numAlumnos = chequeo_lectura(alumnos);
    char opcion,opc;
    
    for (int i=0;i<MAX_ALUMNOS;i++)
    {
    	strcpy(alumnos[i].n_legajo,"0");
    	strcpy(alumnos[i].apellido_nombre,"  ");
    	alumnos[i].promedio=0;
	}
	
    do {
    	menu1();
        scanf(" %c", &opcion);
        switch (opcion) {
            case '1':{
            	
				 agregar_alumno(alumnos,&numAlumnos);
                 break;
             	}
            case '2':{
				 mostrar_struc(alumnos,numAlumnos);			
				 esp_limp();
                 break;
        		}
			case '3':{
				 do{
					menu2();
				    scanf(" %c", &opc);
				    system("cls");
				    switch(opc){
				    	case '1':{
				    			printf("\nLos alumnos que aprobaron son los siguientes\n");
								cant_aprobados=valid_aprobados(alumnos,aprobaron);
								mostrar_struc(aprobaron,cant_aprobados);
								printf("\nCantidad total de aprobados: %i\n",cant_aprobados);
								esp_limp();
								break;
							}
						case '2':{
								printf("\nLos alumnos que rinden en diciembre son los siguientes\n");
				    			cant_diciembre=valid_diciembre(alumnos,diciembre);
								mostrar_struc(diciembre,cant_diciembre);
								printf("\nCantidad total que rinden en diciembre: %i\n",cant_diciembre);
								esp_limp();
								break;
							}
						case '3':{
								printf("\nLos alumnos que rinden en marzo son los siguientes\n");
				    			cant_marzo=valid_marzo(alumnos,marzo);
								mostrar_struc(marzo,cant_marzo);
								printf("\nCantidad total que rinden en marzo: %i\n",cant_marzo);
								esp_limp();
								break;								
							}
						case '4':{
								printf("los alumnos con mejores promedios son:\n");
								for(int i=0;i<MAX_ALUMNOS;i++){
									for(int x=0;x<MAX_ALUMNOS;x++){
										if(alumnos[x].promedio>max_prom){
											max_prom=alumnos[x].promedio;	
										}	
									}
									if(alumnos[i].promedio==max_prom){
									 	printf("\nN de legajo:\t%s",alumnos[i].n_legajo);
									 	printf("\nApellido y nombre:\t%s",alumnos[i].apellido_nombre);
									 	printf("\nPromedio:\t%.2f",alumnos[i].promedio);
									 	printf("\t--------------------------------------\n");
									}
								}
							}
						case '5':{
							printf("Alumnos aprobados:\t%i",&cant_aprobados);
							printf("Alumnos que rinden en Diciembre:\t%i",&cant_diciembre);
							printf("Alumnos que rinden en Marzo:\t%i",&cant_marzo);
							break;
						}
				        default:
               				printf("\nOpcion invalida. Intente nuevamente.\n");				
					} 
				 }while(opc != '6');
				 break;
				}
            case '4':
                printf("Hasta luego\n");
                break;
            default:
                printf("\nOpcion invalida. Intente nuevamente.\n");
        }
    } while (opcion != '4');
}

