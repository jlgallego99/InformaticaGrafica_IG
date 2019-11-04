// #############################################################################
//
// Informática Gráfica (Grado Informática)
//
// Archivo: objrevolucion.h
//
// Jose Luis Gallego Peña
//
// #############################################################################

#ifndef OBJREVOLUCION_H_INCLUDED
#define OBJREVOLUCION_H_INCLUDED

#include "aux.h"
#include "malla.h"
#include "ply_reader.h"

class ObjRevolucion : public Malla3D{
public:
   // Constructores
   ObjRevolucion();
   ObjRevolucion(const std::string & archivo, int num_instancias, bool tapa_inf=true, bool tapa_sup=true, char eje_rotacion='Y');
   ObjRevolucion(std::vector<Tupla3f> perfil, int num_instancias, bool tapa_inf=true, bool tapa_sup=true, char eje_rotacion='Y');

   // Crear las tapas del objeto de revolución
   void crearTapaInf(char eje_rotacion);
   void crearTapaSup(char eje_rotacion);
   // Eliminar las tapas del objeto de revolución
   void eliminarTapas();

   char eje;               // Eje por el cual está rotado el objeto

protected:
   // Crea la malla del objeto de revolución con NM vértices
   void crearMalla(std::vector<Tupla3f> perfil, int num_instancias, bool tapa_inf, bool tapa_sup, char eje_rotacion);

   int numInstancias;      // Número total de réplicas rotadas (N)
   int numVerticesPerfil;  // Número total de vértices en el perfil original (M)
   int numVertices;        // Número total de vértices de la figura (NM)
   int numTriangulos;      // Número total de triángulos de la figura
   bool tapaSup;           // El objeto tiene tapa superior
   bool tapaInf;           // El objeto tiene tapa inferior

	const float PI = atan(1)*4.0;	// Número pi
};

#endif
