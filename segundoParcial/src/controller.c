
#include "./inc/controller.h"

//CONTROLLER DE SALON

/// @fn int controller_AltaSalon(LinkedList*)
/// @brief Da de alta un salon
/// @param pArraySalon
/// @return -1 NULL, 0 OK
int controller_AltaSalon(LinkedList* pArraySalon)
{
	int retorno=-1;
	Salon aux;
	Salon* newSalon;
	int auxId;

	if(pArraySalon != NULL)
	{

		if(!Salon_pedirDatos(&aux))
		{
			auxId = Salon_generadorId();
			if(auxId > 0)
			{
				aux.id = auxId;
				newSalon = Salon_newSalon(aux);

				if(newSalon != NULL && !ll_add(pArraySalon, newSalon))
				{
					retorno = 0;
				}
			}
		}
	}

	return retorno;
}

/// @fn int controller_ListarSalon(LinkedList*)
/// @brief Imprime lista salones
/// @param pArraySalon
/// @return -1 NULL, 0 ok
int controller_ListarSalon(LinkedList* pArraySalon)
{
	int retorno=-1;
	Salon* aux;

	if(pArraySalon != NULL && ll_len(pArraySalon)>0)
	{
		retorno = 0;
		for(int i=0; i<ll_len(pArraySalon); i++)
		{
			aux = (Salon*)ll_get(pArraySalon, i);
			if(aux != NULL)
			{
				//puts("Entro");
				Salon_print(aux);
			}
		}
	}

	return retorno;

}

/// @fn int controller_RemoveSalon(LinkedList*)
/// @brief borra un salon
/// @param pArraySalon
/// @return -1 lista nulla, -2 no existe id, -3 no lo quiere borrar
/// -4 listaVacia
int controller_RemoveSalon(LinkedList* pArraySalon)
{
	int retorno=-1;
	int id;

	if(pArraySalon != NULL)
	{
		if(ll_len(pArraySalon) > 0)
		{
			if(!utn_getNumero(&id, "\nIngrese numero ID:", "\nError Ingrese nuevamente: ", 0, 9999, 2))
			{
				retorno=Salon_remove(pArraySalon, id);
			}

		}
		else
		{
			//Lista vacia
			retorno = -4;
		}

	}

	return retorno;

}


//CONTROLLER DE JUEGO

/// @fn int controller_AltaJuego(LinkedList*)
/// @brief Da de alta un juego
/// @param pArrayJuego
/// @return -1 NULL, 0 OK
int controller_AltaJuego(LinkedList* pArrayJuego)
{
	int retorno=-1;
	Juego aux;
	Juego* newJuego;
	int auxId;

	if(pArrayJuego != NULL)
	{

		if(!Juego_pedirDatos(&aux))
		{
			auxId = Juego_generadorId();
			if(auxId > 0)
			{
				aux.id = auxId;
				newJuego = Juego_newJuego(aux);

				if(newJuego != NULL && !ll_add(pArrayJuego, newJuego))
				{
					retorno = 0;
				}
			}
		}
	}

	return retorno;
}

/// @fn int controller_ListarJuego(LinkedList*)
/// @brief Imprime lista juegos
/// @param pArrayJuego
/// @return -1 NULL, 0 ok
int controller_ListarJuego(LinkedList* pArrayJuego)
{
	int retorno=-1;
	Juego* aux;

	if(pArrayJuego != NULL && ll_len(pArrayJuego)>0)
	{
		retorno = 0;
		for(int i=0; i<ll_len(pArrayJuego); i++)
		{
			aux = (Juego*)ll_get(pArrayJuego, i);
			if(aux != NULL)
			{
				//puts("Entro");
				Juego_print(aux);
			}
		}
	}

	return retorno;

}
