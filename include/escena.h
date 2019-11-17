#ifndef _ESCENA_H
#define _ESCENA_H

#include "ejes.h"
#include "malla.h"
#include "cubo.h"
#include "tetraedro.h"
#include "objply.h"
#include "cilindro.h"
#include "cono.h"
#include "esfera.h"
#include "luz.h"
#include "luzdireccional.h"
#include "luzposicional.h"

typedef enum{
   MENUPRINCIPAL, NADA, SELOBJETO, SELVISUALIZACION, SELDIBUJADO, ILUMINACION
} menu;

typedef enum{
   CUBO, TETRAEDRO, PEON, HORMIGA, CILINDRO, CONO, ESFERA
} objetoEscena;

class Escena{
private:
   // ** PARÁMETROS DE LA CÁMARA (PROVISIONAL)

   // variables que definen la posicion de la camara en coordenadas polares
   GLfloat Observer_distance;
   GLfloat Observer_angle_x;
   GLfloat Observer_angle_y;

   // variables que controlan la ventana y la transformacion de perspectiva
   GLfloat Width, Height, Front_plane, Back_plane;

   // Transformación de cámara
	void change_projection(const float ratio_xy);
	void change_observer();

   void clear_window();

   // Opciones de menú
   menu modoMenu = NADA;               // Menú principal por defecto
   dibujado modoDibujado = INMEDIATO;  // Modo de dibujado inmediato por defecto

   // Objetos de la escena (importante inicializarlos a nullptr)
   Ejes ejes;
   Cubo * cubo           = nullptr;
   Tetraedro * tetraedro = nullptr;
   ObjRevolucion * peon  = nullptr;
   ObjPLY * hormiga      = nullptr;
   Cilindro * cilindro   = nullptr;
   Cono * cono           = nullptr;
   Esfera * esfera       = nullptr;

   // Luces de la escena
   LuzPosicional * luzposicional   = nullptr;
   LuzDireccional * luzdireccional = nullptr;

   // Controlan la visibilidad de los distintos objetos
   bool cuboVisible      = true;
   bool tetraedroVisible = true;
   bool peonVisible      = true;
   bool hormigaVisible   = true;
   bool cilindroVisible  = true;
   bool conoVisible      = true;
   bool esferaVisible    = true;

   // Controlan la visibilidad de los distintos modos
   bool puntosVisible    = false;
   bool lineasVisible    = false;
   bool solidoVisible    = true;
   bool ajedrezVisible   = false;   // Si ajedrez visible, los otros modos invisibles
   bool tapasVisible     = true;

   bool modoIluminacion  = true;    // Modo iluminación: SMOOTH o FLAT
   bool iluminado        = false;   // Luces encendidas

   // Controlan qué ángulo de iluminación aumentar o decrementar
   bool anguloAlpha      = false;
   bool anguloBeta       = false;

public:
   Escena();
   ~Escena();
	void inicializar(int UI_window_width, int UI_window_height);
   void redimensionar(int newWidth, int newHeight);

	// Dibujar
   void eligeObjetos(dibujado modoDibuj, objetoEscena obj);
   void dibujaObjetos(dibujado modoDibuj, objetoEscena obj);
   void eliminaTapas();
   void dibujaTapas();
	void dibujar();

	// Interacción con la escena
	bool teclaPulsada(unsigned char Tecla1, int x, int y);
	void teclaEspecial(int Tecla1, int x, int y);
};

#endif
