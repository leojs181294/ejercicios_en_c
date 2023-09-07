#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main(void)
{
	//entrada de datos
	char nombre_empleado [20];
	int sueldo,sueldo_empleado,b1000,b500,b200,b100,b50,b20,b10;
	int c1000=0;
	int c500=0;
	int c200=0;
	int c100=0;
	int c50=0;
	int c20=0;
	int c10=0;

	printf("Ingrese nombre del Empleado: \t");
	scanf("%s",nombre_empleado);

	printf("Ingrese sueldo del empleado %s: \t",nombre_empleado);
	scanf("%i",&sueldo);
	sueldo_empleado=sueldo;
	while (sueldo>=1000)
	{
		sueldo=sueldo - 1000;
		c1000++;
	}
		while (sueldo>=500)
	{
		sueldo=sueldo - 500;
		c500++;
	}
	while (sueldo>=200)
	{
		sueldo=sueldo - 200;
		c200++;
	}
	while (sueldo>=100)
	{
		sueldo=sueldo - 100;
		c100++;
	}
	while (sueldo>=50)
	{
		sueldo=sueldo - 50;
		c50++;
	}
  	while (sueldo>=20)
	{
		sueldo=sueldo - 20;
		c20++;
	}
  	while (sueldo>=10)
	{
		sueldo=sueldo - 10;
		c10++;
	}

  printf("Para el sueldo del Empleado %s, se le pagara el sueldo de %i \n con la cantidad de billetes siguientes: \n billetes de 1000:\t %i \n billetes de 500:\t %i \n billetes de 200:\t %i \n billetes de 100:\t %i \n billetes de 50:\t %i \n billetes de 20:\t %i \n billetes de 10:\t %i \n",nombre_empleado,sueldo_empleado,c1000,c500,c200,c100,c50,c20,c10);
  system("pause");
}
