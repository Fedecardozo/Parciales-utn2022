
#include "funcionesPropias.h"

static int getStringLetrasEspacioNumeros(char* pResultado,int longitud);
static int sonLetrasEspacioNumeros(char*pLetras,int longitud);

/// @fn Preguntar por si o por no
/// @param msj
/// @param intentos
/// @param msjError
/// @return 1 si 0 no -1 mal los datos -2 Contesto mal
int preguntarSoN(char*msj,int intentos, char*msjError){

	int retorno=-1;
	char respuesta[3];

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

/// @fn int utn_getStringLetrasYnumeros(char*, char*, char*, int, int)
/// @brief Solicita una cadena al usuario, luego de verificarlo devuelve el resultado
/// @param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
/// @param mensaje Es el mensaje a ser mostrado
/// @param mensajeError Es el mensaje a ser mostrado
/// @param limite Es el tamaño del array
/// @param intentos es la cantidad de oportunidades
/// @return 0 si salio bien y -1 si salio mal
int getStringLetras_espacio_numeros(char* pResultado, char* mensaje, char* mensajeError,int longitud, int intentos){

	int retorno=-1;

		//printf("%d",longitud);
		if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && longitud >0 && intentos>=0){

			//Creo la variable aca para primero validar de longitud sea mayor a 0
			char bufferString[longitud];

			do{

				printf("%s",mensaje);

				//Si esta todo bien lo copia en el puntero y sale de la iteracion retornado cero
				if(getStringLetrasEspacioNumeros(bufferString,longitud)==0){

					strncpy(pResultado,bufferString,longitud);
					retorno=0;
					break;

				}else if(intentos>0){

					printf("%s",mensajeError);

				}

				intentos--;


			}while(intentos>=0);


		}


		return retorno;


}

/// \brief Obtien una cadena de letras y numeros
///\param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
///\return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
static int getStringLetrasEspacioNumeros(char* pResultado,int longitud){

	int retorno =-1;
	char bufferString[200];//Esto despues se va a cambiar


	if(pResultado != NULL &&
		myGets(bufferString,sizeof(bufferString))==0
		&& sonLetrasEspacioNumeros(bufferString,sizeof(bufferString))){

		strncpy(pResultado,bufferString,longitud);
		retorno=0;

	}

	return retorno;

}

///\brief Verifica si la cadena ingresada son letras y numeros
///\param pLetras Cadena de caracteres a ser analizada
///\return Retorna 1 (vardadero) si la cadena es numerica y 0 (falso) si no lo es
static int sonLetrasEspacioNumeros(char*pLetras,int longitud)
{
	int retorno= 1;
	int i;

	// No valido los datos por que ya lo hace myGets

	for (i = 0; i<longitud && pLetras[i]!='\0'; i++){


		if(pLetras[i] >= 'A' && pLetras[i] <= 'Z'){

			//printf("\nb");
			continue;

		}

		if(pLetras[i] >= 'a' && pLetras[i] <= 'z'){

			//printf("\nb");
			continue;

		}
		if(pLetras[i] >= '0' && pLetras[i] <= '9'){

			//printf("\nc");
			continue;

		}
		if((pLetras[i] < '0' ) || ( pLetras[i] > '9' && pLetras[i] <'A')
				|| (pLetras[i]>'Z' && pLetras[i] <'a') ||( pLetras[i] >'z')){

			//printf("\nd");
			retorno= 0;
			break;

		}

	}


	return retorno;
}
