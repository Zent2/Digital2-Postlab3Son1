/* 
 * File:   mainPostLab.c
 * Author: Christian Alessandro Campos López 21760
 *
 * Created on 30 de julio de 2023, 04:54 PM
 */

//******************************************************************************
// Palabra de configuración
//******************************************************************************
// PIC16F887 Configuration Bit Settings

// 'C' source line config statements

// CONFIG1
#pragma config FOSC = INTRC_NOCLKOUT// Oscillator Selection bits (INTOSCIO oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF      // RE3/MCLR pin function select bit (RE3/MCLR pin function is digital input, MCLR internally tied to VDD)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown Out Reset Selection bits (BOR disabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal/External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is disabled)
#pragma config LVP = OFF        // Low Voltage Programming Enable bit (RB3 pin has digital I/O, HV on MCLR must be used for programming)

// CONFIG2
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

//******************************************************************************
// Librerías Generales
//******************************************************************************
#include <xc.h>
#include <stdio.h>
#include <stdint.h>
//******************************************************************************
// Librerías Propias
//******************************************************************************
#include "ioc_init.h"
#include "SPI.h"
#include "ADC_config.h"
//******************************************************************************
// Variables
//******************************************************************************
#define _XTAL_FREQ 8000000     // Frecuencia de oscilador de 8MHz
uint8_t contador=0;
uint8_t CONT=0;

//******************************************************************************
// Prototipos de función
//******************************************************************************
void setup(void);
//******************************************************************************
// Vector de Interrupción
//******************************************************************************

void __interrupt() isr(void) {
    if(SSPIF == 1){
        if (contador==0){
            uint8_t lectura = spiRead();
            spiWrite(adc_read());
            SSPIF = 0;
            contador=1;
        }
        if (contador==1){
            uint8_t lectura = spiRead();
            spiWrite(CONT);
            SSPIF = 0;
            contador=0;
        }
    }
    if (INTCONbits.RBIF) {
        
        // Verificar si el pushbutton de suma fue presionado
        if (!PORTBbits.RB7) {
            CONT++;
        }

        // Verificar si el pushbutton de resta fue presionado
        if (!PORTBbits.RB5) {
            CONT--;
        }

        INTCONbits.RBIF = 0;    // Limpiar la bandera de interrupción del puerto B
    }
    
}
//******************************************************************************
// Función principal
//******************************************************************************

void main(void) {
    setup(); // Inicializar el microcontrolador

    while (1) {
        ADCON0bits.GO=1;
       __delay_ms(250);
    }
}
//******************************************************************************
// Funciones secundarias
//******************************************************************************

void setup(void) {
    // Configuración de los puertos
    ANSEL = 0;
    ANSELH = 0;
    
    TRISD = 0;
    

    PORTD = 0;
    
    //Push-Buttons
    ioc_init(7);
    ioc_init(5);
    
    //Oscilador a 8MHz
    OSCCONbits.IRCF = 0b111;
    OSCCONbits.SCS = 1;
    //Configuración ADC 
    adc_init(1);
    adc_IE(0);
    ADCON0bits.GO=1;
    
    
    INTCONbits.GIE = 1;         // Habilitamos interrupciones
    INTCONbits.PEIE = 1;        // Habilitamos interrupciones PEIE
    PIR1bits.SSPIF = 0;         // Borramos bandera interrupción MSSP
    PIE1bits.SSPIE = 1;         // Habilitamos interrupción MSSP
    TRISAbits.TRISA5 = 1;       // Slave Select
    spiInit(SPI_SLAVE_SS_EN, SPI_DATA_SAMPLE_MIDDLE, SPI_CLOCK_IDLE_LOW, SPI_IDLE_2_ACTIVE);


}


