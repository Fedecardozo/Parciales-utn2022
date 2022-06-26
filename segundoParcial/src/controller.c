
#include "./inc/controller.h"

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

int controller_ListarSalon(LinkedList* pArraySalon)
{
	int retorno=-1;
	Salon* aux;

	if(pArraySalon != NULL)
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
