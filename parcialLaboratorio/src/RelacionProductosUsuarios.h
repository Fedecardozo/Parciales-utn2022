

#ifndef RELACIONPRODUCTOSUSUARIOS_H_
#define RELACIONPRODUCTOSUSUARIOS_H_

#include "arrayProducto.h"
#include "arrayUsuario.h"

int alta_Producto(Producto* arrayProducto, int lenProducto,Usuario * arrayUsuario,int indiceUsuario);
int print_ProductosdelUsuario(Producto* arrayProducto, int lenProducto,Usuario * arrayUsuario,int indiceUsuario);
int reponerStock(Producto* arrayProducto, int lenProducto,Usuario * arrayUsuario,int indiceUsuario);

void harcodeo(Producto * listP,int lenP,Usuario * listU,int lenU);

#endif /* RELACIONPRODUCTOSUSUARIOS_H_ */
