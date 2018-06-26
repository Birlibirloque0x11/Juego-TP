#include "Pantalla.h"
#include "Rafaga.h"
#include "Bala.h"
#include "Alien.h"
#include "Nave.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


struct Rafaga
{
    Bala bala;
    Rafaga sig;
};

Rafaga RafagaCrea()
{
    Rafaga aux = malloc(sizeof(struct Rafaga));
    aux->bala = NULL;
    aux->sig = NULL;
    return aux;
}

void RafagaLibera(Rafaga r)
{
    while (r->sig != NULL)
    {
        Rafaga borra = r->sig;
        r->sig = r->sig->sig;
        BalaLibera(borra->bala);
        free(borra);
    }
    free(r);
}

void RafagaInserta(Rafaga r, Bala b)
{
    Rafaga nueva = malloc(sizeof(struct Rafaga));
    nueva->bala = b;
    nueva->sig = r->sig;
    r->sig = nueva;
}

void RafagaMuestra(Rafaga r)
{
    while(r->sig!=NULL)
    {
        BalaImprime(r->sig->bala);
        r = r->sig;
    }
}

void RafagaMueve(Rafaga r, int vel)
{
    Rafaga aux = r;
    while(aux->sig!=NULL)
    {
        if ((BalaGetY(aux->sig->bala)>=Pantalla_Altura())||(BalaGetY(aux->sig->bala)<=10))
        {
            Rafaga borra = aux->sig;
            aux->sig = aux->sig->sig;
            BalaLibera(borra->bala);
            free(borra);
        }
        else
        {
            BalaMueve(aux->sig->bala, vel);
            aux = aux->sig;
        }
    }
}

int RafagaChoqueAlien(Rafaga r, Alien a)
{
    Rafaga aux = r;
    while(aux->sig!=NULL)
    {
        if (AlienColision(a, aux->sig->bala))
        {
            BalaLibera(aux->sig->bala);
            Rafaga borra = aux->sig;
            aux->sig = aux->sig->sig;
            free(borra);
            return 1;
        }
        else
        {
            aux = aux->sig;
        }
    }
    return 0;
}

int RafagaChoqueNave(Rafaga r, Nave n)
{
    Rafaga aux = r;
    while(aux->sig!=NULL)
    {
        if (NaveColision(n, aux->sig->bala))
        {
            BalaLibera(aux->sig->bala);
            Rafaga borra = aux->sig;
            aux->sig = aux->sig->sig;
            free(borra);
            return 1;
        }
        else
        {
            aux = aux->sig;
        }
    }
    return 0;
}
