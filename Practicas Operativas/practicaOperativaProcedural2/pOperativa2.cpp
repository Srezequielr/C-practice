#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int codLib;
    char titulo[50];
    char autor[50];
    float precio;
    int cantidad;
} Libro;

struct Nodo
{
    Libro dato;
    struct Nodo *siguiente;
};

typedef struct Nodo *Puntero;

void crearLista(Puntero &xp)
{
    xp = NULL;
}

void insertar(Puntero &xp)
{
    int codigo;
    Puntero nuevoNodo;
    printf("Ingrese codigo de libro <Cancelar con 0>: ");
    scanf("%d", &codigo);
    while (char c = getchar() != '\n')
        ;
    while (codigo != 0)
    {
        nuevoNodo = (Puntero)malloc(sizeof(struct Nodo)); // Le asigno lugar al nodo en memoria
        nuevoNodo->dato.codLib = codigo;
        printf("Ingrese titulo del libro: ");
        gets(nuevoNodo->dato.titulo);
        printf("Ingese autor del libro: ");
        gets(nuevoNodo->dato.autor);
        printf("Ingese precio del libro: ");
        scanf("%f", &nuevoNodo->dato.precio);
        while (char c = getchar() != '\n')
            ;
        printf("Ingrese cantidad de libros: ");
        scanf("%d", &nuevoNodo->dato.cantidad);
        while (char c = getchar() != '\n')
            ;
        nuevoNodo->siguiente = xp;
        xp = nuevoNodo;

        printf("Ingrese codigo de libro <Cancelar con 0>: ");
        scanf("%d", &codigo);
        while (char c = getchar() != '\n')
            ;
    }
}

Puntero busquedaRecursiva(Puntero xp, int codigo)
{
    if (xp != NULL && xp->dato.codLib != codigo)
    {
        return busquedaRecursiva(xp->siguiente, codigo);
    }
    else
    {
        return xp;
    }
}

void mostrarInvertido(Puntero xp)
{
    if (xp != NULL)
    {
        printf("\n");
        printf("\nCodigo de libro: %d", xp->dato.codLib);
        printf("\nTitulo del libro: ");
        puts(xp->dato.titulo);
        printf("Autor del libro: ");
        puts(xp->dato.autor);
        printf("Precio del libro: %.2f", xp->dato.precio);
        printf("\nStock de libros: %d", xp->dato.cantidad);
        mostrarInvertido(xp->siguiente);
    }
}

void eliminarElemento(Puntero &xp)
{
    int codigo;
    Puntero anterior, actual;
    printf("\nIngrese codigo de libro a eliminar: ");
    scanf("%d", &codigo);
    if (xp->dato.codLib == codigo) // Averigua el primer nodo es el que busca
    {
        actual = xp;
        xp = xp->siguiente;
        free(actual);
    }
    else
    {
        actual = xp;
        anterior = xp;
        while (actual != NULL && actual->dato.codLib != codigo)
        {
            anterior = actual;
            actual = actual->siguiente;
        }
        if (actual != NULL)
        {
            anterior->siguiente = actual->siguiente;
            free(actual);
            printf("El libro se elimino correctamente");
        }
        else
        {
            printf("El libro no se encontro");
        }
    }
}

float calcTotal(Puntero cabeza)
{
    float total = 0;
    while (cabeza != NULL)
    {
        total += cabeza->dato.precio * cabeza->dato.cantidad;
        cabeza = cabeza->siguiente;
    }
    return total;
}

// 1. Creación de una lista enlazada: Crea una función que reciba una cabeza de lista y genere una lista enlazada en la cual registre información de libros: código de libro, titulo, autor, precio y cantidad.
// 2. Búsqueda recursiva de un elemento: Crea una función recursiva que reciba un código de libro y retorne el autor, titulo y precio del mismo si está en la lista enlazada. Mostrar el resultado en el principal.
// 3. Impresión recursiva de la lista: Crea una función recursiva que imprima todos los elementos de la lista enlazada en orden inverso al ingresado.
// 4. Eliminación de un elemento por valor: Crea una función que, dado un código de libro elimine el nodo que contiene dicho valor en la lista enlazada.
// 5. Procesamiento de la lista: Crea una función que calcule el importe total que hay en libros. Mostrar el resultado en el principal.

int main()
{
    Puntero cabeza, libroBuscado;
    crearLista(cabeza);
    insertar(cabeza);
    int codigo;
    float total;
    printf("Ingrese codigo de libro para buscar: ");
    scanf("%d", &codigo);
    libroBuscado = busquedaRecursiva(cabeza, codigo);
    printf("------ Resultado de busqueda ------\n");
    if (libroBuscado == NULL)
    {
        printf("\nEl libro no se ha encontrado");
    }
    else
    {
        printf("Autor del libro: ");
        puts(libroBuscado->dato.autor);
        printf("Titulo del libro: ");
        puts(libroBuscado->dato.titulo);
        printf("Precio del libro: %.2f", libroBuscado->dato.precio);
    }
    eliminarElemento(cabeza);

    printf("\n------ Lista de libros invertida ------ ");
    mostrarInvertido(cabeza);
    printf("\n------------------ ");
    total = calcTotal(cabeza);
    printf("\nEl importe total en libros es de: %.2f", total);
}
