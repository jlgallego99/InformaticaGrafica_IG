#include "cono.h"

Cono::Cono(float h, float r, int num_instancias, char eje_rotacion){
   altura = h;
   radio = r;
   numVerticesPerfil = 2;

   std::vector<Tupla3f> perfil;
   perfil.resize(numVerticesPerfil);

   switch (toupper(eje_rotacion)){
      case 'X' :
         perfil[0] = {0, radio, 0};
         perfil[1] = {altura, 0, 0};
         break;

      case 'Y' :
         perfil[0] = {radio, 0, 0};
         perfil[1] = {0, altura, 0};
         break;

      case 'Z' :
         perfil[0] = {0, radio, 0};
         perfil[1] = {0, 0, altura};
         break;
   }

   crearMalla(perfil, num_instancias, tapaInf, tapaSup, eje_rotacion);

   // Triángulos modo ajedrez
   calcularModoAjedrez();

   // Colores
   calcularColores(VERDE, PUNTOS);
   calcularColores(AMARILLO, LINEAS);
   calcularColores(ROJO, SOLIDO);
   calcularColores(AZUL, DIFERIDO);
   calcularColores(AMARILLO, SELECCIONADO);

   // Material
   Material mat(obsidiana[0], obsidiana[1], obsidiana[2], obsidiana_brillo);
   setMaterial(mat);
   Material mat2(amarillo[0], amarillo[1], amarillo[2], amarillo_brillo);
   setMaterialSeleccionado(mat2);
}
