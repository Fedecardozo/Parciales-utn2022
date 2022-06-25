
#include "./inc/Salon.h"

Salon* Salon_new()
{
	return (Salon*)malloc(sizeof(Salon));
}

Salon* Salon_newSalon(Salon s)
{
	return Salon_newParametros(s.id,s.name,s.direccion,s.tipoSalon);
}

Salon* Salon_newParametros(int id, char* name, char* direccion, int tipoSalon)
{
	Salon* aux= Salon_new();

	if(aux != NULL)
	{
		Salon_setId(aux, id);
		Salon_setName(aux, name);
		Salon_setDireccion(aux, direccion);
		Salon_setTipoSalon(aux, tipoSalon);
	}

	return aux;
}

void Salon_delete(Salon* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

int Salon_setId(Salon* this,int id)
{
	int retorno =-1;

	if(this != NULL)
	{
		retorno = 0;
		this->id= id;

	}

	return retorno;

}

int Salon_getId(Salon* this,int* id)
{
	int retorno =-1;

	if(this != NULL && id != NULL)
	{
		retorno=0;
		*id=this->id;
	}

	return retorno;
}

int Salon_setName(Salon* this,char* name)
{
	int retorno =-1;

	if(this != NULL && name != NULL)
	{
		retorno = 0;
		strncpy(this->name,name,SAL_LEN_NAME);
	}

	return retorno;
}

int Salon_getName(Salon* this,char* name)
{
	int retorno =-1;

	if(this != NULL && name != NULL)
	{
		retorno = 0;
		strncpy(name,this->name,SAL_LEN_NAME);
	}

	return retorno;
}

int Salon_setDireccion(Salon* this,char* direccion)
{
	int retorno =-1;

	if(this != NULL && direccion != NULL)
	{
		retorno = 0;
		strncpy(this->direccion,direccion,SAL_LEN_NAME);
	}

	return retorno;
}

int Salon_getDireccion(Salon* this,char* direccion)
{
	int retorno =-1;

	if(this != NULL && direccion != NULL)
	{
		retorno = 0;
		strncpy(direccion,this->direccion,SAL_LEN_NAME);
	}

	return retorno;
}

int Salon_setTipoSalon(Salon* this,int tipoSalon)
{
	int retorno =-1;

	if(this != NULL && tipoSalon>=0)
	{
		retorno = 0;
		this->tipoSalon= tipoSalon;

	}

	return retorno;
}

int Salon_getTipoSalon(Salon* this,int* tipoSalon)
{
	int retorno =-1;

	if(this != NULL && tipoSalon != NULL)
	{
		retorno = 0;
		*tipoSalon = this->tipoSalon;

	}

	return retorno;
}
