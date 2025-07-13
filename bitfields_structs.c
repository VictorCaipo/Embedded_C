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

//Creacion de un bietfield
struct estado_led
{
    //Al declarar unsigned quiere decir que la variable no tiene signo
    //Si declaramos un -2 los valores seran absurdos
    unsigned int led1 : 1; //Donde led1 es un campo de bit
    unsigned int led2 : 1; //El numero despues de : es la cantidad de bits
    unsigned int led3 : 1; //Podemos usar unsigned int, int, float, char
    unsigned int reservado : 5;
    //De esta manera ahorramos memorias,usamos 8 bits en lugar de 4 int (32 bits)
};


int main(void) {
    //Creando un objeto a traves del struct persona 
    struct persona usuario;
    usuario.edad = 24;
    printf("%d",usuario.edad);
    snprintf(usuario.nombre, sizeof(usuario.nombre),"Victor"); //Solo copia la cadena
    //Victor a usuario.nombre, pero no la imprime
    printf("\n");
    printf("%s\n",usuario.nombre); //%s es el formato correcto para imprimir cadenas
    //char o puntero a char
    //La funcion snprintf sirve para guardar una cadena de texto
    //dentro de un arreglo de caracteres, limitando la cantidad
    //para evitar desbordamiento
    // 'c' es un caracter
    // "Casa" es un arreglo de caracteres (char nombre = "victor")
    
    //  Bitfields
    //  Un bitfield (campo de bits) es una manera de definir structuras en C
    //  donde puedes controlar cuantos bits ocupa cada miembreo
    //  Esto es util al trabajar con registros de hardware, compactar datos en memoria
    //  y manipular bits individuales de forma legible
    struct estado_led estados = {0}; //Inicialisa todos los campos de estados en 0
    //En binario 0b00000000
    estados.led1=1;
    estados.led2=1;
    printf("Estado: %u\n",*(unsigned char*)&estados);
    //%u imprime un numero entero sin signo (unsigned int)
    //&estados devuelve la direccion de donde se creo el objeto estados
    //unsigned char* transforma la direccion a un puntero un byte sin signo
    //* el asterisco nos ayuda a acceder al valor
    //como consecuencia obtendremos 3 en decimal
    return 0;
    //Seria util estudiar char y unsigned char, aun no quedo claro

    //Diferencia entre signed y unsigned
    //signed: puede guardar numeros negativos y positivos
    //unsigened solo guarda numeros positivos, pero numeros mas grandes
    //debido a que no reserva espacion para el signo
    //por ejemplo char signed guarda de -128 a 127 y unsigned de 0 a 255
    //Cuyomo se muestra uint8_t y los demas de la libreria solo guardan numeros
    //positivos lo cual es ideal y sirve para los microcontroladores
    //Dependiendo del tipo de dato que usemos el numero puede ser diferente
    //El negativo en binario se obtiene usando el complemento a 2
    //Que es lo mismo que decir 1+(-2) donde -2 es el complemento a 2
    //De esa manera es facil restar numeros binarios
    //La operacion invertir  bits + 1 es la forma rapida de calcular el complemento a 2
    //que se define como 2^N-x, donde N es el numero de bits y x el numero
}

void print_binary(uint8_t decimal){
    for(int ii = 7; ii >=0  ; ii--){
        printf("%d", (decimal>>ii)&1);
    }
}
