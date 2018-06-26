#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "Alienigenas.h"
#include "Alien.h"

struct AlienigenasRep
{
    Alien *a;
    int max, n;
};

Alienigenas AlienigenasCrea(int max)
{
    Alienigenas nuevo = malloc(sizeof(struct AlienigenasRep));
    nuevo->a = malloc(sizeof(Alien) * max);
    nuevo->n = 0;
    nuevo->max = max;
    for (int i = 0; i<max; i++)
    {
        nuevo->a[i] = NULL;
    }
    return nuevo;
}
void AlienigenasLibera (Alienigenas ali)
{
    for (int i = 0; i < ali->max; i++ )
    {
        AlienLibera(ali->a[i]);
    }
    free(ali);
}
void AlienigenasInserta (Alienigenas ali, Alien a, int i)
{
    ali->a[i]=a;
}
void AlienigenasElimina (Alienigenas ali, int n)
{
    ali->a[n]=NULL;
}
void AlienigenasMuestra (Alienigenas ali)
{
    for (int i = 0; i < ali->max; i++)
    {
        if (ali->a[i] != NULL) AlienDibuja(ali->a[i]);
    }
}
void AlienigenasMueve (Alienigenas ali, int vel)
{
        for (int i = 0; i < ali->max; i++)
    {
        if (ali->a[i] != NULL) AlienMueve(ali->a[i], vel);
    }
}
Alien AlienDeAlienigenas (Alienigenas ali, int n)
{
    return ali->a[n];
}
int PosNDeALienigenas (Alienigenas ali)
{
    return ali->n;
}
