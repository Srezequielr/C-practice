#include <stdio.h>
#include <string.h>
#define N 29

void reemplazar(char str[N]){
    int i = 0;
    while((i < N) && (str[i] != '2')){
        i++;
    }
    str[i] = '0';
    puts(str);
    return;
}

void copiar(char str[N], char subStr[N]){
    strncpy(subStr, str, 12);
    printf("La nueva frase: %s \n", subStr);
    return;
}

void contarVocales(char str[N]){
    int i, cont = 0;
    for(i = 0; i < N; i++){
        switch(str[i]){
        case 'a':
            cont++;
            break;
        case 'e':
            cont++;
            break;
        case 'i':
            cont++;
            break;
        case 'o':
            cont++;
            break;
        case 'u':
            cont++;
            break;
        }
    }
    printf("La cantidad de vocales es de: %d", cont);
    return;
}

int main(){
    char str[N];
    char subStr[N];
    printf("Ingrese una cadena de texto \n");
    gets(str);
    reemplazar(str);
    copiar(str, subStr);
    contarVocales(str);
return 0;
}
