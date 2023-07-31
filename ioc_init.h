/* 
 * File:   
 * Author: Christian
 * Comments: Lab1
 * Revision history: A
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef IOCINIT_H
#define	IOCINIT_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h>
/** Para el ReadMe
    <p><b>Function prototype: IOC_INIT</b></p>
  
    <p><b>Summary: Funci�n que configura los pines como interrupci�n</b></p>

    <p><b>Description: Esta funci�n configura los pines que se le envien
 *  como interrupciones, lo que significa que al cambiar de estado se 
 * activar� la interrupci�n.</b></p>

    <p><b>Precondition:</b></p>

    <p><b>Parameters: PINES DEL PUERTO B QUE SE QUIERE COLOCAR COMO 
 * INTERRUPCIONES</b></p>

    <p><b>Returns: N/A</b></p>

    <p><b>Example: ioc_init(0) har� que el pin 0 del PORTB tenga habilitada 
 * las interrupciones</b></p>
    <code>
 
    </code>

    <p><b>Remarks: </b></p>
 */

//******************************************************************************
// Configuraci�n Interrupciones PIN; mandar como binario, decimal o hexadecimal
//******************************************************************************
void ioc_init(uint8_t pin);

#endif	/* ioc_init_H */


