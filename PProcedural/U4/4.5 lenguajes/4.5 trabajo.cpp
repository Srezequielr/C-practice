#include <stdio.h>
#define N 6

void cerear(int xEncuesta[N])
{
    int i;
    for (i = 0; i < N; i++)
    {
        xEncuesta[i] = 0;
    }
}

void cargaEncuesta(int xEncuesta[N])
{
    int bandera;
    printf("Ingrese codigo de lenguaje votado (0 para cancelar) \n");
    printf("1: JavaScript \n2: HTML \n3: CSS \n4: Java \n5: Python \n6: C \n");
    scanf("%d", &bandera);
    while (bandera != 0)
    {
        xEncuesta[bandera - 1]++;
        printf("Ingrese codigo de lenguaje votado (0 para cancelar): ");
        scanf("%d", &bandera);
    }
}

void menosElegidos(int xEncuesta[N], char *xNombres[])
{
    int i;
    printf("Los lenguajes menos elegidos son:");
    for (i = 0; i < N; i++)
    {
        if (xEncuesta[i] < 5)
        {
            printf("- %s\n", xNombres[i]);
        }
    }
}

void masElegido(int xEncuesta[N], char *xNombres[])
{
    int i, max = 0;
    for (i = 0; i < N; i++)
    {
        if (xEncuesta[i] > max)
        {
            max = i;
        }
    }
    printf("El lenguaje mas elegido fue: %s", xNombres[max]);
}

void totalEncuestas(int xEncuestas[N])
{
    int i, cont = 0;
    for (i = 0; i < N; i++)
    {
        cont += xEncuestas[i];
    }
    printf("La cantidad total de encuestados fue de: %d", cont);
}

int contRecursivo(int xEncuesta[N], int &xMenosCincoMil, int xMasNueveMil, int i)
{

    if (i < N)
    {
        if (xEncuesta[i] < 5000)
        {
            xMenosCincoMil++;
        }
        if (xEncuesta[i] > 9000)
        {
            xMasNueveMil++;
        }
        return contRecursivo(xEncuesta, xMenosCincoMil, xMasNueveMil, i + 1);
    }
    return xMasNueveMil;
}

// Si quieres conseguir un buen trabajo vas a necesitar buenas habilidades. Uno de los perfiles profesionales más demandados son los programadores, pero ¿qué lenguaje de programación merece la pena aprender? Aprender a programar te abrirá puertas a otros empleos. Son muchas las empresas las que valoran esta habilidad, pese a que no sea necesario para el puesto, por la agilidad mental que denota. Por todo ello, la comunidad de desarrolladores Stack Overflow llevó a cabo encuestas sobre las tendencias del sector, sobre cuál de los siguientes lenguajes utilizan.  
// Esta es a información compartida en una encuesta. Para procesarla se ingresa por cada encuestado el número de lenguaje elegido. 
// Realizar un programa en C que, utilizando solo funciones recursivas, permita: 
// a) Generar un arreglo que cuente para cada lenguaje, los encuestados que lo eligieron. 
// b) Mostrar el/los lenguajes/s que se eligió por menos de 4000 encuestados. 
// c) Indicar el lenguaje más elegido. (suponer único) 
// d) Mostrar el total de encuestas realizadas. 
// e) Mostrar la cantidad de lenguajes que fueron elegidos por menos de 5000 encuestados y cuantos por más de 9000 encuestados (hacer una función recursiva que devuelva las dos cantidades). 
// f) Realizar el mapa de memoria cuando se invoca a la función construida en el punto d). 


int main()
{
    int encuesta[N], menosCincoMil = 0, masNueveMil = 0, i = 0;
    char *nombres[] = {"JavaScript", "HTML", "CSS", "Java", "Python", "C"};
    cerear(encuesta);
    cargaEncuesta(encuesta);
    menosElegidos(encuesta, nombres);
    masElegido(encuesta, nombres);
    masNueveMil = contRecursivo(encuesta, menosCincoMil, masNueveMil, i);
    printf("%d fueron elegidos por mas de 9000 y %d fueron elegidos por menos de 5000", masNueveMil, menosCincoMil);
}