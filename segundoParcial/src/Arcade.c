
#include "./inc/Arcade.h"

Arcade* Arcade_new()
{
	return (Arcade*)malloc(sizeof(Arcade));
}

Arcade* Arcade_newArcade(Arcade a)
{
	return Arcade_newParametros(a.id,a.nacionalidad,a.tipoSonido,a.cantidadJugadores,a.maximoFichas,a.fk_Juego,a.fk_Salon);
}

Arcade* Arcade_newParametros(int id, char* nacion, int tipoSonido, int cantJugadores, int fichas, int fk_Juego, int fk_Salon)
{
	Arcade* aux = Arcade_new();

	if(aux != NULL)
	{
		Arcade_setId(aux, id);
		Arcade_setNacionalidad(aux, nacion);
		Arcade_setJugadores(aux, cantJugadores);
		Arcade_setTipoSonido(aux, tipoSonido);
		Arcade_setFichas(aux, fichas);
		Arcade_setFk_juego(aux, fk_Juego);
		Arcade_setFk_salon(aux, fk_Salon);
	}

	return aux;

}

void Arcade_delete(Arcade* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

int Arcade_setId(Arcade* this,int id)
{
	int retorno =-1;

	if(this != NULL)
	{
		retorno = 0;
		this->id= id;

	}

	return retorno;
}

int Arcade_getId(Arcade* this,int* id)
{
	int retorno =-1;

	if(this != NULL && id != NULL)
	{
		retorno=0;
		*id=this->id;
	}

	return retorno;
}

int Arcade_setNacionalidad(Arcade* this,char* nacion)
{
	int retorno =-1;

	if(this != NULL && nacion != NULL)
	{
		retorno = 0;
		strncpy(this->nacionalidad,nacion,LEN_NACIONALIDAD);
	}

	return retorno;
}

int Arcade_getNacionalidad(Arcade* this,char* nacion)
{
	int retorno =-1;

	if(this != NULL && nacion != NULL)
	{
		retorno = 0;
		strncpy(nacion,this->nacionalidad,LEN_NACIONALIDAD);
	}

	return retorno;
}

int Arcade_setTipoSonido(Arcade* this,int tipoSonido)
{
	int retorno =-1;

	if(this != NULL && tipoSonido>=0)
	{
		retorno = 0;
		this->tipoSonido= tipoSonido;

	}

	return retorno;
}

int Arcade_getTipoSonido(Arcade* this,int* tipoSonido)
{
	int retorno =-1;

	if(this != NULL && tipoSonido != NULL)
	{
		retorno = 0;
		*tipoSonido = this->tipoSonido;

	}

	return retorno;
}

int Arcade_setJugadores(Arcade* this,int jugadores)
{
	int retorno =-1;

	if(this != NULL && jugadores>=0)
	{
		retorno = 0;
		this->cantidadJugadores= jugadores;

	}

	return retorno;
}

int Arcade_getJugadores(Arcade* this,int* jugadores)
{
	int retorno =-1;

	if(this != NULL && jugadores != NULL)
	{
		retorno = 0;
		*jugadores = this->cantidadJugadores;

	}

	return retorno;
}

int Arcade_setFichas(Arcade* this,int fichas)
{
	int retorno =-1;

	if(this != NULL && fichas>=1)
	{
		retorno = 0;
		this->maximoFichas= fichas;

	}

	return retorno;
}

int Arcade_getFichas(Arcade* this,int* fichas)
{
	int retorno =-1;

	if(this != NULL && fichas != NULL)
	{
		retorno = 0;
		*fichas = this->maximoFichas;

	}

	return retorno;
}

int Arcade_setFk_juego(Arcade* this,int fk)
{
	int retorno =-1;

	if(this != NULL && fk>=0)
	{
		retorno = 0;
		this->fk_Juego = fk;

	}

	return retorno;
}

int Arcade_getFk_juego(Arcade* this,int* fk)
{
	int retorno =-1;

	if(this != NULL && fk != NULL)
	{
		retorno = 0;
		*fk = this->fk_Juego;

	}

	return retorno;
}

int Arcade_setFk_salon(Arcade* this,int fk)
{
	int retorno =-1;

	if(this != NULL && fk >= 0)
	{
		retorno = 0;
		this->fk_Salon = fk;

	}

	return retorno;
}

int Arcade_getFk_salon(Arcade* this,int* fk)
{
	int retorno =-1;

	if(this != NULL && fk != NULL)
	{
		retorno = 0;
		*fk = this->fk_Salon;

	}

	return retorno;
}
