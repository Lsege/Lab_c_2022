#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

typedef struct{
    char ciudad[40];
    char tipoBasura[40];
    int cantidad;
} RegSal;

int main(){

    
    FILE * ptr;
    ptr=fopen("archivoBasura.csv", "w+");
    
    if(ptr==NULL){
    	printf("Error en la generacion del archivo");
    	return 1;
    }
    
	char Basura[40];
    int cantidadTBasura = 0;
    int i;

    printf("Ingrese la cantidad de tipos de basura que desea registrar \n");
    scanf("%d", &cantidadTBasura);
    
	char tipoBasura[cantidadTBasura][40];
	
    for (i=0; i<cantidadTBasura; i++){
        printf("Escriba el tipo de basura que desea registrar \n");
        scanf("%s", &Basura);
		strcpy(tipoBasura[i], Basura);
    }
	
	int cantidadCiudades = 0;
    printf("Ingrese la cantidad de ciudades que desea registrar \n");
    scanf("%d", &cantidadCiudades);
    
	int totalRegistros = cantidadCiudades * cantidadTBasura;
	RegSal regsal[totalRegistros];

	int j;
    char Ciudad[100];
    int k;
    int cantidadBasura;
    int contador = 0;
	for(k=0; k<cantidadCiudades; k++){
			
	    printf("Ingrese la ciudad de la cual desea registrar la basura: \n");
	    printf("(Si tu ciudad contiene varias palabras, por favor separalas con guion) \n");
		scanf("%s", &Ciudad);
	    	
	    for(j=0; j<cantidadTBasura; j++){
	    	contador++;
	    	printf("Ingrese la cantidad de ");
	    	printf("%s", tipoBasura[j]);
	    	printf(" recolectado en la ciudad de ");
	    	printf("%s", Ciudad);
	    	printf("\n");
	    	scanf("%d", &cantidadBasura);
			strcpy(regsal[contador].ciudad, Ciudad);
			strcpy(regsal[contador].tipoBasura, tipoBasura[j]);
			regsal[contador].cantidad = cantidadBasura;
			
			fprintf(ptr,
					"%s, %s, %d \n", 
					regsal[contador].ciudad,
					regsal[contador].tipoBasura,
					regsal[contador].cantidad);
			
			if (ferror(ptr)){
				printf("Error escribiendo el archivo \n");
				return 1;
			}
	    }
	}

	printf("TERMINO");
    getch();
    fclose(ptr);
    return 0;
}
