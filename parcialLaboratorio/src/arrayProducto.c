
#include "arrayProducto.h"

static char categorias[TAM_CATEGORIA][20]={{"DEPORTES"},{" MODA"},{" OTRO"},{"TECNOLOGIA"}};

static int generadorId();
static int eProducto_Vacio(Producto * list, int len);
static int sort_Categoria(Producto *list, int len, int criterio);
static int eProducto_PrintCompra(Producto* arrayProducto,int len,int indice,int cantidad);
static int eProducto_VacioFk(Producto * list, int len,int fkUsuario);
static int eProducto_VacioCategoria(Producto * list, int len,int categoria);
static int eProducto_MostrarUnoCategoria(Producto * list, int len,int categoria);
static int sort_Nombre(Producto *list, int len, int criterio ,int categoria);
static int eProducto_buscarPorNombre(char*s2,char*s);
static int eProducto_PrintbuscarPorNombre(Producto *list, int len,char*s);
static int sort_Stock(Producto *list, int len, int criterio);
static void eProducto_PrintNombre(Producto *list, int len,char*s);

// GENERALES

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
int eProducto_Inicializar(Producto *list, int len){

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
/// @param list recibe un array tipo Producto
/// @param len es el lenaño del del array
/// \return int Devuelve (-1) si Error [Longitud no válida o puntero NULL]
/// o -2 sin espacio libre - (0) si está bien
int eProducto_ObtenerIndexLibre(Producto* list, int len){

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

/// \brief Producto BuscarPorid by Id en devuelve la posición del índice en el arreglo.
/// \param list Producto *
/// \param len int
/// \param id int
///\return Posición del índice de pasajero de retorno o (-1) si [Longitud o
///Puntero NULL recibido o pasajero no encontrado]
int eProducto_BuscarPorid(Producto *list, int len, int id){

	int retorno=-1;
	int i;

		if(list!= NULL && len >0)
		{

			for (i = 0; i < len; i++)
			{

				if(list[i].isEmpty!=LIBRE  && list[i].id== id)
				{

					retorno=i;
					break;

				}

			}


		}


	return retorno;

}

/// \brief Producto BuscarPorid by Id en devuelve la posición del índice en el arreglo.
/// \param list Producto *
/// \param len int
/// \param id int
///\return Posición del índice de pasajero de retorno o (-1) si [Longitud o
///Puntero NULL recibido o pasajero no encontrado]
int eProducto_BuscarPorid_FK(Producto *list, int len, int id,int fk){

	int retorno=-1;
	int i;

		if(list!= NULL && len >0 && fk>0)
		{

			for (i = 0; i < len; i++)
			{

				if(list[i].isEmpty!=LIBRE  && list[i].Fk_idUsuario==fk  && list[i].id== id)
				{
					puts("entro");
					retorno=i;
					break;

				}

			}


		}


	return retorno;

}

/// @fn pide Un Solo Dato al usuario
/// @pre pide datos para llenar un Producto y los valida
/// @post y luego los copia en passanger pasado por parametro
/// @param recibi un tipo Producto
/// @return un 0 si esta todo bien o -1 si esta mal
int eProducto_PediUnDato(Producto * list){

	Producto aux;
	int retorno=-1;

	if(list!=NULL){

		if(utn_getStringLetrasYnumeros(aux.nombreProducto, "\nIngrese nombre producto: ",
				"\nNOMBRE INVALIDO!", MAX_NOMBRE, 2)==0
			&& utn_getNumeroFlotante(&aux.precio,"\nIngrese precio producto: ",
					"\nError precio invalido", 0, 99999999, 2)==0
			&& utn_getShorInt(&aux.categoria, "\n** Categorias **"
					"\n1)Deportes"
					"\n2)Moda"
					"\n3)Otro"
					"\n4)Tecnologia"
					"\nIngrese categoria:", "\nOpcion incorrecta\nIngrese nuevamente: ",
					1, 4, 2)==0
			&& utn_getNumero(&aux.stock, "\nIngrese cantidad a vender: ",
					"\nError cantidad invalida\nIngrese nuevamente:", 1, 9999, 2)==0)
		{

			retorno=0;
			*list=aux;

		}

	}

	return retorno;

}

/// @fn int imprime Producto
/// @param imprimi un Producto solo
void eProducto_MostrarUno(Producto list){

	printf("|%-10d|%-25s|%-15f|%-25s|%-10d|\n",
			list.id,list.nombreProducto,
			list.precio,categorias[list.categoria-1],list.stock);

}

/// @fn imprime un array de Producto que esten cargados
/// @param recibi un puntero tipo Producto
/// @param la longitud para recorrer el array
///\return int Devuelve (-1) si hay error [longitud no válida o puntero NULL] - (0) si está bien
int eProducto_MostrarTodos(Producto *list, int len){

	int retorno = -1;
	int i;

	if(list != NULL && len >=0){

		retorno=0;
		printf("+----------------------------------------------"
				"-------------------------------------------+\n");
		printf("|%-10s|%-25s|%-15s|%-25s|%-10s|\n",
				" ID "," NOMBRE PRODUCTO "," PRECIO "," CATEGORIA "," STOCK ");
		printf("+----------------------------------------------"
						"-------------------------------------------+\n");
		for (i = 0; i < len ; i++) {

			if(list[i].isEmpty==OCUPADO){

				eProducto_MostrarUno(list[i]);
				printf("+----------------------------------------------"
								"-------------------------------------------+\n");

			}

		}

	}


	return retorno;

}

/// \brief Pregunta si las posiciones en el array están vacías,
/// \param list Producto * Puntero del array de Producto
/// \param len int Longitud del arreglo
///\return int Devuelve (-1) si hay error [longitud no válida o puntero NULL] - (0)vacio
/// (1) Cargado
static int eProducto_Vacio(Producto * list, int len){

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

//F

static void eProducto_PrintNombre(Producto *list, int len,char*s){

	int i;

	printf("+----------------------------------------------"
									"-------------------------------------------+\n");
	printf("|%-10s|%-25s|%-15s|%-25s|%-10s|\n",
			" ID "," NOMBRE PRODUCTO "," PRECIO "," CATEGORIA "," STOCK ");
	printf("+----------------------------------------------"
					"-------------------------------------------+\n");

	for (i = 0; i < len; i++)
	{


		if(eProducto_buscarPorNombre(list[i].nombreProducto, s)>0)
		{

			eProducto_MostrarUno(list[i]);

		printf("+----------------------------------------------"
							"-------------------------------------------+\n");
		}



	}


}

static int eProducto_PrintbuscarPorNombre(Producto *list, int len,char*s)
{
	int i;
	int retorno=-1;

	if(list != NULL && len >=0 && s!=NULL )
	{
		retorno =0;

		for (i = 0; i < len; i++)
		{


			if(eProducto_buscarPorNombre(list[i].nombreProducto, s)>0)
			{

				retorno=1;
				break;

			}


		}
	}

	return retorno;

}

static int eProducto_buscarPorNombre(char*s2,char*s)
{
	int retorno=-1;
	char aux[MAX_NOMBRE];
	char aux2[MAX_NOMBRE];


	if(s2 != NULL && s!=NULL )
	{
		retorno =0;
		strncpy(aux,s,MAX_NOMBRE);
		strncpy(aux2,s2,MAX_NOMBRE);
		strupr(aux);
		strupr(aux2);

		if(strcmp(aux,aux2)==0)
		{
			retorno=1;

		}




	}

	return retorno;

}

/// @fn int eProductoFiltroNombre(Producto*, int)
/// @param list
/// @param len
/// @return -2 lista vacia -1 nullo 0 ok
int eProductoFiltroNombre(Producto *list, int len)
{

	int retorno=-1;
	char aux [MAX_NOMBRE];

	if(list != NULL && len >=0 )
	{
		retorno =0;
		if(eProducto_Vacio(list, len))
		{

			if(utn_getStringLetrasYnumeros(aux, "\nIngrese nombre producto: ",
					"\nNOMBRE INVALIDO!", MAX_NOMBRE, 2)==0)
			{

					if(eProducto_PrintbuscarPorNombre(list, len, aux))
					{
						eProducto_PrintNombre(list, len, aux);
						retorno=0;

					}

			}

		}
		else
		{
			//Lista vacia
			retorno =-2;
		}

	}

	return retorno;


}

//PRINT POR CATEGORIA Y NOMBRE

/// @fn int eProducto_MostrarUnoCategoria(Producto*, int, int)
/// @param list puntero Producto
/// @param len tamaño Producto
/// @param categoria a mostrar
/// @return -1 nullos 0 ok
static int eProducto_MostrarUnoCategoria(Producto * list, int len,int categoria){

	int retorno = -1;
		int i;

		if(list != NULL && len >=0){

			retorno=0;
			printf("+----------------------------------------------"
					"-------------------------------------------+\n");
			printf("|%-10s|%-25s|%-15s|%-25s|%-10s|\n",
					" ID "," NOMBRE PRODUCTO "," PRECIO "," CATEGORIA "," STOCK ");
			printf("+----------------------------------------------"
							"-------------------------------------------+\n");
			for (i = 0; i < len ; i++) {

				if(list[i].isEmpty==OCUPADO && list[i].categoria== categoria){

					eProducto_MostrarUno(list[i]);
					printf("+----------------------------------------------"
									"-------------------------------------------+\n");

				}

			}

		}


		return retorno;

}

/// \brief Pregunta si las posiciones en el array están vacías,
/// \param list Producto * Puntero del array de Producto
/// \param len int Longitud del arreglo
///\return int Devuelve (-1) si hay error [longitud no válida o puntero NULL] - (0)vacio
/// (1) Cargado
static int eProducto_VacioCategoria(Producto * list, int len,int categoria){

	int retorno=-1;
	int i;

		if(list != NULL && len >=0){
			retorno=0;
			for (i = 0; i < len; i++)
			{

				if(list[i].isEmpty==OCUPADO && list[i].categoria==categoria)
				{
					retorno=1;
					break;
				}

			}

		}

		return retorno;


	}

///@fn imprime un array de Producto que esten cargados
/// @param recibi un puntero tipo Producto
/// @param la longitud para recorrer el array
///\return int Devuelve (-1) si hay error [longitud no válida o puntero NULL] - (0) si está bien
/// -2 lista vacia -3 error al ordenar
int eProducto_PrintOrdenCategoria_Nombre(Producto *list, int len,int orden){

	int retorno = -1;
	int i;

	if(list != NULL && len >=0 && orden>=0 && orden<=1){

		retorno=0;

		if(eProducto_Vacio(list, len))
		{

			retorno =eProducto_Sort(list, len, orden);

			for(i=1; i<TAM_CATEGORIA+1 ; i++)
			{
				//Verifica si hay de la categoria que quiero imprimir
				if(eProducto_VacioCategoria(list, len, i)>0)
				{
					printf("\n+----------------------------------------------"
								"-------------------------------------------+\n");
					printf("|%58s %-30s|\n",
									" ORDENAMIENTO POR NOMBRES Y CATEGORIAS :",categorias[i-1] );

					sort_Nombre(list, len, orden, i);
					eProducto_MostrarUnoCategoria(list,len,i);

					retorno =0;
				}


			}

		}
		else
		{
			//lista vacias
			retorno = -2;

		}



	}


	return retorno;

}

/// @fn Ordenamiento por nombre y categoria
/// @param list
/// @param len
/// @param criterio
/// @param categoria
/// @return -1 nullos, 0 ok
static int sort_Nombre(Producto *list, int len, int criterio ,int categoria){

	int i;
	Producto aux;
	int flagSwap=0;
	int newLimite=len-1;
	int retorno=-1;

	if(list != NULL && len>0 && criterio>=0 && criterio<=1)
	{
		retorno=0;
		//*copia=*list;
		do{

			flagSwap=0;

			for (i = 0; i < newLimite; i++)
			{

				if(list[i].isEmpty==OCUPADO && list[i].categoria==categoria)
				{
					//Se ordena por categoria
					if(swapCadenas(list[i].nombreProducto , list[i+1].nombreProducto,MAX_NOMBRE, criterio)>0)
					{
						aux= list[i];
						list[i]=list[i+1];
						list[i+1]=aux;
						retorno=1;
						flagSwap=1;

					}

				 }


			 }
			newLimite--;

		}while(flagSwap);

		//*list=*copia;

	}

	return retorno;

}

//FK USUARIO

/// @fn imprime un array de Producto que esten cargados
/// @param recibi un puntero tipo Producto
/// @param la longitud para recorrer el array
///\return int Devuelve (-1) si hay error [longitud no válida o puntero NULL] - (0) si hay productos
/// 1 se ordeno
int eProducto_MostrarFk(Producto *list, int len,int fk){

	int retorno = -1;
	int i;

	if(list != NULL && len >=0){

			retorno=0;
		if(eProducto_VacioFk(list, len, fk))
		{
			if(eProducto_Sort(list, len, 1)==0)
			{
				retorno=1;
				printf("+----------------------------------------------"
								"-------------------------------------------+\n");
				printf("|%-10s|%-25s|%-15s|%-25s|%-10s|\n",
						" ID "," NOMBRE PRODUCTO "," PRECIO "," CATEGORIA "," STOCK ");
				printf("+----------------------------------------------"
								"-------------------------------------------+\n");
				for (i = 0; i < len ; i++)
				{

					if(list[i].isEmpty==OCUPADO && list[i].Fk_idUsuario==fk){

						eProducto_MostrarUno(list[i]);
						printf("+----------------------------------------------"
									"-------------------------------------------+\n");;

					}

				}

			}

		}



	}


	return retorno;

}

/// @fn int eProducto_print_listProductosOrdenados(Producto*, int)
/// @param arrayProducto
/// @param lenProducto
/// @return -2 lista vacia -3 error al ordenar 0 ok
int eProducto_print_listProductosOrdenados(Producto* arrayProducto, int lenProducto){

	int retorno = -1;

	if(arrayProducto != NULL  && lenProducto >0)
	{
		if(eProducto_Vacio(arrayProducto, lenProducto))
		{
			retorno =eProducto_Sort(arrayProducto, lenProducto, 1);

			if(retorno == 0 )
			{

				retorno = eProducto_MostrarTodos(arrayProducto, lenProducto);

			}
		}
		else
		{

			retorno = -2;

		}


	}

	return retorno;


}

/// \brief Pregunta si las posiciones en el array están vacías,
/// \param list Producto * Puntero del array de Producto
/// \param len int Longitud del arreglo
///\return int Devuelve (-1) si hay error [longitud no válida o puntero NULL] - (0)vacio
/// (1) Cargado
static int eProducto_VacioFk(Producto * list, int len,int fkUsuario){

	int retorno=-1;
	int i;

		if(list != NULL && len >=0){
			retorno=0;
			for (i = 0; i < len; i++)
			{

				if(list[i].isEmpty==OCUPADO && list[i].Fk_idUsuario==fkUsuario)
				{
					retorno=1;
					break;
				}

			}

		}

		return retorno;


	}

/// @fn int eProducto_PrintCompra(Producto*, int, int, int)
/// @param arrayProducto
/// @param len
/// @param indice
/// @param cantidad
/// @return -1 nullos 0 ok
static int eProducto_PrintCompra(Producto* arrayProducto,int len,int indice,int cantidad)
{
	int retorno = -1;
	float total;

	if(arrayProducto != NULL && len >=0 && indice >= 0 && cantidad >=1)
	{
		retorno=0;
		total = arrayProducto[indice].precio * cantidad;

		printf("\n+---------------------------------------------------------------+\n");
		printf("|%-20s|%-10s|%-15s|%-15s|","PRODUCTO","CANTIDAD","PRECIO","TOTAL");
		printf("\n+---------------------------------------------------------------+\n");
		printf("|%-20s|%-10d|%-15f|%-15f|",arrayProducto[indice].nombreProducto,cantidad,
				arrayProducto[indice].precio,total);
		printf("\n+---------------------------------------------------------------+\n");

	}


	return retorno;

}


//SORT

///\brief Ordenar los elementos en el arreglo de Producto
/// Indicar orden ARRIBA o ABAJO
///\param lista Producto *
///\param len int
///\param criterio int [1] indica ARRIBA - [0] indica ABAJO
///\return int Devuelve (-1) si hay error [longitud no válida o puntero NULL] - (0) si está bien
/// (-2)Esta vacio (-3)Error al ordenar
int eProducto_Sort(Producto *list, int len, int criterio){

	int retorno = -1;

		if(list != NULL && len >= 0 &&  criterio>=0 && criterio<=1 )
		{
			if(eProducto_Vacio(list, len))
			{

				if(sort_Categoria(list,len,criterio)>=0)//sort>=0)
				{

					retorno=0;


				}
				else
				{
					//Error al ordenar
					retorno=-3;

				}

			}
			else
			{
				//ARREGLO VACIO
				retorno=-2;
			}

		}

		//Retorno =-1 error en los parametros
	return retorno;
}

/// @fn sort_x
/// @param list puntero de Producto
/// @param len longitud del array de  Producto
/// @param criterio orden 1 arriba - 0 abajo
/// @return 0 bien 1 se ordeno -1[parametros nullos o menor a 0]
static int sort_Categoria(Producto *list, int len, int criterio){

	int i;
	Producto aux;
	int flagSwap=0;
	int newLimite=len-1;
	int retorno=-1;

	if(list != NULL && len>0 && criterio>=0 && criterio<=1)
	{
		retorno=0;
		//*copia=*list;
		do{

			flagSwap=0;

			for (i = 0; i < newLimite; i++)
			{

				if(list[i].isEmpty==OCUPADO)
				{
					//Se ordena por categoria
					if(ordenEnteros(list[i].categoria , list[i+1].categoria, criterio)>0)
					{
						aux= list[i];
						list[i]=list[i+1];
						list[i+1]=aux;
						retorno=1;
						flagSwap=1;

					}

				 }


			 }
			newLimite--;

		}while(flagSwap);

		//*list=*copia;

	}

	return retorno;

}

///\brief Ordenar los elementos en el arreglo de Producto
/// Indicar orden ARRIBA o ABAJO
///\param lista Producto *
///\param len int
///\param criterio int [1] indica ARRIBA - [0] indica ABAJO
///\return int Devuelve (-1) si hay error [longitud no válida o puntero NULL] - (0) si está bien
/// (-2)Esta vacio (-3)Error al ordenar
int eProducto_SortStock(Producto *list, int len, int criterio){

	int retorno = -1;

		if(list != NULL && len >= 0 &&  criterio>=0 && criterio<=1 )
		{
			if(eProducto_Vacio(list, len))
			{

				if(sort_Stock(list,len,criterio)>=0)//sort>=0)
				{

					retorno=0;


				}
				else
				{
					//Error al ordenar
					retorno=-3;

				}

			}
			else
			{
				//ARREGLO VACIO
				retorno=-2;
			}

		}

		//Retorno =-1 error en los parametros
	return retorno;
}

/// @fn sort_x
/// @param list puntero de Producto
/// @param len longitud del array de  Producto
/// @param criterio orden 1 arriba - 0 abajo
/// @return 0 bien 1 se ordeno -1[parametros nullos o menor a 0]
static int sort_Stock(Producto *list, int len, int criterio){

	int i;
	Producto aux;
	int flagSwap=0;
	int newLimite=len-1;
	int retorno=-1;

	if(list != NULL && len>0 && criterio>=0 && criterio<=1)
	{
		retorno=0;
		//*copia=*list;
		do{

			flagSwap=0;

			for (i = 0; i < newLimite; i++)
			{

				if(list[i].isEmpty==OCUPADO)
				{
					//Se ordena por categoria
					if(ordenEnteros(list[i].stock , list[i+1].stock, criterio)>0)
					{
						aux= list[i];
						list[i]=list[i+1];
						list[i+1]=aux;
						retorno=1;
						flagSwap=1;

					}

				 }


			 }
			newLimite--;

		}while(flagSwap);

		//*list=*copia;

	}

	return retorno;

}



//ABM

/// @fn int eProducto_compra(Producto*, int)
/// @param arrayProducto
/// @param lenProducto
/// @return -1 datos nullos -2 lista vacia
/// -3 error al ordenar -4 id inexistente
/// -5 cantidad invalida -6 Si o no incorrecto 0 ok
int eProducto_compra(Producto* arrayProducto, int lenProducto,int* cantidad){

	int retorno = -1;
	int idProducto;
	int indice;
	int cantidadAux;

	if(arrayProducto != NULL  && lenProducto >0)
	{
		//MUESTRO ORDENADO
		retorno = eProducto_print_listProductosOrdenados(arrayProducto, lenProducto);
		if(retorno == 0)
		{
			//GUARDO ID
			if(utn_getNumero(&idProducto, "\nIngrese ID a comprar: ", "\nError ID incorrecto.\nIngrese nuevamente: "
					, 1000, 9999, 2)==0)
			{

				//BUSCO EL ID
				indice = eProducto_BuscarPorid(arrayProducto, lenProducto, idProducto);
				if(indice >= 0)
				{

					if(utn_getNumero(&cantidadAux, "\nIngrese cantidad a comprar:",
							"\nError cantidad invalida.\nIngrese nuevamente: ",
							1, arrayProducto[indice].stock, 2)==0)
					{

						if(eProducto_PrintCompra(arrayProducto, lenProducto, indice, cantidadAux)==0
								&& preguntarSoN("\n¿Estas seguro?Si o No: ", 2, "\nRespuesta incorrecta")>0)
						{

							*cantidad = cantidadAux;
							eProducto_ModificacionStock(arrayProducto,lenProducto, idProducto, cantidadAux,0);
							retorno =indice;

						}

						else
						{
							//Si o no incorrecto
							retorno = -6;

						}
					}
					else
					{
						//Cantidad invalida
						retorno =-5;
					}
				}
				else
				{
					//ID inexistente
					retorno = -4;

				}

			}
			else
			{
				//ERROR AL OBTENER ID
				retorno = -4;

			}

		}


	}

	return retorno;


}


/// @fn Producto Cargar los Datos de una list de Producto
/// @param list puntero de Producto
/// @param len longitud de Producto
/// @return -1 punteros nullos len <0 [0]bien
int eProducto_CargarDatos(Producto * list,int len){

	int retorno=-1;
	int indice;
	Producto aux;

		if(list != NULL && len >0)
		{

			indice = eProducto_ObtenerIndexLibre(list, len);

			if(indice>=0 && eProducto_PediUnDato(&aux)==0)
			{

				if(eProducto_Alta(list, len, aux)==0)
				{
					//ok
					retorno=0;

				}

			}
			else
			{
				//lista llena
				retorno = -2;
			}


		}



		return retorno;

}


/// \brief Eliminar un Producto por Id (poner el indicador isEmpty en 1)
///\lista de parámetros Producto *
///\parametro len int
///\return int Retorna (-1) si Error [longitud inválida o NULL
/// puntero o si no puede encontrar un Producto] -
///  (0) si está bien (-2) ERROR AL PEDIR ID
/// (-3) ERROR AL OBTENER INDICE (-4) //NO SE MODIFICO NADA
int eProducto_remove(Producto* list, int len)
{
	int retorno=-1;
	int id;
	int indice;

		if(list!=NULL && len>0)
		{
			if(utn_getNumero(&id, "\nINGRESE ID A DAR DE BAJA: ", "\nERROR! INGRESE NUEVAMENTE: ",
					0, 9999, 2)==0)
			{
				indice = eProducto_BuscarPorid(list, len, id);

				if(indice >= 0)
				{
					printf("\n %60s \n","**** PRODUCTO A DAR DE BAJA ****");
					printf("+----------------------------------------------"
									"-------------------------------------------+\n");
					printf("|%-10s|%-25s|%-15s|%-25s|%-10s|\n",
							" ID "," NOMBRE PRODUCTO "," PRECIO "," CATEGORIA "," STOCK ");
					printf("+----------------------------------------------"
									"-------------------------------------------+\n");
					eProducto_MostrarUno(list[indice]);
					printf("+----------------------------------------------"
														"-------------------------------------------+\n");

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


/// @fn Da de alta un Producto
/// @param lista de Producto
/// @param len longitud del array Gen
/// @return 0 alta Producto (-1) si [Longitud o
///Puntero NULL recibido o pasajero no encontrado] -2 lista llena
int eProducto_Alta(Producto *list, int len,Producto productoDarAlta){

	int retorno=-1;
	int indice;


		if(list != NULL && len >=0)
		{
			indice=eProducto_ObtenerIndexLibre(list, len);

			if(indice>=0)
			{

				list[indice]=productoDarAlta;
				list[indice].id = generadorId();
				list[indice].isEmpty=OCUPADO;
				retorno=0;

			}
			else
			{
				retorno = indice;
			}


		}
		return retorno;

}


/// @fn Baja para Producto
/// @param list arreglo Producto
/// @param len longitud del arreglo
/// @param id del arreglo
/// @return 0 bien -1 error parametros -2 Vacio
int eProducto_Baja(Producto *list, int len,int id){

	int retorno=-1;
	int index;

	if(list != NULL && len >0 && id>=0)
	{
		if(eProducto_Vacio(list, len))
		{
			index = eProducto_BuscarPorid(list, len, id);

			if(index >= 0)
			{
				list[index].isEmpty = BAJA;
				retorno=0;
			}
			else
			{
				retorno = index;
			}


		}
		else
		{
			//Array vacio
			retorno = -2;
		}

	}


	return retorno;

}


/// @fn Modificacion para Producto
/// @param gen arreglo Producto
/// @param len longitud del arreglo
/// @param 1 suma 0 resta
/// @return 0 ok(-1)Datos nullos
int eProducto_ModificacionStock(Producto * list,int len,int id,int stock,int sumaOresta){

	int retorno =-1;
	int indice;

	if(list != NULL && id>=0 && stock >=0 && len>=0 && sumaOresta>=0 && sumaOresta<=1)
	{
		indice =eProducto_BuscarPorid(list, len, id);

		if(indice>=0)
		{
			if(sumaOresta==0)
			{
				list[indice].stock = list[indice].stock -stock;

				if(list[indice].stock == 0)
				{

					list[indice].isEmpty = SIN_STOCK;

				}
				retorno=0;

			}
			if(sumaOresta==1)
			{
				list[indice].stock = list[indice].stock +stock;
				retorno=0;

			}


		}

	}


	return retorno;

}
