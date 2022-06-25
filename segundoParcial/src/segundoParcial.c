
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int menu();

int main(void) {

	setbuf(stdout, NULL);

	int opcion;

	do
	{
		opcion = menu();

		switch(opcion)
		{
			case 1://controller_AltaSalon();
				break;
			case 2://controller_RemoveSalon();
				break;
			case 3://controller_ListarSalon();
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
