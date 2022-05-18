
#ifndef ARRAYUSUARIO_H_
#define ARRAYUSUARIO_H_

#include "utn.h"
#include "funcionesPropias.h"
#include <stdio.h>
#include <stdlib.h>

#define BAJA 2
#define LIBRE 1
#define OCUPADO 0

//TIPOS
#define USUARIO 1
#define ADMIN 2

#define MAX_CORREO 25
#define MIN_PASSWORD 4
#define MAX_PASSWORD 10
#define MAX_DIRECCION 50

typedef struct{

	int idUsuario;
	short int isEmpty; //Libre - ocupado - pausado

	//AGREGAR RELACION
	short int tipo; //Admin - usuario
	char correo[MAX_CORREO]; //validado
	char password[MAX_PASSWORD]; //minimo 4 alfanumerico sin signo
	char direccion[MAX_DIRECCION]; //domicilio
	int codigoPostal;

}Usuario;

/** INICIO CABECERAS DE FUNCION*/
int eUsuario_Inicializar(Usuario *list, int len);
int eUsuario_ObtenerIndexLibre(Usuario *list, int len);
int eUsuario_BuscarPorid(Usuario *list, int len, int id);
int eUsuario_Registrarse(Usuario * list);
int eUsuario_InicioSesion(Usuario * list,int len);
void eUsuario_MostrarUno(Usuario list);
int eUsuario_MostrarTodos(Usuario *list, int len);
int eUsuario_MostrarDadosDeBaja(Usuario *list, int len);

//ABM
int eUsuario_CargarDatos(Usuario * list,int len);
int eUsuario_ModificarUno(Usuario *list,int len,int id);
int eUsuario_Alta(Usuario *list, int len,Usuario usuarioDarAlta);
int eUsuario_Baja(Usuario *list, int len);
int eUsuario_Modificacion(Usuario *list, int len);
int eUsuario_remove(Usuario* list, int len);

#endif /* ARRAYUSUARIO_H_ */
