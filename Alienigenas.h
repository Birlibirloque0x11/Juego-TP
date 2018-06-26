#ifndef Alienigenas_H_INCLUDED
#define Alienigenas_H_INCLUDED
#include "Alien.h"
/**
    \file Alienigenas.h
    \brief La biblioteca Alienigenas permite la realizacion de programas que requieren el uso de arrays de AlienIn.
*/
/**
    \brief TDA Alienigenas
 */
typedef struct AlienigenasRep *Alienigenas;

/**
  \brief Crea una lista vacia a la que se le pueden ir insertando campos.
  \param n El numero maximo de elementos que se quieren tener.
 */
Alienigenas AlienigenasCrea(int n);
/**
  \brief Libera la memoria reservada para los Aliens.
  \param ali La lista de Aliens que se va a liberar de memoria.
 */
void AlienigenasLibera (Alienigenas ali);
/**
  \brief Inserta un elemento en la lista.
  \param ali La lista de Aliens en la que se quiere insertar el elemento.
  \param a El elemento Alien que se quiera insertar en la lista.
 */
void AlienigenasInserta (Alienigenas ali, Alien a, int n);
/**
  \brief Elimina un elemento de la lista de Aliens.
  \param ali La lista de Aliens en la que se quiere eliminar el elemento.
  \param i EL numero del elemento en la lista que se quiere eliminar.
 */
void AlienigenasElimina (Alienigenas ali, int i);
/**
  \brief Dibuja la lista de Aliens en la pantalla.
  \param ali La lista de Aliens que se quiere dibujar.
 */
void AlienigenasMuestra (Alienigenas ali);
/**
  \brief Actualiza las posiciones en pantalla de los elementos en la lista de Aliens.
  \param ali La lista de Aliens cuyas posiciones se quieren actualizar.
 */
void AlienigenasMueve (Alienigenas ali, int vel);
/**
  \brief Devuelve el elemento Alien de una posicion concreta de la lista.
  \param ali La lista de Aliens de la que se quiere obtener el Alien.
  \param n La posicion del Alien solicitado.
  \return El Alien solicitado.
 */
Alien AlienDeAlienigenas (Alienigenas ali, int n);
/**
    \brief Obtiene la posicion en la lista de un Alien concreto y la devuelve.
    \param ali La lista de Aliens en la que se encuentra la posicion del Alien que queremos obtener.
    \return La posicion del Alien.
*/
int PosNDeALienigenas (Alienigenas ali);

#endif // Alienigenas_H_INCLUDED
