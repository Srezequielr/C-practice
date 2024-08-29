#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#define N 50

void carga(int arre[N]){
	int i;
		for(i=0;i<N;i++){
			arre[i]= rand()% 50-25;
		}
	}

void mostrar(int arre[N]){
	int i;
		for(i=0; i<N;i++){
			printf(" | %d",arre[i]);
		}
		printf("\n");
	}

int may0(int arre[N]){
		int i, contador=0;
		for(int i=0; i<N;i++){
			if(arre[i]>0){
				contador++;
			}
		}
		return(contador);
	}

int men0(int arre[N]){
		int i, contador=0;
		for(int i=0; i<N;i++){
			if(arre[i]<0){
				contador++;
			}
		}
		return(contador);
	}

int sumaI(int arre[N]){
		int i, inpar=0;
		for(i=1; i<N; i+=2){
				inpar+=arre[i];
		}
		return(inpar);
	}

int sumaP(int arre[N]){
	int i, par=0;
	for(int i=0;i<N;i+=2){
				par+=arre[i];
	}
	return(par);
}

int buscar(int arre[N], int numero){
	for(int i=0; i<N;i++){
			if(arre[i] == numero){
				printf("Se encontro el nro %d en la posicion nro %d\n", numero, i+1);
			}
			if(arre[i] != numero){
				printf("No se encontro el nro %d en la posicion nro %d\n", numero, i+1);
			}
		}
}

int main(){
	srand(time(NULL));
	int arre[N], mayores, menores, sumaInpar, sumaPar, numero;
	carga(arre);
	mostrar(arre);
	mayores=may0(arre);
	menores=men0(arre);
	if(mayores >= menores){
		printf("Hay mas numeros mayores o iguales a 0\n");
	}
	else{
		printf("Hay mas numeros menores o iguales a 0\n");
	}
	sumaInpar=sumaI(arre);
	sumaPar=sumaP(arre);
	printf("Suma de componentes en posiciones impares: %d\n",sumaInpar);
	printf("Suma de componentes en posiciones pares: %d\n",sumaPar);

	printf("Ingrese el numero a buscar\n");
	scanf("%d",&numero);
	buscar(arre,numero);


}
