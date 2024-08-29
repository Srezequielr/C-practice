 #include <stdio.h>
 #define N 5

 struct Postulantes{
    char nombre[20];
    char sexo;
    int DNI;
    int edad;
    int codLoc;
 };

 void carga(struct Postulantes post[N]){
     int i;
     for(i = 0; i < N; i++){
        printf("Escriba el nombre del postulante Nro %d \n", i + 1);
        scanf("%s", &post[i].nombre);
        printf("Indique el sexo del postulante Nro %d \n H: Hombre \n M: Mujer \n", i + 1);
        scanf("%s", &post[i].sexo);
        printf("Escriba el DNI del postulante Nro %d \n", i + 1);
        scanf("%d", &post[i].DNI);
        printf("Escriba la edad del postulante Nro %d \n", i + 1);
        scanf("%d", &post[i].edad);
        printf("Escriba la localidad (1-19) del postulante Nro %d \n", i + 1);
        scanf("%d", &post[i].codLoc);
     }
     return;
 }

 void mMenores(struct Postulantes post[N]){
    int i, cont = 0;
    for(i = 0; i < N; i++){
        if(post[i].sexo == 'm' && post[i].edad < 30){
            cont++;
        }
    }
    printf("%d mujeres postuladas tienen menos de 30 años \n", cont);
 }

 void edPromVarones(struct Postulantes post[N]){
    int i, acum = 0, prom, cont = 0;
    for(i = 0; i < N; i++){
        if(post[i].sexo == 'h'){
            cont++;
            acum = acum + post[i].edad;
        }
    }
    prom = acum / cont;
    printf("La edad promedio de los varones es de %d años \n", prom);
 }

 void mosLocalidad(struct Postulantes post[N]){
    int i;
    printf("Los postulantes que viven en la localidad 14 son: \n");
    for(i = 0; i < N; i++){
        if(post[i].codLoc == 14){
            printf("Nombre: %s \n", post[i].nombre);
            printf("DNI: %d \n", post[i].DNI);
        }
    }
 }

 int main(){
    Postulantes post[N];

    carga(post);
    mMenores(post);
    edPromVarones(post);
    mosLocalidad(post);
    return 0;
 }
