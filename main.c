#include "Pantalla.h"
#include "Alien.h"
#include "Nave.h"
#include "Bala.h"
#include "Rafaga.h"
#include "Alienigenas.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
    \mainpage
    \file main.c
    \brief Archivo donde se ejecutara las funciones donde usamos lo ya creado en los TDA.
*/

#define MAX_ALIENS 5

int main(int argc, char *argv[])
{
    srand(time(NULL));
    Pantalla_Crea("Ventana", 1366, 768);
    Imagen fondo = Pantalla_ImagenLee("imagenes/escenario.bmp",0);
    Imagen menu = Pantalla_ImagenLee("imagenes/controles.bmp",0);
    Imagen gameover = Pantalla_ImagenLee("imagenes/gameover.bmp",0);
    Imagen kokoro = Pantalla_ImagenLee("imagenes/kokoro.bmp",1);
    Alienigenas listaAlien=AlienigenasCrea(MAX_ALIENS);
    Alien aliencomun=AlienCrea("imagenes/enemigo2.bmp");
    AlienigenasInserta(listaAlien, aliencomun, 0);
    int aliens = 1;
    Nave nave = NaveCrea("imagenes/C.bmp");
    Rafaga BalasNave = RafagaCrea();
    Rafaga BalasAliens = RafagaCrea();
    Alien superAlien = AlienCrea("imagenes/enemigo.bmp");
    int teclpulsada = 0;
    int muerto = 0;
    int terminar = 1;
    int salud = 10;
    int saludSAlien = 100;
    int aliensmuertos =1;
    int archivo=0;
    char puntuacionCadena[25];



    while (Pantalla_Activa() && terminar)
    {

        Pantalla_DibujaImagen(menu,0,0,Pantalla_ImagenAnchura(menu),Pantalla_ImagenAltura(menu));
        if (Pantalla_TeclaPulsada(SDL_SCANCODE_RETURN))
        {
            terminar=0;
        }
        Pantalla_Espera(250);
        Pantalla_Actualiza();
    }

    while (Pantalla_Activa() && !terminar)
    {

        // Pantalla derrota
        if (muerto)
        {

            Pantalla_DibujaImagen(gameover,0,0,Pantalla_ImagenAnchura(gameover),Pantalla_ImagenAltura(gameover));
            Pantalla_ColorTrazo(255,255,255,255);
            Pantalla_DibujaTexto(puntuacionCadena,Pantalla_Anchura()/2-100,Pantalla_Altura()/2-20);
        }
        // Juego
        else

        {
            // Mover la nave a la izquierda
            if (Pantalla_TeclaPulsada(SDL_SCANCODE_LEFT))
            {
                // Detecta que puede moverse hacia la izquierda y se mueve
                if (NaveGetX(nave)>0) NaveMueve(nave, -1, 20);
            }
            // Mover la nave a la derecha
            if (Pantalla_TeclaPulsada(SDL_SCANCODE_RIGHT))
            {
                // Detecta que puede moverse a la derecha y se mueve
                if (NaveGetX(nave)<Pantalla_Anchura()-40) NaveMueve(nave, 1, 20);
            }
            // Hacer que la nave dispare
            if ((Pantalla_TeclaPulsada(SDL_SCANCODE_SPACE)==1)&&(teclpulsada==0))
            {
                RafagaInserta(BalasNave, NaveDispara(nave, "imagenes/disparo.bmp"));
                teclpulsada = 1;
            }
            if (Pantalla_TeclaPulsada(SDL_SCANCODE_SPACE)==0)
            {
                teclpulsada=0;
            }

            // Mostrar en pantalla
            // Fondo
            Pantalla_DibujaImagen(fondo, 0, 0, Pantalla_ImagenAnchura(fondo), Pantalla_ImagenAltura(fondo));
            // Aliens
            // Nivel final
            if ((aliensmuertos%50)==0)
            {
                AlienMueve(superAlien, 25);
                AlienDibuja(superAlien);
                if (rand()%10==1)
                {
                    RafagaInserta(BalasAliens, AlienDispara(superAlien, "imagenes/disparo.bmp"));
                }
                if (RafagaChoqueAlien(BalasNave, superAlien)) saludSAlien -= 10;
                // Mostrar vida alien final
                Pantalla_ColorRelleno(0,0,255,255);
                Pantalla_ColorTrazo(255,255,255,255);
                Pantalla_DibujaRectangulo(Pantalla_Anchura()-113,3,100*saludSAlien/100,10);
                if (saludSAlien <= 0) aliensmuertos += 5 ;
            }
            // Nivel inicial
            else
            {
                for (int i=0 ; i<aliens; i++)
                {
                    if (rand()%60==1)
                    {
                        RafagaInserta(BalasAliens, AlienDispara(AlienDeAlienigenas(listaAlien,i), "imagenes/disparo.bmp"));
                    }

                    if (RafagaChoqueAlien(BalasNave, AlienDeAlienigenas(listaAlien,i)))
                    {
                        AlienigenasElimina (listaAlien,i);

                        if (aliens<MAX_ALIENS)
                        {
                            AlienigenasInserta(listaAlien, AlienCrea("imagenes/enemigo2.bmp"), i);
                            AlienigenasInserta(listaAlien, AlienCrea("imagenes/enemigo2.bmp"), aliens);
                            aliens++;
                        }else AlienigenasInserta(listaAlien, AlienCrea("imagenes/enemigo2.bmp"), i);
                        aliensmuertos++;
                    }
                    AlienigenasMueve(listaAlien , 15);
                    AlienigenasMuestra(listaAlien);
                }
            }
            // Rafagas
            RafagaMuestra(BalasAliens);
            RafagaMueve(BalasAliens, 15);
            RafagaMuestra(BalasNave);
            RafagaMueve(BalasNave, 15);
            // Nave
            NaveDibuja(nave);
            // Reducir vida nave
            if (RafagaChoqueNave(BalasAliens, nave))
            {
                salud -= 1;

            }
            // Mostrar vida
            float xko=0;
            for(int i=0; i<salud; i++)
            {
                Pantalla_DibujaImagen(kokoro,xko,0,Pantalla_ImagenAnchura(kokoro),Pantalla_ImagenAltura(kokoro));
                xko += Pantalla_ImagenAnchura(kokoro);
            }
            // Mostrar puntuación
            sprintf(puntuacionCadena, "Burbujas destruidas: %d", aliensmuertos);
            Pantalla_ColorTrazo(255,255,255,255);
            Pantalla_DibujaTexto(puntuacionCadena,0,Pantalla_ImagenAltura(kokoro));
            // DEAD!!
            if (salud <= 0) muerto = 1;

        }
        // Salir del juego
        if (Pantalla_TeclaPulsada(SDL_SCANCODE_Q)==1) terminar = 1;
        Pantalla_Actualiza();
        Pantalla_Espera(50);
    }
    // Liberacion
    for (int i=0 ; i<aliens; i++) AlienLibera(AlienDeAlienigenas(listaAlien,i));
     AlienLibera(superAlien);
    RafagaLibera(BalasAliens);
    RafagaLibera(BalasNave);
    NaveLibera(nave);
    Pantalla_ImagenLibera(fondo);
    Pantalla_ImagenLibera(menu);
    Pantalla_ImagenLibera(gameover);
    Pantalla_ImagenLibera(kokoro);
    Pantalla_Libera();


    FILE * f=fopen("puntuacion.txt", "r");
    if (f!=NULL)
    {
        fscanf(f, "%d", &archivo);
        fclose(f);
    }
    if (aliensmuertos>archivo)
    {
        FILE * f = fopen("puntuacion.txt", "w");
        fprintf(f, "%d", aliensmuertos);
        fclose(f);
    }
    return 0;
}
