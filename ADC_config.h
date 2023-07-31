/* 
 * File:   
 * Author: Christian
 * Comments: Lab1-ADC
 * Revision history: A
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef ADCCONFIG_H
#define	ADCCONFIG_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h>
/** Para el ReadMe
    <p><b>Function prototype: ADC_CONFIG</b></p>
  
    <p><b>Summary: Configuraci�n del ADC</b></p>

    <p><b>Description: Esta librer�a configura el ADC, permitiendo escoger
 * el puerto de entrada y el puerto de salida del ADC, sin necesidad de tener la
 * salida, puede tener solo la entrada.</b></p>

    <p><b>Precondition:</b></p>

    <p><b>Parameters: Channel, el canal anal�gico a leer</b></p>

    <p><b>Returns: Lectura ADC</b></p>

    <p><b>Example: adc_init(0); //Configura el adc en el canal 0
 * PORTB=adc_read();  //Muestra ADC en PORTB
 * __delay_ms(10); //Delay antes de cambio de canal
 * adc_change_channel(1); //cambia el canal al canal 1
 * PORTC=adc_read(); //Muestra ADC en PORTC
 * PORTE=adc_get_channel(); //Devuelve el valor/n�mero del canal al 
 * PuertoE</b></p>
    <code>
 
    </code>

    <p><b>Remarks: </b></p>
 */

//******************************************************************************
// Configuración Interrupción ADC
//******************************************************************************
void adc_IE(char E);
//******************************************************************************
// Configuración ADC
//******************************************************************************
void adc_init(int channel);
//******************************************************************************
// Lectura ADC
//******************************************************************************
int adc_read();
//******************************************************************************
// Cambiar canal ADC
//******************************************************************************
void adc_change_channel(int channel);
//******************************************************************************
// Conocer el canal de configuración
//******************************************************************************
int adc_get_channel();

#endif	/* ADCCONFIG_H */


