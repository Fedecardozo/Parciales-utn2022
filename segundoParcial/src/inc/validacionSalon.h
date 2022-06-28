
#ifndef INC_VALIDACIONSALON_H_
#define INC_VALIDACIONSALON_H_

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "LinkedList.h"
#include "Salon.h"
#include "funcionesPropias.h"

int Salon_generadorId();
int Salon_pedirDatos(Salon* s);
int Salon_print(Salon* s);
int Salon_remove(LinkedList* pArraySalon, int id);
int Salon_printByIdMsj(LinkedList* pArraySalon,int id,char* msj,char* msjError);
Salon* Salon_getSalon(LinkedList* pArraySalon,int id);

#endif /* INC_VALIDACIONSALON_H_ */
