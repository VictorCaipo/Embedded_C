#include <stdio.h>//Interactua con OS
#include <stdlib.h>//Manejar memoria dinamica
#include <stdint.h>//Para usar uint8_t y otros tipos de datos
#include <string.h>//Para manejar strings facilmente

/*
Struct:
    Un struct es una forma de agrupar diferentes tipos de datos bajo un mismo nombre
    Parecido a una caja que contiene varias variables llamadas miembros o campos
    Dentro de struct se pueden guardar int, float, char, arrays, otros struct o punteros
    tambien puedes tener structs anidados
*/

//Creacion de un struct
struct universitario {
    char nombre [50]; //Reserva 50 bytes, cada byte es igual a 8 bits
    /*
    Al escribir char nombre[50] reservamos una dirección que apunta al primer byte
    Cuando escribimos "victor" el compilador guarda la cadena de solo lectura y nos da
    un puntero al primer caracter.
    Como nombre ya tiene una direccion fija y "Victor" es otra direccion, C no permite
    hacer nombre = "Victor"
    Esto no sucede con int o float, no porque sean especiales, sino que el problema
    sucede al usar arrays

    Que sucede al hacer:
    int x;
    x = 10;
    Ahi no hay error, porque no estoy asignando una direccion sino un valor literal
    los tipos primitivos, como int, float, char se asignan por valor no por direccion
    es decir  10 no se guarda antes de asignarse, se asigna inmediatamente.
    
    En C, los arrays no son asignables. Solo puedes copiar su contenido manualmente
    \0: es un caracter especial en C conocido como NUL, su valor numero es 0 en decimal
    es diferente a 0 o al punteor NULL, aunque esten relacionados.
    Este es agregado automaticamente al final y sirve como bandera para decir a la
    funcion printf este es el final
    
    Uno pensaria que si el tamaño del array de char es 4 solo se leerian 4 caracteres
    pero esto solo pasa si tu controlas las lecturas, las funciones printf() leen
    hasta encontrar el "\0"

    Si creamos
        char saludo[5] = "Hola"; estarias en lo correcto porque tenemos que añadir
        un caracter adicional para el "\0", donde saludo[0] seria H y saludo[4] seria \0  

    Como vemos los arrays de caracteres consumen mucha memoria por lo que una buena practice
    seria usar 
        const char mensaje[] = "Error : Sensor desconectado";
        Siempre dimensionar los arrays

    */
    int edad; // En años
    float altura; // En cm
}

int main(){

    //Declaracion de una variable tipo struct
    struct universitario victor;
    victor.edad = 24;
    victor.altura = 1.69;
    strcpy(victor.nombre, "Victor"); Pone a una cadena de caracteres dentro de un array?

    printf("Nombre: %s\n",victor); //Sirve para imprimir una cadena de caracteres
    printf("Edad: %d years\n");
    printf("Altura: %.2f cm\n");


}
