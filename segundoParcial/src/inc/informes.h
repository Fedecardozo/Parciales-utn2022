
#ifndef INC_INFORMES_H_
#define INC_INFORMES_H_

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "LinkedList.h"
#include "validacionSalon.h"
#include "validacionJuego.h"
#include "validacionArcade.h"

typedef int (*pFuncListar)(LinkedList* );

int informes_Salon_MasCuatroArcades(LinkedList* pArrayArcade,LinkedList* pArraySalon);
int informes_Arcade_MasDosJugadores(LinkedList* pArrayArcade,LinkedList* pArraySalon,LinkedList* pArrayJuego);
int informes_Salon_PorId(LinkedList* pArraySalon);
int informes_Salon_Completo(LinkedList* pArrayArcade,LinkedList* pArraySalon,LinkedList* pArrayJuego);
int informes_Salon_porIdArcade(LinkedList* pArrayArcade,LinkedList* pArraySalon,LinkedList* pArrayJuego);
int informes_Salon_masArcadedOrdenados(LinkedList* pArrayArcade,LinkedList* pArraySalon,pFuncListar listArcade);
int informes_Arcades(LinkedList* pArrayArcade,LinkedList* pArrayJuego);
int informes_printSalonMenosArcades(LinkedList* pArrayArcade,LinkedList* pArraySalon);
int informes_printSalonMenosArcades2(LinkedList* pArrayArcade,LinkedList* pArraySalon);

#endif /* INC_INFORMES_H_ */
