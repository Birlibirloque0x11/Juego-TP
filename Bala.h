#ifndef __Bala_H__
#define __Bala_H__

/**
    \file Bala.h
    \brief La biblioteca Bala permite la realización de programas que requieren el uso de balas que se mueven verticalmente.
*/

/**
    \brief TDA Bala
*/
typedef struct Bala *Bala;

// FUNCIONES

/**
    \brief Crea y reserva espacio para una bala en la posición y con la dirección que se especifica.
    \param x La posición x desde donde se desea disparar la bala.
    \param y La posición y desde donde se desea disparar la bala.
    \param dy La dirección vertical en la bala se moverá posteriormente.
    \param imagen La dirección relativa de la imagen que se desea usar.
    \return La bala que ha sido creada.
*/
Bala BalaCrea(float x, float y, float dy, char *imagen);

/**
    \brief Libera la memoria reservada para la bala y todas sus dependencias.
    \param b La bala cuya memoria se desea liberar.
*/
void BalaLibera(Bala b);

/**
    \brief Mueve una bala con la velocidad que se especifica en la dirección que lleva la bala.
    \param b La bala que se desea mover.
    \param vel La velocidad con la que desea mover en pixeles/ejecución.
*/
void BalaMueve(Bala b, int vel);

/**
    \brief Imprime una bala en su posición de la pantalla.
    \param b La bala que se desea imprimir.
*/
void BalaImprime(Bala b);

/**
    \brief Calcula la posición x de la bala.
    \param b La bala de la que se desea obtener la posición.
    \return La posición x de la bala.
*/
float BalaGetX(Bala b);

/**
    \brief Calcula la posición y de la bala.
    \param b La bala de la que se desea obtener la posición.
    \return La posición y de la bala.
*/
float BalaGetY(Bala b);

/**
    \brief Calcula la posición x del centro de la bala.
    \param b La bala de la que se desea obtener la posición.
    \return La posición x del centro de la bala.
*/
float BalaCentroX(Bala b);

/**
    \brief Calcula la posición y del centro de la bala.
    \param b La bala de la que se desea obtener la posición.
    \return La posición y del centro de la bala.
*/
float BalaCentroY(Bala b);

/**
    \brief Calcula el radio de la circunferencia inscrita a la imagen de la bala.
    \param b La bala de la que se desea obtener el radio.
    \return El radio de la circunferencia inscrita a la imagen de la bala.
*/
float BalaRadio(Bala b);

#endif
