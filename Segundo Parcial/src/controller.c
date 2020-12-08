#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "articulo.h"
#include "parser.h"
#include "utn.h"
#define LEN 51


int controller_loadFromText(char *path, LinkedList *pArrayListArticulo) {
	int i;
	Articulo *auxArticulo;
	FILE *datos;
	char respuesta[50];
	utn_getString(respuesta,"que archivo desea cargar? respete simbolos y mayusculas\n Archivos disponibles:\n Datos_SP_LABO1.csv\nno hay otro\n","archivo no encontrado",2,30,90);
			while(strcmp(respuesta,path)!=0){
				utn_getString(respuesta,"que archivo desea cargar? respete simbolos y mayusculas\n Archivos disponibles:\n Datos_SP_LABO1.csv\nno hay otro\n","archivo no encontrado",2,3,90);
				break;
			}
	datos = fopen(respuesta, "r+");
	if (pArrayListArticulo != NULL) {
		ll_clear(pArrayListArticulo);
		for (i = 0; i < ll_len(pArrayListArticulo); i++) {
			auxArticulo = ll_get(pArrayListArticulo, i);
			articulo_delete(auxArticulo);
		}
	}
	if (datos != NULL) {
		parser_articuloFromText(datos, pArrayListArticulo);
		printf("\n\n Carga modo Texto OK.");
		fclose(datos);
	} else {
		printf("\n\nNo se pudo realizar la carga.");
	}

	return 0;
}


int controller_ListArticulo(LinkedList *pArrayListArticulo,
		LinkedList *pArrayListRubro)
{
	int i,j,idAuxR,idAux,rubroIdAux;
	    float precioAux;
	    char articuloAux[LEN],medidaAux[LEN],rubroAux[LEN];

	    Articulo* auxArticulo ;
	    Rubro* auxRubro;


	    for(i = 0; i < ll_len(pArrayListArticulo); i++)
	    {
	        auxArticulo = ll_get(pArrayListArticulo, i);


	        			if(articulo_getId(auxArticulo,&idAux)==0 &&
	        				articulo_getArticulo(auxArticulo,articuloAux)==0 &&
	        				articulo_getMedida(auxArticulo,medidaAux)==0 &&
	        				articulo_getPrecio(auxArticulo,&precioAux)==0 &&
	        				articulo_getRubroId(auxArticulo,&rubroIdAux)==0 ){

	        				for(j=0;j<ll_len(pArrayListRubro);j++){

	        					auxRubro=ll_get(pArrayListRubro,j);
	        					if(rubro_getId(auxRubro,&idAuxR)==0){
	        						if(idAuxR==rubroIdAux){
	        							rubro_getRubro(auxRubro,rubroAux);
	        						}
	        					}


	        				}
	        				printf("Id:%d--Articulo:%s--Medida:%s--Precio:$%.0f--Id del Rubro:%d--Rubro:%s\n", idAux, articuloAux,medidaAux,precioAux,rubroIdAux,rubroAux);
	        			}
	    }
	    return 0;
}


int controller_sortArticulo(LinkedList *pArrayListArticulo) {
	int retorno = -1;

	if (pArrayListArticulo != NULL) {
		ll_sort(pArrayListArticulo, articulo_criterioArt, 1);
		printf("ordenamiento completado\n");
		retorno = 0;
	}
	return retorno;
}


int controller_saveAsText(char *path, LinkedList *pArrayListArticulo) {
	FILE *datos;
	Articulo *auxArticulo;
	int i, idAux, rubroIdAux;
	float precioAux;
	char articuloAux[LEN], medidaAux[LEN];

	datos = fopen(path, "w");
	if (datos != NULL) {
		for (i = 0; i < ll_len(pArrayListArticulo) + 1; i++) {
			auxArticulo = ll_get(pArrayListArticulo, i);

			if (articulo_getId(auxArticulo, &idAux) == 0
					&& articulo_getArticulo(auxArticulo, articuloAux) == 0
					&& articulo_getPrecio(auxArticulo, &precioAux) == 0
					&& articulo_getMedida(auxArticulo, medidaAux) == 0
					&& articulo_getRubroId(auxArticulo, &rubroIdAux) == 0) {
				fprintf(datos, "%d,%s,%s,%.0f,%d\n", idAux, articuloAux,
						medidaAux, precioAux, rubroIdAux);
			}
		}
		fclose(datos);
	}
	return 0;
}

int contoller_mapArticulos(LinkedList *pArrayListArticulo){

	pArrayListArticulo=ll_map(pArrayListArticulo,aplicarDescuento);
	printf("mapeado completado\n");
	return 0;
}

int contoller_informes(LinkedList *pArrayListArticulo){
	int contadorP,contadorR;
	contadorP=ll_count(pArrayListArticulo,articulosMayo100);
	contadorR=ll_count(pArrayListArticulo,articulosRubro1);

	printf("Hay %d Articulos con precio mayor a $100 \nHay %d Articulos del rubro Cuidado de ropa\n",contadorP,contadorR);
	return 0;
}
