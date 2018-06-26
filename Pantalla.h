#ifndef __Pantalla_H__
#define __Pantalla_H__

#include "SDL2/SDL.h"


/**

   \file Pantalla.h
   \brief La biblioteca pantalla es un wrapper de la SDL 2.0. El objetivo es permitir realizar programas interactivos que usan gráficos sin necesidad de conocer los detalles de la programación dirigida por eventos. Evidentemente, utilizando SDL directamente se pueden escribir programas más potentes y eficientes.

 */


/**
    \brief TDA Imagen
 */

typedef struct Imagen *Imagen;

// FUNCIONES BÁSICAS

/**
  \brief Crea y configura una ventana gráfica en donde aparecerá el resultado de las distintas primitivas gráficas que se vayan aplicando.
  \param titulo Título de la ventana.
  \param w Anchura de la ventana en puntos.
  \param h Altura de la vantana en puntos.
 */
void Pantalla_Crea(char *titulo, int w, int h);

/**
  \brief Libera la memoria reservada para la pantalla y sus recursos asociados.
 */
void Pantalla_Libera();

/**
  \brief Recupera la anchura de la pantalla.
  \return La anchura de la pantalla.
*/
int Pantalla_Anchura();

/**
  \brief Recupera la anchura de la pantalla.
  \return La anchura de la pantalla.
*/
int Pantalla_Altura();

/**
  \brief Indica si la pantalla está activa o no. La pantalla deja de estar activa cuando el usuario la cierra.
  \return 1 si la pantalla está activa.
  \return 0 si la pantalla no está activa.
 */
int Pantalla_Activa();

/**
 \brief Detiene la ejecución el número de milisegundos que se desee.
 \param ms Número de milisegundos a detener la ejecución.
*/
void Pantalla_Espera(int ms);

/**
 * \brief Actualiza la ventana mostrando el resultado de las funciones de dibujo que se hayan ejecutado hasta el momento.
 *
 * El esquema básico para hacer una animación consiste pues en lo siguiente:
 * while (Pantalla_Activa()) {
 *     // Modificar el estado de la animación en función de los eventos que se hayan producido usando las funciones tecla_pulsada, raton_pulsado.
 *     // Componer el siguiente frame de la animación usando las funciones de dibujo.
 *     // Mostrar el frame que acabamos de componer usando la función Pantalla_Redibuja.
 *     // Esperar unos milisegundos utilizando la función Pantalla_Espera (50 para conseguir unos 20fps) para que de tiempo al ojo humano a ver lo que ha pasado.
 * }
 */
void Pantalla_Actualiza();



/**
  \brief Indica si una tecla en concreto está pulsada.
  \param keycode Tecla de la que se desea conocer su estado. Los valores correspondientes a cada tecla se pueden encontrar en la documentación de SDL 2.0 (https://wiki.libsdl.org/SDL_Scancode)
  \return 1 si la tecla está pulsada.
  \return 0 si la tecla no está pulsada.
*/
int Pantalla_TeclaPulsada(SDL_Scancode scancode);


/**
  \brief Asigna el color de trazo que se usará al dibujar los bordes de las primitivas de dibujo.
  \param r Componente roja del color (Formato RGB) como un valor entero entre 0 a 255.
  \param g Componente verde del color (Formato RGB) como un valor entero entre 0 a 255.
  \param b Componente azul del color (Formato RGB) como un valor entero entre 0 a 255.
  \param a Compleente de transparencia del color como un valor entero entre 0 y 255 siendo 0 totalmente transparente y 255 totalmente opaco.
*/
void Pantalla_ColorTrazo(int r, int g, int b, int a);

/**
 * \brief Asigna el color de relleno que se usará al dibujar los bordes de las demás primitivas gráficas
  \param r Componente roja del color (Formato RGB) como un valor entero entre 0 a 255.
  \param g Componente verde del color (Formato RGB) como un valor entero entre 0 a 255.
  \param b Componente azul del color (Formato RGB) como un valor entero entre 0 a 255.
  \param a Compleente de transparencia del color como un valor entero entre 0 y 255 siendo 0 totalmente transparente y 255 totalmente opaco.
*/
void Pantalla_ColorRelleno(int r, int g, int b, int a);



/**
  \brief Rellena la ventana con el color indicado borrando todo lo que haya en ese momento.
  \param r Componente roja del color (Formato RGB) como un valor entero entre 0 a 255.
  \param g Componente verde del color (Formato RGB) como un valor entero entre 0 a 255.
  \param b Componente azul del color (Formato RGB) como un valor entero entre 0 a 255.
  \param a Compleente de transparencia del color como un valor entero entre 0 y 255 siendo 0 totalmente transparente y 255 totalmente opaco.
*/
void Pantalla_DibujaRellenoFondo(int r, int g, int b, int a);

/**
  \brief Dibuja un punto utilizando el color de trazo.
  \param x Coordenada horizontal del punto.
  \param y Coordenada vertical del punto.
*/
void Pantalla_DibujaPunto(double x, double y);

/**
  \brief Dibuja una línea utilizando el color de trazo.
  \param x1 Coordenada horizontal de uno de los extremos de la línea.
  \param y1 Coordenada vertical de uno de los extremos de la línea.
  \param x2 Coordenada horizontal de uno del otro extremo de la línea.
  \param y2 Coordenada vertical de uno del extremo de la línea.
*/
void Pantalla_DibujaLinea(double x1, double y1, double x2, double y2);

/**
  \brief Dibuja un triangulo utilizando el color de relleno y el color de trazo para el borde.
  \param x1 Coordenada horizontal de uno de los puntos del triángul.
  \param y1 Coordenada vertical de uno de los puntos del triángulo.
  \param x2 Coordenada horizontal del segundo de los puntos del triángulo.
  \param y2 Coordenada vertical del segundo de los puntos del triángulo.
  \param x3 Coordenada horizontal del tercer de los puntos del triángulo.
  \param y3 Coordenada vertical del tercer de los puntos del triángulo.
*/
void Pantalla_DibujaTriangulo(double x1, double y1, double x2, double y2, double x3, double y3);

/**
  \brief Dibuja un rectángulo utilizando el color de relleno y el color de trazo para el borde.
  \param x Coordenada horizontal de la esquina superior izquierda del rectángulo.
  \param y Coordenada vertical de la esquina superior izquierda del rectángulo.
  \param w Anchura del rectángulo.
  \param h Altura del rectángulo.
*/
void Pantalla_DibujaRectangulo(double x, double y, double w, double h);

/**
  \brief Dibuja un círculo utilizando el color de relleno y el color de trazo para el borde.
  \param x Coordenada horizontal del centro del círculo.
  \param y Coordenada vertical del centro del círculo.
  \param r Radio del círculo.
*/
void Pantalla_DibujaCirculo(double x, double y, double r);

/**
  \brief Muestra (dibuja) una cadena de texto en la ventana gráfica. El texto mostrado usa una fuente de paso fijo de 8 puntos de ancho por 13 de alto.
  \param st Cadena de caracteres terminada en \0 que será mostrada.
  \param x Coordenada horizontal de la esquina superior izquierda del rectángulo que enmarcará el texto.
  \param y Coordenada vertical de la esquina superior izquierda del rectángulo que enmarcará el texto.
*/
void Pantalla_DibujaTexto(char *st, int x, int y);

/**
  \brief Carga en memoria una imagen guardada en un fichero. La imagen debe estar en formato BMP y se debe especificar el path completo incluido el nombre del fichero.
  \param fichero Nombre del fichero de donde leer la imagen.
  \param transparencia Parámetro que indica si la imagen debe considerarse transparente. Cualquier valor distinto de 0 indicará a la función que asuma que el color del pixel situado en las coordenadas 0,0 se debe considerar transparente en toda la imagen.
  \return La imagen cargada.
*/
Imagen Pantalla_ImagenLee(char *fichero, int transparencia);

/**
  \brief Dibuja una imagen previamente cargada en memoria.
  \param imagen La imagen que se dibuja.
  \param x Coordenada horizontal de la esquina superior izquierda del rectángulo que contendrá la imagen.
  \param y Coordenada vertical de la esquina superior izquierda del rectángulo que contendrá la imagen.
  \param w Anchura de la imagen a dibujar (si no coincide con el tamaño original se hará un reescalado).
  \param h Altura de la imagen a dibujar (si no coincide con el tamaño original se hará un reescalado).
*/
void Pantalla_DibujaImagen(Imagen imagen, double x, double y, double ancho, double alto);

/**
 * \brief Recupera la anchura de una imagen.
 * \return La anchura de la imagen.
 */
int Pantalla_ImagenAnchura(Imagen imagen);

/**
 * \brief Recupera la altura de una imagen.
 * \return La altura de la imagen.
 */
int Pantalla_ImagenAltura(Imagen imagen);

/**
 * \brief Libera la memoria reservada para la imagen.
 */
void Pantalla_ImagenLibera(Imagen imagen);

// FUNCIONES AVANZADAS

/**
  \brief Indica si alguno de los botones del ratón está pulsado.
  \param boton El botón del que se desea conocer su estado. Los valores corresponden a una de las tres constantes predefinidas por SDL: SDL_BUTTON_LEFT, SDL_BUTTON_MIDDLE o SDL_BUTTON_RIGHT
  \return 1 si el botón está pulsado.
  \return 0 si el botón no está pulsado.
 */
int Pantalla_RatonBotonPulsado(int boton);

/**
  \brief Recupera las coordenadas del ratón.
  \param x Dirección donde se dejará el valor de la coordenada horizontal del ratón o NULL si no se desea obtener esa coordenada.
  \param y Dirección donde se dejará el valor de la coordenada vertical del ratón o NULL si no se desea obtener esa coordenada.
*/
void Pantalla_RatonCoordenadas(int *x, int *y);

/**
  \brief Carga en memoria una imagen con el contenido de la zona de la pantalla que se desee.
  \param x Coordenada horizontal de la esquina superior izquierda del rectángulo que queremos capturar.
  \param y Coordenada vertical de la esquina superior izquierda del rectángulo que queremos capturar.
  \param w Anchura de la zona a capturar.
  \param h Altura de la zona a capturar.
  \return La imagen capturada.
 */
Imagen Pantalla_ImagenCaptura(int x1, int y1, int w, int h);

/**
  \brief Crea un fichero con el contenido de una imagen.
  \param imagen La imagen.
  \param fichero El nombre del fichero.
  \return 1 si todo fue bien.
  \return 0 si hubo problemas.
*/
int Pantalla_ImagenEscribe(Imagen imagen, char *fichero);

#endif
