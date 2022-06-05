/*- ISBN (International Standard Book Number): estándar de 13 dígitos.

Prefijo Internacional: Actualmente sÃ³lo se usan 978, para equiparar a los viejos ISBN de 10 dÃ­gitos;
 o 979 para los nuevos ISBN que ya no son compatibles con los ISBN de 10 dÃ­gitos.
 
Identificador de grupo o Grupo de registro: Identifica al paÃ­s, la regiÃ³n geogrÃ¡fica o 
el Ã¡rea lingÃ¼Ã­stica que participa en el sistema ISBN. 
Este elemento debe tener entre 1 y 5 dÃ­gitos.

Prefijo de editor o de agente editor: Identifica a un determinado editor o a un sello editorial. Debe tener de 1 a 7 dÃ­gitos.

Identificador de título o publbicación: Identifica una determinada ediciÃ³n y formato de un determinado tÃ­tulo. Debe tener  de 1 a 6 dÃ­gitos.

Dígito de comprobación de edición: e obtiene a partir de los 12 dÃ­gitos anteriores. 
Se suman todos los dÃ­gitos, previa multiplicaciÃ³n por 3 de los dÃ­gitos cuya posiciÃ³n es par.
DespuÃ©s se calcula R como el mÃ³dulo 10 de esa suma. 
Por Ãºltimo se toma como dÃ­gito de control el nÃºmero 10-R, si R es distinto de cero y el propio R si es cero.
 
- Título de la obra: Secuencia no vacía de letras, dígitos decimales, signos de puntuación. Máxima longitud 40.

- Apellido y Nombre del Autor principal: Debe contener al menos un Apellido y un Nombre. 
Cada uno debe ser una secuencia de letras que empiece con mayúsculas. 
Puede haber abreviaturas: mayúscula seguida de minúsculas y termina en punto. 
También siglas: mayúscula y punto. Se separan con espacio en blanco. Máxima longitud 30.

- Nombre de la Editorial: Idem que título de la obra.

- Fecha de Publicación: formato dd/mm/aaaa

- Precio: número real con formato decimal, con punto para separar parte entera de la fraccionaria. 
Con dos dígitos decimales. Desde 0.01 a 99999.99

- Cantidad: número entero sin signo. Desde 1 a 9999

Validación de datos:
Finalmente, diseñar e implementar un programa que realice el proceso de ALTA de estos datos, 
con la validación de cada campo a medida que son introducidos y 
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

