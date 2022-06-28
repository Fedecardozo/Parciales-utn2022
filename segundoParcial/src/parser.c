
#include "./inc/parser.h"

// MODO TEXTO

/// @fn int parser_funcArcade(FILE*, LinkedList*)
/// @brief funcion parseo Salon(Texto)
/// @param name
/// @param pArray
/// @return -1 nullos, 0 ok
int parser_Salon(char*path, LinkedList* pArraySalon)
{
	int retorno = -1;
	FILE* salon;
	int contDatos;
	char varId[10];
	char varName[50];
	char varCalle[50];
	char varAltura[10];
	char varLocal[50];
	Salon* newSalon;

	if(path != NULL && pArraySalon != NULL)
	{
		salon = fopen(path,"r");
		if(salon != NULL)
		{
			retorno=0;
			do
			{
				contDatos=fscanf(salon,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",
								varId,varName,varCalle,varAltura,varLocal);

				int id = atoi(varId);
				int local= atoi(varLocal);
				sprintf(varCalle,"%s %s",varCalle,varAltura);

				if(contDatos==5)
				{
					newSalon = Salon_newParametros(id, varName, varCalle,local);
					ll_add(pArraySalon,newSalon);
				}

			}while(!feof(salon));
		}
	}

	return retorno;
}

/// @fn int parser_funcArcade(FILE*, LinkedList*)
/// @brief funcion parseo Juego(Texto)
/// @param name
/// @param pArray
/// @return -1 nullos, 0 ok
int parser_Juego(char*path, LinkedList* pArrayJuego)
{
	int retorno = -1;
	FILE* juego;
	int contDatos;
	char varId[10];
	char varName[50];
	char varEmpresa[10];
	char varGenero[50];
	Juego* newJuego;

	if(path != NULL && pArrayJuego != NULL)
	{
		juego = fopen(path,"r");

		if(juego != NULL)
		{
			retorno = 0;
			do
			{
				contDatos=fscanf(juego,"%[^,],%[^,],%[^,],%[^\n]\n",
								varId,varName,varEmpresa,varGenero);

				int id = atoi(varId);
				int genero = atoi(varGenero);

				if(contDatos==4)
				{
					newJuego = Juego_newParametros(id, varName, varEmpresa, genero);
					ll_add(pArrayJuego,newJuego);
				}

			}while(!feof(juego));
		}


	}

	return retorno;
}

/// @fn int parser_funcArcade(FILE*, LinkedList*)
/// @brief funcion parseo Arcade(Texto)
/// @param name
/// @param pArray
/// @return -1 nullos, 0 ok
int parser_Arcade(char*path, LinkedList* pArrayArcade)
{
	int retorno=-1;
	FILE* arcade;
	int contDatos;
	char varId[10];
	char varNacion[50];
	char varTipoSonido[10];
	char varCant[50];
	char varFichas[50];
	char varFkSalon[50];
	char varfkJuego[50];
	Arcade* newArcade;
	if(path != NULL && pArrayArcade != NULL)
	{

		arcade = fopen(path,"r");

		if(arcade != NULL)
		{
			retorno = 0;
			do
			{
				contDatos=fscanf(arcade,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",
								varId,varNacion,varTipoSonido,varCant,varFichas,varFkSalon,varfkJuego);

				int id = atoi(varId);
				int cant = atoi(varCant);
				int sonido = atoi(varTipoSonido);
				int fichas = atoi(varFichas);
				int fkSalon = atoi(varFkSalon);
				int fkJuego = atoi(varfkJuego);

				if(contDatos==7)
				{
					newArcade = Arcade_newParametros(id, varNacion, sonido,cant, fichas,fkJuego,fkSalon);
					ll_add(pArrayArcade,newArcade);
				}

			}while(!feof(arcade));
		}

	}

	return retorno;
}

/// @fn int parser_Id(char*)
/// @brief parsea e inicializa Id
/// @param path
/// @return -1 nulls, 0 ok
int parser_Id(char*path)
{
	int retorno =-1;
	FILE* fileId;
	int idAux;
	int contador=0;

	if(path != NULL)
	{
		fileId = fopen(path,"r");

		if(fileId != NULL)
		{
			retorno=0;
			do
			{
				if(fscanf(fileId,"%d",&idAux)>0)
				{
					contador++;
					switch(contador)
					{
						case 1: Salon_InicioId(idAux); break;
						case 2: Juego_InicioId(idAux); break;
						case 3: Arcade_InicioId(idAux);break;
					}
				}

			}while(!feof(fileId));
		}

		fclose(fileId);
	}

	return retorno;
}

//MODO BINARIO

/// @fn int parser_Bin(char*, LinkedList*, funcionParseo)
/// @brief  carga datos de los archivos(binarios) a la linked
/// @param path
/// @param pArray
/// @param parsear puntero a funcion
/// @return -1 NULLS, 0 ok
int parser_Bin(char*path, LinkedList* pArray,funcionParseo parsear)
{
	int retorno=-1;
	FILE* fileGenerico;


	if(path != NULL && pArray != NULL && parsear != NULL)
	{
		retorno = 0;
		fileGenerico = fopen(path,"rb");

		if(fileGenerico != NULL)
		{
			do{
				if(parsear(fileGenerico,pArray)<0)
				{
					retorno = -1;
					break;
				}

			}while(!feof(fileGenerico));

		}
		fclose(fileGenerico);
	}

	return retorno;
}

/// @fn int parser_funcArcade(FILE*, LinkedList*)
/// @brief funcion parseo Arcade
/// @param name
/// @param pArray
/// @return -1 nullos, 0 ok
int parser_funcArcade(FILE* name,LinkedList* pArray)
{
	int retorno=-1;
	int contDatos;
	Arcade aux;
	Arcade* auxNew;

	if(name != NULL && pArray != NULL)
	{
		retorno = 0;
		contDatos=fread(&aux,sizeof(Arcade),1,name);

		if(contDatos)
		{
			auxNew = Arcade_newArcade(aux);
			retorno = ll_add(pArray, auxNew);

		}
	}

	return retorno;
}

/// @fn int parser_funcArcade(FILE*, LinkedList*)
/// @brief funcion parseo Juego
/// @param name
/// @param pArray
/// @return -1 nullos, 0 ok
int parser_funcJuego(FILE* name,LinkedList* pArray)
{
	int retorno=-1;
	int contDatos;
	Juego aux;
	Juego* auxNew;

	if(name != NULL && pArray != NULL)
	{
		retorno=0;
		contDatos=fread(&aux,sizeof(Juego),1,name);

		if(contDatos)
		{
			auxNew = Juego_newJuego(aux);
			retorno = ll_add(pArray, auxNew);

		}
	}

	return retorno;
}

/// @fn int parser_funcArcade(FILE*, LinkedList*)
/// @brief funcion parseo Salon
/// @param name
/// @param pArray
/// @return -1 nullos, 0 ok
int parser_funcSalon(FILE* name,LinkedList* pArray)
{
	int retorno=-1;
	int contDatos;
	Salon aux;
	Salon* auxNew;

	if(name != NULL && pArray != NULL)
	{
		retorno = 0;
		contDatos=fread(&aux,sizeof(Salon),1,name);

		if(contDatos)
		{
			auxNew = Salon_newSalon(aux);
			retorno = ll_add(pArray, auxNew);

		}

	}

	return retorno;
}

/*		puts("\nBIENVENIDO!");
		//4 plataforma, 3 laberinto, 5 aventura
		//platforma: 13,14,19,20
		//laberinto: 5,6,8,9
		//aventura: 2,11,15,26,33
		for(int i=0; i<15;i++)
		{
			aux = (Arcade*)ll_get(listaArcades, i);
			Arcade_setFk_salon(aux, 5);
			if(i<5)
			{
				Arcade_setFk_juego(aux, fk);
			}
		}
		for(int i=15; i<30;i++)
		{
			aux = (Arcade*)ll_get(listaArcades, i);
			Arcade_setFk_salon(aux, 8);
		}
		for(int i=30; i<45;i++)
		{
			aux = (Arcade*)ll_get(listaArcades, i);
			Arcade_setFk_salon(aux, 7);
		}
		for(int i=45; i<60;i++)
		{
			aux = (Arcade*)ll_get(listaArcades, i);
			Arcade_setFk_salon(aux, 11);
		}*/

/*		//4 plataforma, 3 laberinto, 5 aventura
		//platforma: 13,14,19,20
		//laberinto: 5,6,8,9
		//aventura: 2,11,15,26,33
		for(int i=0; i<15;i++)
		{
			aux = (Arcade*)ll_get(listaArcades, i);
			Arcade_setFk_salon(aux, 5);
			if(i<5)
			{
				Arcade_setFk_juego(aux, 13);
			}
			else if(i<9)
			{
				Arcade_setFk_juego(aux, 6);
			}
			else
			{
				Arcade_setFk_juego(aux, 11);
			}
		}
		for(int i=15; i<30;i++)
		{
			aux = (Arcade*)ll_get(listaArcades, i);
			Arcade_setFk_salon(aux, 8);
			if(i<21)
			{
				Arcade_setFk_juego(aux, 14);
			}
			else if(i<25)
			{
				Arcade_setFk_juego(aux, 8);
			}
			else
			{
				Arcade_setFk_juego(aux, 26);
			}
		}
		for(int i=30; i<45;i++)
		{
			aux = (Arcade*)ll_get(listaArcades, i);
			Arcade_setFk_salon(aux, 7);
			if(i<36)
			{
				Arcade_setFk_juego(aux, 19);
			}
			else if(i<41)
			{
				Arcade_setFk_juego(aux, 5);
			}
			else
			{
				Arcade_setFk_juego(aux, 15);
			}
		}
		for(int i=45; i<60;i++)
		{
			aux = (Arcade*)ll_get(listaArcades, i);
			Arcade_setFk_salon(aux, 11);
			if(i<51)
			{
				Arcade_setFk_juego(aux, 20);
			}
			else if(i<54)
			{
				Arcade_setFk_juego(aux, 9);
			}
			else
			{
				Arcade_setFk_juego(aux, 33);
			}
		}*/
