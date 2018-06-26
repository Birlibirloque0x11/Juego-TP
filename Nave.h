#ifndef __Nave_H__
#define __Nave_H__

#include "Bala.h"

/**
    \file NAve.h
    \brief La biblioteca Nave permite la realización de programas que requieren el uso de personajes que se mueven horizontaalmente y disparan balas.
*/
/**
    \brief TDA Nave
*/
typedef struct Nave *Nave;

// FUNCIONES

/**
    \brief Crea y reserva espacio para una nave. La nave se crea centrada en la parte inferior de la pantalla.
    \param imagen La dirección relativa de la imagen que se desea usar.
    \return La nave que ha sido creada.
*/
Nave NaveCrea(char *imagen);

/**
    \brief Libera la memoria reservada para la nave y todas sus dependencias.
    \param n La nave cuya memoria se desea liberar.
*/
void NaveLibera(Nave n);

/**
    \brief Mueve una nave en la dirección y con la velocidad que se especifica.
    \param n La nave que se desea mover.
    \param dx La dirección en la que se desea mover. (1: derecha -1: izquierda).
    \param vel La velocidad con la que desea mover en pixeles/ejecución.
*/
void NaveMueve(Nave n, int dx, int vel);

/**
    \brief Imprime una nave en su posición de la pantalla.
    \param n La nave que se desea imprimir.
*/
void NaveDibuja(Nave n);

/**
    \brief Crea la bala que es disparada por la bala.
    \param n La nave que dispara la bala.
    \param imagen La dirección relativa de la imagen que se desea usar como bala.
    \return La bala que la bala ha disparado.
*/
Bala NaveDispara(Nave n, char *imagen);

/**
    \brief Calcula la posición x de la nave
    \param n La nave de la que queremos calcular la posición.
    \return La posición x de la nave.
*/
float NaveGetX(Nave n);

/**
    \brief Detecta la colisión entre una nave y una bala.
    \param n La nave que queremos comprobar si colisiona con la bala.
    \param b La bala que queremos comprobar si colisiona con la nave.
    \return 1 Se ha producido una colisión entre la nave y la bala.
    \return 0 No se ha producido la colisión.
*/
int NaveColision(Nave n, Bala b);


#endif
