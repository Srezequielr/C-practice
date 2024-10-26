#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int numPlan;
    int dni;
    char nombre[20];
    char apellido[20];
    int cantCuotas = 0;
} Adjudicatario;

struct Nodo
{
    Adjudicatario dato;
    struct Nodo *siguiente;
};

typedef struct Nodo *Puntero;

void crearLista(Puntero &xp)
{
    xp = NULL;
}

void 
insertar(Puntero &xp)
{
    int plan;
    Puntero nuevoNodo;
    int dato;
    printf("Ingrese numero de plan < Cancelar con 0 >: ");
    scanf("%d", &dato);
    while (dato != 0)
    {
        nuevoNodo = (Puntero)malloc(sizeof(struct Nodo));
        nuevoNodo->dato.numPlan = dato;
        printf("Ingrese DNI: ");
        scanf("%d", &nuevoNodo->dato.dni);
        printf("Ingrese nombre: ");
        scanf("%s", &nuevoNodo->dato.nombre);
        printf("Ingrese apellido: ");
        scanf("%s", &nuevoNodo->dato.apellido);
        printf("Ingrese cantidad de cuotas pagadas: ");
        scanf("%d", &nuevoNodo->dato.cantCuotas);

        nuevoNodo->siguiente = xp;
        xp = nuevoNodo;

        printf("Ingrese numero de plan < Cancelar con 0 >: ");
        scanf("%d", &dato);
    }
}

void cargaCuotas(Puntero xp, Puntero &xd)
{
    Puntero nuevoNodo;
    while (xp != NULL)
    {
        if (xp->dato.cantCuotas > 30)
        {
            nuevoNodo = (Puntero)malloc(sizeof(struct Nodo));

            nuevoNodo->dato.numPlan = xp->dato.numPlan;
            strcpy(nuevoNodo->dato.nombre, xp->dato.nombre);
            strcpy(nuevoNodo->dato.apellido, xp->dato.apellido);
            nuevoNodo->dato.dni = xp->dato.dni;
            nuevoNodo->dato.cantCuotas = xp->dato.cantCuotas;

            nuevoNodo->siguiente = xd;
            xd = nuevoNodo;
        }
    }
}

void mostrar(Puntero xp)
{
    while (xp != NULL)
    {
        printf("-----------------------------");
        printf("Numero de documento: %d\n", xp->dato.dni);
        printf("Nombre y apellido: %s %s\n", xp->dato.nombre, xp->dato.apellido);
        printf("Cantidad de cuotas pagadas: %d\n", xp->dato.cantCuotas);
        printf("Numero de plan: %d\n", xp->dato.numPlan);
        printf("-----------------------------");

        xp = xp->siguiente;
    }
}

int main()
{
    Puntero cabezaAdj, cabezaAdjCuota;
    int selec;
    crearLista(cabezaAdj);
    crearLista(cabezaAdjCuota);
    insertar(cabezaAdj);
    printf("Que Lista desea mostrar (1 o 2): ");
    scanf("%d", &selec);
    if (selec == 1)
    {
        mostrar(cabezaAdj);
    }
    else
    {
        mostrar(cabezaAdjCuota);
    }

    return 0;
}
