#include <stdio.h>
#include <stdlib.h>

struct Nodo
{
    int numero;
    struct Nodo *siguiente;
};

typedef struct Nodo *Puntero;

void crearLista(Puntero &xp)
{
    xp = NULL;
}

void insertar(Puntero &xp)
{
    Puntero nuevoNodo, actual, anterior;
    int num;
    printf("Ingresar un numero <0 para cancelar>: ");
    scanf("%d", &num);
    while (num != 0)
    {
        nuevoNodo = (Puntero)malloc(sizeof(struct Nodo));
        nuevoNodo->numero = num;
        if (xp == NULL) // Verifica si no hay nodos en la lista
        {
            xp = nuevoNodo;
            nuevoNodo->siguiente = NULL;
        }
        else
        {
            if (xp->numero == nuevoNodo->numero)
            {
                nuevoNodo->siguiente = xp;
                xp = nuevoNodo;
            }
            else
            {
                actual = xp;
                anterior = xp;
                while ((actual != NULL) && (nuevoNodo->numero > actual->numero))
                {
                    anterior = actual;
                    actual = actual->siguiente;
                }
                anterior->siguiente = nuevoNodo;
                nuevoNodo->siguiente = actual;
            }
            printf("El elemento fue correctamente insertado \n");
            printf("Ingresar un numero <0 para cancelar>: ");
            scanf("%d", &num);
        }
    }
}

void ultimoPar(Puntero xp)
{
    int esPar;
    while (xp != NULL)
    {
        if (xp->numero % 2 == 0)
        {
            esPar = 1;
        }
        else
        {
            esPar = 0;
        }
        xp = xp->siguiente;
    }

    if (esPar)
    {
        printf("El ultimo nodo es par");
    }
    else
    {
        printf("El ultimo nodo es impar");
    }
}

void mostrarInvertido(Puntero xp)
{
    if (xp != NULL)
    {
        printf("Numero %d\n", xp->numero);
        mostrarInvertido(xp->siguiente);
    }
}

// Realizar un programa que mediante funciones recursivas permita:
// a) Generar una lista enlazada de números enteros positivos, ordenada en forma ascendente. Validar la entrada.
// b) Escribir un mensaje indicando si el número del último nodo de la lista es par.
// c) Mostrar la lista generada en forma inversa.
// d) Ingresar un número y decir en qué lugar se encuentra.

int main()
{
    Puntero cabeza;
    crearLista(cabeza);
    insertar(cabeza);
    ultimoPar(cabeza);
}