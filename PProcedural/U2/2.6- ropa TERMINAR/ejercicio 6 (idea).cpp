
#include <stdio.h>
#include <string.h>
#define N 3  // numero de productos
#define M 3  // numero de proveedores

// los productos
struct Prod {
    int cod;
    float precio;
    int stock;
};

// los proveedores
struct Prov {
    char nomb[50];
    int num;
    int cantc;
};

// carga productos
void carga1(struct Prod producto[N]) {
    for (int i = 0; i < N; i++) {
        printf("Ingrese el codigo del producto (1 al 50): \n");
        scanf("%d", &producto[i].cod);
        printf("Ingrese el precio del producto: \n");
        scanf("%f", &producto[i].precio);
        printf("Ingrese el stock del producto: \n");
        scanf("%d", &producto[i].stock);
    }
}

// carga proveedores
void carga2(struct Prov proveedor[M]) {
	int i;
    	for (i = 0; i < M; i++) {
        	proveedor[i].cantc = 0; // Inicializar la cantidad de compras
        	printf("Ingrese el nombre del proveedor: \n");
        	scanf("%s", proveedor[i].nomb);
        	printf("Ingrese el numero del proveedor (1000 al 1022): \n");
        	scanf("%d", &proveedor[i].num);
    		}
}

// item b
void compras(struct Prod producto[N], struct Prov proveedor[M]) {
    int i, cuc, numeroProd, numeroProv;
    printf("Ingrese el numero del producto (ingrese -1 para terminar): \n");
    scanf("%d", &numeroProd);
    	while (numeroProd != -1) {
        	printf("Ingrese el numero del proveedor: \n");
        	scanf("%d", &numeroProv);
        	printf("Ingrese cantidad de unidades compradas: \n");
        	scanf("%d", &cuc);
			producto[numeroProd - 1].stock += cuc;
        // encuentra y actualiza el proveedor
        for (i = 0; i < M; i++) {
            if (proveedor[i].num == numeroProv) {
                proveedor[i].cantc++;
            }
        }

        printf("Ingrese el numero del producto (ingrese -1000 para terminar): \n");
        scanf("%d", &numeroProd);
    }
}

// item c
void invertido(struct Prod producto[N]) {
	int i;
	float dineroInvertido;
    	for (i=0; i<N; i++) {
        	dineroInvertido = producto[i].precio * producto[i].stock;
        printf("El dinero invertido en el producto %d es: %.2f\n", producto[i].cod, dineroInvertido);
    }
}

// item d
int masde10(struct Prov proveedor[M], struct Prov proveedores10[M]) {
	int i;
    int contador = 0;
    for (i = 0; i < M; i++) {
        if (proveedor[i].cantc > 10) {
            proveedores10[contador] = proveedor[i];
            contador++;
        }
    }
    return contador;
}

// item e
void ordenar(struct Prov proveedor[], int tam) {
    int i, k, cota;
    struct Prov aux;
    k = 1;
    cota = tam-1;
    	while (k != -1) {
        	k = -1;
        	for (i=0; i<cota; i++) {
            	if (strcmp(proveedor[i].nomb, proveedor[i+1].nomb) > 0) {
                	aux = proveedor[i];
                	proveedor[i] = proveedor[i+1];
                	proveedor[i+1] = aux;
                	k = i;
            		}
        		}
        cota = k;
    }
}

// item f
void mostrar(struct Prov proveedor[], int tam) {
	int i;
    for (i = 0; i < tam; i++) {
        printf("Proveedor: %s, Número: %d, Cantidad de compras: %d\n", proveedor[i].nomb, proveedor[i].num, proveedor[i].cantc);
    }
}

void buscarProveedor(struct Prov proveedores10[], int tam) {
	int i;
	int encontrado = 0; // bandera
    char nombre[50];
    printf("Ingrese el nombre del proveedor a buscar: \n");
    fflush(stdin);
    gets(nombre);
    	for (i=0; i<tam; i++) {
        	if (strcmp(proveedores10[i].nomb, nombre) == 0) {
            	printf("Proveedor encontrado: Número: %d, Cantidad de compras: %d\n", proveedores10[i].num, proveedores10[i].cantc);
            	encontrado = 1; // bandera
        		}
    		}

    if (!encontrado) { // significa encontrado == 0 osea falso
        printf("Proveedor no encontrado.\n");
    }
}

// principal

int main() {
    struct Prod producto[N];
    struct Prov proveedor[M];
    struct Prov proveedores10[M];
    int C;

    carga1(producto);
    carga2(proveedor);
    compras(producto, proveedor);
    invertido(producto);
    C=masde10(proveedor, proveedores10);
    ordenar(proveedores10, C);
    mostrar(proveedores10, C);
    buscarProveedor(proveedores10, C);
	return 0;    
}
