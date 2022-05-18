
#include <stdio.h>
#include <stdlib.h>

#include "menu.h"

#define TAM_USUARIO 200
#define TAM_PRODUCTO 200
#define TAM_TRACKING 200

int main(void) {

	setbuf(stdout, NULL);



	Usuario arrayUsuario[TAM_USUARIO];
	eUsuario_Inicializar(arrayUsuario, TAM_USUARIO);

	Producto arrayProducto[TAM_PRODUCTO];
	eProducto_Inicializar(arrayProducto, TAM_PRODUCTO);

	Tracking arrayTracking[TAM_TRACKING];
	eTracking_Inicializar(arrayTracking, TAM_TRACKING);

	if(menu(arrayUsuario, TAM_USUARIO,arrayProducto,TAM_PRODUCTO,arrayTracking,TAM_TRACKING) == -1)
	{

		printf("\nHubo un error. Intentelo mas tarde...");

	}




	return EXIT_SUCCESS;
}
