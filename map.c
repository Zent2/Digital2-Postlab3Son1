/* 
 * File:   map.c
 * Author: Christian Alessandro Campos L�pez 21760
 *
 * Created on 22 de julio de 2023, 11:37 PM
 */
#include "map.h"

//******************************************************************************
// Variables Internas
//******************************************************************************

/* // **************************************************************************
// Mapeo de valores
--Val es el valor a mapear
--MinX es el valor minimo de val
--MaxX es el valor m�ximo de val
--Miny es el valor minimo de salida
--MaxY es el valor maximo de salida
// *****************************************************************************
*/
unsigned int map(unsigned int val, unsigned int minx, unsigned int maxx, unsigned int miny, float maxy) {
    // Asegurar que el valor est� dentro del rango original
    if (val < minx) {
        val = minx;
    }
    if (val > maxx) {
        val = maxx;
    }

    // Calcular el valor en el rango de salida con interpolaci�n lineal
    int resultado=(float)(val - minx) * (float)(maxy - miny) / (float)(maxx - minx) + miny;
    return resultado;
    
}

