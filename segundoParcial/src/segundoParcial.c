
#include "./inc/controller.h"
#define pathJuego "dataJuego.csv"
#define pathSalon "dataSalon.csv"
#define pathArcade "dataArcade.csv"

int menu();
char subMenu();

int main(void) {

	setbuf(stdout, NULL);

	int opcion;
	LinkedList* listaSalones = ll_newLinkedList();
	LinkedList* listaJuegos = ll_newLinkedList();
	LinkedList* listaArcades = ll_newLinkedList();


	if(!controller_Inicio(listaArcades, listaSalones, listaJuegos, pathArcade, pathJuego, pathSalon))
	{
		puts("\nBIENVENIDO!");
		/*//4 plataforma, 3 laberinto, 5 aventura
		//platforma: 13,14,19,20
		//laberinto: 5,6,8,9
		//aventura: 2,11,15,26,33
		for(int i=0; i<15;i++)
		{
			aux = (Arcade*)ll_get(listaArcades, i);
			Arcade_setFk_salon(aux, 5);
			if(i<5)
			{
				Arcade_setFk_juego(aux, 13);
			}
			else if(i<9)
			{
				Arcade_setFk_juego(aux, 6);
			}
			else
			{
				Arcade_setFk_juego(aux, 11);
			}
		}
		for(int i=15; i<30;i++)
		{
			aux = (Arcade*)ll_get(listaArcades, i);
			Arcade_setFk_salon(aux, 8);
			if(i<21)
			{
				Arcade_setFk_juego(aux, 14);
			}
			else if(i<25)
			{
				Arcade_setFk_juego(aux, 8);
			}
			else
			{
				Arcade_setFk_juego(aux, 26);
			}
		}
		for(int i=30; i<45;i++)
		{
			aux = (Arcade*)ll_get(listaArcades, i);
			Arcade_setFk_salon(aux, 7);
			if(i<36)
			{
				Arcade_setFk_juego(aux, 19);
			}
			else if(i<41)
			{
				Arcade_setFk_juego(aux, 5);
			}
			else
			{
				Arcade_setFk_juego(aux, 15);
			}
		}
		for(int i=45; i<60;i++)
		{
			aux = (Arcade*)ll_get(listaArcades, i);
			Arcade_setFk_salon(aux, 11);
			if(i<51)
			{
				Arcade_setFk_juego(aux, 20);
			}
			else if(i<54)
			{
				Arcade_setFk_juego(aux, 9);
			}
			else
			{
				Arcade_setFk_juego(aux, 33);
			}
		}*/
	}
	else
	{
		exit(1);
	}

	do
	{
		opcion = menu();

		switch(opcion)
		{
			case 1:

				if(!controller_AltaSalon(listaSalones))
				{
					puts("\nSE DIO DE ALTA CON EXITO!");
				}
				else
				{
					puts("\nNO SE PUDO DAR DE ALTA!");
				}

				break;
			case 2:
				switch(controller_RemoveSalon(listaSalones))
				{
					case 0: puts("\nSE ELIMINO CON EXITO!"); break;
					case -1: puts("\nHUBO UN ERROR!"); break;
					case -2: puts("\nNO EXISTE EL ID!"); break;
					case -3: puts("\nNO SE BORRO EL SALON!"); break;
					case -4: puts("\nLISTA VACIA!"); break;
				}
				break;
			case 3:
				if(controller_ListarSalon(listaSalones)<0)
				{
					puts("\nNO HAY SALONES CARGADOS");
				}
				break;
			case 4:
				if(!controller_AltaArcade(listaArcades,listaSalones,listaJuegos))
				{
					puts("\nSE DIO DE ALTA CON EXITO!");
				}
				else
				{
					puts("\nNO SE PUDO DAR DE ALTA!");
				}
				break;
			case 5://controller_ModificarArcade();
				switch(controller_ModificarArcade(listaArcades,listaJuegos))
				{
					case -1: puts("\nHUBO UN ERROR!"); break;
					case -2: puts("\nNO EXISTE EL ID!"); break;
					case -3: puts("\nOPCION INCORRECTA!"); break;
					case -4: puts("\nDATOS INVALIDOS!"); break;
					case -5:
					case -6: puts("\nHUBO UN ERROR... INTENTELO MAS TARDE!"); break;
					case -7: puts("\nLISTA VACIA!"); break;
				}
				break;
			case 6:
				switch(controller_RemoveArcade(listaArcades))
				{
					case 0: puts("\nSE ELIMINO CON EXITO!"); break;
					case -1: puts("\nHUBO UN ERROR!"); break;
					case -2: puts("\nNO EXISTE EL ID!"); break;
					case -3: puts("\nNO SE BORRO EL ARCADE!"); break;
					case -4: puts("\nLISTA VACIA!"); break;
				}
				break;
			case 7:
				if(controller_ListarArcade(listaArcades)<0)
				{
					puts("\nNO HAY ARCADES CARGADOS");
				}
				break;
			case 8:
				if(!controller_AltaJuego(listaJuegos))
				{
					puts("\nSE DIO DE ALTA CON EXITO!");
				}
				else
				{
					puts("\nNO SE PUDO DAR DE ALTA!");
				}
				break;
			case 9:
				if(controller_ListarJuego(listaJuegos)<0)
				{
					puts("\nNO HAY JUEGOS CARGADOS");
				}
				break;
			case 10://controller_Informes();

				controller_Informes(subMenu(),listaArcades,listaSalones,listaJuegos);

				break;
			case 11:

				if(!controller_FinPrograma(pathArcade, pathJuego, pathSalon, listaArcades, listaJuegos, listaSalones))
				{
					puts("\nSE GUARDO CON EXITO! HASTA LUEGO!");
				}
				else
				{
					puts("\nHUBO UN PROBLEMA AL CERRAR EL PROGRAMA!");
				}

				break;
			default:

				puts("\nHUBO UN ERROR...\nHASTA LUEGO");
				exit(1);

				break;

		}

	}while(opcion != 11);


	return EXIT_SUCCESS;
}

int menu()
{
	int num=12;

	utn_getNumero(&num,"\n1. ALTA SALON"
			"\n2. ELIMINAR SALON"
			"\n3. LISTAR SALONES"
			"\n4. INCORPORAR ARCADE"
			"\n5. MODIFICAR ARCADE"
			"\n6. ELIMINAR ARCADE"
			"\n7. IMPRIMIR ARCADE"
			"\n8. AGREGAR JUEGO"
			"\n9. IMPRIMIR JUEGO"
			"\n10. INFORMES"
			"\n11. SALIR"
			"\nINGRESE OPCION: "
			,"\nOPCION INVALIDA.\nIngrese nuevamente: ", 1, 11, 2);

	return num;
}

char subMenu()
{
	char letra='z';

	utn_getCaracter(&letra,"\nA) Listado de los salones con mas de 4 arcade"
			"\nB)Listado de los arcades para  mas  de  2  jugadores"
			"\nC)Informacion de un salon en especifico"
			"\nD)Filtro salones"
			"\nE)Lista de los arcades de un salon en especifico"
			"\nF)Salon con mas arcades"
			"\nG)Listado de los arcades con sonido MONO y genero de juego PLATAFORMA"
			"\nH)Salir de sub menu"
			"\nINGRESE OPCION: "
			,"\nOPCION INVALIDA.\nIngrese nuevamente: ", 'a', 'h', 2);

	return letra;
}
