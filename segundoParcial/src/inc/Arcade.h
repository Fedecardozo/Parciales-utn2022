
#ifndef INC_ARCADE_H_
#define INC_ARCADE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN_NACIONALIDAD 20

typedef struct{

	int id;
	char nacionalidad[LEN_NACIONALIDAD];
	int tipoSonido;
	int cantidadJugadores;
	int maximoFichas;
	int fk_Juego;
	int fk_Salon;

}Arcade;

Arcade* Arcade_new();
Arcade* Arcade_newArcade(Arcade a);
Arcade* Arcade_newParametros(int, char*, int, int, int, int, int);

void Arcade_delete(Arcade* this);

int Arcade_setId(Arcade* this,int id);
int Arcade_getId(Arcade* this,int* id);

int Arcade_setNacionalidad(Arcade* this,char* nacion);
int Arcade_getNacionalidad(Arcade* this,char* nacion);

int Arcade_setTipoSonido(Arcade* this,int tipoSonido);
int Arcade_getTipoSonido(Arcade* this,int* tipoSonido);

int Arcade_setJugadores(Arcade* this,int jugadores);
int Arcade_getJugadores(Arcade* this,int* jugadores);

int Arcade_setFichas(Arcade* this,int fichas);
int Arcade_getFichas(Arcade* this,int* fichas);

int Arcade_setFk_juego(Arcade* this,int fk);
int Arcade_getFk_juego(Arcade* this,int* fk);

int Arcade_setFk_salon(Arcade* this,int fk);
int Arcade_getFk_salon(Arcade* this,int* fk);



#endif /* INC_ARCADE_H_ */
