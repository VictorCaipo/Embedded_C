#include <stdio.h> //Interactua con el sistema
#include <stdint.h> //Nuevos tipos de datos como unit8_t

/* 
volatile:   sirve para decirle al compilador "no optimices el acceso a esta variable"
            normalmente  el compilador intenta optimizar el codigo, si una variable 
            no cambia dentro de una funcion, el compilador asume que siempre tiene 
            el mismo valor y evita leerla varias veces.
Existen casos donde la variable cambia por afuera del programa:
            Un registro de hardware que cambia su valor po si solo
            Una variable modificada por una interrupción
            Una variable compartida entre hilos o tareas (FreeRTOS)
Porque se usa en C?
            C te da acceso directo al hardware y no impone abstracciones, por eso
            tu eres el responsable de decirle al compilador que no toque algo
            Es un lenguaje ideal para sistemas embebidos, pero requiere cuidado
*/

/*
Ejercicio:
    En este contexto, el hardware cambia la variable flag
    El main espera a que flag se vuelva 1
*/

int flag = 0;

void fake_interrupt(){
    flag = 1;//El valor si hace el cambio de memoria, pero el compilador podria
    //ignorarlo
    printf("Interrupción cambia a : flag = %d\n",flag);
}

int main(void) {
    printf("[MAIN] Esperando que flag sea 1 ...\n");
    for(int i = 0; i<10000000; ++i); //delay artificial
    fake_interrupt(); //cambia el valor de flag a 1 

    while (flag ==0){
        //Bucle infinito si es que flag nunca llega  a ser uno
        //Es decir que el fake_interrupt no se activa
    }
    printf("[MAIN] Cambio detectado: flag = %d\n",flag);
    return 0;
    /*
    El compilador al ver que flag no cambia en el main() dice, no necesito leer
    flag otra vez, lo lei una vez y era 0 asi que lo dejare asi, de esa manera
    nos quedamos en un bucle infinito
    */
    /*
    Es suficiente entender el tema y hacer un ejemplo para pasar al siguiente tema
    */
}
