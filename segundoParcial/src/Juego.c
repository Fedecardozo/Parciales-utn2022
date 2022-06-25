
#include "./inc/Juego.h"

Juego* Juego_new()
{
	return (Juego*)malloc(sizeof(Juego));
}

Juego* Juego_newJuego(Juego j)
{
	return Juego_newParametros(j.id,j.name,j.empresa,j.genero);
}

Juego* Juego_newParametros(int id, char* name, char* empresa, int genero)
{
	Juego* aux= Juego_new();

	if(aux != NULL)
	{
		Juego_setId(aux, id);
		Juego_setName(aux, name);
		Juego_setEmpresa(aux, empresa);
		Juego_setGenero(aux, genero);
	}

	return aux;
}

void Juego_delete(Juego* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

int Juego_setId(Juego* this,int id)
{
	int retorno =-1;

	if(this != NULL)
	{
		retorno = 0;
		this->id= id;

	}

	return retorno;

}

int Juego_getId(Juego* this,int* id)
{
	int retorno =-1;

	if(this != NULL && id != NULL)
	{
		retorno=0;
		*id=this->id;
	}

	return retorno;
}

int Juego_setName(Juego* this,char* name)
{
	int retorno =-1;

	if(this != NULL && name != NULL)
	{
		retorno = 0;
		strncpy(this->name,name,JUE_LEN_NAME);
	}

	return retorno;
}

int Juego_getName(Juego* this,char* name)
{
	int retorno =-1;

	if(this != NULL && name != NULL)
	{
		retorno = 0;
		strncpy(name,this->name,JUE_LEN_NAME);
	}

	return retorno;
}

int Juego_setEmpresa(Juego* this,char* empresa)
{
	int retorno =-1;

	if(this != NULL && empresa != NULL)
	{
		retorno = 0;
		strncpy(this->empresa,empresa,JUE_LEN_EMPRESA);
	}

	return retorno;
}

int Juego_getEmpresa(Juego* this,char* empresa)
{
	int retorno =-1;

	if(this != NULL && empresa != NULL)
	{
		retorno = 0;
		strncpy(empresa,this->empresa,JUE_LEN_EMPRESA);
	}

	return retorno;
}

int Juego_setGenero(Juego* this,int genero)
{
	int retorno =-1;

	if(this != NULL && genero>=0)
	{
		retorno = 0;
		this->genero= genero;

	}

	return retorno;
}

int Juego_getGenero(Juego* this,int* genero)
{
	int retorno =-1;

	if(this != NULL && genero != NULL)
	{
		retorno = 0;
		*genero = this->genero;

	}

	return retorno;
}


