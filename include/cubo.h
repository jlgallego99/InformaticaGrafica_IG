// #############################################################################
//
// Informática Gráfica (Grado Informática)
// Archivo: cubo.h
//
// Jose Luis Gallego Peña
//
// #############################################################################

#ifndef CUBO_H_INCLUDED
#define CUBO_H_INCLUDED

#include "aux.h"
#include "malla.h"

// *****************************************************************************
//
// clases derivadas de Malla3D (definen constructores específicos)
//
// *****************************************************************************

// *****************************************************************************
// Cubo con centro en el origen y lado unidad por defecto
// (tiene 8 vertices y 6 caras)

class Cubo : public Malla3D{
public:
   Cubo(float lado = 1);

private:
   static const int numVertices   = 8;
   static const int numTriangulos = 12;
};

#endif
