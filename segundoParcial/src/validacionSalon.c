
#include "./inc/validacionSalon.h"

/// @fn int generadorId()
/// @brief Genera un id automatico
/// @return -1datos nullos 0 hubo error al obtener nuevo id
/// Sino Devuelve un id entero mayor a 0
int Salon_generadorId()
{
	static int id = 1000;
	return id++;

}

/// @fn pide Datos al usuario
/// @pre pide datos para llenar un salon y los valida
/// @param recibi un tipo Salon
/// @return un 0 si esta tod bien o -1 si esta mal
int Salon_pedirDatos(Salon* s){

	Salon s1;
	int retorno=-1;
	//char salon [5][20]={{"Shopping"},{"Restaurante"},{"Bar"},{"Hotel"},{"Otro"}};

	if(s!=NULL)
	{

		if(!utn_getStringMayusculayMinuscula(s1.name,"\nIngrese nombre del salon:",
				"\nError! Nombre invalido ", SAL_LEN_NAME, 2)
			&& !utn_getString(s1.direccion, "\nIngrese direccion: ", "\nError! direccion invalida",
					SAL_LEN_DIREC, 2)
			&& !utn_getNumero(&s1.tipoSalon, "\n1- Shopping"
					"\n2- Restaurante"
					"\n3- Bar"
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


//FUNCIONES CON LA CONSOLA
/// @fn imprime un Salon en filas
/// @param imprimi un Salon
int Salon_print(Salon* s)
{
	int retorno=-1;
	int id;
	char name[SAL_LEN_NAME];
	char direccion[SAL_LEN_DIREC];
	int tipoSalon;

	char salon [5][20]={{"Shopping"},{"Restaurante"},{"Bar"},{"Hotel"},{"Otro"}};

	if(s != NULL && !Salon_getId(s, &id) && !Salon_getName(s, name)
			&& !Salon_getDireccion(s, direccion) && !Salon_getTipoSalon(s, &tipoSalon))
	{

		retorno=0;
		printf("|%-10d|%-20s|%-20s|%-20s|\n"
			,id,name,direccion,salon[tipoSalon-1]);
	}

	return retorno;

}
