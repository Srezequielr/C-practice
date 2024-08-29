
#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>

//<> porque esta tecla no me funca
//for (i; i<N; i++) para copiar y pegar directamente

#define F 2 // Numero de Filas
#define C 2 //NUmero de columnas

void carga (int arr[F][C]){
	int f, c;
	
for(f=0; f<F; f++){
	
	for(c=0; c<C; c++){
		printf("ingrese el valor de la columna\n", c+1);
		scanf("%d", &arr[f][c]);
	}
  }
}
	


void sum(int arr[F][C]){
    int f, c, sum;

    for (f = 0; f < F; f++) {
        sum = 0;
        for (c = 0; c < C; c++) {
            printf("%d\t", arr[f][c]);
            sum += arr[f][c];
        }
         printf(" | Suma de la fila %d: %d\n", f + 1, sum);
    }
    return;
}

float promedio(int arr[F][C]){
	int f, sum = 0;
	for (f = 0; f < F; f++){
		sum += arr[f][2];
	}
	
	return sum/F;
}

int mayoresA100(int arr[F][C]){
	int f, c, count = 0;
	for (f = 0; f < F; f++){
		for (c = 0; c < C; c++){
			if((arr[f][c]>100)){
				count++;
			}
		}
	}
	return count;
}

int main(){
	int arr[F][C];
	int s, c;
	float p;
	
	carga(arr);
	sum(arr);
	
	p = promedio(arr);
	printf("El promedio de las terceras columnas es: %.2f \n", p);
	
	c = mayoresA100(arr);
	printf("La cantidad de numeros mayores a 100 que se ingresaron es: %d \n", c);
	
	return 0;
	
}

