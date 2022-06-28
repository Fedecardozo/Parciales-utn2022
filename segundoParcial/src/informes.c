
#include "./inc/informes.h"


int informes_Salon_MasCuatroArcades(LinkedList* pArrayArcade,LinkedList* pArraySalon)
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

//B)  Listar  los  arcade  para  más  de  2  jugadores,  indicando  ID  de  arcade,  cantidad  de  jugadores,  nombre  del juego,  su
//género y nombre del salón al que pertenece.
int informes_Arcade_MasDosJugadores(LinkedList* pArrayArcade,LinkedList* pArraySalon,LinkedList* pArrayJuego)
{
	int retorno=-1;
	Arcade* aux;
	Juego* auxJuego;
	Salon* auxSalon;
	int cantidadJugadores;
	int fkJuego;
	int fkSalon;
	char nameJuego[JUE_LEN_NAME];
	char nameSalon[SAL_LEN_NAME];
	int genero;
	int idArcade;
	int flag=0;
	char tiposJuegos [5][20]={{"Plataforma"},{"Aventura"},{"Laberinto"},{"Estrategia"},{"Otro"}};

	if(pArrayArcade != NULL && pArraySalon != NULL && pArrayJuego != NULL)
	{
		retorno = 0;
		for(int i=0; i<ll_len(pArrayArcade); i++)
		{
			aux = (Arcade*)ll_get(pArrayArcade, i);
			if(aux != NULL && !Arcade_getJugadores(aux, &cantidadJugadores)
				&& cantidadJugadores > 2 && !Arcade_getFk_juego(aux, &fkJuego)
			  && !Arcade_getFk_salon(aux, &fkSalon))
			{

				if(!flag)
				{
					printf("\n|%-10s|%-20s|%-40s|%-20s|%-40s|\n","ID ARCADE","CANTIDAD JUGADORES","NOMBRE JUEGO","GENERO JUEGO","NOMBRE SALON");
					flag=1;
				}

				auxSalon=Salon_getSalon(pArraySalon, fkSalon);
				auxJuego=Juego_getJuego(pArrayJuego, fkJuego);

				if(auxSalon != NULL && auxJuego != NULL && !Arcade_getId(aux, &idArcade) && !Juego_getName(auxJuego, nameJuego)
					&& !Juego_getGenero(auxJuego, &genero) && !Salon_getName(auxSalon, nameSalon))
				{

					printf("|%-10d|%-20d|%-40s|%-20s|%-40s|\n",idArcade,cantidadJugadores,nameJuego,tiposJuegos[genero-1],
						nameSalon);

					retorno++;
				}

			}
		}
	}

	return retorno;
}

//C) Listar toda la información de un salón en específico ingresado por el usuario. Imprimir ID de salón, nombre, tipo y
//dirección.
int informes_Salon_PorId(LinkedList* pArraySalon)
{
	int retorno = -1;
	int auxId;

	if(pArraySalon != NULL)
	{
		retorno=utn_getNumero(&auxId, "\nIngrese id del salon a obtener: ", "\nError! Ingrese nuevamente: ",
				1, 9999, 2);
		if(!retorno && Salon_printByIdMsj(pArraySalon, auxId, "\n\tSALON OBTENIDO", "\nNo se encontro el salon!")>=0)
		{
			retorno=0;
		}
	}

	return retorno;
}
