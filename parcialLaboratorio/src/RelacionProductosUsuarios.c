
#include "RelacionProductosUsuarios.h"

void harcodeo(Producto * listP,int lenP,Usuario * listU,int lenU){

	Producto aux;

	Usuario auxUsuario;


	strncpy(auxUsuario.correo,"FEDECARDOZO@GMAIL.COM",MAX_CORREO);
	strncpy(auxUsuario.password,"anuel12",MAX_PASSWORD);
	strncpy(auxUsuario.direccion,"pasaje calabria 1590",MAX_DIRECCION);
	auxUsuario.codigoPostal = 1828;
	auxUsuario.tipo = 1;

	eUsuario_Alta(listU, lenU, auxUsuario);

	strncpy(auxUsuario.correo,"FEDE@G.COM",MAX_CORREO);
	strncpy(auxUsuario.password,"1234",MAX_PASSWORD);
	strncpy(auxUsuario.direccion,"calle falsa 123",MAX_DIRECCION);
	auxUsuario.codigoPostal = 1152;
	auxUsuario.tipo = 1;

	eUsuario_Alta(listU, lenU, auxUsuario);

	strncpy(auxUsuario.correo,"CARS@G.COM",MAX_CORREO);
	strncpy(auxUsuario.password,"1235",MAX_PASSWORD);
	strncpy(auxUsuario.direccion,"carriego 321",MAX_DIRECCION);
	auxUsuario.codigoPostal = 1125;
	auxUsuario.tipo = 1;

	eUsuario_Alta(listU, lenU, auxUsuario);

	strncpy(auxUsuario.correo,"MINI@G.COM",MAX_CORREO);
	strncpy(auxUsuario.password,"asdasd",MAX_PASSWORD);
	strncpy(auxUsuario.direccion,"pasaje calabria 1590",MAX_DIRECCION);
	auxUsuario.codigoPostal = 1828;
	auxUsuario.tipo = 2;

	eUsuario_Alta(listU, lenU, auxUsuario);

	//PRODUCTOS

	strncpy(aux.nombreProducto,"Botines",MAX_NOMBRE);
	aux.precio = 1828;
	aux.categoria = 1;
	aux.stock = 10;
	aux.Fk_idUsuario = 1000;

	eProducto_Alta(listP, lenP, aux);

	strncpy(aux.nombreProducto,"Estufa",MAX_NOMBRE);
	aux.precio = 2900;
	aux.categoria = 3;
	aux.stock = 5;
	aux.Fk_idUsuario = 1002;


	eProducto_Alta(listP, lenP, aux);

	strncpy(aux.nombreProducto,"Vestido",MAX_NOMBRE);
	aux.precio = 3028;
	aux.categoria = 2;
	aux.stock = 2;
	aux.Fk_idUsuario = 1001;


	eProducto_Alta(listP, lenP, aux);

	strncpy(aux.nombreProducto,"Notebook",MAX_NOMBRE);
	aux.precio = 3028;
	aux.categoria = 4;
	aux.stock = 7;
	aux.Fk_idUsuario = 1003;


	eProducto_Alta(listP, lenP, aux);

	strncpy(aux.nombreProducto,"Camisetas",MAX_NOMBRE);
	aux.precio = 1828;
	aux.categoria = 1;
	aux.stock = 10;
	aux.Fk_idUsuario = 1000;

	eProducto_Alta(listP, lenP, aux);

	strncpy(aux.nombreProducto,"Lavarropa",MAX_NOMBRE);
	aux.precio = 2900;
	aux.categoria = 3;
	aux.stock = 5;
	aux.Fk_idUsuario = 1002;


	eProducto_Alta(listP, lenP, aux);

	strncpy(aux.nombreProducto,"Smoking",MAX_NOMBRE);
	aux.precio = 3028;
	aux.categoria = 2;
	aux.stock = 2;
	aux.Fk_idUsuario = 1001;


	eProducto_Alta(listP, lenP, aux);

	strncpy(aux.nombreProducto,"PS5",MAX_NOMBRE);
	aux.precio = 3028;
	aux.categoria = 4;
	aux.stock = 7;
	aux.Fk_idUsuario = 1003;


	eProducto_Alta(listP, lenP, aux);

	strncpy(aux.nombreProducto,"Corsa",MAX_NOMBRE);
	aux.precio = 1828;
	aux.categoria = 3;
	aux.stock = 15;
	aux.Fk_idUsuario = 1000;

	eProducto_Alta(listP, lenP, aux);

	strncpy(aux.nombreProducto,"Ferrari",MAX_NOMBRE);
	aux.precio = 2900;
	aux.categoria = 3;
	aux.stock = 10;
	aux.Fk_idUsuario = 1002;


	eProducto_Alta(listP, lenP, aux);

	strncpy(aux.nombreProducto,"Zapatos",MAX_NOMBRE);
	aux.precio = 3028;
	aux.categoria = 2;
	aux.stock = 2;
	aux.Fk_idUsuario = 1001;


	eProducto_Alta(listP, lenP, aux);

	strncpy(aux.nombreProducto,"Crocs",MAX_NOMBRE);
	aux.precio = 3028;
	aux.categoria = 4;
	aux.stock = 7;
	aux.Fk_idUsuario = 1003;


	eProducto_Alta(listP, lenP, aux);

	strncpy(aux.nombreProducto,"Corsa",MAX_NOMBRE);
	aux.precio = 1828;
	aux.categoria = 3;
	aux.stock = 10;
	aux.Fk_idUsuario = 1000;

	eProducto_Alta(listP, lenP, aux);

	strncpy(aux.nombreProducto,"Ferrari",MAX_NOMBRE);
	aux.precio = 2900;
	aux.categoria = 3;
	aux.stock = 5;
	aux.Fk_idUsuario = 1002;


	eProducto_Alta(listP, lenP, aux);

	strncpy(aux.nombreProducto,"Zapatos",MAX_NOMBRE);
	aux.precio = 3028;
	aux.categoria = 2;
	aux.stock = 5;
	aux.Fk_idUsuario = 1001;


	eProducto_Alta(listP, lenP, aux);

	strncpy(aux.nombreProducto,"Crocs",MAX_NOMBRE);
	aux.precio = 3028;
	aux.categoria = 4;
	aux.stock = 2;
	aux.Fk_idUsuario = 1003;


	eProducto_Alta(listP, lenP, aux);



}

/// @fn int alta_Producto(Producto*, int, Usuario*, int, int)
/// @param arrayProducto
/// @param lenProducto
/// @param arrayUsuario
/// @param lenUsuario
/// @param indice
/// @return -1 datos nullos -2 lista llena 0 bien
int alta_Producto(Producto* arrayProducto, int lenProducto,Usuario * arrayUsuario,int indiceUsuario)
{

	int retorno =-1;
	Producto aux;
	int indexProducto;

	if(arrayProducto != NULL  && lenProducto >0 && arrayUsuario != NULL && indiceUsuario >=0 )
	{
		indexProducto = eProducto_ObtenerIndexLibre(arrayProducto, lenProducto);

		if(indexProducto >=0)
		{

			if(eProducto_PediUnDato(&aux)==0)
			{
			//Guardar id usuario en fk producto del que vende
				aux.Fk_idUsuario = arrayUsuario[indiceUsuario].idUsuario;
				if(eProducto_Alta(arrayProducto, lenProducto, aux)==0)
				{
					retorno=0;

				}


			}

		}
		else if(indexProducto == -2)
		{
			//Lista llena
			retorno = -2;

		}




	}



	return retorno;

}

/// @fn int print_ProductosdelUsuario(Producto*, int, Usuario*, int)
/// @param arrayProducto
/// @param lenProducto
/// @param arrayUsuario
/// @param indiceUsuario
/// @return -1 datos nullos 0 no hay producto 1 se ordeno
int print_ProductosdelUsuario(Producto* arrayProducto, int lenProducto,Usuario * arrayUsuario,int indiceUsuario){

	int retorno = -1;
	int idUsu;

	if(arrayProducto != NULL  && lenProducto >0 && arrayUsuario != NULL && indiceUsuario >=0 )
	{
		idUsu = arrayUsuario[indiceUsuario].idUsuario;

		retorno =eProducto_MostrarFk(arrayProducto, lenProducto, idUsu);

	}


	return retorno;

}

/// @fn Reponer stock
/// @param arrayProducto
/// @param lenProducto
/// @param arrayUsuario
/// @param lenUsuario
/// @param indice
/// @return -1 datos nullos  0 bien
/// -2 NO TIENE PRODUCTOS PARA REPONER
/// -3 ERROR AL OBTENER ID
/// -4 ID inexistente
/// -5 Cantidad invalida
/// -6 Si o no incorrecto
int reponerStock(Producto* arrayProducto, int lenProducto,Usuario * arrayUsuario,int indiceUsuario)
{

	int retorno =-1;
	int indexProducto;
	int idProducto;
	int agregar;

	if(arrayProducto != NULL  && lenProducto >0 && arrayUsuario != NULL && indiceUsuario >=0 )
	{
		//MUESTRO PRODUCTO
		if(print_ProductosdelUsuario(arrayProducto, lenProducto, arrayUsuario, indiceUsuario))
		{
			//LE PIDO EL ID QUE QUIERE REPONER
			if(utn_getNumero(&idProducto, "\nIngrese id a reponer: ", "\nError! Ingrese nuevamente: "
					, 1, 9999, 2)==0)
			{
				//BUSCO EL ID
				indexProducto = eProducto_BuscarPorid_FK(arrayProducto, lenProducto, idProducto,arrayUsuario[indiceUsuario].idUsuario);

				if(indexProducto >= 0)
				{
					//LE PIDO LA CANTIDAD A REPONER
					if(utn_getNumero(&agregar, "\nIngrese cantidad a reponer:",
							"\nError cantidad invalida.\nIngrese nuevamente: ",
							1, 9999, 2)==0)
					{

						if(preguntarSoN("\n¿Estas seguro?Si o No: ", 2, "\nRespuesta incorrecta")>0)
						{


							retorno = eProducto_ModificacionStock(arrayProducto,lenProducto, idProducto, agregar,1);

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
				retorno = -3;

			}

		}
		else
		{
			//NO TIENE PRODUCTOS PARA REPONER
			retorno = -2;
		}


	}



	return retorno;



}
