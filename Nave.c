#include "Pantalla.h"
#include "Nave.h"
#include "Bala.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Nave
{
    float x;
    float y;
    Imagen img;
};
Nave NaveCrea(char *imagen)
{
    Nave aux = malloc(sizeof(struct Nave));
    aux->img = Pantalla_ImagenLee(imagen,1);
    aux->x = Pantalla_Anchura()/2-Pantalla_ImagenAnchura(aux->img);
    aux->y = Pantalla_Altura()-Pantalla_ImagenAltura(aux->img);
    return aux;
}

void NaveLibera(Nave n)
{
    Pantalla_ImagenLibera(n->img);
    free(n);
}

void NaveMueve(Nave n, int dx, int vel)
{
    n->x = n->x + vel*dx;
}

void NaveDibuja(Nave n)
{
    Pantalla_DibujaImagen(n->img,n->x, n->y, Pantalla_ImagenAnchura(n->img), Pantalla_ImagenAltura(n->img));
}

Bala NaveDispara(Nave n, char *imagen)
{
    double w = Pantalla_ImagenAnchura(n->img)/2;
    float x = n->x + w;
    float y = n->y;
    return BalaCrea(x, y, -1, imagen);
}

float NaveGetX(Nave n)
{
    return n->x;
}

int NaveColision(Nave n, Bala b)
{
    double w = Pantalla_ImagenAnchura(n->img)/2;
    double h = Pantalla_ImagenAltura(n->img)/2;
    float nx = n->x + w;
    float ny = n->y + h;
    float rn = h;
    float bx = BalaCentroX(b);
    float by = BalaCentroY(b);
    float rb = BalaRadio(b);
    float distancia = sqrt(pow(bx-nx,2)+pow(by-ny,2));
    return (distancia<rn+rb);
}
