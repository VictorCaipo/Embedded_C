#include <stdio.h>//Interactua con OS
#include <stdlib.h>//Manejar memoria dinamica
#include <stdint.h>//Para usar uint8_t y otros tipos de datos

//  Bitwise operators
//      Internamente todos los valores siempre estan en binario por lo que no se necesita alguna conversion

void imprimir_binario(uint8_t valor_decimal){
    for(int ii = 7; ii>= 0 ; ii--){
        //El bucle va de 7 a 0, esto porque al usar el operador ">>" agarraremos la mayor cifa significativa primero (derecha)
        //hasta por ultimo la menos cifra significativa (izquierda)
        printf("%d", (valor_decimal>>ii) & 1);
        // val>>ii, este es otro operador que hace avanzar hacia la derecha ii numero de bits
        // al hacer un and con 1 solo agarramos la ultima cifra que sera la que queramos gracias al bucle
        // se imprime solo 1 y no 0000001 porque %d lo convierte en decimal
        // la impresion siempre se hace de izquierda a derecha, esto se debe a que asi se leen los numeros binarios, el bit
        // mas significativo primero
    }
    printf("\n");
}

int main(){
    // & AND operator
    uint8_t a = 0b1100;
    uint8_t b = 0b1111;
    uint8_t c = a & b;
    printf("%u\n",c);//Utiliza %u para unsigned int (el numero sera impreso en decimal)
    printf("\n");
    imprimir_binario(c);

    uint8_t decimal = 42;
    uint8_t binario = 0b101010;
    //El compilador reconoce como decimal al numero si no tiene ningun prefijo
    //Si asigno un numero mayor a 255 a uint8_t solo se leera los 8 bits menos significativos
    //El valor maximo es 255 (2^8=255)donde 8 es el numero de bits que puede representar uint8_t

}