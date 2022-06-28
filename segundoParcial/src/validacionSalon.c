
#include "./inc/validacionSalon.h"

static int Salon_ById(LinkedList* pArraySalon,int id);

static int idSalon=0;

/// @fn int iniciadorId()
/// @brief Inicializa un id
/// @return -1datos nullos 0 hubo error al obtener nuevo id
/// Sino Devuelve un id entero mayor a 0
int Salon_InicioId(int idInicial)
{
	int retorno=-1;
	if(idInicial > 0)
	{
		idSalon = idInicial;
	}
	return retorno;

}

/// @fn int generadorId()
/// @brief Genera un id automatico
/// @return -1datos nullos 0 hubo error al obtener nuevo id
/// Sino Devuelve un id entero mayor a 0
int Salon_generadorId()
{
	if(idSalon > 0)
	{
		idSalon++;
	}

	return idSalon;
}

/// @fn pide Datos al usuario
/// @pre pide datos para llenar un salon y los valida
/// @param recibi un tipo Salon
/// @return un 0 si esta tod bien o -1 si esta mal
int Salon_pedirDatos(Salon* s){

	Salon s1;
	int retorno=-1;

	if(s!=NULL)
	{

		if(!utn_getStringMayusculayMinuscula(s1.name,"\nIngrese nombre del salon:",
				"\nError! Nombre invalido ", SAL_LEN_NAME, 2)
			&& !utn_getString(s1.direccion, "\nIngrese direccion: ", "\nError! direccion invalida",
					SAL_LEN_DIREC, 2)
			&& !utn_getNumero(&s1.tipoSalon, "\n1- Shopping"
					"\n2- Restaurante"
					"\n3- Local"
					"\n4- Hotel"
					"\n5- Otro"
					"\nIngrese tipo salon: ", "\nError! Ingrese nuevamente: ",
					1, 5, 2))
		{
			*s = s1;
			retorno = 0;
		}
	}

	return retorno;

}


/// @fn imprime un Salon en filas
/// @param imprimi un Salon
int Salon_print(Salon* s)
{
	int retorno=-1;
	int id;
	char name[SAL_LEN_NAME];
	char direccion[SAL_LEN_DIREC];
	int tipoSalon;

	char salon [5][20]={{"Shopping"},{"Local"},{"Bar"},{"Hotel"},{"Otro"}};

	if(s != NULL && !Salon_getId(s, &id) && !Salon_getName(s, name)
			&& !Salon_getDireccion(s, direccion) && !Salon_getTipoSalon(s, &tipoSalon))
	{

		retorno=0;
		printf("|%-10d|%-40s|%-30s|%-20s|\n"
			,id,name,direccion,salon[tipoSalon-1]);
	}

	return retorno;

}


/// @param LinkedList* pArraySalon
/// @param int id
/// @return -1 datos nullos, indice del id
static int Salon_ById(LinkedList* pArraySalon,int id)
{
	int retorno=-1;
	Salon* aux;
	int idAux;

	if(pArraySalon != NULL && id >0)
	{
		for (int i = 0; i < ll_len(pArraySalon); i++)
		{
			aux = (Salon*) ll_get(pArraySalon, i);
			Salon_getId(aux, &idAux);

			if(idAux == id)
			{
				retorno=i;
				break;
			}

		}
	}

	return retorno;

}

/// \brief Eliminar un salon por Id
///\linkedList* pArraySalon
///\id de parámetro int
///\return int Retorna (-1) si Error [longitud inválida o NULL
/// puntero o si no puede
///encontrar un pasajero] - (0) si está bien, (-2)NO existe id, (-3) No lo quiere borrar
int Salon_remove(LinkedList* pArraySalon, int id)
{
	int retorno=-1;
	int indice;

	if(pArraySalon != NULL && id>0){

		indice=Salon_ById(pArraySalon, id);

		if(indice<0)
		{

			//NO existe id
			retorno=-2;

		}
		else if(indice>=0)
		{

			Salon_print((Salon*)ll_get(pArraySalon, indice));

			//Preguntar si esta seguro
			if(preguntarSoN("\nEsta seguro que desea eliminar este salon? Si o No: ", 2, "\nRespuesta invalida")>0)
			{
				Salon_delete((Salon*)ll_pop(pArraySalon, indice));
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

/// @fn int Salon_printByIdMsj(LinkedList*, int, char*, char*)
/// @brief obtiene un salon por id, y lo imprime con un mensaje
/// @param pArraySalon
/// @param id
/// @param msj
/// @param msjError
/// @return -1 Null, >0 el indice
int Salon_printByIdMsj(LinkedList* pArraySalon,int id,char* msj,char* msjError)
{
	int indice=-1;

	if(pArraySalon != NULL && msj != NULL && msjError != NULL)
	{
		indice = Salon_ById(pArraySalon, id);

		if(indice >= 0)
		{
			puts(msj);
			Salon_print((Salon*)ll_get(pArraySalon, indice));
		}
		else
		{
			puts(msjError);
		}
	}

	return indice;
}

/// @fn Salon Salon_getSalon*(LinkedList*, int)
/// @brief devuelve un salon por Id
/// @param pArraySalon
/// @param id
/// @return Salon,O NULL
Salon* Salon_getSalon(LinkedList* pArraySalon,int id)
{
	int indice;
	Salon* aux=NULL;

	if(pArraySalon != NULL)
	{
		indice = Salon_ById(pArraySalon, id);

		if(indice >= 0)
		{
			aux = (Salon*)ll_get(pArraySalon, indice);
		}

	}

	return aux;
}
