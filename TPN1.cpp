/*- ISBN (International Standard Book Number): est�ndar de 13 d�gitos.

Prefijo Internacional: Actualmente sólo se usan 978, para equiparar a los viejos ISBN de 10 dígitos;
 o 979 para los nuevos ISBN que ya no son compatibles con los ISBN de 10 dígitos.
 
Identificador de grupo o Grupo de registro: Identifica al país, la región geográfica o 
el área lingüística que participa en el sistema ISBN. 
Este elemento debe tener entre 1 y 5 dígitos.

Prefijo de editor o de agente editor: Identifica a un determinado editor o a un sello editorial. Debe tener de 1 a 7 dígitos.

Identificador de t�tulo o publbicaci�n: Identifica una determinada edición y formato de un determinado título. Debe tener  de 1 a 6 dígitos.

D�gito de comprobaci�n de edici�n: e obtiene a partir de los 12 dígitos anteriores. 
Se suman todos los dígitos, previa multiplicación por 3 de los dígitos cuya posición es par.
Después se calcula R como el módulo 10 de esa suma. 
Por último se toma como dígito de control el número 10-R, si R es distinto de cero y el propio R si es cero.
 
- T�tulo de la obra: Secuencia no vac�a de letras, d�gitos decimales, signos de puntuaci�n. M�xima longitud 40.

- Apellido y Nombre del Autor principal: Debe contener al menos un Apellido y un Nombre. 
Cada uno debe ser una secuencia de letras que empiece con may�sculas. 
Puede haber abreviaturas: may�scula seguida de min�sculas y termina en punto. 
Tambi�n siglas: may�scula y punto. Se separan con espacio en blanco. M�xima longitud 30.

- Nombre de la Editorial: Idem que t�tulo de la obra.

- Fecha de Publicaci�n: formato dd/mm/aaaa

- Precio: n�mero real con formato decimal, con punto para separar parte entera de la fraccionaria. 
Con dos d�gitos decimales. Desde 0.01 a 99999.99

- Cantidad: n�mero entero sin signo. Desde 1 a 9999

Validaci�n de datos:
Finalmente, dise�ar e implementar un programa que realice el proceso de ALTA de estos datos, 
con la validaci�n de cada campo a medida que son introducidos y 
posteriormente los almacene en un archivo binario de registros. 
Considerar como campo clave el ISBN. 

Impedir el ingreso de ISBN repetidos.
*/

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct registro
{
	int prefijoInternacional;
	int identificadorGrupo;
	int prefijoEditor;
	int identificadorTitulo;
	int digitoComprobacion;
	char tituloObra[40];
	char apellidoNombre[30];
	char nombreEditorial[40]; //usar funcion de validar la de titulo de la obra
	FECHA fecha; 
	float precio;
	int cantidad;
}

struct FECHA
{
	int dia,mes,anio;
}

bool validarPrefijoInternacional(registro ISBN)
{
	if(ISBN.prefijoInternacional== 978 || ISBN.prefijoInternacional== 979)return true;
	else return false;
}

main()
{
	registro ISBN;
	
	bool valido = false;
	FILE*arch;
	
	arch = fopen("isbn.dat","a+b");
	if(arch==NULL)
	{
		fclose(arch);
		arch = fopen("encomienda.dat","w+b");
		if(arch==NULL)
		{
			printf("Error no se pudo abrir/crear el archivo, saliendo del programa...");
			getch();
			exit (1);
		}
	}
	
	printf("Ingreso de ISBN\n");
	do
	{
		printf("Ingrese Prefijo Internacional 978 viejos ISBN o 979 para los nuevos ISBN\n");
		scanf("%d",&ISBN.prefijoInternacional);
		valido=validarPrefijoInternacional(ISBN);
		if (valido == false)printf("El prefijo ingresado no es valido ingrese uno correcto...\n\n");
		
	}while(valido == false);
	
	
	
	
	
}

