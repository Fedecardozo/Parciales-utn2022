
#ifndef ARRAYTRACKING_H_
#define ARRAYTRACKING_H_

#include "RelacionProductosUsuarios.h"
#include <time.h>


#define VACIO 0
#define EN_VIAJE 1
#define ENTREGADO 2
#define CANCELADO 3

typedef struct{

	int idTracking;
	int idProducto;
	short int isEmpty;

	//AGREGAR RELACION
	int Fk_UsuarioComprador;
	int Fk_UsuarioVendedor;

	int cantidad;
	int distanciaKM;
	long int horaLlegada;



}Tracking;

long int time_Current(void);
long int time_Add(double secondsAdd);

//GENERLES
int eTracking_Inicializar(Tracking *list, int len);
int eTracking_ObtenerIndexLibre(Tracking* list, int len);
int eTracking_BuscarPorid(Tracking *list, int len, int id);
void eTracking_MostrarUno(Tracking list);
int eTracking_MostrarTodos(Tracking * list,int len);

//IMPRIMIR POR PANTALLA
void eTracking_Estado(Tracking list,Producto listProducto);

//HARCODEO
void harcodeoTracking(Tracking * listTracking,int lenTracking , Producto* listProducto, int lenProducto);

//VENTAS
int eTracking_MostrarProductosUsuarioEstado(Tracking *list, int len,Usuario* arrayUsuario,
		int indiceUsuario,int estado,Producto * listProducto, int lenProducto);

//COMPRAS
int eTracking_MostrarProductosUsuario(Tracking *list, int len,Usuario* arrayUsuario,
		int indiceUsuario,Producto * listProducto, int lenProducto);
int eTracking_ConsultaEstado(Tracking* listTracking,int lenTracking, Usuario * listUsuario,
		int indiceUsuario, Producto*listProducto, int lenProducto);


//ABM
int eTracking_CargarDatos(Tracking * listTracking,int lenTracking,Producto* arrayProducto,
		int indiceProducto,Usuario *listUsuario, int indiceUsuario,int cantidad);
int eTracking_Alta(Tracking* listTracking,int lenTracking,Tracking aDarseAlta);
int eTracking_ModificarEstado(Tracking* listTracking,int indice,int estado);

#endif /* ARRAYTRACKING_H_ */
