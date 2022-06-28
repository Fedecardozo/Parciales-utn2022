
#ifndef INC_INFORMES_H_
#define INC_INFORMES_H_

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "LinkedList.h"
#include "validacionSalon.h"
#include "validacionJuego.h"
#include "validacionArcade.h"

int informes_Salon_Mas4Arcades(LinkedList* pArrayArcade,LinkedList* pArraySalon);
int informes_Arcade_Mas2Jugadores(LinkedList* pArrayArcade,LinkedList* pArraySalon,LinkedList* pArrayJuego);

#endif /* INC_INFORMES_H_ */
