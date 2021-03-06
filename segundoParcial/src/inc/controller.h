

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
#include "parser.h"
#include "informes.h"

//INICIO PROGRAMA
int controller_Inicio(LinkedList* pArrayArcade,LinkedList* pArraySalon,LinkedList* pArrayJuego
		,char*pathArcade,char*pathJuego,char*pathSalon,char*pathId);

//INICIO SALON
int controller_AltaSalon(LinkedList* pArraySalon);
int controller_ListarSalon(LinkedList* pArraySalon);
int controller_RemoveSalon(LinkedList* pArraySalon);
//FIN SALON

//INICIO ARCADE
int controller_AltaArcade(LinkedList* pArrayArcade,LinkedList* pArraySalon,LinkedList* pArrayJuego);
int controller_RemoveArcade(LinkedList* pArrayArcade);
int controller_ListarArcade(LinkedList* pArrayArcade);
int controller_ModificarArcade(LinkedList* pArrayArcade,LinkedList* pArrayJuego);
//FIN ARCADE

//INICIO JUEGO
int controller_AltaJuego(LinkedList* pArrayJuego);
int controller_ListarJuego(LinkedList* pArrayJuego);
//FIN JUEGO

//INFORMES
int controller_Informes(char letra,LinkedList* pArrayArcade,LinkedList* pArraySalon,LinkedList* pArrayJuego);

//FIN PROGRAMA
int controller_FinPrograma(char*pathArcade,char*pathJuego,char*pathSalon,
		LinkedList* pArrayArcade,LinkedList* pArrayJuego,LinkedList* pArraySalon
		,char* pathId);


#endif /* INC_CONTROLLER_H_ */
