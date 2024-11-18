#include <stdio.h>
#include <string.h>

void esPalindromo(char cadena[10], char palindromo[10], int i, int j, int largo)
{
    if (i < largo)
    {
        palindromo[j] = cadena[i];
        esPalindromo(cadena, palindromo, i + 1, j - 1, largo);
    }
    else
    {
        palindromo[largo] = '\0'; // Terminar la cadena con '\0'
    }
}

// Ejercicio 8
// Implemente una función recursiva que nos diga si una cadena es palíndromo (palabra que se escribe igual al derecho
// y al revés).

int main()
{
    char cadena[10], palindromo[10];
    int i = 0, j, largo;
    printf("Ingrese cadena a analizar: ");
    scanf("%s", &cadena);
    largo = strlen(cadena);
    j = largo - 1;
    esPalindromo(cadena, palindromo, i, j, largo);

    if (strcmp(cadena, palindromo) == 0)
    {
        printf("La palabra es palindromo\n");
    }
    else
    {
        printf("La palabra no es palindromo\n");
    }
}