/* 
 * File:   
 * Author: Christian
 * Comments: Lab1
 * Revision history: A
 */

#include "ioc_init.h"

//******************************************************************************
// Configuraci�n Interrupciones PUERTOB; mandar el pin como 0b, d, 0x
//******************************************************************************
void ioc_init(uint8_t pin){
    
    
    
    // Configuraci�n de las interrupciones
    INTCONbits.GIE = 1;     // Habilitar interrupciones globales
    INTCONbits.RBIE = 1;    // Habilitar interrupciones por cambio en el puerto B
    INTCONbits.RBIF = 0;    // Limpiar la bandera de interrupci�n del puerto B
    
    // Configuraci�n de los puertos
    ANSEL=0;
    ANSELH=0;
    
    //Pull-ups
    OPTION_REGbits.nRBPU=0;
    // Configuraci�n de las interrupciones por cambio en el puerto B como entradas
    if (pin==0){
        TRISBbits.TRISB0=1;
        WPUBbits.WPUB0=1;
        IOCBbits.IOCB0 = 1;
    }
    if (pin==1){
        TRISBbits.TRISB1=1;
        WPUBbits.WPUB1=1;
        IOCBbits.IOCB1 = 1;
    }
    if (pin==2){
        TRISBbits.TRISB2=1;
        WPUBbits.WPUB2=1;
        IOCBbits.IOCB2 = 1;
    }
    if (pin==3){
        TRISBbits.TRISB3=1;
        WPUBbits.WPUB3=1;
        IOCBbits.IOCB3 = 1;
    }
    if (pin==4){
        TRISBbits.TRISB4=1;
        WPUBbits.WPUB4=1;
        IOCBbits.IOCB4 = 1;
    }
    if (pin==5){
        TRISBbits.TRISB5=1;
        WPUBbits.WPUB5=1;
        IOCBbits.IOCB5 = 1;
    }
    if (pin==6){
        TRISBbits.TRISB6=1;
        WPUBbits.WPUB6=1;
        IOCBbits.IOCB6 = 1;
    }
    if (pin==7){
        TRISBbits.TRISB7=1;
        WPUBbits.WPUB7=1;
        IOCBbits.IOCB7 = 1;
    }
    
}

