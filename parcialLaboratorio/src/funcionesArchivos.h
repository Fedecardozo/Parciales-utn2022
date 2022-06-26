
#ifndef FUNCIONESARCHIVOS_H_
#define FUNCIONESARCHIVOS_H_

#include "arrayProducto.h"

Producto guardarUnProducto(char* var,char* var1,char* var2,char* var3,char* var4,char* var5,char* var6);
void imprimirUno(Producto auxProducto);
int printArrayProducto(Producto* list,int len);
int llenarArray(FILE* archivo,Producto* list);

#endif /* FUNCIONESARCHIVOS_H_ */
