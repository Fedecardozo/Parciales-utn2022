
#include "arrayUsuario.h"

static int generadorId();
static int eUsuario_Vacio(Usuario * list, int len);
static int eUsuario_VerificacionSesion(Usuario * list,int len,Usuario aux);
static int eUsuario_VerificacionRegistrarse(Usuario * list,int len,Usuario aux);

/// @fn int generadorId()
/// @brief genera un id automatico
/// @return Devuelve un id entero
static int generadorId(){

	static int id=1000;
	return id++;

}

/// \brief Para indicar que todas las posiciones en el array están vacías,
/// esta función pone la bandera (isEmpty) en VERDADERO en todos
/// posiciónes del array
/// \param list Gen* Puntero del array de pasajeros
/// \param len int Longitud del arreglo
///\return int Devuelve (-1) si hay error [longitud no válida o puntero NULL] - (0) si está bien
int eUsuario_Inicializar(Usuario *list, int len){

	int retorno=-1;
	int i;

	if(list != NULL && len >0){

		for (i = 0; i < len; i++) {

			list[i].isEmpty=LIBRE;

		}

		retorno = 0;

	}

	return retorno;


}

/// @fn ObtenerIndexLibre
/// @param list recibe un array tipo Usuario
/// @param len es el lenaño del del array
/// \return int Devuelve (-1) si Error [Longitud no válida o puntero NULL]
/// o -2 sin espacio libre - (0) si está bien
int eUsuario_ObtenerIndexLibre(Usuario* list, int len){

	int retorno=-1;
	int i;


		if (list != NULL && len > 0)
		{

		for (i = 0; i < len; i++)
		{

			if (list[i].isEmpty == LIBRE)
			{

				retorno = i;
				break;

			} else
			{

				//Si esta todo lleno
				retorno = -2;

			}

		}

	}

		return retorno;


}

/// \brief Usuario BuscarPorid by Id en devuelve la posición del índice en el arreglo.
/// \param list Usuario *
/// \param len int
/// \param id int
///\return Posición del índice de pasajero de retorno o (-1) si [Longitud o
///Puntero NULL recibido o pasajero no encontrado]
int eUsuario_BuscarPorid(Usuario *list, int len, int id){

	int retorno=-1;
	int i;

		if(list!= NULL && len >0)
		{

			for (i = 0; i < len; i++)
			{

				if(list[i].isEmpty==OCUPADO && list[i].idUsuario== id)
				{

					retorno=i;
					break;

				}

			}


		}


	return retorno;

}

/// @fn pide Un Solo Dato al usuario
/// @pre pide datos para llenar un Usuario y los valida
/// @post y luego los copia en passanger pasado por parametro
/// @param recibi un tipo Usuario
/// @return (-1)[list null, longitud menor a 0]
/// (-2)NO hay datos cargados
/// (0)NO hay correo o contraseña
/// (1)Hay correo y contraseña
int eUsuario_InicioSesion(Usuario * list, int len){

	Usuario aux;
	int retorno=-1;
	int intentos =2;

	if(list!=NULL){

		retorno =eUsuario_Vacio(list, len);

		if(retorno)
		{
			do{

				if(utn_getStringCorreo(aux.correo, "\nexample@gmail.com\nIngrese correo: ", "\nError correo invalido", MAX_CORREO, 2)==0
						&& utn_getStringLetrasYnumerosLimite(aux.password,"\nIngrese password: ",
								"\nError password invalido",MIN_PASSWORD, MAX_PASSWORD , 2)==0)
				{

					retorno=eUsuario_VerificacionSesion(list, len, aux);

				}
				else
				{
					retorno=-1;
				}
				if(retorno == -3 && intentos>0)
				{
					printf("\nCorreo o contraseña incorrecto");
					intentos--;
				}


			}while(retorno==-3 && intentos>0);
		}
		else if(retorno == 0)
		{
			retorno = -2;
		}

	}

	return retorno;

}

/// @fn Verifica si el correo y password hay en el array
/// @param list lista de Usuario
/// @param len longitud de Usuario
/// @param aux Usuario a comparar
/// @return (-1)[list null, longitud menor a 0]
/// (-2)NO hay datos cargados
/// (-3)NO hay correo o contraseña
/// (indice>=0)Hay correo y contraseña
static int eUsuario_VerificacionSesion(Usuario * list,int len,Usuario aux){

	int i;
	int retorno=-1;

	if(list != NULL && len>=0 )
	{
		if(eUsuario_Vacio(list, len))
		{
			//puts("ENtro");
			retorno =-3;
			for (i = 0; i < len; i++)
			{
				if(list[i].isEmpty==OCUPADO)
				{
					if(strcmp(list[i].correo,aux.correo)==0 && strcmp(list[i].password,aux.password)==0)
					{
					  // puts("ENtro");
						retorno = i;
						break;

					}


				}

			}

		}else
		{
			retorno = -2;
		}

	}

	return retorno;

}

/// @fn pide Un Solo Dato al usuario
/// @pre pide datos para llenar un Usuario y los valida
/// @post y luego los copia en passanger pasado por parametro
/// @param recibi un tipo Usuario
/// @return un 0 si esta todo bien o -1 si esta mal
int eUsuario_Registrarse(Usuario * list){

	Usuario aux;
	int retorno=-1;

	if(list!=NULL){
		if(utn_getStringLetrasYnumerosLimite(aux.password,"\nPassword de 4 a 8 caracteres\nIngrese password: ",
						"\nError password invalido",MIN_PASSWORD, MAX_PASSWORD, 2)==0
				&& utn_getString(aux.direccion,"\nIngrese domicilio: ", "\nError direccion invalida", MAX_DIRECCION, 2)==0
				&& utn_getNumero(&aux.codigoPostal, "\nIngrese codigo postal: ",
						"\nError codigo postal invalido \nIngrese nuevamente: ", 1, 9999, 2)==0
				&& utn_getShorInt(&aux.tipo, "\n**TIPOS** \n 1)Usuario \n 2) Administrador"
						" \nIngrese tipo: ",
						"\nError tipo invalido", 1, 2, 2)==0)
		{
			strncpy(aux.correo,list->correo,MAX_CORREO);

			retorno=0;
			*list=aux;

		}

	}

	return retorno;

}

/// @fn Verifica que al registrarse no haya un email igual
/// @param list *Usuario
/// @param len tamaño array Usuario
/// @param aux Usuario
/// @return 0 datos no nullos -1 hay correo repetido
static int eUsuario_VerificacionRegistrarse(Usuario * list,int len,Usuario aux){

	int i;
	int retorno=0;

	if(list != NULL && len>=0 )
	{
		for (i = 0; i < len; i++)
		{
			if(list[i].isEmpty==OCUPADO || list[i].isEmpty==BAJA)
			{

				if(strcmp(list[i].correo,aux.correo)==0)
				{
					retorno = -1;
					break;

				}


			}

		}

	}

	return retorno;

}

/// @fn int imprime Usuario
/// @param imprimi un Usuario solo
void eUsuario_MostrarUno(Usuario list){

	char estado[3][10]={{"  ACTIVO"},{"  LIBRE "},{"   BAJA "}};

	printf("|%-11d|%-10s|%-30s|\n"
			,list.idUsuario,estado[list.isEmpty],list.correo);

}

/// @fn imprime un array de Usuario que esten cargados
/// @param recibi un puntero tipo Usuario
/// @param la longitud para recorrer el array
///\return int Devuelve (-1) si hay error [longitud no válida o puntero NULL] - (0) si está bien
int eUsuario_MostrarTodos(Usuario *list, int len){

	int retorno = -1;
	int i;

	if(list != NULL && len >=0){

		retorno=0;
		printf("+-----------------------------------------------------+\n");
		printf("|%-11s|%-10s|%-30s|\n",
				"ID USUARIO","  ESTADO"," CORREO ELECTRONICOS");
		printf("+-----------------------------------------------------+\n");

		for (i = 0; i < len ; i++) {

			if(list[i].isEmpty!=LIBRE){

				eUsuario_MostrarUno(list[i]);
				printf("+-----------------------------------------------------+\n");

			}

		}

	}


	return retorno;

}

/// @fn imprime un array de Usuario que esten dados de baja
/// @param recibi un puntero tipo Usuario
/// @param la longitud para recorrer el array
///\return int Devuelve (-1) si hay error [longitud no válida o puntero NULL] - (0) si está bien
int eUsuario_MostrarDadosDeBaja(Usuario *list, int len){

	int retorno = -1;
	int i;

	if(list != NULL && len >=0){

		retorno=0;
		printf("+-----------------------------------------------------------"
				"----------------------------------------------+\n");
		printf("|%-15s|%-15s|%-15s|%-15s|%-20s|%-20s|\n",
				" Nombres"," Apellidos"," Precio"," Codigo"," Tipo de pasajero"," Estado Vuelo");
		  printf("+-------------------------------------------------------------------"
				  "--------------------------------------+\n");
		for (i = 0; i < len ; i++) {

			if(list[i].isEmpty==LIBRE){

				eUsuario_MostrarUno(list[i]);
				printf("+-----------------------------------------------------------"
								"----------------------------------------------+\n");

			}

		}

	}


	return retorno;

}

/// \brief Pregunta si las posiciones en el array están vacías,
/// \param list Usuario * Puntero del array de Usuario
/// \param len int Longitud del arreglo
///\return int Devuelve (-1) si hay error [longitud no válida o puntero NULL] - (0)vacio
/// (1) Cargado
static int eUsuario_Vacio(Usuario * list, int len){

	int retorno=-1;
	int i;

		if(list != NULL && len >=0){
			retorno=0;
			for (i = 0; i < len; i++)
			{

				if(list[i].isEmpty==OCUPADO)
				{
					retorno=1;
					break;
				}

			}

		}

		return retorno;


	}


//ABM

/// @fn Usuario Cargar los Datos de una list de Usuario
/// @param list puntero de Usuario
/// @param len longitud de Usuario
/// @return 1 punteros nullos len <0 [0]bien -2 lista llena
/// -3 correo existente
int eUsuario_CargarDatos(Usuario * list,int len){

	int retorno=-1;
	int indice;
	int intentos=2;
	Usuario aux;

	if(list != NULL && len >0)
	{

		indice = eUsuario_ObtenerIndexLibre(list, len);

		if(indice>=0 )
		{
			do{

				if(utn_getStringCorreo(aux.correo, "\nexample@gmail.com\nIngrese correo: ", "\nError correo invalido", MAX_CORREO, 0)==0)
				{
					if(eUsuario_VerificacionRegistrarse(list, len, aux)==0)
					{
						//eUsuario_MostrarUno(aux);
						if(eUsuario_Registrarse(&aux)==0)
						{
							if(eUsuario_Alta(list, len, aux)==0)
							{
								//ok
								retorno=0;
								break;
							}

						}
						else
						{
							retorno = -1;
							break;
						}

					}
					else if(intentos>0)
					{
						puts("\nERROR CORREO EXISTENTE!");
						retorno=-3;

					}


				}

				intentos--;

			}while(intentos>=0);

		}
		else
		{
			//lista llena
			retorno = -2;
		}


	}



	return retorno;

}


/// \brief Eliminar un Usuario por Id (poner el indicador isEmpty en 1)
///\lista de parámetros Usuario *
///\parametro len int
///\id de parámetro int
///\return int Retorna (-1) si Error [longitud inválida o NULL
/// puntero o si no puede encontrar un Producto] -
///  (0) si está bien (-2) ERROR AL PEDIR ID
/// (-3) ERROR AL OBTENER INDICE (-4) //NO SE MODIFICO NADA
int eUsuario_remove(Usuario* list, int len)
{
	int retorno=-1;
	int id;
	int indice;

		if(list!=NULL && len>0)
		{
			if(utn_getNumero(&id, "\nINGRESE ID A DAR DE BAJA: ", "\nERROR! INGRESE NUEVAMENTE: ",
					0, 9999, 2)==0)
			{
				indice = eUsuario_BuscarPorid(list, len, id);

				if(indice >= 0)
				{
					printf("\n %30s \n","**** USUARIO A DAR DE BAJA ****");
					printf("+-----------------------------------------------------+\n");
					printf("|%-11s|%-10s|%-30s|\n",
									"ID USUARIO","  ESTADO"," CORREO ELECTRONICOS");
					printf("+-----------------------------------------------------+\n");
					eUsuario_MostrarUno(list[indice]);
					printf("+-----------------------------------------------------+\n");

					//Preguntar si esta seguro
					if(preguntarSoN("\nEsta seguro? Si o No: ", 2, "\nRespuesta invalida")>0)
					{
						list[indice].isEmpty=BAJA;
						retorno=0;

					}
					else
					{

						//NO SE MODIFICO NADA
						retorno = -4;

					}


				}
				else
				{

					//ERROR AL OBTENER INDICE
					retorno=-3;

				}

			}


			else
			{
				//ERROR AL PEDIR ID
				retorno=-2;
			}


		}

	return retorno;
}


/// @fn Da de alta un Usuario
/// @param lista de Usuario
/// @param len longitud del array Gen
/// @return Posición del índice de pasajero de retorno o (-1) si [Longitud o
///Puntero NULL recibido o pasajero no encontrado] -2 lista llena
int eUsuario_Alta(Usuario *list, int len,Usuario usuarioDarAlta){

		int retorno=-1;
		int indice;


		if(list != NULL && len >=0)
		{

			indice=eUsuario_ObtenerIndexLibre(list, len);

			if(indice>=0)
			{

				list[indice]=usuarioDarAlta;
				list[indice].idUsuario = generadorId();
				list[indice].isEmpty=OCUPADO;
				retorno=0;

			}


		}
		return retorno;

}


/// @fn Baja para Usuario
/// @param list arreglo Usuario
/// @param len longitud del arreglo
/// @return 0 bien -1 error parametros -2 no existe id -3 No hay datos cargados
/// -4 no estaba seguro
int eUsuario_Baja(Usuario *list, int len){

	int retorno=-1;

	if(list != NULL && len >0)
	{
		if(eUsuario_Vacio(list, len))
		{
			retorno=0;
		}
		else
		{
			//Array vacio
			retorno = -3;
		}

	}


	return retorno;

}
