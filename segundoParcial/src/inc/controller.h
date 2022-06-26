

#ifndef INC_CONTROLLER_H_
#define INC_CONTROLLER_H_

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "LinkedList.h"
#include "Arcade.h"
#include "validacionSalon.h"
#include "validacionJuego.h"
#include "validacionArcade.h"

//INICIO SALON
int controller_AltaSalon(LinkedList* pArraySalon);
int controller_ListarSalon(LinkedList* pArraySalon);
int controller_RemoveSalon(LinkedList* pArraySalon);
//FIN SALON

//INICIO ARCADE
int controller_AltaArcade(LinkedList* pArrayArcade);
int controller_ModificarArcade(LinkedList* pArrayArcade);
int controller_RemoveArcade(LinkedList* pArrayArcade);
int controller_ListarArcade(LinkedList* pArrayArcade);
//FIN ARCADE

//INICIO JUEGO
int controller_AltaJuego(LinkedList* pArrayJuego);
int controller_ListarJuego(LinkedList* pArrayJuego);
//FIN JUEGO



#endif /* INC_CONTROLLER_H_ */
