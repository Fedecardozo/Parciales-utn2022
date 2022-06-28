
#ifndef INC_PARSER_H_
#define INC_PARSER_H_

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "validacionSalon.h"
#include "validacionJuego.h"
#include "validacionArcade.h"

typedef int (*funcionParseo)(FILE* ,LinkedList* );

//Texto
int parser_Salon(char*path, LinkedList* pArraySalon);
int parser_Juego(char*path, LinkedList* pArrayJuego);
int parser_Arcade(char*path, LinkedList* pArrayArcade);
int parser_Id(char*path);

//Binario
int parser_Bin(char*path, LinkedList* pArray,funcionParseo parsear);
int parser_funcArcade(FILE* name,LinkedList* pArray);
int parser_funcJuego(FILE* name,LinkedList* pArray);
int parser_funcSalon(FILE* name,LinkedList* pArray);

#endif /* INC_PARSER_H_ */
