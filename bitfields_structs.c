#include <stdio.h> //Interactua con el sistema
#include <stdint.h> //Nuevos tipos de datos como unit8_t


void print_binary(uint8_t decimal);

// Structs
// Es una coleccion de variables agrupadas bajo un solo nombre
// Como C es no orientada a objetos tiene cosas como structs
// pointers, etc, que pueden simular este comportamiento
    //Creando una struct
struct persona{
    int edad;
    float altura;
    char nombre[20]; //Esta es la manera de declarar un array de caracteres
    //En C no existen Strings
 };

int main(void) {

   
    struct persona usuario;
    usuario.edad = 24;

    printf("%d",usuario.edad);
    snprintf(usuario.nombre, sizeof(usuario.nombre),"Victor");
    //La funcion snprintf sirve para guardar una cadena de texto
    //dentro de un arreglo de caracteres, limitando la cantidad
    //para evitar desbordamiento
    // 'c' es un caracter
    // "Casa" es un arreglo de caracteres (char nombre = "victor")
    


}

void print_binary(uint8_t decimal){
    for(int ii = 7; ii >=0  ; ii--){
        printf("%d", (decimal>>ii)&1);
    }
}
