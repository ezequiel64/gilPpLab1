#ifndef EGILL_H_INCLUDED
#define EGILL_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Egil.h"


#endif // EGILL_H_INCLUDED

/** \brief Valida el ingrese de una opcion numerica y asigna por referencia el valor de la misma
 *
 * \param Puntero a variable ingresada (Solo es cargada en caso de cumplir con los requisitos)
 * \param limite cantidad de intentos que se le brinda al usuario
 * \param limite inferior del rango
 * \param limite superior del rango
 * \param mensaje (ej: "Ingrese numero")
 * \param mensaje de error (ej "Error. ingrese nuevamente el numero")
 * \return retorna 1 = true o 0 = false
 *
 */
int getInt(int* valor,int intentos,int limx,int limy,char mensaje[],char error[]);

/** \brief Valida el ingreso de un flotates y lo asigna por referencia en el caso de ser uno
 *
 * \param puntero a la variable fotante donde se va cargar el valor de ser correcto
 * \param cantidad de intenos fallidos que puede tener el usuario
 * \param rango inferior
 * \param rango superior
 * \param mensaje (ej: "Ingrese numero")
 * \param mensaje de error (ej "Error. ingrese nuevamente el numero")
 * \return 1 si es flotante -- 0 si no cumple con las condiciones para ser un flotante.
 *
 */
int getFloat (float* valor,int intentos,int limx,int limy,char mensaje[],char error[]);


/** \brief Valida el ingrese de una opcion numerica y asigna por referencia el valor de la misma
 *
 * \param Puntero a la opcion ingresada (Solo es cargada en caso de cumplir con los requisitos)
 * \param limite inferior del rango
 * \param limite superior del rango
 * \param Cantidad de intentos fallidos que se le da al usuario
 * \param mensaje de ingreso
 * \param mensaje de error.
 * \return retorna 1 = true o 0 = false
 *
 */
int validarRango(int* valor,int limX,int limY,int intentos,char mensaje[],char error[]);

/** \brief Da el siguiente formato y lo asigna a una nueva cadena //Coche, Ruedas...
 *
 * \param cadena a modificar
 * \param cadena a modificar
 *
 */ 
void formatearNombre(char cad1[],char cad2[],char cad3[]);//en proceso

/** \brief valida el ingreso de una cadena y que no realizar un overflow
 *
 * \param puntero a vector origen donde se va a cargar el string en caso de no overflow
 * \param tamaño del vector de origen
 * \param mensaje de ingreso de cadena
 * \param mensaje de Error
 * \param Cantidad de intentos que se dan de reingreso
 * \return 1 o 0 en caso de ser True o false
 *
 */ 
int getString(char *cadena,int tam,char mensaje[],char error[],int intentos);



/** \brief valida el ingreso de una caracter
 *
 * \param puntero a vector origen donde se va a cargar el string en caso de no overflow
 * \param cantidad de inentos que se le da al usuario
 * \param  criterio de validacion, 0 para rango 1 para validar el ingreso de 2 caracteres univocos
 * \param  rango inferior
 * \param rango superior
 * \param mensaje (ej: "Ingrese sexo")
 * \param mensaje de error (ej "Error. ingrese nuevamente el sexo")
 * \return 1 o 0 en caso de ser True o false
 *
 */ 
int getChar(char* valor,int intentos,int criterio,char limx,char limy,char mensaje[],char error[]);