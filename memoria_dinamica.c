#include <stdio.h>//Interactua con OS
#include <stdlib.h>//Manejar memoria dinamica

int main() {
    int *array;
    int tamaño;
    //Al declarar la variable se le asigna automaticamente
    //una direccion
    printf("¿Cuántos elementos quieres en el array? ");
    scanf("%d", &tamaño);//lee datos y almacena
    //guarda segun la direccion de la variable
    //%d indica que lea un numero en base 10

    // Reservamos memoria dinámica
    array = (int *) malloc(tamaño * sizeof(int));
    //(int*) convierte void* en int*
    //malloc, devuelve un puntero void (generico) que puede apuntar a cualquier tipo de dato
    //malloc necesita como parametro la cantidad de bytes que va a almacenar

    //El tipo de puntero es importante, porque dice al compilador 2 cosas importantes
    //  Que tipo de datos se almacenan 
    //  Cuantos bytes avanzar con operaciones ptr++o

    // Verificamos si la asignación fue exitosa
    if (array == NULL) {
        printf("Error: no se pudo asignar memoria.\n");
        return 1;
    }

    // Inicializamos y mostramos los elementos del array
    for (int i = 0; i < tamaño; i++) {
        array[i] = i * 10;  // Ejemplo: llenamos con múltiplos de 10
    }

    printf("Elementos del array:\n");
    for (int i = 0; i < tamaño; i++) {
        printf("%p ", (void*)&array[i]);
        //la salida de %p es hexadecimal tambien existen otros operadores para decimal, etc
        //Es por estandar convertir el puntero a void antes de imprimir
        
    }
    printf("\n");

    // Liberamos la memoria cuando ya no la necesitamos
    free(array);

    return 0;
}
