
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

//D) Un salón se encuentra completo si posee al menos 4 juegos del género plataforma, 3 del género laberinto y 5 del
//género Aventura. Listar los salones que cumplan con este mínimo de requisito.
int informes_Salon_Completo(LinkedList* pArrayArcade,LinkedList* pArraySalon,LinkedList* pArrayJuego)
{
	int retorno = -1;
	int contPlataforma=0;
	int contLaberinto=0;
	int contAventura=0;
	int idSalon;
	int fkSalon;
	int fkJuego;
	int genero;
	Arcade* auxArcade;
	Salon* auxSalon;
	Juego* auxJuego;

	if(pArrayArcade != NULL && pArraySalon != NULL && pArrayJuego != NULL)
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
						&& idSalon == fkSalon && !Arcade_getFk_juego(auxArcade, &fkJuego))
					{
						auxJuego = Juego_getJuego(pArrayJuego, fkJuego);

						if(auxJuego != NULL && !Juego_getGenero(auxJuego, &genero))
						{
							switch(genero)
							{
								case 1:contPlataforma++; break;
								case 2:contAventura++; break;
								case 3:contLaberinto++; break;

							}
						}

					}
				}

				if(contPlataforma >=4 && contAventura >=5 && contLaberinto >=3)
				{
					Salon_print(auxSalon);
					retorno++;
				}
				contPlataforma=0;
				contAventura=0;
				contLaberinto=0;

			}

		}
	}

	return retorno;
}

//E) Listar todos los arcades de un salón determinado ingresando su ID. Informar nombre y tipo de salón, listar todos los
//arcade con sus datos junto con el nombre del juego que lo compone
int informes_Salon_porIdArcade(LinkedList* pArrayArcade,LinkedList* pArraySalon,LinkedList* pArrayJuego)
{
	int retorno=-1;
	Arcade* aux;
	Juego* auxJuego;
	Salon* auxSalon;
	int fkSalon;
	int fkJuego;
	char nameJuego[JUE_LEN_NAME];
	char nameSalon[SAL_LEN_NAME];
	int tipoSalon;
	int flag=0;
	int auxId;
	char tipoSalonStr [5][20]={{"Shopping"},{"Local"},{"Bar"},{"Hotel"},{"Otro"}};

	if(pArrayArcade != NULL && pArraySalon != NULL && pArrayJuego != NULL)
	{
		retorno = utn_getNumero(&auxId, "\nIngrese id del salon a obtener: ", "\nError! Ingrese nuevamente: ",
				1, 9999, 2);
		if(!retorno)
		{
			auxSalon = Salon_getSalon(pArraySalon, auxId);
			if(auxSalon != NULL && !Salon_getName(auxSalon, nameSalon) && !Salon_getTipoSalon(auxSalon, &tipoSalon))
			{
				for(int i=0; i<ll_len(pArrayArcade); i++)
				{
					aux = (Arcade*)ll_get(pArrayArcade, i);
					if(!Arcade_getFk_salon(aux, &fkSalon) && fkSalon == auxId && !Arcade_getFk_juego(aux, &fkJuego))
					{
						auxJuego = Juego_getJuego(pArrayJuego, fkJuego);
						if(auxJuego != NULL && !Juego_getName(auxJuego, nameJuego))
						{
							if(!flag)
							{
								printf("|%-40s|%-30s|%-40s|%-10s|%-40s|%-10s|%-10s|%-20s|%-10s|%-10s|\n"
										,"NOMBRE SALON","TIPO SALON","NOMBRE DEL JUEGO","ID ARCADE","NACIONALIDAD"
										,"JUGADORES","FICHAS","TIPO SONIDO","FK SALON","FK JUEGO");
								flag=1;
							}
							printf("|%-40s|%-30s|%-40s",nameSalon,tipoSalonStr[tipoSalon-1],nameJuego);
							Arcade_print(aux);
						}
					}
				}
			}
			else
			{
				retorno = -2;
			}
		}

	}

	return retorno;
}
