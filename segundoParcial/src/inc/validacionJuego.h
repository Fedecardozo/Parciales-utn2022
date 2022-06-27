
#ifndef INC_VALIDACIONJUEGO_H_
#define INC_VALIDACIONJUEGO_H_

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "LinkedList.h"
#include "Juego.h"
#include "funcionesPropias.h"

int Juego_generadorId();
int Juego_pedirDatos(Juego* j);
int Juego_print(Juego* j);
int Juego_printById(LinkedList* pArrayJuego,int id);
int Juego_printByIdMsj(LinkedList* pArrayJuego,int id,char* msj,char* msjError);

#endif /* INC_VALIDACIONJUEGO_H_ */
