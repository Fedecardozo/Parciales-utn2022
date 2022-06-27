
#include "./inc/parser.h"

// MODO TEXTO

int parser_Salon(char*path, LinkedList* pArraySalon)
{
	int retorno = -1;
	FILE* salon;
	int contDatos;
	char varId[10];
	char varName[50];
	char varCalle[50];
	char varAltura[10];
	char varLocal[50];
	Salon* newSalon;

	if(path != NULL && pArraySalon != NULL)
	{
		salon = fopen(path,"r");
		if(salon != NULL)
		{
			retorno=0;
			do
			{
				contDatos=fscanf(salon,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",
								varId,varName,varCalle,varAltura,varLocal);

				int id = atoi(varId);
				int local= atoi(varLocal);
				sprintf(varCalle,"%s %s",varCalle,varAltura);

				if(contDatos==5)
				{
					newSalon = Salon_newParametros(id, varName, varCalle,local);
					ll_add(pArraySalon,newSalon);
				}

			}while(!feof(salon));
		}
	}

	return retorno;
}

int parser_Juego(char*path, LinkedList* pArrayJuego)
{
	int retorno = -1;
	FILE* juego;
	int contDatos;
	char varId[10];
	char varName[50];
	char varEmpresa[10];
	char varGenero[50];
	Juego* newJuego;

	if(path != NULL && pArrayJuego != NULL)
	{
		juego = fopen(path,"r");

		if(juego != NULL)
		{
			retorno = 0;
			do
			{
				contDatos=fscanf(juego,"%[^,],%[^,],%[^,],%[^\n]\n",
								varId,varName,varEmpresa,varGenero);

				int id = atoi(varId);
				int genero = atoi(varGenero);

				if(contDatos==4)
				{
					newJuego = Juego_newParametros(id, varName, varEmpresa, genero);
					ll_add(pArrayJuego,newJuego);
				}

			}while(!feof(juego));
		}


	}

	return retorno;
}

int parser_Arcade(char*path, LinkedList* pArrayArcade)
{
	int retorno=-1;
	FILE* arcade;
	int contDatos;
	char varId[10];
	char varNacion[50];
	char varTipoSonido[10];
	char varCant[50];
	char varFichas[50];
	char varFkSalon[50];
	char varfkJuego[50];
	Arcade* newArcade;
	if(path != NULL && pArrayArcade != NULL)
	{

		arcade = fopen(path,"r");

		if(arcade != NULL)
		{
			retorno = 0;
			do
			{
				contDatos=fscanf(arcade,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",
								varId,varNacion,varTipoSonido,varCant,varFichas,varFkSalon,varfkJuego);

				int id = atoi(varId);
				int cant = atoi(varCant);
				int sonido = atoi(varTipoSonido);
				int fichas = atoi(varFichas);
				int fkSalon = atoi(varFkSalon);
				int fkJuego = atoi(varfkJuego);

				if(contDatos==7)
				{
					newArcade = Arcade_newParametros(id, varNacion, sonido,cant, fichas,fkJuego,fkSalon);
					ll_add(pArrayArcade,newArcade);
				}

			}while(!feof(arcade));
		}

	}

	return retorno;
}


//MODO BINARIO

int parser_Bin(char*path, LinkedList* pArray,funcionParseo parsear)
{
	int retorno=-1;
	FILE* fileGenerico;


	if(path != NULL && pArray != NULL && parsear != NULL)
	{
		retorno = 0;
		fileGenerico = fopen(path,"rb");

		if(fileGenerico != NULL)
		{
			do{
				if(parsear(fileGenerico,pArray)<0)
				{
					retorno = -1;
					break;
				}

			}while(!feof(fileGenerico));

		}
	}

	return retorno;
}

int parser_funcArcade(FILE* name,LinkedList* pArray)
{
	int retorno=-1;
	int contDatos;
	Arcade aux;
	Arcade* auxNew;

	if(name != NULL && pArray != NULL)
	{
		retorno = 0;
		contDatos=fread(&aux,sizeof(Arcade),1,name);

		if(contDatos)
		{
			auxNew = Arcade_newArcade(aux);
			retorno = ll_add(pArray, auxNew);

		}
	}

	return retorno;
}

int parser_funcJuego(FILE* name,LinkedList* pArray)
{
	int retorno=-1;
	int contDatos;
	Juego aux;
	Juego* auxNew;

	if(name != NULL && pArray != NULL)
	{
		retorno=0;
		contDatos=fread(&aux,sizeof(Juego),1,name);

		if(contDatos)
		{
			auxNew = Juego_newJuego(aux);
			retorno = ll_add(pArray, auxNew);

		}
	}

	return retorno;
}

int parser_funcSalon(FILE* name,LinkedList* pArray)
{
	int retorno=-1;
	int contDatos;
	Salon aux;
	Salon* auxNew;

	if(name != NULL && pArray != NULL)
	{
		retorno = 0;
		contDatos=fread(&aux,sizeof(Salon),1,name);

		if(contDatos)
		{
			auxNew = Salon_newSalon(aux);
			retorno = ll_add(pArray, auxNew);

		}

	}

	return retorno;
}
