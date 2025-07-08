#include <stdio.h>//Interactua con OS
#include <stdlib.h>//Manejar memoria dinamica

// Stack
//      Aca el array de char se guarda en el stack, y solo
//      vive hasta que se ejecute la funcion, luego desaparece
void saludar() {
    char mensaje[] = "Hola, Victor!";  // ← Vive en el stack
    printf("%s\n", mensaje);
    printf("%c\n",mensaje[0]); //%s imprime una cadena de caracteres (string)
    //para imprimir un solo caracter uso %c
}

//  Heap
//      ptr es el puntero (guarda la direccion)
//      *ptr guarda el valor de la dirección
void heap_example(){
    int* ptr = malloc(sizeof(int));
    if (ptr == NULL){
        printf("Error al asignar memoria\n");
        return;
    }
    *ptr = 123;
    printf("Valor en el heap %d\n",*ptr);
    printf("Valor del puntero %p\n",ptr);
    free(ptr);
}


int main(){
    saludar();
    heap_example();
}