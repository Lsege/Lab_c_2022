#include <stdio.h>
#include <string.h>

typedef struct{
    char ciudad[40];
    char tipoBasura[40];
    int cantidad;
} RegEn;

int main(){
	FILE *ptr;
	ptr = fopen("archivoBasura.csv", "r");
	
	if (ptr == NULL){
		printf("Error abriendo el archivo \n");
		return 1;
	}
	
	RegEn RBasura[100]; // Acá podemos guardar como máximo 100 registros solamente
	int read = 0; // Esto es la cantidad de campos.
	int registros = 0; //Esta es la cantidad de Registros. 
	
	do {
		read = fscanf(ptr,
					"%40[^,], %40[^,], %d \n", // %49[^,] avanza el string y lo almacena hasta que cuenta 49 caracteres o se encuentra una coma. 
					RBasura[registros].ciudad,
					RBasura[registros].tipoBasura,
					&RBasura[registros].cantidad
					);
					
		if(read == 3) registros++; // Este asigna cuantos campos tenemos. 
		
		if(read!=3 && !feof(ptr)){
			printf("Formato de archivo incorrecto.\n");
			return 1;
		} 
		if(ferror(ptr)){
			printf("Error leyendo el archivo.\n");
			return 1;
		}
		
		
	}while (!feof(ptr));
	fclose(ptr);
	
	//ACA VAMOS A ARRANCAR A CONTAR LA CANTIDAD DE CIUDADES QUE TENEMOS
	char city[40] = "";
	int contadorCiudades = 0;
	int i, result;
	
	for(i=0; i<registros; i++){
		result = strcmp(city, RBasura[i].ciudad);
		if (result != 0){
			strcpy(city, RBasura[i].ciudad);
			contadorCiudades++;
		}
	}
	printf("\n\n LA CANTIDAD DE CIUDADES ES %d \n\n", contadorCiudades);
	
	// ACA VAMOS A CONTAR LA CANTIDAD DE BASURA QUE TENEMOS
	char tipoB[40] = "";
	int contadorBasura = 0;
	strcpy(city, RBasura[0].ciudad);
	printf("              ");
	for(i=0; i<registros; i++){
		result = strcmp(city, RBasura[i].ciudad);
		if (result != 0){
			break; //Queremos que salga del  loop una vez finalizado de contabilizar los tipos de basura
		}
		printf(" %s |", RBasura[i].tipoBasura);
		contadorBasura++;
	}
	//printf("\n\n LA CANTIDAD DE BASURA ES %d \n\n", contadorBasura);
	

	//ACA VAMOS A GENERAR UN ARREGLO DE DOS DIMENSIONES, CON TODAS LAS CANTIDADES
	int matriz[contadorCiudades][contadorBasura];
	int ICity = 0;
	int IBas = 0;
	strcpy(city, RBasura[0].ciudad);
	printf("\n %s | ", RBasura[0].ciudad);
	for(i=0; i<registros; i++){
		result = strcmp(city, RBasura[i].ciudad);
		if (result != 0){
			printf("\n%s | ", RBasura[i].ciudad);
			strcpy(city, RBasura[i].ciudad);
			IBas = 0;
			ICity++;
		}
		matriz[ICity][IBas] = RBasura[i].cantidad;
		printf("    %d", matriz[ICity][IBas]);
		printf("|");
		IBas++;
	}
	
	
	
	
	return 0;
}
