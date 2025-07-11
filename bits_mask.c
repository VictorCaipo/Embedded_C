#include <stdio.h> //Interactua con el sistema
#include <stdint.h> //Nuevos tipos de datos como unit8_t

void print_binary(uint8_t decimal);

//  BITMASKS 
//      Es un numero binario que se utiliza para aislar, establecer
//      limpiar o alternar ciertos bits

int main(void) {
    //Creando  una variable (informalmente llamada registro)
    uint8_t variable = 0b00000000 ; 
    variable |= (1<<2);
    //(1<<2) no es mas que el numero binario 00000001 movido 2 bits
    //a la izquierda
    //Equivale a:   variable = variable | (1<<2)
    // ¿Para que nos sirve esto?
    // Para activar bits especificos de un registro
    // Si el registro ya estaba activo entonces no sucede nada
    // Porque no cambiaria nada en el programa
    // Esto tiene utilidades que aun no tengo claro ("esperar")
    print_binary(variable);
    printf("\n");


    //  Apagando un bit especifico
    uint8_t led_rojo = 0b00000111;
    //  Como vemos tenemos los primeros 3 bits encendidos
    led_rojo &= ~(1<<1); //Apagando el segundo bit 0b00000010
    // Al hacer la negacion obtenemos 0b11111101;
    //Al comprar el led_rojo con el AND tendremos todos los bits
    //correspondientes al led_rojo pero el bit 2 siempre estara
    //apagado, de esta manera conseguimos apagar un bit


}

void print_binary(uint8_t decimal){
    for(int ii = 7; ii >=0  ; ii--){
        printf("%d", (decimal>>ii)&1);
    }
}
