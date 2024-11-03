 #include <stdio.h>
 #define N 50

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
    printf("%d mujeres postuladas tienen menos de 30 a�os \n", cont);
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
    printf("La edad promedio de los varones es de %d a�os \n", prom);
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

// Una agencia de empleo registra los datos de 50 postulantes a un puesto de trabajo. De cada uno registra nombre,
// sexo, dni, edad y codigo de localidad donde vive (1…19).
// Se pide que usando funciones para cada ítem, resuelva lo siguiente:
// a) Indicar cuantas postulantes mujeres tienen menos de 30 años.
// b) Indicar la edad promedio de los postulantes varones.
// b) Mostrar los nombres de los postulantes y el dni de quienes viven en la localidad 14.

 int main(){
    Postulantes post[N];
    carga(post);
    mMenores(post);
    edPromVarones(post);
    mosLocalidad(post);
    return 0;
 }
