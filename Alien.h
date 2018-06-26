#ifndef __Alien_H__
#define __Alien_H__

#include "Bala.h"

/**
    \file Alien.h
    \brief La biblioteca Alien permite la realización de programas que requieren el uso de enemigos que disparan balas y permite detectar sus colisiones.
*/

/**
    \brief TDA Alien
*/
typedef struct Alien *Alien;

// FUNCIONES

/**
    \brief Crea y reserva espacio para un alien. El alien se crea en una posición de la pantalla y con una dirección aleatoria.
    \param imagen La dirección relativa de la imagen que se desea usar.
    \return El alien que ha sido creado.
*/
Alien AlienCrea(char *imagen);

/**
    \brief Libera la memoria reservada para el alien y todas sus dependencias.
    \param a El alien cuya memoria se desea liberar.
*/
void AlienLibera(Alien a);

/**
    \brief Mueve un alien con la velocidad que se especifica en la dirección que lleva el alien. Cambia la dirección del alien si éste choca con algún límite de la pantalla.
    \param a El alien que se desea mover.
    \param vel La velocidad con la que desea mover en pixeles/ejecución.
*/
void AlienMueve(Alien a, int vel);

/**
    \brief Imprime un alien en su posición de la pantalla.
    \param a El alien que se desea imprimir.
*/
void AlienDibuja(Alien a);

/**
    \brief Crea la bala que es disparada por el alien.
    \param a El alien que dispara la bala.
    \param imagen La dirección relativa de la imagen que se desea usar como bala.
    \return La bala que el alien ha disparado.
*/
Bala AlienDispara(Alien a, char *imagen);

/**
    \brief Detecta la colisión entre un alien y una bala.
    \param alien El alien que queremos comprobar si colisiona con la bala.
    \param bala La bala que queremos comprobar si colisiona con el alien.
    \return 1 Se ha producido una colisión entre el alien y la bala.
    \return 0 No se ha producido la colisión.
*/
int AlienColision(Alien alien, Bala bala);


#endif
