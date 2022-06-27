
#include "./inc/validacionArcade.h"

static int Arcade_ById(LinkedList* pArrayArcade,int id);
static int queModifcar(Arcade* list,LinkedList* pArrayJuego,pFuncListar listJuego);
static int opcionesParaModifcar(int opc, Arcade* list, LinkedList* pArrayJuego,pFuncListar listJuego);

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
int Arcade_pedirDatos(Arcade* a,LinkedList* pArrayJuego,LinkedList* pArraySalon)
{

	Arcade a1;
	int retorno=-1;

	if(a!=NULL)
	{

		if(!utn_getNumero(&a1.fk_Juego, "\nIngrese Id del juego: ", "\nError! Ingrese nuevamente: ",
				1, 9999, 2) && Juego_printByIdMsj(pArrayJuego, a1.fk_Juego,
						"\n**** Se agrego este juego ****", "No existe tal juego en el sistema") >=0
			&& !utn_getNumero(&a1.fk_Salon, "\nIngrese Id del salon: ", "\nError! Ingrese nuevamente: ",
					1, 9999, 2) && Salon_printByIdMsj(pArraySalon, a1.fk_Salon,
							"\n**** Se agrego este salon ****","No existe tal salon en el sistema") >=0
			&& !utn_getStringMayusculayMinuscula(a1.nacionalidad,"\nIngrese nacionalida:",
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
	int fkSalon;
	int fkJuego;

	char sonidos [4][20]={{"Mono"},{"Stereo"},{"Ultra Sonido"},{"Otro"}};

	if(a != NULL && !Arcade_getId(a, &id) && !Arcade_getNacionalidad(a, nacion)
			&& !Arcade_getJugadores(a, &jugadores) && !Arcade_getTipoSonido(a, &tipoSonido)
			&& !Arcade_getFichas(a, &fichas) && !Arcade_getFk_juego(a, &fkJuego)
			&& !Arcade_getFk_salon(a, &fkSalon))
	{

		//printf("%d",tipoSonido);
		retorno=0;
		printf("|%-10d|%-20s|%-10d|%-10d|%-20s|%-10d|%-10d|\n"
			,id,nacion,jugadores,fichas,sonidos[tipoSonido-1],fkSalon,fkJuego);
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


/// @fn modifica Arcade
/// @brief modica un dato de Arcade
/// @param recibe un tipo Arcade list
/// @param recibe el tamanio del arraylen
/// @param recibe el id que va a buscar
/// @return 1 un exito 0 ok(-1)Datos nullos (-2) No se encontro ID
/// (-3)Ingreso mal las opciones
/// (-4)Ingreso mal los datos a modificar
/// (-5)mal respuesta de si esta seguro
/// (-6)mal respuesta si desea continuar
int Arcade_edit(LinkedList* pArrayListArcade, int id,LinkedList* pArrayJuego,pFuncListar listJuego)
{

	int retorno=-1;
	int indice;
	Arcade* aux;

	if(pArrayListArcade!=NULL && id>0 && pArrayJuego != NULL && listJuego != NULL)
	{

		retorno=0;
		indice=Arcade_ById(pArrayListArcade, id);

		if(indice<0)
		{

			//ERROR NO ENCONTRO EL ID
			retorno=-2;

		}else if(indice>=0){

			//-1 mal los datos -3 mal las opciones
			//-4 mal datos a modificar
			//-5 mal respuesta de si esta seguro
			//-6 mal respuesta si desea continuar
			aux = (Arcade*) ll_get(pArrayListArcade, indice);
			retorno= queModifcar(aux,pArrayJuego,listJuego);
			if(!retorno && !ll_set(pArrayListArcade, indice, aux))
			{
				retorno=1;
			}

		}


	}

		return retorno;
}

/// @fn queModifcar
/// @pre Segun la opcion ingresada por el usuario
/// @post va a mostrar un msj y guardarlo en auxiliar
/// De tipo Arcade
/// @param opc la opcion para el switch
/// @param indice para saber cual hay que modificar
/// @param p el puntero Arcade para sobreecribir con
/// el auxiliar
/// @return 0 bien o -1 mal -3 mal las opciones
/// -4 mal datos a modificar -5 mal respuesta si esta seguro
/// -6 Mal la respuesta de si desea continuar
static int queModifcar(Arcade* list,LinkedList* pArrayJuego,pFuncListar listJuego){

	int retorno=-1;
	Arcade aux=*list;
	int respuesta;
	int opc;

	if(list != NULL && pArrayJuego != NULL && listJuego != NULL)
	{

		do{
			retorno= utn_getNumero(&opc, "\nOpciones de lo que desea modificar"
					"\n1-Cantidad de jugadores"
					"\n2-Juego"
					"\nIngrese opcion: ",
					"\nError Ingrese nuevamente: ", 1, 2, 2);

			if(retorno==0)
			{
				retorno= opcionesParaModifcar(opc, &aux,pArrayJuego,listJuego);

				if(retorno==0)
				{
					respuesta=preguntarSoN("\nEstas seguro? Si-No: ", 2, "\nIngrese [si] o [no]: ");

					if(respuesta>0)
					{
						*list=aux;
						printf("\nSE MODIFICO CON EXITO !");
					}
					if(respuesta==0)
					{
						printf("\nNO SE MODIFICARION LOS DATOS !");
					}
					else if(respuesta<0)
					{
						//Mal la respuesta de si esta seguro
						retorno=-5;
						break;
					}


				}
				else
				{
					//Mal los datos a modificar
					retorno=-4;
					break;
				}


				respuesta = preguntarSoN("\nDesea continuar modificando? Si-No: ", 2, "\nIngrese [si] o [no]: ");
				if(respuesta<0)
				{
					//Mal la respuesta de si desea continuar
					retorno=-6;
					break;
				}
			}
			else
			{
				//mal las opciones
				retorno =-3;
				break;
			}

		}while(respuesta);

	}

	return retorno;
}

/// @fn opcionesParaModifcar
/// @brief Modifica los datos segun la opcion
/// @return -1 mal 0 bien
static int opcionesParaModifcar(int opc, Arcade* list, LinkedList* pArrayJuego,pFuncListar listJuego){

 	int retorno=-1;
 	Arcade aux = *list;
 	int fkJuegoActual;

 	if(list != NULL && pArrayJuego != NULL && listJuego != NULL)
 	{

 		switch (opc)
 		{

 			case 1:

 				retorno = utn_getNumero(&aux.cantidadJugadores, "\nIngrese cantidad jugadores: ",
 						"\nError! Ingrese nuevamente: " ,1,4, 2);

 				break;

 			case 2:

 				// listar juego, y que ingrese a id para cambiar de juego
 				if(!listJuego(pArrayJuego) &&
 					!utn_getNumero(&aux.fk_Juego, "\nIngrese id del juego: ",
 				 			"\nError! Ingrese nuevamente: " ,1,9999, 2))
 				{
 					Arcade_getFk_juego(list, &fkJuegoActual);

 					if(fkJuegoActual>0 && Juego_printByIdMsj(pArrayJuego,fkJuegoActual,"\n\t\t*** JUEGO ACTUAL ***",
 							"\nNo existe tal juego!")>=0
 						&& Juego_printByIdMsj(pArrayJuego, aux.fk_Juego,"\n\t**** SE REEMPLAZARA CON ESTE JUEGO ****",
 							"\nNo existe tal juego!")>=0)
 					{
 						retorno = 0;
 					}

 				}

 				break;

 			default:
 				retorno = -1;
 			break;

 		}

 		if(retorno==0)
 		{
 			*list=aux;
 		}

 	}

 	return retorno;


 }
