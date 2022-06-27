
#include "./inc/informes.h"


int informes_Salon_Mas4Arcades(LinkedList* pArrayArcade,LinkedList* pArraySalon)
{
	int retorno = -1;
	int cont=0;
	int idSalon;
	int fkSalon;
	Arcade* auxArcade;
	Salon* auxSalon;

	if(pArrayArcade != NULL && pArraySalon != NULL)
	{
		retorno = 0;
		for(int i=0; i<ll_len(pArraySalon); i++)
		{
			auxSalon =(Salon*)ll_get(pArraySalon, i);
			if(auxSalon != NULL && !Salon_getId(auxSalon,&idSalon))
			{
				for(int j=0; j<ll_len(pArrayArcade); j++)
				{
					auxArcade =(Arcade*)ll_get(pArrayArcade, j);

					if(auxArcade != NULL && !Arcade_getFk_salon(auxArcade,&fkSalon)
						&& idSalon == fkSalon)
					{
						cont++;
					}
				}

				if(cont >= 4)
				{
					Salon_print(auxSalon);
					retorno++;
				}
				cont=0;

			}

		}
	}

	return retorno;
}
