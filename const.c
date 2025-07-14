#include <stdio.h> //Interactua con el sistema
#include <stdint.h> //Nuevos tipos de datos como unit8_t

void print_binary(uint8_t decimal);

//  Const : sirve para declarar valores que no pueden cambiar una vez asignados
//  Sus ventajas son proteger datos importante, mejorar claridad del codigo
//  y optimizacion

int main(void) {
    // Uso de const con tipos de datos
    const float pi = 3.1416;
    printf("El valor de PI es: %.2f\n");
    return 0;

    //Uso de const con punteros

    //No se puede cambiar el valor de x a través del punter ptr
    int x = 10;
    int y = 20;
    const int *ptr = &x; //Al declarar el puntero *ptr es el valor apuntado
    //ptr es la direccion
    //*ptr = 30 botaria error porque estamos modificando el valor de x
    ptr = &y; //Aca no hay error porque estamos modificando la direccion de x
    //De manera que *ptr = 20, aca debo aclarar que no modificamos ni x ni y
    //solo hicimos que el puntero apuntara a otra variable (y) esto tiene varios usos
    //que veremos mas adelante
    
    
    
    
    //No se puede hacer que ptr apunte a otro lado
    int y = 10;
    int *const ptr = &y;

    //No se puede cambiar el valor apuntado ni el puntero
    int z = 10;
    const int* const ptr = &z;

    //Cual es la diferencia entre #define y const?
    // #define sirve para sustitucion textual, const es una variable constante
    // en el debug #define es dificil de rastrear y const es facil de rastrear
    //Es totajlmente sabio evitar #define para valores constantes
    //EL #defina solo se usa en casos particulares
    //Se usaba antes porque habia falta de herramientas que existen hoy en dia
}

void print_binary(uint8_t decimal){
    for(int ii = 7; ii >=0  ; ii--){
        printf("%d", (decimal>>ii)&1);
    }
}
