
#ifndef INC_VALIDACIONARCADE_H_
#define INC_VALIDACIONARCADE_H_

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "LinkedList.h"
#include "Arcade.h"
#include "funcionesPropias.h"

int Arcade_generadorId();
int Arcade_pedirDatos(Arcade* a);
int Arcade_print(Arcade* a);
int Arcade_remove(LinkedList* pArrayArcade, int id);

#endif /* INC_VALIDACIONARCADE_H_ */
