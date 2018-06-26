#ifndef __Rafaga_H__
#define __Rafaga_H__

#include "Alien.h"
#include "Nave.h"
#include "Bala.h"

/**
    \file Rafaga.h
    \brief La biblioteca Ráfaga permite la realización de programas que requieren el uso de ráfagas de balas.
*/

/**
    \brief TDA Ráfaga
*/
typedef struct Rafaga *Rafaga;

// FUNCIONES

/**
    \brief Crea y reserva espacio para una estructura de balas.
    \return La estructura de balas creada.
*/
Rafaga RafagaCrea();

/**
    \brief Libera la memoria reservada para la ráfaga y la de todas sus balas.
    \param r La ráfaga cuya memoria se desea liberar.
*/
void RafagaLibera(Rafaga r);

/**
    \brief Inserta una bala en la ráfaga.
    \param r La ráfaga donde se va a insertar la bala.
    \param b La bala que vamos a insertar
*/
void RafagaInserta(Rafaga r, Bala b);

/**
    \brief Imprime en la pantalla todas las balas de la estructura.
    \param r La ráfaga que se desea imprimir.
*/
void RafagaMuestra(Rafaga r);

/**
    \brief Mueve todas las balas de la estrucutra con la velocidad que se especifica. Además, libera la memoria de las balas que salen de la pantalla.
    \param r La ráfaga cuyas balas se desea desplazar.
    \param vel La velocidad con la que se desea mover las balas
*/
void RafagaMueve(Rafaga r, int vel);

/**
    \brief Detecta la posible colisión entre alguna bala y un alien. Además, si se produce el choque se libera la memoria de la bala.
    \param r La ráfaga cuyas balas nos interesa detectar una posible colisión.
    \param a El alien con el que detecta la posible colisión.
    \return 1 Se ha producido la colisión entre alguna bala y el alien.
    \return 0 No se ha producido ninguna colisión con el alien.
*/
int RafagaChoqueAlien(Rafaga r, Alien a);

/**
    \brief Detecta la posible colisión entre alguna bala y una nave. Además, si se produce el choque se libera la memoria de la bala.
    \param r La ráfaga cuyas balas nos interesa detectar una posible colisión.
    \param n La nave con el que detecta la posible colisión.
    \return 1 Se ha producido la colisión entre alguna bala y la nave.
    \return 0 No se ha producido ninguna colisión con la nave.
*/
int RafagaChoqueNave(Rafaga r, Nave n);

#endif
