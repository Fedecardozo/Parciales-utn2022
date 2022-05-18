
#ifndef ARRAYPRODUCTO_H_
#define ARRAYPRODUCTO_H_

#include "utn.h"
#include "funcionesPropias.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_NOMBRE 20
#define TAM_CATEGORIA 4

#define LIBRE 1
#define OCUPADO 0
#define BAJA 2
#define SIN_STOCK -1

typedef struct{

	int id;
	short int isEmpty;

	//RELACION
	int Fk_idUsuario;

	char nombreProducto[MAX_NOMBRE];
	float precio;
	short int categoria; //Ej moda,tecnologia....
	int stock; // cantidad de productos a vender


}Producto;

/** INICIO CABECERAS DE FUNCION GENERALES*/
int eProducto_Inicializar(Producto *list, int len);
int eProducto_ObtenerIndexLibre(Producto *list, int len);
int eProducto_BuscarPorid(Producto *list, int len, int id);
int eProducto_PediUnDato(Producto * list);
void eProducto_MostrarUno(Producto list);
int eProducto_MostrarTodos(Producto *list, int len);

//FK USUARIO
int eProducto_MostrarFk(Producto *list, int len,int fk);
int eProducto_print_listProductosOrdenados(Producto* arrayProducto, int lenProducto);
int eProducto_compra(Producto* arrayProducto, int lenProducto,int* cantidad);
int eProducto_BuscarPorid_FK(Producto *list, int len, int id,int fk);
int eProducto_PrintOrdenCategoria_Nombre(Producto *list, int len,int orden);

//SORT
int eProducto_Sort(Producto *list, int len, int criterio);

//ABM
int eProducto_CargarDatos(Producto * list,int len);
int eProducto_ModificarUno(Producto *list,int len,int id);
int eProducto_Alta(Producto *list, int len,Producto productoDarAlta);
int eProducto_Baja(Producto *list, int len,int id);
int eProducto_ModificacionStock(Producto * list,int len,int id,int stock,int sumaOresta);
int eProducto_remove(Producto* list, int len);


int eProductoFiltroNombre(Producto *list, int len);
int eProducto_SortStock(Producto *list, int len, int criterio);

#endif /* ARRAYPRODUCTO_H_ */
