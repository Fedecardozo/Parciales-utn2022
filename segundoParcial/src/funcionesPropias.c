
#include "./inc/funcionesPropias.h"

/// @fn Preguntar por si o por no
/// @param msj
/// @param intentos
/// @param msjError
/// @return 1 si 0 no -1 mal los datos -2 Contesto mal
int preguntarSoN(char*msj,int intentos, char*msjError){

	int retorno=-1;
	char respuesta[2];

	if(msj != NULL && msjError != NULL && intentos >=0)
	{

		do{

			printf(msj);

			if(myGets(respuesta,sizeof(respuesta))==0)
			{
				strupr(respuesta);
				if(respuesta[0] =='S' || strcmp(respuesta,"SI")==0)
				{
					retorno=1;
					break;

				}
				if( respuesta[0] =='N'|| strcmp(respuesta,"NO")==0)
				{
					retorno=0;
					break;

				}
				if(intentos>0)
				{

					printf(msjError);
					retorno=-2;

				}

				intentos--;

			}

		}while(intentos>=0);


	}

	return retorno;


}

/// @fn compara 2 de cadenas
/// @param cadena puntero
/// @param cadena2 puntero
/// @param len longitud de las cadenas
/// @param order para en que orden compara 1 para arriba
/// 0 para abajo
/// @return 1 hay swap 0 no hubo swap -1 mal los parametros
int swapCadenas(char *cadena,char *cadena2,int len, int order){

	int retorno=-1;
	char cadenaAuxiliar[len];
	char cadenaAuxiliar2[len];

	if(cadena != NULL && cadena != NULL && len>0 && order>=0 && order<=1)
	{

		//COPIO LAS CADENAS
		//*cadenaAuxiliar = *cadena;
		strncpy(cadenaAuxiliar,cadena,len);
		//*cadenaAuxiliar2 = *cadena2;
		strncpy(cadenaAuxiliar2,cadena2,len);

		//CONVIERTO A MAYUSCULAS LAS CADENAS
		strupr(cadenaAuxiliar);
		strupr(cadenaAuxiliar2);


		switch(order){

		case 1:

			 if(strcmp(cadenaAuxiliar ,cadenaAuxiliar2)>0)
				{

					retorno=1;

				}
			 break;

		 case 0:

			 if(strcmp(cadenaAuxiliar ,cadenaAuxiliar2)<0)
				{

					retorno=1;

				}
			 break;

		 default: retorno=-2; break;

		}
	}

	return retorno;

}


/// @fn compara 2 de enteros
/// @param int puntero
/// @param int2 puntero
/// @param order para en que orden compara 1 para arriba
/// 0 para abajo
/// @return 1 hay swap 0 no hubo swap -1 mal los parametros
int ordenEnteros(int num1,int num2, int order){

	int retorno=-1;

		if(order>=0 && order<=1)
		{

			switch(order){

			case 1:

				 if(num1 > num2)
				{

					retorno=1;

				}
				 break;

			 case 0:

				if(num1 < num2)
				{

					retorno=1;

				}
			 break;

			 default: retorno=-2; break;

			}
		}

		return retorno;

}

/// @fn compara 2 de float
/// @param float puntero
/// @param float puntero
/// @param order para en que orden compara 1 para arriba
/// 0 para abajo
/// @return 1 hay swap 0 no hubo swap -1 mal los parametros
int ordenFloat(float num1,float num2, int order){

	int retorno=-1;

		if(order>=0 && order<=1)
		{

			switch(order){

			case 1:

				 if(num1 > num2)
				{

					retorno=1;

				}
				 break;

			 case 0:

				if(num1 < num2)
				{

					retorno=1;

				}
			 break;

			 default: retorno=-2; break;

			}
		}

		return retorno;

}
