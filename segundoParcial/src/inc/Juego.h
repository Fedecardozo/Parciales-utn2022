
#ifndef INC_JUEGO_H_
#define INC_JUEGO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define JUE_LEN_NAME 50
#define JUE_LEN_EMPRESA 50

typedef struct{

	int id;
	char name[JUE_LEN_NAME];
	char empresa[JUE_LEN_EMPRESA];
	int genero;

}Juego;

Juego* Juego_new();
Juego* Juego_newJuego(Juego s);
Juego* Juego_newParametros(int, char*, char*, int);

void Juego_delete(Juego* this);

int Juego_setId(Juego* this,int id);
int Juego_getId(Juego* this,int* id);

int Juego_setName(Juego* this,char* name);
int Juego_getName(Juego* this,char* name);

int Juego_setEmpresa(Juego* this,char* empresa);
int Juego_getEmpresa(Juego* this,char* empresa);

int Juego_setGenero(Juego* this,int genero);
int Juego_getGenero(Juego* this,int* genero);

#endif /* INC_JUEGO_H_ */
