
#include "funcionesArchivos.h"

Producto guardarUnProducto(char* var,char* var1,char* var2,char* var3,char* var4,char* var5,char* var6){

	Producto auxProducto;
	//char var[7][50];

   //Guardar en un auxiliar
   //idProducto,idUsuario,isEmpty,nombreDelProducto,precio,categoria,stock
   auxProducto.id = atoi(var);
   auxProducto.Fk_idUsuario = atoi(var1);
   auxProducto.isEmpty = atoi(var2);
   strncpy(auxProducto.nombreProducto,var3,sizeof(auxProducto.nombreProducto));
   auxProducto.precio = atoi(var4);
   auxProducto.categoria = atoi(var5);
   auxProducto.stock = atoi(var6);

   return auxProducto;

}

int llenarArray(FILE* archivo,Producto* list){

	int retorno=-1;
	int contador;
	int i=0;
	char var[7][50];

	if(archivo != NULL && list !=NULL)
	{
		do{

		   contador = fscanf(archivo,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",var[0],var[1],var[2],var[3],var[4],var[5],var[6]);
		   if(contador == 7)
		   {
			   list[i]=guardarUnProducto(var[0],var[1],var[2],var[3],var[4],var[5],var[6]);
			   i++;
		   }

		}while(!feof(archivo));
		retorno =i;
	}

	return retorno;
}

void imprimirUno(Producto auxProducto)
{
	printf("\nID:%d \nID Usuario:%d \nisEmpty:%d \nNombre:%s \nPrecio:%f \nCategoria:%d \nStock:%d \n",
	   auxProducto.id,auxProducto.Fk_idUsuario,auxProducto.isEmpty,auxProducto.nombreProducto
	   ,auxProducto.precio,auxProducto.categoria,auxProducto.stock);
}

int printArrayProducto(Producto* list,int len){

	int retorno =-1;
	int i;

	if(list != NULL && len >0)
	{
		retorno = 0;
		for(i=0; i<len; i++)
		{
			if(list[i].isEmpty==OCUPADO)
			{
				imprimirUno(list[i]);

			}
		}
	}

	return retorno;

}
