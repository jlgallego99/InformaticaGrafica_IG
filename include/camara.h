// #############################################################################
//
// Informática Gráfica (Grado Informática)
// Archivo: camara.h
// Declaraciones de clase Camara
//
// Jose Luis Gallego Peña
//
// #############################################################################

#ifndef CAMARA_H_INCLUDED
#define CAMARA_H_INCLUDED

#include "aux.h"

typedef enum {
   ORTOGONAL, PERSPECTIVA
} TipoCamara;

typedef enum{
   MOVIENDO_CAMARA_FIRSTPERSON, MOVIENDO_CAMARA_EXAMINAR, QUIETA
} estadoRaton;

class Camara{
private:
   Tupla3f eye;
   Tupla3f at;
   Tupla3f up;

   TipoCamara tipo;  // Ortogonal o Perspectiva
   float left, right, bottom, top, near, far;

public:
   Camara(Tupla3f e, Tupla3f a, Tupla3f u, float l, float r, float b, float t, float n, float f, TipoCamara tip);

   // Mover dónde está la cámara (eye)
   void rotarXExaminar(float angle);
   void rotarYExaminar(float angle);
   void rotarZExaminar(float angle);

   // Mover dirección en la que mira la cámara (at)
   void rotarXFirstPerson(float angle);
   void rotarYFirstPerson(float angle);
   void rotarZFirstPerson(float angle);

   void mover(float x, float y, float z);
   void zoom(float factor);
   void girar(float x, float y);

   void setObserver();
   void setProyeccion();
};

#endif