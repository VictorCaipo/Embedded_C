#include <stdio.h> //Interactua con el sistema
#include <stdint.h> //Nuevos tipos de datos como unit8_t

void print_binary(uint8_t decimal);

int main(void) {
    //  Operador OR "|"
    //  Declarando 2 numeros binarios, para ver como funciona result
    uint8_t a = 0b00001100;
    uint8_t b = 0b00001010;
    uint8_t result1 = a | b; //Operador bitwise "or"
    printf("Operador OR\n");
    print_binary(a);
    printf("\n");
    print_binary(b);
    printf("\n");
    print_binary(result1);
    printf("\n");

    //Operador "<<"
    uint8_t num = 0b00000011;
    uint8_t result2 = num << 3;
    printf("Operador <<\n");
    print_binary(num);
    printf("\n");
    print_binary(result2);
    printf("\n");


}

void print_binary(uint8_t decimal){
    for(int ii = 7; ii >=0  ; ii--){
        printf("%d", (decimal>>ii)&1);
    }
}
