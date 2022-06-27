
#ifndef INC_VALIDACIONARCADE_H_
#define INC_VALIDACIONARCADE_H_

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "LinkedList.h"
#include "Arcade.h"
#include "funcionesPropias.h"
#include "validacionJuego.h"
#include "validacionSalon.h"

typedef int (*pFuncListar)(LinkedList* );

int Arcade_generadorId();
int Arcade_pedirDatos(Arcade* a,LinkedList* pArrayJuego,LinkedList* pArraySalon);
int Arcade_print(Arcade* a);
int Arcade_remove(LinkedList* pArrayArcade, int id);
int Arcade_edit(LinkedList* pArrayListArcade, int id,LinkedList* pArrayJuego,pFuncListar);

#endif /* INC_VALIDACIONARCADE_H_ */
