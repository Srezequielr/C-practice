# Programación Procedural

## Introducción a la Programación Procedural

La **programación procedural** es un paradigma imperativo basado en la ejecución secuencial de instrucciones que modifican el estado del programa. Este libro utiliza el lenguaje **C** para enseñar los conceptos fundamentales, incluyendo:

- **Algoritmos**: Secuencias de pasos para resolver problemas.
- **Estructuras de datos**: Organización y almacenamiento de información.
- **Modularización**: División del código en funciones reutilizables.

---

## Conceptos Clave

### 1. **Punteros**
Los punteros son variables que almacenan direcciones de memoria. Son esenciales para el manejo dinámico de memoria y estructuras de datos.

**Ejemplo en C:**
```c
int x = 10;
int *p = &x;  // p apunta a la dirección de x
printf("%d", *p);  // Imprime 10
```

### 2. **Memoria Dinámica**
Se gestiona mediante las funciones `malloc` y `free`, permitiendo asignar y liberar memoria en tiempo de ejecución.

**Ejemplo:**
```c
int *arr = (int*)malloc(5 * sizeof(int));  // Arreglo dinámico
free(arr);  // Liberar memoria
```

### 3. **Pasaje de Parámetros**
- **Por valor**: Se pasa una copia del dato.
- **Por referencia**: Se pasa la dirección de memoria, permitiendo modificar el original.

**Ejemplo de pasaje por referencia:**
```c
void modificar(int *x) {
    *x = 20;
}
int main() {
    int a = 10;
    modificar(&a);  // a ahora es 20
}
```

### 4. **Listas Enlazadas**
Estructuras dinámicas donde cada nodo contiene datos y un puntero al siguiente nodo.

**Ejemplo de definición:**
```c
typedef struct nodo {
    int dato;
    struct nodo *sig;
} Nodo;
```

**Inserción en lista:**
```c
void insertar(Nodo **cabeza, int valor) {
    Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->dato = valor;
    nuevo->sig = *cabeza;
    *cabeza = nuevo;
}
```

### 5. **Recursividad**
Técnica donde una función se llama a sí misma para resolver problemas de manera elegante, aunque puede ser menos eficiente en memoria.

**Ejemplo:**
```c
int factorial(int n) {
    if (n == 0) return 1;
    return n * factorial(n - 1);
}
```

---

## Estructuras de Datos y Gestión de Memoria

### **Memoria Estática vs. Dinámica**
- **Estática**: Asignada en tiempo de compilación (variables globales/locales).
- **Dinámica**: Asignada en tiempo de ejecución (`malloc`, `free`).

### **Problemas Comunes**
- **Basura**: Memoria asignada pero inaccesible.
- **Punteros colgantes**: Referencias a memoria ya liberada.

---

## Conclusión

Este libro proporciona una base sólida en programación procedural usando C, enfocándose en:
- Uso de **punteros** para acceso directo a memoria.
- **Gestión dinámica** de memoria.
- Implementación de **estructuras de datos** como listas enlazadas.
- Técnicas de **modularización** y **recursividad**.

Estos conceptos son fundamentales para entender cómo los programas interactúan con la memoria y gestionan datos eficientemente.
