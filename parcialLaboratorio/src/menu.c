
#include "menu.h"

/** GENERAL **/
static void erroresInicioSesion(int inicio,Usuario* listUsuario , int lenUsuario, Producto* listProducto,int lenProducto,Tracking* listTracking,int lenTracking);
static void erroresAlta(int registro);

/** PROTOTYPO USUARIO **/
static int subMenuUsuario(int indice,Usuario* listUsuario , int lenUsuario, Producto* listProducto,int lenProducto,Tracking* listTracking,int lenTracking);
static void estadosVentas(Tracking* listTracking,int lenTracking,Producto* listProducto,int lenProducto,Usuario* listUsuario,int indiceUsuario);
static void errorEstadosCompras(int error);
static void  estadoCompras(Tracking* listTracking,int lenTracking,Usuario* listUsuario,int indiceUsuario,Producto* listProducto,int lenProducto);
static void erroresAlComprar(int error);
static void vender(Producto* listProducto,int lenProducto,Usuario* listUsuario, int indiceUsuario );
static void erroresAlReponer(int error);

/** PROTOTYPO ADMIN **/
static int subMenuAdmin(int indice,Usuario* listUsuario , int lenUsuario, Producto* listProducto,
		int lenProducto,Tracking* listTracking,int lenTracking);

/** INICIO FUNCIONES USUARIOS**/
//USUARIO PUNTOS 1,2,3 Y 4
static int subMenuUsuario(int indice,Usuario* listUsuario , int lenUsuario, Producto* listProducto,int lenProducto,Tracking* listTracking,int lenTracking){

	int opc;
	int retorno=0;
	int indiceProducto;
	int cantidad;

	do{

		printf("\n****************************"
				"\n** 1er EXAMEN LAB I - 1H ***"
				"\n********* USUARIO **********"
				"\n****************************");

		retorno=utn_getNumero(&opc, "\n\n1)COMPRAR "
				"\n2)VENDER "
				"\n3)ESTADO DE COMPRAS"
				"\n4)ESTADO DE VENTAS"
				"\n0)SALIR"
				"\nINGRESE OPCION: "
				, "\nOPCION INCORRECTA\nIngrese nuevamente: "
				, 0, 4, 2);

		if(retorno == 0)
		{
			switch(opc)
			{
				case 1: //COMPRAR

					indiceProducto = eProducto_compra(listProducto, lenProducto,&cantidad);
					if(indiceProducto<0)
					{
						erroresAlComprar(indiceProducto);
					}
					else
					{

						if(eTracking_CargarDatos(listTracking, lenTracking, listProducto, indiceProducto, listUsuario, indice, cantidad)<0)
						{
							printf("\nError");
						}
						else
						{
							printf("\nCOMPRA EXITOSA!\n");
						}

					}

					break;
				case 2://VENDER

					vender(listProducto, lenProducto, listUsuario, indice);

					break;
				case 3://ESTADO COMPRAS

					estadoCompras(listTracking, lenTracking, listUsuario, indice,listProducto,lenProducto);

					break;
				case 4: //ESTADO VENTAS

					// HACER QUE INGRESE UNA OPCION 1)LISTADO DE VENTAS FINALIZADO| 2)VER PRODUCTOS EN STOCK
					estadosVentas(listTracking, lenTracking, listProducto, lenProducto, listUsuario, indice);

					break;

			}
		}else
		{
			printf("\nOpcion inexistente. Intentelo mas tarde...");
		}

	}while(opc != 0);

	return retorno;
}

//PUNTO 1
static void erroresAlComprar(int error){

	switch(error)
	{
		case 0: puts("\nSE CANCELO CON EXITO!"); break;
		case -2: puts("\nNO HAY PRODUCTOS A LA VENTA!"); break;
		case -3: puts("\nERROR AL ORDENAR PRODUCTOS!"); break;
		case -4: puts("\nNO EXISTE TAL ID!"); break;
		case -5: puts("\nERROR AL PROCESAR LA CANTIDAD!"); break;
		case -6: puts("\nRESPUESTA INVALIDA! INTENTELO MAS TARDE"); break;
		default: puts("\nHUBO UN ERROR! INTENTELO MAS TARDE"); break;

	}

}

//PUNTO 2 VENDER
static void vender(Producto* listProducto,int lenProducto,Usuario* listUsuario, int indiceUsuario )
{
	int opc;


	if(utn_getNumero(&opc, "\n1)Dar de alta un producto \n2) Reponer stock \nIngrese opcion: ",
			"\nError! Ingrese nuevamente: ", 1, 2, 2)==0)
	{

		switch(opc){

			case 1://ALTA

				if(alta_Producto(listProducto, lenProducto,listUsuario, indiceUsuario)==0)
				{

					printf("\nCarga exitosa!");

					if(print_ProductosdelUsuario(listProducto, lenProducto, listUsuario, indiceUsuario)==-1)
					{
						printf("\nNo tiene productos para vender! ");
					}

				}
				else
				{

					printf("\nNo se puede cagar producto!");

				}

				break;

			case 2: //REponer

					erroresAlReponer(reponerStock(listProducto, lenProducto,listUsuario, indiceUsuario));

				break;

		}

	}



}

static void erroresAlReponer(int error)
{
	switch(error)
	{
		case 0: puts("\nSE CARGO CON EXITO!"); break;
		case -1: puts("\nHUBO UN ERROR!"); break;
		case -2: puts("\nNO TIENE PRODUCTOS PARA REPONER!"); break;
		case -3: puts("\nERROR AL OBTENER ID!"); break;
		case -4: puts("\nID INEXISTENTE!"); break;
		case -5: puts("\nCANTIDAD INVALIDA!"); break;
		case -6: puts("\nHUBO UN ERROR AL CARGAR EL PRODUCTO!"); break;



	}

}

//USUARIO PUNTO 3 COMPRAS
static void  estadoCompras(Tracking* listTracking,int lenTracking,Usuario* listUsuario,int indiceUsuario,Producto* listProducto,int lenProducto)
{
	int opc;

	if(eTracking_MostrarProductosUsuario(listTracking, lenTracking,
			listUsuario, indiceUsuario,listProducto,lenProducto))
	{

		if(utn_getNumero(&opc, "\n1)Cambiar estado \n2)Actualizar estado \n0)Salir \nIngrese opcion: ",
				"\nOpcion incorrecta.\nIngrese nuevamente: ", 0, 2, 2)==0)
		{

			if(opc == 1)
			{

				errorEstadosCompras(eTracking_ConsultaEstado(listTracking, lenTracking, listUsuario,
						indiceUsuario,listProducto,lenProducto));

			}
			if(opc == 2)
			{
				eTracking_MostrarProductosUsuario(listTracking, lenTracking, listUsuario,
						indiceUsuario,listProducto,lenProducto);
			}

		}
		else
		{
			puts("Opcion incorrecta!");
		}

	}
	else
	{
		puts("\nNO TIENE PRODUCTOS COMPRADOS");
	}

}

//USUARIO PUNTO 3 COMPRAS
static void errorEstadosCompras(int error){



	switch(error)
	{
		case 0: puts("\nSE CANCELO CON EXITO!"); break;
		case -1: puts("\nHUBO UN ERROR!"); break;
		case -2: puts("\nID INEXISTENTE!"); break;
		case -3: puts("\nNO EXISTE TAL PRODUCTO!"); break;
		case -4: puts("\nNO HUBO UN MODIFICACION DE ESTADO!"); break;
		case -5: puts("\nNO HAY PRODUCTOS!"); break;



	}

}

//USUARIO PUNTO 4 VENTAS
static void estadosVentas(Tracking* listTracking,int lenTracking,Producto* listProducto,int lenProducto,Usuario* listUsuario,int indiceUsuario){

	// HACER QUE INGRESE UNA OPCION 1)LISTADO DE VENTAS FINALIZADO| 2)VER PRODUCTOS EN STOCK
	int opc;

	printf("\n****************************"
			"\n** 1er EXAMEN LAB I - 1H ***"
			"\n***** ESTADO DE VENTAS *****"
			"\n****************************");

	if(utn_getNumero(&opc, "\n\n1)LISTADO DE VENTAS FINALIZADO \n2)VER PRODUCTOS EN STOCK"
			"\n0)SALIR\nIngrese opcion: ", "\nError! Ingrese nuevamente: ", 0, 2, 2)==0
			&& opc >=1)
	{


		switch(opc)
		{
			case 1:

				if(eTracking_MostrarProductosUsuarioEstado(listTracking, lenTracking, listUsuario,
						indiceUsuario,2,listProducto,lenProducto)==0)
					{
						puts("\nNo hay productos ventas entregados");

					}
				if(eTracking_MostrarProductosUsuarioEstado(listTracking, lenTracking, listUsuario,
						indiceUsuario,3,listProducto,lenProducto)==0)
					{
						puts("\nNo hay productos ventas cancelados");
					}
				break;

			case 2:

				if(print_ProductosdelUsuario(listProducto, lenProducto, listUsuario, indiceUsuario)<=0)
					{
						puts("\nNo hay productos con stock");
					}

				break;


		}

	}
	else if(opc<0)
	{

		puts("\nOPCION INVALIDA INTENTELO MAS TARDE");

	}






}
/** FIN FUNCIONES USUARIOS **/


/** INICIO FUNCIONES ADMINISTRADOR **/
static int subMenuAdmin(int indice,Usuario* listUsuario , int lenUsuario, Producto* listProducto,
		int lenProducto,Tracking* listTracking,int lenTracking)
{
	char opc;
	int retorno=0;
	int errorBaja;
	//int indiceProducto;
	//int cantidad;

		do{

			printf("\n****************************"
					"\n** 1er EXAMEN LAB I - 1H ***"
					"\n****** ADMINISTRADOR *******"
					"\n****************************");

			retorno=utn_getCaracter(&opc, "\n\nA)LISTAR ESTADO DE TODOS LOS USUARIOS "
					"\nB)LISTAR TODOS LOS PRODUCTO POR CATEGORIA "
					"\nC)BAJA DE UN PRODUCTO"
					"\nD)BAJA DE UN USUARIO"
					"\nE)VER TRACKING GLOBAL"
					"\nF)FILTRAR POR NOMBRE"
					"\nG)SALIR"
					"\nINGRESE OPCION: "
					, "\nOPCION INCORRECTA\nINGRESE NUEVAMENTE: "
					,'a', 'g', 2);

			if(retorno == 0)
			{
				switch(opc)
				{
					case 'A':
					case 'a':
							if(eUsuario_MostrarTodos(listUsuario, lenUsuario)<0)
							{
								puts("\nERROR AL LISTAR USUARIOS!");
							}

						break;

					case 'B':
					case 'b':
							if(eProducto_PrintOrdenCategoria_Nombre(listProducto, lenProducto,1)<0)
							{
								puts("\nERROR AL ORDENAR LISTA DE PRODUCTOS!");
							}
						break;
					case 'C':
					case 'c':

							if(eProducto_MostrarTodos(listProducto, lenProducto)==0)
							{
								if(preguntarSoN("\n¿DESEA CONTINUAR? Si - No:", 2, "\nRESPUESTA INCORRECTA!")>0)
								{
									errorBaja = eProducto_remove(listProducto, lenProducto);
									if(errorBaja==0)
									{
										puts("\nBAJA EXITOSA!");
									}
									else if(errorBaja == -3)
									{
										puts("\nNO SE EXISTE TAL ID!");
									}
									else if(errorBaja == -2)
									{
										puts("\nHUBO UN ERROR AL OBTENER ID. INTENTELO MAS TARDE!");
									}
									else
									{
										puts("\nNO SE MODIFICARON LOS PRODUCTOS!");
									}
								}
							}
							else
							{
								puts("\nNO HAY PRODUCTOS CARGADOS!");
							}

						break;
					case 'D':
					case 'd':

							if(eUsuario_MostrarTodos(listUsuario, lenUsuario)==0)
							{
								if(preguntarSoN("\n¿DESEA CONTINUAR? Si - No:", 2, "\nRESPUESTA INCORRECTA!")>0)
								{
									errorBaja = eUsuario_remove(listUsuario, lenUsuario);
									if(errorBaja==0)
									{
										puts("\nBAJA EXITOSA!");
									}
									else if(errorBaja == -3)
									{
										puts("\nNO SE EXISTE TAL ID!");
									}
									else if(errorBaja == -2)
									{
										puts("\nHUBO UN ERROR AL OBTENER ID. INTENTELO MAS TARDE!");
									}
									else
									{
										puts("\nNO SE MODIFICARON LOS USUARIOS!");
									}
								}
							}
							else
							{
								puts("\nNO HAY USUARIOS CARGADOS!");
							}

						break;

					case 'E':
					case 'e':
							if(eTracking_MostrarTodos(listTracking, lenTracking)<1)
							{
								puts("\nNO HAY TRACKINGS REALIZADOS!");
							}
						break;

					case 'F':
					case 'f':
							if(eProducto_SortStock(listProducto, lenProducto, 0)==0)
							{
								if(eProductoFiltroNombre(listProducto, lenProducto)<0)
								{
									puts("\nNO HAY PRODUCTOS PARA MOSTRAR !");
								}

							}
							else
							{

								puts("\nESTA VACIO !");

							}


						break;

					case 'G':
					case 'g':

							opc = 'G';
						break;


				}
			}
			else
			{
				printf("\nOpcion inexistente. Intentelo mas tarde...");
			}

		}while(opc != 'G');

		return retorno;


}

/** FIN FUNCIONES ADMINISTRADOR **/

/** INICIO FUNCIONES GENERALES**/
static void erroresInicioSesion(int indiceUsuario,Usuario* listUsuario , int lenUsuario, Producto* listProducto,int lenProducto,Tracking* listTracking,int lenTracking)
{

	switch(indiceUsuario)
	{
		case -3: printf("\nIntentelo mas tarde\n"); break;
		case -2: printf("\nNO HAY DATOS CARGADOS !\n"); break;
		case -1: printf("\nHUBO UN ERROR !\n"); break;
		default:
			//SEGUN TIPO DE USUARIO

			if(listUsuario[indiceUsuario].tipo==USUARIO)
			{
				//USUARIO
				subMenuUsuario(indiceUsuario,listUsuario,lenUsuario,listProducto,lenProducto,listTracking,lenTracking);

			}
			if(listUsuario[indiceUsuario].tipo==ADMIN)
			{
				//ADMIN
				subMenuAdmin(indiceUsuario,listUsuario,lenUsuario,listProducto,lenProducto,listTracking,lenTracking);

			}


			break;
	}




}

//GENERAL SESION
static void erroresAlta(int registro)
{

	switch(registro)
	{
		case -1: printf("\nHUBO UN ERROR!\n"); break;
		case -2:printf("\nHUBO UN ERROR AL REGISTRARSE! \n");break;
		case -3:printf("\nCORREO YA EXISTENTE! \n");break;
		case 0:printf("\nSE REGISTRO CON EXITO\n");break;
		default:printf("\nHUBO UN ERROR!\n"); break;
	}




}
/** FIN FUNCIONES GENERALES**/

int menu(Usuario* listUsuario , int lenUsuario, Producto* listProducto,int lenProducto,Tracking* listTracking,int lenTracking){

	int retorno =-1;
	int rta;
	int opc;
	int indice;

	if(listUsuario != NULL && lenUsuario >=0)
	{
		retorno =0;
		do{

			printf("\n****************************"
					"\n** 1er EXAMEN LAB I - 1H ***"
					"\n****************************");
			rta=utn_getNumero(&opc, "\n\n1)INGRESAR \n2)REGISTRARSE \n3)CARGA FORZADA\n0)SALIR"
					"\nIngrese opcion:", "\nOpcion incorrecta! \nIngrese nuevamente: ", 0, 3, 2);

			if(rta==0)
			{
				switch(opc)
				{
					case 1:
						printf("\n****************************"
								"\n** 1er EXAMEN LAB I - 1H ***"
								"\n********** LOGIN ***********"
								"\n****************************\n");
						indice=eUsuario_InicioSesion(listUsuario,lenUsuario);
						erroresInicioSesion(indice, listUsuario, lenUsuario, listProducto, lenProducto, listTracking, lenTracking);

						break;
					case 2:
						printf("\n****************************"
								"\n** 1er EXAMEN LAB I - 1H ***"
								"\n******* REGISTRARSE ********"
								"\n****************************\n");

						erroresAlta(eUsuario_CargarDatos(listUsuario, lenUsuario));

						break;

					case 3:

						harcodeo(listProducto, lenProducto, listUsuario, lenUsuario);
						harcodeoTracking(listTracking, lenTracking,listProducto, lenProducto);

						break;

					default: printf("\nGracias. Vuelva prontos!"); break;

				}

				}
			else
			{
				printf("\nOpcion inexistente intentelo mas tarde");
				opc=0;
			}

		}while(opc!=0);


	}

	return retorno;

}




