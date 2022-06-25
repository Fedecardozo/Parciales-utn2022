
#ifndef INC_SALON_H_
#define INC_SALON_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SAL_LEN_NAME 20
#define SAL_LEN_DIREC 30

typedef struct{

	int id;
	char name[SAL_LEN_NAME];
	char direccion[SAL_LEN_DIREC];
	int tipoSalon;

}Salon;

Salon* Salon_new();
Salon* Salon_newSalon(Salon s);
Salon* Salon_newParametros(int, char*, char*, int);

void Salon_delete(Salon* this);

int Salon_setId(Salon* this,int id);
int Salon_getId(Salon* this,int* id);

int Salon_setName(Salon* this,char* name);
int Salon_getName(Salon* this,char* name);

int Salon_setDireccion(Salon* this,char* direccion);
int Salon_getDireccion(Salon* this,char* direccion);

int Salon_setTipoSalon(Salon* this,int tipoSalon);
int Salon_getTipoSalon(Salon* this,int* tipoSalon);


#endif /* INC_SALON_H_ */
