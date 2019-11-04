#include "cilindro.h"

Cilindro::Cilindro(int num_instancias, float h, float r, char eje_rotacion, bool tapa_inf, bool tapa_sup){
   altura = h;
   radio = r;
   numVerticesPerfil = 2;

   std::vector<Tupla3f> perfil;
   perfil.resize(numVerticesPerfil);

   switch (toupper(eje_rotacion)){
      case 'X' :
         perfil[0] = {0, radio, 0};
         perfil[1] = {altura, radio, 0};
         break;

      case 'Y' :
         perfil[0] = {radio, 0, 0};
         perfil[1] = {radio, altura, 0};
         break;

      case 'Z' :
         perfil[0] = {0, radio, 0};
         perfil[1] = {0, radio, altura};
         break;
   }

   crearMalla(perfil, num_instancias, tapa_inf, tapa_sup, eje_rotacion);

   // Triángulos modo ajedrez
   f_par.resize(numTriangulos/2);
   f_impar.resize(numTriangulos/2);
   int i_par = 0, i_impar = 0;
   for (int i = 0 ; i < numTriangulos ; i++){
      // Triángulos pares
      if (i % 2 == 0){
         f_par[i_par] = f[i];
         i_par++;
      }
      // Triángulos impares
      else{
         f_impar[i_impar] = f[i];
         i_impar++;
      }
   }

   // Inicializar la tabla de colores inmediato (rojo)
   c.resize(numVertices);
   for (int i = 0 ; i < numVertices ; i++){
      c[i] = {1, 0, 0};
   }

   // Inicializar la tabla de colores diferido (azul)
   c_dif.resize(numVertices);
   for (int i = 0 ; i < numVertices ; i++){
      c_dif[i] = {0, 0, 1};
   }
}
