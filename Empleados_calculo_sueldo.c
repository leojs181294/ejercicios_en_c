#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NOMBRE 30
#define MAX_EMPLEADOS 50
struct Empleado 
{
    char nombre [MAX_NOMBRE];
    int salario;
};

void agregarEmpleado(struct Empleado empleados[], int* numEmpleados) {
    struct Empleado nuevo_empleado;
    printf("Ingrese el nombre del empleado: ");
    getchar(); // Limpiamos el buffer de entrada
    gets(nuevo_empleado.nombre);
	while (strlen(nuevo_empleado.nombre)==0)
	{
		printf("No puso nombre del empleado\n");
	    printf("Ingrese el nombre del empleado: ");
	    getchar(); // Limpiamos el buffer de entrada
	    gets(nuevo_empleado.nombre);
	}
    printf("Ingrese el salario del empleado: ");
    scanf("%i", &nuevo_empleado.salario);
    empleados[*numEmpleados] = nuevo_empleado;
    (*numEmpleados)++;
    system("cls");
}


int calcular_billetes(int monto ,int valor_billete) {
    int billetes = monto / valor_billete;
    return billetes;
}

void imprimirPagoEmpleados(struct Empleado empleados[], int numEmpleados) {
    long int sueldo_total_empleados=0;
	for (int i = 0; i < numEmpleados; i++) {
        long int sueldo = empleados[i].salario;
        int c1000=0,c500=0,c200=0,c100=0,c50=0,c20=0,c10=0;
        sueldo_total_empleados=sueldo_total_empleados+empleados[i].salario;
		
		c1000=calcular_billetes(sueldo,1000);
		c500=calcular_billetes(sueldo%=1000,500);
		c200=calcular_billetes(sueldo%=500,200);
		c100=calcular_billetes(sueldo%=200,100);
		c50=calcular_billetes(sueldo%=100,50);
		c20=calcular_billetes(sueldo%=50,20);
		c10=calcular_billetes(sueldo%=20,10);
		
		printf("Empleado: %s\n", empleados[i].nombre);
        printf("Salario: %i pesos\n", empleados[i].salario);
        printf("Billetes de 1000: %i\n", c1000);
        printf("Billetes de 500: %i\n", c500);
        printf("Billetes de 200: %i\n", c200);
        printf("Billetes de 100: %i\n", c100);
        printf("Billetes de 50: %i\n", c50);
        printf("Billetes de 20: %i\n", c20);
        printf("Billetes de 10: %i\n", c10);
        printf("--------------------------------------\n");
    }
    printf("\nEl monto total a pagar por todos los empleados es %i\n",sueldo_total_empleados);
}


int main(void)
{
	//entrada de datos
	struct Empleado empleados[MAX_EMPLEADOS];
    int numEmpleados = 0;
    char opcion;
	
	 do {
        printf("1. Agregar empleado\n");
        printf("2. Calcular billetes de pago\n");
        printf("3. Salir\n");
        printf("Ingrese la opcion deseada: ");
        scanf(" %c", &opcion);

        switch (opcion) {
            case '1':
                agregarEmpleado(empleados, &numEmpleados);
                break;
            case '2':
                imprimirPagoEmpleados(empleados, numEmpleados);
                break;
            case '3':
                printf("¡Hasta luego!\n");
                break;
            default:
                printf("Opcion invalida. Intente nuevamente.\n");
        }
    } while (opcion != '3');
    return 0;
}