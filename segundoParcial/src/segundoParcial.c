
#include "./inc/controller.h"

int menu();

int main(void) {

	setbuf(stdout, NULL);

	int opcion;
	LinkedList* listaSalones = ll_newLinkedList();

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
			case 4://controller_AltaArcade();
				break;
			case 5://controller_ModificarArcade();
				break;
			case 6://controller_RemoveArcade();
				break;
			case 7://controller_ListarArcade();
				break;
			case 8://controller_AltaJuego();
				break;
			case 9://controller_ListarJuego();
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
