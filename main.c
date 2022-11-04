#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//fopen: funcion para abrir archivos de texto
//feof: funcion para determinar el final de un archivo de texto
//fscanf: lee datos con formato en secuencia
//fclose: cierra una secuencia
//calloc: Asigna una matriz en la memoria con elementos que se inicializan en 0, usado en el arreglo dinamico
//ftell: obtiene la posición actual del indicador de posición de archivo del flujo al cual señala la secuencia


int main(int argc, char *argv[]) {

	FILE *edades=fopen("setdatosedades.txt","rb"); //abriendo el archivo de texto con las edades
	int i=0;
	int n=0;
	int *e;
	int j=0;
	int longitud=0;
	double tiempo_total=0.0;
	
	clock_t principio=clock();
	
	while (feof(edades)==0){ //ciclo contar los caracteres del texto
		fscanf(edades, "%d", &n);
		j++;

	}
	rewind(edades);
    e=(int *) calloc(j,sizeof(int));
	while (feof(edades)==0){ //ciclo para guardar valores en el arreglo
		fscanf(edades, "%d", &n);
		i++;
		e[i]=n;
	}
	//Ordenamiento burbuja
	int a=2;
	int aux=0;
	while(j!=a+1){
		for(i=0;i<=j-a;i++){
			if(e[i]>e[i+1]){
			aux=e[i];
			e[i]=e[i+1];
			e[i+1]=aux;	
			}
		}
		a++;
	}
	printf("Ordenamiento burbuja:\n");
	for(i=0;i<j;i++){
	printf("%i \n", e[i]);
	}
	
	clock_t final=clock();
	
	tiempo_total+=(double)(final-principio)/CLOCKS_PER_SEC;
	
	printf("El tiempo de ejecucion fue: %f\n",tiempo_total);
	
	system("pause");
	
	//Ordenamiento seleccion
	
	tiempo_total=0.0;
	
	principio=clock();
	
	int aux1=0;
	int aux2=0;
	int k=0;
	for(i=0;i<j;i++){
		aux1=e[i];
		for(k=i+1;k<n;k++){
			if(aux1>e[k]){
			    aux1=e[k];
				aux2=k;
			}
			else{
			aux2=i;
			}
			e[aux2]=e[i];
			e[i]=aux1;
		}
	}
    printf("Ordenamiento seleccion:\n");
	for(i=0;i<j;i++){
	printf("%d \n", e[i]);
	}
	
	final=clock();
	
	tiempo_total+=(double)(final-principio)/CLOCKS_PER_SEC;
	
	printf("El tiempo de ejecucion fue: %f\n",tiempo_total);
	
	system("pause");
	
	//Ordenamiento inserción
	
	tiempo_total=0.0;
	
	principio=clock();
	
	i=0;
	int y=0;
	aux=0;
	k=0;
	for(i=0;i<j;i++){
		for(y=1;y<j;y++){
			if(e[k]>e[y]){
				aux=e[k];
				e[k]=e[y];
				e[y]=aux;;
				if(e[k]<e[k-1]){
				y--;
				}
			}	
		}
		k++;	
	}
	
	printf("Ordenamiento insercion \n");
	
	for(y=0;y<j;y++){
		printf("%d\n",e[y]);
	}
	
	final=clock();
	
	tiempo_total+=(double)(final-principio)/CLOCKS_PER_SEC;
	
	printf("El tiempo de ejecucion fue: %f\n",tiempo_total);
	
	system("pause");
	
	fclose(edades);
	
	return 0;
}
