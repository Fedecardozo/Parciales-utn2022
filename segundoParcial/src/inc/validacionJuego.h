
#ifndef INC_VALIDACIONJUEGO_H_
#define INC_VALIDACIONJUEGO_H_

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "LinkedList.h"
#include "Juego.h"
#include "funcionesPropias.h"

int Juego_InicioId(int idInicial);
int Juego_generadorId();
int Juego_pedirDatos(Juego* j);
int Juego_print(Juego* j);
int Juego_printById(LinkedList* pArrayJuego,int id);
int Juego_printByIdMsj(LinkedList* pArrayJuego,int id,char* msj,char* msjError);
Juego* Juego_getJuego(LinkedList* pArrayJuego,int id);

#endif /* INC_VALIDACIONJUEGO_H_ */
