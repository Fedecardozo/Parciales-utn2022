
#include "./inc/validacionJuego.h"

static int Juego_ById(LinkedList* pArrayJuego,int id);

/// @fn int generadorId()
/// @brief Genera un id automatico
/// @return -1datos nullos 0 hubo error al obtener nuevo id
/// Sino Devuelve un id entero mayor a 0
int Juego_generadorId()
{
	static int id = 1000;
	return id++;

}

/// @fn pide Datos al usuario
/// @pre pide datos para llenar un Juego y los valida
/// @param recibi un tipo Juego
/// @return un 0 si esta tod bien o -1 si esta mal
int Juego_pedirDatos(Juego* j){

	Juego j1;
	int retorno=-1;

	if(j!=NULL)
	{
		if(!utn_getStringMayusculayMinuscula(j1.name,"\nIngrese nombre del Juego:",
				"\nError! Nombre invalido ", JUE_LEN_NAME, 2)
			&& !utn_getString(j1.empresa, "\nIngrese nombre empresa: ", "\nError! empresa invalida",
					JUE_LEN_EMPRESA, 2)
			&& !utn_getNumero(&j1.genero, "\n1- Plataforma"
					"\n2- Aventura"
					"\n3- Laberinto"
					"\n4- Estrategia"
					"\n5- Otro"
					"\nIngrese tipo Juego: ", "\nError! Ingrese nuevamente: ",
					1, 5, 2))
		{
			*j = j1;
			retorno = 0;
		}
	}

	return retorno;

}

/// @fn imprime un Juego en filas
/// @param imprimi un Juego
int Juego_print(Juego* j)
{
	int retorno=-1;
	int id;
	char name[JUE_LEN_NAME];
	char empresa[JUE_LEN_EMPRESA];
	int genero;

	char tiposJuegos [5][20]={{"Plataforma"},{"Aventura"},{"Laberinto"},{"Estrategia"},{"Otro"}};

	if(j != NULL && !Juego_getId(j, &id) && !Juego_getName(j, name)
			&& !Juego_getEmpresa(j, empresa) && !Juego_getGenero(j, &genero))
	{

		retorno=0;
		printf("|%-10d|%-40s|%-40s|%-20s|\n"
			,id,name,empresa,tiposJuegos[genero-1]);
	}

	return retorno;

}

/// @param LinkedList* pArrayJuego
/// @param int id
/// @return -1 datos nullos, indice del id
static int Juego_ById(LinkedList* pArrayJuego,int id)
{
	int retorno=-1;
	Juego* aux;
	int idAux;

	if(pArrayJuego != NULL && id >0)
	{
		for (int i = 0; i < ll_len(pArrayJuego); i++)
		{
			aux = (Juego*) ll_get(pArrayJuego, i);
			Juego_getId(aux, &idAux);

			if(idAux == id)
			{
				retorno=i;
				break;
			}

		}
	}

	return retorno;

}

int Juego_printById(LinkedList* pArrayJuego,int id)
{
	int indice=-1;

	if(pArrayJuego != NULL)
	{
		indice = Juego_ById(pArrayJuego, id);

		if(indice >= 0)
		{
			Juego_print((Juego*)ll_get(pArrayJuego, indice));
		}
	}

	return indice;
}

int Juego_printByIdMsj(LinkedList* pArrayJuego,int id,char* msj,char* msjError)
{
	int indice=-1;

	if(pArrayJuego != NULL && msj != NULL && msjError != NULL)
	{
		indice = Juego_ById(pArrayJuego, id);

		if(indice >= 0)
		{
			puts(msj);
			Juego_print((Juego*)ll_get(pArrayJuego, indice));
		}
		else
		{
			puts(msjError);
		}
	}

	return indice;
}

Juego* Juego_getJuego(LinkedList* pArrayJuego,int id)
{
	int indice;
	Juego* aux=NULL;

	if(pArrayJuego != NULL)
	{
		indice = Juego_ById(pArrayJuego, id);

		if(indice >= 0)
		{
			aux = (Juego*)ll_get(pArrayJuego, indice);
		}

	}

	return aux;
}
