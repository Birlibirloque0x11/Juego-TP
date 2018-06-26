#include "Pantalla.h"
#include "Alien.h"
#include "Bala.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


struct Alien
{
    float x;
    float y;
    float dx;
    float dy;
    Imagen img;
};

Alien AlienCrea(char *imagen)
{
    Alien aux = malloc(sizeof(struct Alien));
    aux->img = Pantalla_ImagenLee(imagen,1);

    if ((rand()%10)<5) aux->dx = -1;
    else aux->dx = 1;

    if ((rand()%10)<5) aux->dy = -1;
    else aux->dy = 1;

    aux->x = rand()%(Pantalla_Anchura()-Pantalla_ImagenAnchura(aux->img));
    aux->y = rand()%(Pantalla_Altura()-2*Pantalla_ImagenAltura(aux->img));
    return aux;
}

void AlienLibera(Alien a)
{
    Pantalla_ImagenLibera(a->img);
    free(a);
}

void AlienMueve(Alien a, int vel)
{
    if ((a->x<=0)||(a->x>=Pantalla_Anchura()-Pantalla_ImagenAnchura(a->img)))
    {
        a->dx = a->dx - 2*a->dx;
    }
    if ((a->y<=0)||(a->y>=Pantalla_Altura()-2*Pantalla_ImagenAltura(a->img)))
    {
        a->dy = a->dy - 2*a->dy;
    }

    a->x = a->x + vel*a->dx;
    a->y = a->y + vel*a->dy;
}

void AlienDibuja(Alien a)
{
    Pantalla_DibujaImagen(a->img,a->x, a->y, Pantalla_ImagenAnchura(a->img), Pantalla_ImagenAltura(a->img));
}

Bala AlienDispara(Alien a, char *imagen)
{
    float x = a->x + Pantalla_ImagenAnchura(a->img)/2;
    float y = a->y + Pantalla_ImagenAltura(a->img);
    return BalaCrea(x, y, 1, imagen);
}



int AlienColision(Alien a, Bala b)
{
    double w = Pantalla_ImagenAnchura(a->img)/2;
    double h = Pantalla_ImagenAltura(a->img)/2;
    float ax = a->x + w;
    float ay = a->y + h;
    float ra = h;
    float bx = BalaCentroX(b);
    float by = BalaCentroY(b);
    float rb = BalaRadio(b);
    float distancia = sqrt(pow(bx-ax,2)+pow(by-ay,2));
    return (distancia<=(ra+rb));
}
