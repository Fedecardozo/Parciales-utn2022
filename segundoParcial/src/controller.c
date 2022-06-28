
#include "./inc/controller.h"

static int controller_SaveBin(char*path, LinkedList* pArray,int size);

//INICIO PROGRAMA

/// @fn int controller_Inicio(LinkedList*, LinkedList*, LinkedList*, char*, char*, char*)
/// @brief Inicio el programa cargando los datos de los archivos a las linkedLists
/// @param pArrayArcade
/// @param pArraySalon
/// @param pArrayJuego
/// @param pathArcade
/// @param pathJuego
/// @param pathSalon
/// @return -1 Parametros Nulls o error al cargar desde los archivos, 0 ok
int controller_Inicio(LinkedList* pArrayArcade,LinkedList* pArraySalon,LinkedList* pArrayJuego
		,char*pathArcade,char*pathJuego,char*pathSalon,char*pathId)
{
	int retorno=-1;

	if(pathArcade != NULL && pathJuego != NULL && pathSalon != NULL && pathId != NULL
		&& pArrayArcade != NULL && pArrayJuego != NULL && pArraySalon != NULL)
	{
		puts("\nESPERE! INICIANDO PROGRAMA...");
		if(!parser_Bin(pathArcade, pArrayArcade, parser_funcArcade)
		   && !parser_Bin(pathJuego, pArrayJuego, parser_funcJuego)
		   && !parser_Bin(pathSalon, pArraySalon, parser_funcSalon)
		   && !parser_Id(pathId))
		{
			retorno=0;
		}
	}

	return retorno;
}

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
		printf("\n|%-10s|%-40s|%-30s|%-20s|\n","ID SALON","NOMBRE DEL SALON","DIRECCION DEL SALON","TIPO DE SALON");
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

//CONTROLLER DE ARCADE

/// @fn int controller_AltaArcade(LinkedList*)
/// @brief Da de alta un Arcade
/// @param pArrayArcade
/// @return -1 NULL, 0 OK
int controller_AltaArcade(LinkedList* pArrayArcade,LinkedList* pArraySalon,LinkedList* pArrayJuego)
{
	int retorno=-1;
	Arcade aux;
	Arcade* newArcade;
	int auxId;

	if(pArrayArcade != NULL && pArraySalon != NULL && pArrayJuego != NULL)
	{
		puts("\n*** ALTA DE ARCADE ***");
		if(!Arcade_pedirDatos(&aux,pArrayJuego,pArraySalon))
		{
			auxId = Arcade_generadorId();
			if(auxId > 0)
			{
				aux.id = auxId;
				newArcade = Arcade_newArcade(aux);

				if(newArcade != NULL && !ll_add(pArrayArcade, newArcade))
				{
					retorno = 0;
				}
			}
		}
	}

	return retorno;
}

/// @fn int controller_ListarArcade(LinkedList*)
/// @brief Imprime lista Arcadees
/// @param pArrayArcade
/// @return -1 NULL, 0 ok
int controller_ListarArcade(LinkedList* pArrayArcade)
{
	int retorno=-1;
	Arcade* aux;

	if(pArrayArcade != NULL && ll_len(pArrayArcade)>0)
	{
		retorno = 0;
		printf("\n|%-10s|%-40s|%-10s|%-10s|%-20s|%-10s|%-10s|\n"
				,"ID ARCADE","NACIONALIDAD ARCADE","JUGADORES","FICHAS","TIPO SONIDO","FK SALON","FK JUEGO");
		for(int i=0; i<ll_len(pArrayArcade); i++)
		{
			aux = (Arcade*)ll_get(pArrayArcade, i);
			if(aux != NULL)
			{
				//puts("Entro");
				Arcade_print(aux);
			}
		}
	}

	return retorno;

}

/// @fn int controller_RemoveArcade(LinkedList*)
/// @brief borra un Arcade
/// @param pArrayArcade
/// @return -1 lista nulla, -2 no existe id, -3 no lo quiere borrar
/// -4 listaVacia
int controller_RemoveArcade(LinkedList* pArrayArcade)
{
	int retorno=-1;
	int id;

	if(pArrayArcade != NULL)
	{
		if(ll_len(pArrayArcade) > 0)
		{
			if(!utn_getNumero(&id, "\nIngrese numero ID: ", "\nError Ingrese nuevamente: ", 0, 9999, 2))
			{
				retorno=Arcade_remove(pArrayArcade, id);
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

///brief Modificar datos de Arcade
///param LinkedList* pArrayArcade
///param LinkedList* pArrayJuego
///@return 1 un exito 0 ok(-1)Datos nullos (-2) No se encontro ID
///(-3)Ingreso mal las opciones
///(-4)Ingreso mal los datos a modificar
///(-5)mal respuesta de si esta seguro
///(-6)mal respuesta si desea continuar
///(-7)Lista vacia
int controller_ModificarArcade(LinkedList* pArrayArcade,LinkedList* pArrayJuego)
{
	int retorno =-1;
	int id;

	if(pArrayArcade != NULL && pArrayJuego != NULL)
	{
		if(ll_len(pArrayArcade) > 0)
		{
			//HASTA ACA EL RETORNO ES -1
			if(!utn_getNumero(&id, "\nIngrese id:", "\nDato invalido. Ingrese nuevamente: ", 1, 9999, 2))
			{
				//RETORNO PUEDE 0 BIEN <0 QUE ALGO SALIO MAL
				retorno=Arcade_edit(pArrayArcade,id,pArrayJuego,controller_ListarJuego);
			}

		}
		else
		{
			//LISTA VACIA
			retorno =-7;
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
		printf("\n|%-10s|%-40s|%-40s|%-20s|\n","ID JUEGO","NOMBRE DEL JUEGO","EMPRESA DEL JUEGO","GENERO DE JUEGO");
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

//INFORMES

/// @fn int controller_Informes(char, LinkedList*, LinkedList*, LinkedList*)
/// @brief llama a la funciones del sub menu
/// @param letra
/// @param pArrayArcade
/// @param pArraySalon
/// @param pArrayJuego
/// @return -1 NULLOS, -2 letra incorrecta, 0 ok
int controller_Informes(char letra,LinkedList* pArrayArcade,LinkedList* pArraySalon,LinkedList* pArrayJuego)
{
	int retorno = -1;
	int cantidad;

	if(pArrayArcade != NULL &&  pArraySalon != NULL && pArrayJuego != NULL)
	{
		retorno=0;
		switch(letra)
		{
			case 'a':
			case 'A':
				cantidad = informes_Salon_MasCuatroArcades(pArrayArcade, pArraySalon);
				if(cantidad > 0)
				{
					printf("\nTotal de salones con mas de 4 arcades son: %d",cantidad);
				}
				else
				{
					puts("\nNo hay salones con mas de 4 arcades");
				}
				break;
			case 'b':
			case 'B':
				cantidad = informes_Arcade_MasDosJugadores(pArrayArcade, pArraySalon, pArrayJuego);
				if(cantidad > 0)
				{
					printf("\nTotal de Arcades con mas de 2 jugadores son: %d",cantidad);
				}
				else
				{
					puts("\nNo hay Arcades con mas de 2 jugadores");
				}
				break;
			case 'c':
			case 'C':

				if(informes_Salon_PorId(pArraySalon)<0)
				{
					puts("\nHUBO UN PROBLEMA INTENTELO MAS TARDE!");
				}

				break;
			case 'd':
			case 'D':
				cantidad = informes_Salon_Completo(pArrayArcade, pArraySalon, pArrayJuego);
				if(cantidad > 0)
				{
					printf("\nTotal de salones completos: %d",cantidad);
				}
				else
				{
					puts("\nNo hay salones completos");
				}
				break;
			case 'e':
			case 'E':
				cantidad = informes_Salon_porIdArcade(pArrayArcade, pArraySalon, pArrayJuego);
				if(cantidad == -1)
				{
					puts("\nHUBO UN ERROR, INTENTALO MAS TARDE! ");
				}
				else if(cantidad == -2)
				{
					puts("\nNO SE ENCONTRO EL SALON! ");
				}
				break;
			case 'f':
			case 'F':
				cantidad = informes_Salon_masArcadedOrdenados(pArrayArcade, pArraySalon, controller_ListarArcade);
				if(cantidad > 0)
				{
					printf("\nCantidad de arcades del salon con mas arcades es: %d\n",cantidad);
				}
				else
				{
					puts("\nHUBO UN ERROR, INTENTALO MAS TARDE! ");
				}

				break;
			case 'g':
			case 'G':
				if(!informes_Arcades(pArrayArcade, pArrayJuego))
				{
					puts("\nArcades con tipo de sonido Mono y con tipo de juego plataforma");
				}
				else
				{
					puts("\nAlgo salio mal, intentelo mas tarde...");
				}
				break;
			case 'h':
			case 'H':
				puts("\nMENU INCIAL");
				break;
			default: retorno=-2; break;
		}

	}

	return retorno;
}

//FIN PROGRAMA

/// @fn int controller_SaveBin(char*, LinkedList*, int)
/// @brief guarda en modo binario
/// @param path
/// @param pArray
/// @param size
/// @return -1 Nullos, 0 ok
static int controller_SaveBin(char*path, LinkedList* pArray,int size)
{
	int retorno=-1;
	FILE* fileGenerico;
	void* aux;

	if(path != NULL && pArray != NULL && size > 0)
	{
		fileGenerico=fopen(path,"wb");

		if(fileGenerico != NULL)
		{
			retorno=0;
			for(int i=0;i<ll_len(pArray);i++)
			{
				aux = ll_get(pArray, i);
				fseek(fileGenerico,0,SEEK_END);
				fwrite(aux,size,1,fileGenerico);
			}

			fclose(fileGenerico);
		}
	}

	return retorno;
}

/// @fn int controller_FinPrograma(char*, char*, char*, LinkedList*, LinkedList*, LinkedList*)
/// @brief guarda los los datos en su archivo correspondiente
/// @param pathArcade
/// @param pathJuego
/// @param pathSalon
/// @param pArrayArcade
/// @param pArrayJuego
/// @param pArraySalon
/// @return -1 Parametros Nulls o error al cargar desde los archivos, 0 ok
int controller_FinPrograma(char*pathArcade,char*pathJuego,char*pathSalon, LinkedList* pArrayArcade,LinkedList* pArrayJuego,LinkedList* pArraySalon)
{
	int retorno = -1;

	if(pathArcade != NULL && pathJuego != NULL && pathSalon != NULL
		&& pArrayArcade != NULL && pArrayJuego != NULL && pArraySalon != NULL)
	{
		puts("\nESPERE! GUARDANDO INFORMACION...");
		if(!controller_SaveBin(pathArcade, pArrayArcade, sizeof(Arcade))
		   && !controller_SaveBin(pathSalon, pArraySalon, sizeof(Salon))
		   && !controller_SaveBin(pathJuego, pArrayJuego, sizeof(Juego)))
		{
			retorno = 0;
		}
	}

	return retorno;
}
