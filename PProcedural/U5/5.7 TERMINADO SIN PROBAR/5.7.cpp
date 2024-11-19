#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 4

typedef struct
{
    char nya[25];
    char paisOrigen[25];
    int goles;
} Jugador;

struct Nodo
{
    Jugador dato;
    struct Nodo *siguiente;
};

typedef struct Nodo *Puntero;

typedef struct
{
    char pais[20];
    int estadios;
    Puntero jugadores;
} Mundial;

void crearLista(Puntero &xp)
{
    xp = NULL;
}

void insertarJugador(Puntero &xp)
{
    char nombreJug[25];
    Puntero nuevoNodo;
    printf("Ingrese nombre de jugador y apellido del jugador (Cancelar con fin): ");
    gets(nombreJug);
    while (strcmp(nombreJug, "fin") != 0)
    {
        nuevoNodo = (Puntero)malloc(sizeof(struct Nodo));
        strcpy(nuevoNodo->dato.nya, nombreJug);
        printf("Ingrese pais de residencia del jugador: ");
        gets(nuevoNodo->dato.paisOrigen);
        printf("Ingrese cantidad de goles realizados: ");
        scanf("%d", &nuevoNodo->dato.goles);
        while (getchar() != '\n')
            ;

        nuevoNodo->siguiente = xp;
        xp = nuevoNodo;

        printf("Ingrese nombre de jugador y apellido del jugador (Cancelar con fin): ");
        gets(nombreJug);
    }
}

void carga(Mundial mundiales[N])
{
    int anios[] = {2010, 2014, 2018, 2022}, i;
    for (i = 0; i < N; i++)
    {
        printf("-------  Mundial %d  -------\n", anios[i]);
        printf("Ingrese nombre del pais anfitrion: ");
        gets(mundiales[i].pais);
        printf("Ingrese la cantidad de estadios: ");
        scanf("%d", &mundiales[i].estadios);
        while (getchar() != '\n')
            ;
        crearLista(mundiales[i].jugadores);
        insertarJugador(mundiales[i].jugadores);
    }
}

void contArgYGoles(Mundial mundiales[N], int &argentinos, int &cincoGoles)
{
    char pais[20];
    int i = 0;
    Puntero xp;
    printf("Ingrese pais anfitrion de mundial a buscar: ");
    gets(pais);
    while (strcmp(pais, mundiales[i].pais) != 0 && i < 0)
    {
        i++;
    }
    if (i == N)
    {
        printf("El pais buscado no se encontro\n");
    }
    else
    {
        xp = mundiales[i].jugadores;
        while (xp != NULL)
        {
            if (xp->dato.goles > 5)
            {
                cincoGoles++;
            }
            if (strcmp(xp->dato.paisOrigen, "Argentina") == 0)
            {
                argentinos++;
            }
            xp = xp->siguiente;
        }
    }
}

void cargarSubList(Mundial mundiales[N], Puntero &xp)
{
    Puntero nuevoNodo, bandera;
    int i;
    for (i = 0; i < N; i++)
    {
        bandera = mundiales[i].jugadores;
        while (mundiales[i].jugadores != NULL)
        {
            if (mundiales[i].jugadores->dato.goles >= 3)
            {
                nuevoNodo = (Puntero)malloc(sizeof(struct Nodo));

                nuevoNodo->dato = mundiales[i].jugadores->dato;

                nuevoNodo->siguiente = xp;
                xp = nuevoNodo;
            }
            bandera = mundiales[i].jugadores->siguiente;
        }
    }
}

void eliminarJugador(Mundial mundiales[N])
{
    int i;
    Puntero actual, anterior;
    char nombreJugador[20];
    printf("Ingresar un nombre de jugador");
    gets(nombreJugador);

    for (i = 0; i < N; i++)
    {
        if (strcmp(mundiales[i].jugadores->dato.nya, nombreJugador) == 0) // Averigua el primer nodo es el que busca
        {
            actual = mundiales[i].jugadores;
            mundiales[i].jugadores = mundiales[i].jugadores->siguiente;
            free(actual);
        }
        else
        {
            actual = mundiales[i].jugadores;
            anterior = mundiales[i].jugadores;
            while (actual != NULL && strcmp(mundiales[i].jugadores->dato.nya, nombreJugador) == 0)
            {
                anterior = actual;
                actual = actual->siguiente;
            }
            if (actual != NULL)
            {
                anterior->siguiente = actual->siguiente;
                free(actual);
                printf("El jugador se elimino correctamente");
            }
            else
            {
                printf("El jugador no se encontro");
            }
        }
    }
}

// La Federación Internacional de Futbol FIFA tiene el objetivo de recopilar información de los futbolistas de 4 mundiales (años 2022,2018,2014 y 2010). Para ello se está generando una nueva base de datos con información acotada de dichos acontecimientos. De cada mundial se conoce: Nombre del país de realización y cantidad de estadios, de cada futbolista: Nombre y apellido, país de residencia y cantidad de goles registrados.
// Realizar un programa en C que a través de funciones óptimas permita:
// a) Generar un arreglo de lista a través de punteros con los datos de los jugadores para los distintos mundiales. El ingreso de información se encuentra ordenada por año de mundial. Para cada mundial el ingreso de información finaliza con el nombre de país igual a FIN.
// b) Para un mundial ingresado por teclado, realizar una función que devuelva al programa principal la cantidad de jugadores de Argentina y cantidad de jugadores con más de 5 goles realizados. Realizar una función recursiva que devuelva un dato por parámetro y el otro que lo calcule la función.
// c) Eliminar un jugador cuyo nombre y apellido es ingresado por teclado.
// d) Generar una nueva estructura con todos aquellos jugadores que por mundial hayan convertido 3 o más goles.

int main()
{
    Mundial mundiales[N];
    Puntero jugadoresPro;
    int cantArgentinos = 0, cantCincoGoles = 0;
    crearLista(jugadoresPro);
    carga(mundiales);

    // Procesar cantidad de argentinos en mundial elegido y cantidad de jugadores con mas de 5 goles
    contArgYGoles(mundiales, cantArgentinos, cantCincoGoles);
    printf("La cantidad de jugadores argentinos es de %d, y la cantidad de jugadores con mas de 5 goles es de %d", cantArgentinos, cantCincoGoles);
    // --------------------------

    // Carga sublista
    cargarSubList(mundiales, jugadoresPro);
    // --------------------------

    // Eliminar jugador
    eliminarJugador(mundiales);
}