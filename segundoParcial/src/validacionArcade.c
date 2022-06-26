
#include "./inc/validacionArcade.h"

static int Arcade_ById(LinkedList* pArrayArcade,int id);

/// @fn int generadorId()
/// @brief Genera un id automatico
/// @return -1datos nullos 0 hubo error al obtener nuevo id
/// Sino Devuelve un id entero mayor a 0
int Arcade_generadorId()
{
	static int id = 1000;
	return id++;

}

/// @fn pide Datos al usuario
/// @pre pide datos para llenar un Arcade y los valida
/// @param recibi un tipo Arcade
/// @return un 0 si esta tod bien o -1 si esta mal
int Arcade_pedirDatos(Arcade* a){

	Arcade a1;
	int retorno=-1;

	if(a!=NULL)
	{

		if(!utn_getStringMayusculayMinuscula(a1.nacionalidad,"\nIngrese nacionalida:",
				"\nError! nacionalidad invalida ", LEN_NACIONALIDAD, 2)
			&& !utn_getNumero(&a1.cantidadJugadores, "\nIngrese cantidad de jugadores: ",
					"\nError! ingrese nuevamente: ", 1, 4, 2)
			&& !utn_getNumero(&a1.maximoFichas,"\nIngrese maximo de fichas: " ,"\nError! Ingrese nuevamente: "
					, 1, 9999, 2)
			&& !utn_getNumero(&a1.tipoSonido, "\n1- Mono"
					"\n2- Stereo"
					"\n3- Ultra Sonido"
					"\n4- Otro"
					"\nIngrese tipo sonido: ", "\nError! Ingrese nuevamente: ",
					1, 4, 2))
		{
			*a = a1;
			retorno = 0;
		}
	}

	return retorno;

}


/// @fn imprime un Arcade en filas
/// @param imprimi un Arcade
int Arcade_print(Arcade* a)
{
	int retorno=-1;
	int id;
	char nacion[LEN_NACIONALIDAD];
	int tipoSonido;
	int jugadores;
	int fichas;

	char sonidos [4][20]={{"Mono"},{"Stereo"},{"Ultra Sonido"},{"Otro"}};

	if(a != NULL && !Arcade_getId(a, &id) && !Arcade_getNacionalidad(a, nacion)
			&& !Arcade_getJugadores(a, &jugadores) && !Arcade_getTipoSonido(a, &tipoSonido)
			&& !Arcade_getFichas(a, &fichas))
	{

		//printf("%d",tipoSonido);
		retorno=0;
		printf("|%-10d|%-20s|%-10d|%-10d|%-20s|\n"
			,id,nacion,jugadores,fichas,sonidos[tipoSonido-1]);
	}

	return retorno;

}


/// @param LinkedList* pArrayArcade
/// @param int id
/// @return -1 datos nullos, indice del id
static int Arcade_ById(LinkedList* pArrayArcade,int id)
{
	int retorno=-1;
	Arcade* aux;
	int idAux;

	if(pArrayArcade != NULL && id >0)
	{
		for (int i = 0; i < ll_len(pArrayArcade); i++)
		{
			aux = (Arcade*) ll_get(pArrayArcade, i);
			Arcade_getId(aux, &idAux);

			if(idAux == id)
			{
				retorno=i;
				break;
			}

		}
	}

	return retorno;

}

/// \brief Eliminar un Arcade por Id
///\linkedList* pArrayArcade
///\id de parámetro int
///\return int Retorna (-1) si Error [longitud inválida o NULL
/// puntero o si no puede
///encontrar un pasajero] - (0) si está bien, (-2)NO existe id, (-3) No lo quiere borrar
int Arcade_remove(LinkedList* pArrayArcade, int id)
{
	int retorno=-1;
	int indice;

	if(pArrayArcade != NULL && id>0){

		indice=Arcade_ById(pArrayArcade, id);

		if(indice<0)
		{

			//NO existe id
			retorno=-2;

		}
		else if(indice>=0)
		{

			Arcade_print((Arcade*)ll_get(pArrayArcade, indice));

			//Preguntar si esta seguro
			if(preguntarSoN("\nEsta seguro que desea eliminar este Arcade? Si o No: ", 2, "\nRespuesta invalida")>0)
			{
				Arcade_delete((Arcade*)ll_pop(pArrayArcade, indice));
				retorno=0;
			}
			else
			{
				//No lo quiere borrar
				retorno=-3;
			}

		}


	}

	return retorno;
}
