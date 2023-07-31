/* 
 * File:   map5V.h
 * Author: Christian Alessandro Campos L�pez 21760
 *
 * Created on 22 de julio de 2023, 11:34 PM
 */
// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef MAP_H
#define	MAP_H

#include <xc.h> // include processor files - each processor file is guarded.  

/** Para el ReadMe
    <p><b>Function prototype:</b></p>
  
    <p><b>Summary:</b></p>

    <p><b>Description:</b></p>

    <p><b>Precondition:</b></p>

    <p><b>Parameters:</b></p>

    <p><b>Returns:</b></p>

    <p><b>Example:</b></p>
    <code>
 
    </code>

    <p><b>Remarks:</b></p>
 */


/*//****************************************************************************
// Mapeo de valores
--Val es el valor a mapear
--MinX es el valor minimo de val
--MaxX es el valor m�ximo de val
--Miny es el valor minimo de salida
--MaxY es el valor maximo de salida
//******************************************************************************
*/
unsigned int map(unsigned int val, unsigned int minx, unsigned int maxx, unsigned int miny, float maxy);
#endif	/* MAP_H */

