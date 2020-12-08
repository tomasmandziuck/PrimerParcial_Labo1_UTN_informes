#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "articulo.h"


int parser_articuloFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	Articulo* auxEmp;

	char id[50],articulo[50],precio[50],medida[50],rubroId[50];


		do{
			if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,articulo,medida,precio,rubroId)==5){
				//printf("%s-%s-%s-%s-%s\n",id,articulo,medida,precio,rubroId);
				auxEmp=articulo_newParametros(id,articulo,medida,precio,rubroId);
				ll_add(pArrayListEmployee,auxEmp);
			}

		}while(feof(pFile)==0);

    return 0;
}


int parser_rubroFromText(FILE* pFile , LinkedList* pArrayListRubro)
{
	Rubro* auxR;

	char id[50],articulo[50];


		do{
			if(fscanf(pFile,"%[^,],%[^\n]\n",id,articulo)==2){
				auxR=rubro_newParametros(id,articulo);
				ll_add(pArrayListRubro,auxR);
			}

		}while(feof(pFile)==0);

    return 0;
}
