#include <stdio.h>
#include <string.h>

typedef struct{
    char ciudad[40];
    char tipoBasura[40];
    int cantidad;
} RegEn; 

int main(){
	// Primero abrimos el archivo
	FILE *ptr;
	ptr = fopen("archivoBasura.csv", "r");
	
	if (ptr == NULL){
		printf("Error abriendo el archivo \n");
		return 1;
	}
	
	RegEn RegistroBasura[100]; // Declaramos el archivo de memoria interna RegistroBasura, donde podemos guardar como maximo 100 registros
	int CantidadCampos = 0; // Esto es la cantidad de campos.
	int Registros = 0; //Esta es la cantidad de Registros. 
	
	do {
		CantidadCampos = fscanf(ptr,
					"%40[^,], %40[^,], %d \n", // %49[^,] avanza el string y lo almacena hasta que cuenta 49 caracteres o se encuentra una coma. 
					RegistroBasura[Registros].ciudad,
					RegistroBasura[Registros].tipoBasura,
					&RegistroBasura[Registros].cantidad
					);
					
		if(CantidadCampos == 3) Registros++; // Este asigna cuantos campos tenemos. 
		
		if(CantidadCampos!=3 && !feof(ptr)){
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
	// Y VAMOS A GENERAR UN ARREGLO CON TODAS LAS CIUDADES
	char NombreCiudades[50][50];
	char city[40] = "";
	int contadorCiudades = 0;
	int i,j, result;
	
	for(i=0; i<Registros; i++){
		result = strcmp(city, RegistroBasura[i].ciudad);
		if (result != 0){
			strcpy(city, RegistroBasura[i].ciudad);
			strcpy(NombreCiudades[contadorCiudades], city);
			contadorCiudades++;
		}
	}
	//printf("\n\n LA CANTIDAD DE CIUDADES ES %d \n\n", contadorCiudades);

	//ACA VAMOS A CONTAR LA CANTIDAD DE TIPOS DE BASURA DISTINTA QUE TENEMOS
	//Y VAMOS A GENERAR UN ARREGLO CON TODOS LOS TIPOS DE BASURA
	char TiposDeBasura[50][50]; // Generamos un arreglo de strings
	int contadorBasura = 0;
	strcpy(city, RegistroBasura[0].ciudad);
	for(i=0; i<Registros; i++){
		result = strcmp(city, RegistroBasura[i].ciudad);
		strcpy(TiposDeBasura[i], RegistroBasura[i].tipoBasura);
		if (result != 0){
			break; //Queremos que salga del  loop una vez finalizado de contabilizar los tipos de basura
		}
		contadorBasura++;
	}
	//printf("\n\n LA CANTIDAD DE CIUDADES ES %d \n\n", contadorBasura);

	

	
	//ACA VAMOS A GENERAR UN ARREGLO DE DOS DIMENSIONES, CON TODAS LAS CANTIDADES
	int matriz[contadorCiudades][contadorBasura];
	int ICity = 0;
	int IBas = 0;
	strcpy(city, RegistroBasura[0].ciudad);
	printf("\n%s | ", RegistroBasura[0].ciudad);
	for(i=0; i<Registros; i++){
		result = strcmp(city, RegistroBasura[i].ciudad);
		if (result != 0){
			printf("\n%s | ", RegistroBasura[i].ciudad);
			strcpy(city, RegistroBasura[i].ciudad);
			IBas = 0;
			ICity++;
		}
		matriz[ICity][IBas] = RegistroBasura[i].cantidad;
		printf("    %d", matriz[ICity][IBas]);
		printf("|");
		IBas++;
	}
	printf("\n\n");
	
	int totalPorCiudad[contadorCiudades];
	int totalPorTipo[contadorBasura];
	int acumulador = 0;
	int mayorCiudad, indMayorC, indMayorT;
	int mayorTotal = 0;
	for(i=0; i<contadorCiudades; i++){
		mayorCiudad = 0;
		for(j=0; j<contadorBasura; j++){
			acumulador =  acumulador + matriz[i][j];
			if (matriz[i][j]>mayorCiudad){
				mayorCiudad = matriz[i][j];
				indMayorC = i;
				
			}
		}
		if(mayorCiudad > mayorTotal){
			mayorTotal = mayorCiudad;
			indMayorT = indMayorC;
		}
		
		totalPorCiudad[i] = acumulador;
		printf("El total por ciudad es:%d\n", totalPorCiudad[i]);
		acumulador = 0;
	}
	printf("EL MAS GRANDE ES: %d", mayorTotal);


	
	return 0;
}


