#include "Pantalla.h"
#include "Bala.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Bala
{
    float x;
    float y;
    float dy;
    Imagen img;
};

Bala BalaCrea(float x, float y, float dy, char *imagen)
{
    Bala aux = malloc(sizeof(struct Bala));
    aux->dy = dy;
    aux->img = Pantalla_ImagenLee(imagen,1);
    aux->x = x - Pantalla_ImagenAnchura(aux->img)/2;
    aux->y = y + dy*BalaRadio(aux)*2;
    return aux;
}

void BalaLibera(Bala b)
{
    Pantalla_ImagenLibera(b->img);
    free(b);
}
void BalaMueve(Bala b, int vel)
{
    b->y = b->y + vel*b->dy;
}

void BalaImprime(Bala b)
{
    Pantalla_DibujaImagen(b->img,b->x, b->y, Pantalla_ImagenAnchura(b->img), Pantalla_ImagenAltura(b->img));
}

float BalaGetX(Bala b)
{
    return b->x;
}

float BalaGetY(Bala b)
{
    return b->y;
}

float BalaCentroX(Bala b)
{
    return b->x + (Pantalla_ImagenAnchura(b->img)/2);
}

float BalaCentroY(Bala b)
{
    return b->y + (Pantalla_ImagenAltura(b->img)/2);
}

float BalaRadio(Bala b)
{
    return Pantalla_ImagenAltura(b->img)/2;
}
