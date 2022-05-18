
#include "arrayTracking.h"


long int time_Current(void){
	return time(NULL);
}

long int time_Add(double secondsAdd){
	return time_Current() + secondsAdd;
}
long int time_Llegada(double secondsAdd){
	return secondsAdd-time_Current();
}

static int generadorId();
static int eTracking_Vacio(Tracking * list, int len);
static int eTracking_VacioUsuarioVentas(Tracking * list,int fkUsuario, int len ,int estado);
static int eTracking_VacioUsuarioCompras(Tracking * list,int fkUsuario, int len);
static void eTracking_ActualizarList(Tracking * list,int len);

void harcodeoTracking(Tracking * listTracking,int lenTracking , Producto* listProducto, int lenProducto){

	Tracking aux;

	//Usuario 1000
	aux.Fk_UsuarioComprador = 1000;
	aux.idProducto= 1001;
	aux.Fk_UsuarioVendedor = 1002;
	aux.cantidad = 2;
	aux.distanciaKM = 20;
	aux.horaLlegada = time_Add(20);
	eProducto_ModificacionStock(listProducto, lenProducto,aux.idProducto , aux.cantidad, 0);

	eTracking_Alta(listTracking, lenTracking, aux);

	aux.Fk_UsuarioComprador = 1000;
	aux.idProducto = 1002;
	aux.Fk_UsuarioVendedor = 1001;
	aux.cantidad = 1;
	aux.distanciaKM = 40;
	aux.horaLlegada = time_Add(40);
	eProducto_ModificacionStock(listProducto, lenProducto,aux.idProducto , aux.cantidad, 0);

	eTracking_Alta(listTracking, lenTracking, aux);

	aux.Fk_UsuarioComprador = 1000;
	aux.idProducto = 1003;
	aux.Fk_UsuarioVendedor = 1001;
	aux.cantidad = 5;
	aux.distanciaKM = 30;
	aux.horaLlegada = time_Add(30);
	eProducto_ModificacionStock(listProducto, lenProducto,aux.idProducto , aux.cantidad, 0);

	eTracking_Alta(listTracking, lenTracking, aux);

	//Usuario 1001

	aux.Fk_UsuarioComprador = 1001;
	aux.idProducto = 1000;
	aux.Fk_UsuarioVendedor = 1000;
	aux.cantidad = 5;
	aux.distanciaKM = 50;
	aux.horaLlegada = time_Add(50);
	eProducto_ModificacionStock(listProducto, lenProducto,aux.idProducto , aux.cantidad, 0);

	eTracking_Alta(listTracking, lenTracking, aux);

	aux.Fk_UsuarioComprador = 1001;
	aux.idProducto = 1001;
	aux.Fk_UsuarioVendedor = 1002;
	aux.cantidad = 2;
	aux.distanciaKM = 80;
	aux.horaLlegada = time_Add(80);
	eProducto_ModificacionStock(listProducto, lenProducto,aux.idProducto , aux.cantidad, 0);

	eTracking_Alta(listTracking, lenTracking, aux);

	aux.Fk_UsuarioComprador = 1001;
	aux.idProducto = 1003;
	aux.Fk_UsuarioVendedor = 1001;
	aux.cantidad = 2;
	aux.distanciaKM = 150;
	aux.horaLlegada = time_Add(150);
	eProducto_ModificacionStock(listProducto, lenProducto,aux.idProducto , aux.cantidad, 0);

	eTracking_Alta(listTracking, lenTracking, aux);


	//Usuario 1002

	aux.Fk_UsuarioComprador = 1002;
	aux.idProducto = 1003;
	aux.Fk_UsuarioVendedor = 1001;
	aux.cantidad = 2;
	aux.distanciaKM = 80;
	aux.horaLlegada = time_Add(80);
	eProducto_ModificacionStock(listProducto, lenProducto,aux.idProducto , aux.cantidad, 0);

	eTracking_Alta(listTracking, lenTracking, aux);

	aux.Fk_UsuarioComprador = 1002;
	aux.idProducto = 1000;
	aux.Fk_UsuarioVendedor = 1000;
	aux.cantidad = 2;
	aux.distanciaKM = 30;
	aux.horaLlegada = time_Add(30);
	eProducto_ModificacionStock(listProducto, lenProducto,aux.idProducto , aux.cantidad, 0);

	eTracking_Alta(listTracking, lenTracking, aux);

}

//GENERALES

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
int eTracking_Inicializar(Tracking *list, int len){

	int retorno=-1;
	int i;

	if(list != NULL && len >0){

		for (i = 0; i < len; i++) {

			list[i].isEmpty=VACIO;

		}

		retorno = 0;

	}

	return retorno;


}

/// @fn ObtenerIndexLibre
/// @param list recibe un array tipo Tracking
/// @param len es el lenaño del del array
/// \return int Devuelve (-1) si Error [Longitud no válida o puntero NULL]
/// o -2 sin espacio libre - (0) si está bien
int eTracking_ObtenerIndexLibre(Tracking* list, int len){

	int retorno=-1;
	int i;


		if (list != NULL && len > 0)
		{

		for (i = 0; i < len; i++)
		{

			if (list[i].isEmpty == VACIO)
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

/// \brief Tracking BuscarPorid by Id en devuelve la posición del índice en el arreglo.
/// \param list Tracking *
/// \param len int
/// \param id int
///\return Posición del índice de pasajero de retorno o (-1) si [Longitud o
///Puntero NULL recibido o pasajero no encontrado]
int eTracking_BuscarPorid(Tracking *list, int len, int id){

	int retorno=-1;
	int i;

		if(list!= NULL && len >0)
		{

			for (i = 0; i < len; i++)
			{

				if(list[i].idTracking== id)
				{

					retorno=i;
					break;

				}

			}


		}


	return retorno;

}

/// \brief Pregunta si las posiciones en el array están vacías,
/// \param list Tracking * Puntero del array de Tracking
/// \param len int Longitud del arreglo
///\return int Devuelve (-1) si hay error [longitud no válida o puntero NULL] - (0)vacio
/// (1) Cargado
static int eTracking_Vacio(Tracking * list, int len){

	int retorno=-1;
	int i;

		if(list != NULL && len >=0){
			retorno=0;
			for (i = 0; i < len; i++)
			{

				if(list[i].isEmpty != VACIO)
				{
					retorno=1;
					break;
				}

			}

		}

		return retorno;


	}

/// @fn int imprime Tracking
/// @param imprimi un Tracking solo
void eTracking_MostrarUno(Tracking list){

	char estado [4][20]={{"LIBRE"},{"EN VIAJE"},{"ENTREGADO"},{"CANCELADO"}};

	printf("|%-15d|%-19s|%-15d|%-15d|",
			list.idTracking,estado[list.isEmpty],list.Fk_UsuarioComprador,list.Fk_UsuarioVendedor);

}

/// @fn int eTracking_MostrarTodos(Tracking*, int)
/// @param list
/// @param len
/// @return -1 nullos 0 ok 1 imprime uno aunque sea
/// -2 lista vacia
int eTracking_MostrarTodos(Tracking * list,int len){

	int i;
	int retorno=-1;

	if(list != NULL && len>0)
	{
		retorno=0;
		if(eTracking_Vacio(list, len)>0)
		{
			eTracking_ActualizarList(list, len);
			printf("+-------------------------------------------------------------------+\n");
			printf("|%38s %29s","TRACKING GLOBAL","|");
			printf("\n+-------------------------------------------------------------------+\n");
			printf("|%-15s|%-19s|%-15s|%-15s|\n",
							" ID TRACKING","   ESTADO"," ID COMPRADOR","  ID VENDEDOR");
			printf("+-------------------------------------------------------------------+\n");

			for (i = 0; i < len ; i++)
			{

				if(list[i].isEmpty!=VACIO)
				{
					retorno = 1;
					eTracking_MostrarUno(list[i]);

					printf("\n+-------------------------------------------------------------------+\n");


				}

			}

		}
		else
		{
			//LISTA VACIA
			retorno = -2;
		}


	}

	return retorno;

}

//TRACKING PRODUCTO USUARIO

/// @fn int imprime Tracking
/// @param imprimi un Tracking solo
void eTracking_Estado(Tracking list,Producto listProducto){

	char estado [4][20]={{"LIBRE"},{"EN VIAJE"},{"ENTREGADO"},{"CANCELADO"}};
	int long horallegada = list.horaLlegada - time_Current();

	if(horallegada <= 0)
	{

		horallegada =0;

	}

	printf("|%-11d|%-19s|%-15d|%-3ld%-12s|%-14s|",list.idTracking,listProducto.nombreProducto,
			list.cantidad,horallegada,"Segundos",estado[list.isEmpty]);

}


//VENTAS
/// \brief Pregunta si las posiciones en el array están vacías,
/// \param list Tracking * Puntero del array de Tracking
/// \param len int Longitud del arreglo
///\return int Devuelve (-1) si hay error [longitud no válida o puntero NULL] - (0)vacio
/// (1) Cargado
static int eTracking_VacioUsuarioVentas(Tracking * list,int fkUsuario, int len ,int estado){

	int retorno=-1;
	int i;

		if(list != NULL && len >=0){
			retorno=0;
			for (i = 0; i < len; i++)
			{

				if(list[i].Fk_UsuarioVendedor==fkUsuario && list[i].isEmpty==estado)
				{
					retorno=1;
					break;
				}

			}

		}

		return retorno;


	}

//VENTAS
/// @fn imprime un array de Tracking que esten cargados
/// @param recibi un puntero tipo Tracking
/// @param la longitud para recorrer el array
/// @param estado EN_VIAJE 1 ENTREGADO 2 CANCELADO 3
///return int Devuelve (-1) si hay error [longitud no válida o puntero NULL] - (0) esta vacio
/// 1 ok
int eTracking_MostrarProductosUsuarioEstado(Tracking *list, int len,Usuario* arrayUsuario,
		int indiceUsuario,int estado,Producto * listProducto, int lenProducto){

	int retorno = -1;
	int i;
	int indiceProducto;
	char sEstado [4][20]={{"LIBRE     "},{"EN VIAJE  "},{"ENTREGADOS"},{"CANCELADOS"}};

	if(list != NULL && len >=0 && indiceUsuario >= 0 && estado>=1 && estado<=3
			&& listProducto != NULL && lenProducto>0)
	{

		eTracking_ActualizarList( list,len);

		if(eTracking_VacioUsuarioVentas(list, arrayUsuario[indiceUsuario].idUsuario, len, estado))
		{

			retorno=1;

			printf("+----------------------------------------"
											"--------------------------------------+\n");
			printf("| %47s %s                   |\n",
							" ESTADOS DE PRODUCTOS ",sEstado[estado]);

			printf("+----------------------------------------"
									"--------------------------------------+\n");
			printf("|%-11s|%-19s|%-15s|%-15s|%-14s|\n",
								"ID TRACKING"," PRODUCTO"," CANTIDAD"," HORA LLEGADA","ESTADO");
			printf("+--------------------------------------------"
									"----------------------------------+\n");
			for (i = 0; i < len ; i++)
			{

				if(list[i].isEmpty==estado && list[i].Fk_UsuarioVendedor== arrayUsuario[indiceUsuario].idUsuario)
				{
					indiceProducto = eProducto_BuscarPorid(listProducto, lenProducto, list[i].idProducto);
					eTracking_Estado(list[i],listProducto[indiceProducto]);
					printf("\n+-------------------------------------------"
										"-----------------------------------+\n");

				}

			}

	   }
	   else
	   {

		   retorno = 0;

	   }

	}


	return retorno;

}


//COMPRAS
/// @fn imprime un array de Tracking que esten cargados
/// @param recibi un puntero tipo Tracking
/// @param la longitud para recorrer el array
///\return int Devuelve (-1) si hay error [longitud no válida o puntero NULL] - (0) vacio
/// 1 cargado
int eTracking_MostrarProductosUsuario(Tracking *list, int len,Usuario* arrayUsuario,
		int indiceUsuario,Producto * listProducto, int lenProducto){

	int retorno = -1;
	int i;
	int indiceProducto;

	if(list != NULL && len >=0 && indiceUsuario >= 0
			&& arrayUsuario != NULL && listProducto != NULL && lenProducto>0)
	{
		eTracking_ActualizarList( list,len);
		retorno=0;

		if(eTracking_VacioUsuarioCompras(list, arrayUsuario[indiceUsuario].idUsuario, len))
		{

			retorno = 1;
			printf("+----------------------------------------"
									"--------------------------------------+\n");
			printf("|%-11s|%-19s|%-15s|%-15s|%-14s|\n",
							"ID TRACKING"," PRODUCTO "," CANTIDAD"," HORA LLEGADA","ESTADO");
			printf("+--------------------------------------------"
									"----------------------------------+\n");
			for (i = 0; i < len ; i++)
			{

				if(list[i].isEmpty>=EN_VIAJE && list[i].Fk_UsuarioComprador== arrayUsuario[indiceUsuario].idUsuario)
				{

					indiceProducto = eProducto_BuscarPorid(listProducto, lenProducto, list[i].idProducto);
					eTracking_Estado(list[i],listProducto[indiceProducto]);
						printf("\n+-------------------------------------------"
											"-----------------------------------+\n");


				}

			}
	    }
	}


	return retorno;

}

//COMPRAS
/// @fn int eTracking_ConsultaEstado(Tracking*, int, Usuario*, int)
/// @param listTracking
/// @param lenTracking
/// @param listUsuario
/// @param indiceUsuario
/// @return -1 nullos -2 id incorrecto
/// -3 no existe tal Tracking -4 contesto S-N negativamente
/// -5 no tiene productos 0 ok
int eTracking_ConsultaEstado(Tracking* listTracking,int lenTracking, Usuario * listUsuario, int indiceUsuario, Producto*listProducto, int lenProducto){

	int retorno = -1;
	int idTracking;
	int indexTracking;

		if(listTracking != NULL && lenTracking >= 0 && listUsuario != NULL && indiceUsuario >=0
				&& listProducto != NULL && lenProducto>0 )
		{
			//tener el id del tracking
			if(utn_getNumero(&idTracking, "\nIngrese id a modificar: ",
					"Error!\nIngrese nuevamente: ", 1000, 9999, 2)==0)
			{
				indexTracking = eTracking_BuscarPorid(listTracking, lenTracking, idTracking);

				if(indexTracking>=0)
				{
					if(listTracking[indexTracking].Fk_UsuarioComprador == listUsuario[indiceUsuario].idUsuario
						&&  listTracking[indexTracking].isEmpty == EN_VIAJE)
					{

						if(preguntarSoN("\nEstas seguro de cancelar el envio? Si - No: ", 2, "\nRespuesta incorrecta")>0)
						{

							eProducto_ModificacionStock(listProducto, lenProducto, listTracking[indexTracking].idProducto,
									listTracking[indexTracking].cantidad,1);

							retorno = eTracking_ModificarEstado(listTracking, indexTracking, CANCELADO);

						}
						else
						{
							//No estaba seguro
							retorno = -4;

						}


					}
					else
					{

						//NO tiene productos
						retorno = -5;

					}

				}
				else
				{

					//no existe tal Tracking
					retorno = -3;

				}


			}
			else
			{
				// id incorrecto
				retorno = -2;
			}



		}


	return retorno;

}

//COMPRAS
/// \brief Pregunta si las posiciones en el array están vacías,
/// \param list Tracking * Puntero del array de Tracking
/// \param len int Longitud del arreglo
///\return int Devuelve (-1) si hay error [longitud no válida o puntero NULL] - (0)vacio
/// (1) Cargado
static int eTracking_VacioUsuarioCompras(Tracking * list,int fkUsuario, int len){

	int retorno=-1;
	int i;

		if(list != NULL && len >=0){
			retorno=0;
			for (i = 0; i < len; i++)
			{

				if(list[i].Fk_UsuarioComprador==fkUsuario)
				{
					retorno=1;
					break;
				}

			}

		}

		return retorno;


	}

/// @fn int eTracking_calculoDistancia(int)
/// @param codigoPostal
/// @return -1 codigoPostal<0 distancia>0
static int eTracking_calculoDistancia(int codigoPostal){

	int retorno=-1;;
	int distancia;

	if(codigoPostal > 0)
	{
		retorno=0;

		if(codigoPostal>=1 && codigoPostal <=1000)
		{
			distancia = 20;
		}
		if (codigoPostal >= 1001 && codigoPostal <= 3000)
		{
			distancia = 30;
		}
		if (codigoPostal >= 3001 && codigoPostal <= 5000)
		{
			distancia = 50;
		}
		if (codigoPostal >= 5001 && codigoPostal <= 8000)
		{
			distancia = 80;
		}
		if (codigoPostal >= 8001 && codigoPostal <= 9999)
		{
			distancia = 150;
		}
		retorno= distancia;

	}

	return retorno;

}

/// @fn void eTracking_ActualizarList(Tracking*, int)
/// @post actualiza los estados y la hora de llegada
/// @param list
/// @param len
static void eTracking_ActualizarList(Tracking * list,int len)
{
	long int horallegada;
	int i;

	for(i=0; i<len; i++)
	{

		if(list[i].isEmpty==EN_VIAJE)
		{
			horallegada=list[i].horaLlegada-time_Current();

			if(horallegada <= 0)
			{
				list[i].horaLlegada = 0;
				eTracking_ModificarEstado(list, i, ENTREGADO);

			}


		}
		if(list[i].isEmpty==CANCELADO)
		{

			list[i].horaLlegada = 0;

		}


	}


}


//ABM

/// @fn Tracking Cargar los Datos de una list de Tracking
/// @param list puntero de Tracking
/// @param len longitud de Tracking
/// @return -1 punteros nullos len <0 [0]bien
int eTracking_CargarDatos(Tracking * listTracking,int lenTracking,Producto* arrayProducto, int indiceProducto,Usuario *listUsuario, int indiceUsuario,int cantidad){

	int retorno = -1;
	int distancia;
	Tracking aux;

	if(arrayProducto != NULL  && listTracking != NULL && listUsuario != NULL
			&& lenTracking >0 && indiceProducto>=0 && indiceUsuario >=0)
	{

		distancia = eTracking_calculoDistancia(listUsuario[indiceUsuario].codigoPostal);

		aux.idProducto = arrayProducto[indiceProducto].id;
		aux.Fk_UsuarioComprador = listUsuario[indiceUsuario].idUsuario;
		aux.Fk_UsuarioVendedor = arrayProducto[indiceProducto].Fk_idUsuario;
		aux.cantidad = cantidad;
		aux.distanciaKM = distancia;
		aux.horaLlegada = time_Add(distancia);

		retorno=eTracking_Alta(listTracking, lenTracking, aux);

	}



	return retorno;

}


/// @fn int eTracking_Alta(Tracking*, int, Tracking)
/// @param listTracking
/// @param lenTracking
/// @param aDarseAlta
/// @return -1 nullos -2 lista llena 0 ok
int eTracking_Alta(Tracking* listTracking,int lenTracking,Tracking aDarseAlta){

	int retorno=-1;
	int index;

	if(listTracking != NULL && lenTracking> 0)
	{

		index = eTracking_ObtenerIndexLibre(listTracking, lenTracking);

		if(index >= 0)
		{
			retorno=0;
			listTracking[index] = aDarseAlta;
			listTracking[index].idTracking = generadorId();
			listTracking[index].isEmpty = EN_VIAJE;

		}
		else
		{
			retorno = index;

		}



	}



	return retorno;

}


/// @fn int eTracking_ModificarEstado(Tracking*, int, int)
/// @param listTracking
/// @param indice
/// @param estado
/// @return -1 nullo 0 ok
int eTracking_ModificarEstado(Tracking* listTracking,int indice,int estado){

	int retorno = -1;

	if(listTracking != NULL && indice >= 0)
	{

		listTracking[indice].isEmpty = estado;
		retorno=0;

	}

	return retorno;
}

