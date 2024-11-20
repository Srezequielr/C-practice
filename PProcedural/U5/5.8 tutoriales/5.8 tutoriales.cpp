#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 5

struct Nodo
{
    int dato;
    struct Nodo *siguiente;
};

typedef struct Nodo *Puntero;

typedef struct
{
    char titulo[20];
    Puntero inscriptos;
} Tutorial;

void crearLista(Puntero &xp)
{
    xp = NULL;
}

void cargaTutoriales(Tutorial tutoriales[N])
{
    int i;

    for (i = 0; i < N; i++)
    {
        printf("Ingrese el nombre del tutorial N%d: ", i + 1);
        gets(tutoriales[i].titulo);
        crearLista(tutoriales[i].inscriptos);
    }
}

void insertarInscripto(Puntero &xp)
{
    Puntero nuevoNodo;

    nuevoNodo = (Puntero)malloc(sizeof(struct Nodo));

    printf("Increse documento del inscripto: ");
    scanf("%d", &nuevoNodo->dato);

    nuevoNodo->siguiente = xp;
    xp = nuevoNodo;
}

void agregarInscripto(Tutorial tutoriales[N])
{
    int i;
    printf("------- Incripcion -------\n");
    printf("Ingrese numero del tutorial <0 para cancelar>: ");
    scanf("%d", &i);

    while (i != 0)
    {
        insertarInscripto(tutoriales[i - 1].inscriptos);
        printf("Ingrese numero del tutorial <0 para cancelar>: ");
        scanf("%d", &i);
    }
}

void eliminarNodo(Puntero &xp, int dni)
{
    Puntero actual, anterior;

    if (xp->dato == dni)
    {
        xp = xp->siguiente;
        actual = xp;
        free(xp);
    }
    actual = xp;
    anterior = xp;
    while (actual != NULL && actual->dato != dni)
    {
        anterior = actual;
        actual = xp->siguiente;
    }
    if (actual == NULL)
    {
        printf("No se encontro el inscripto\n");
    }
    else
    {
        anterior->siguiente = actual->siguiente;
        free(actual);
        printf("El elemento de la lista se elimino correctamente\n");
    }
}

void eliminarInscripto(Tutorial tutoriales[N])
{
    int dni, i;
    printf("Ingrese numero de tutorial: ");
    scanf("%d", &i);
    printf("Ingrese DNI de inscripto para eliminar: ");
    scanf("%d", &dni);
    eliminarNodo(tutoriales[i - 1].inscriptos, dni);
}

int contRecursivo(Puntero xp, int cont)
{
    if (xp != NULL)
    {
        cont++;
        xp = xp->siguiente;
        return contRecursivo(xp, cont);
    }
    else
    {
        return cont;
    }
}

void mostrarInscriptos(Tutorial tutoriales[N])
{
    int i, inscriptos = 0;
    printf("Ingresar numero de tutorial: ");
    scanf("%d", &i);
    inscriptos = contRecursivo(tutoriales[i].inscriptos, inscriptos);
    printf("La sala ");
    puts(tutoriales[i].titulo);
    printf(" tiene %d inscriptos\n", inscriptos);
}

Puntero buscarEnLista(Puntero xp, int dni)
{

    if (xp != NULL && xp->dato != dni)
    {
        xp = xp->siguiente;
        return buscarEnLista(xp, dni);
    }
    else
    {
        return xp;
    }
}

void buscarPersona(Tutorial tutoriales[N])
{
    int dni, i;
    Puntero esta;
    printf("Ingrese DNI: ");
    scanf("%d", &dni);

    for (i = 0; i < N; i++)
    {
        esta = buscarEnLista(tutoriales[i].inscriptos, dni);
        if (esta != NULL)
        {
            printf("Esta incripto al tutorial %d: ", i + 1);
            puts(tutoriales[i].titulo);
        }
    }
}

// La Facultad de Ciencias Exactas organizó el Congreso de Informática, y necesita administrar la información relativa a
// los 10 tutoriales que se proponen en dicho evento.
// Realizar un programa, que a través de un menú de opciones permita:
// a) Ingresar los datos correspondientes a cada tutorial: número de tutorial (1-10) y título.
// b) Registrar las inscripciones, ingresando el DNI del inscripto y el número de tutorial al que desea asistir.
// c) Eliminar alguna inscripción, en cuyo caso se ingresarán los mismos datos que en el ítem anterior.
// d) Dado el número de un tutorial, mostrar su título y la cantidad de inscriptos en él.
// e) Dado el DNI de una persona, informar el/los tutoriales (número y título) en los que se inscribió.

int main()
{
    Tutorial tutoriales[N];
    cargaTutoriales(tutoriales);
    agregarInscripto(tutoriales);
    eliminarInscripto(tutoriales);
    mostrarInscriptos(tutoriales);
    buscarPersona(tutoriales);
}