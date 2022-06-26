
#include "./inc/controller.h"

int menu();

int main(void) {

	setbuf(stdout, NULL);

	int opcion;
	LinkedList* listaSalones = ll_newLinkedList();
	LinkedList* listaJuegos = ll_newLinkedList();
	LinkedList* listaArcades = ll_newLinkedList();

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
				if(!controller_AltaArcade(listaArcades))
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
				break;
			case 11:

				puts("HASTA LUEGO");

				break;
			default:

				puts("\nHUBO UN ERROR...\nHASTA LUEGO");
				opcion = 11;

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
