#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "articulo.h"
#include "LinkedList.h"
#include "parser.h"
#include "controller.h"

#include "utn.h"
#define LEN 128

Rubro* rubro_new(void) {
	Rubro *p=NULL;
	p = (Rubro*) malloc(sizeof(Rubro));
	return p;
	}

Rubro* rubro_newParametros(char* id,char* rubro) {
	Rubro* punteroR;
	punteroR=rubro_new();
	if (punteroR != NULL) {
				rubro_setId(punteroR,id);
				rubro_setRubro(punteroR,rubro);

		return punteroR;
	}
	else
	{
		return NULL;
	}

}

int hardcodear_Rubros(char* path , LinkedList* pArrayListRubro){
	int i;
		Articulo* auxRubro;
		FILE* datos;

		 datos=fopen(path,"r+");
		 if(pArrayListRubro != NULL)
		     {
		         ll_clear(pArrayListRubro);
		         for(i = 0; i < ll_len(pArrayListRubro); i++)
		             {
		        	 	 auxRubro = ll_get(pArrayListRubro, i);
		                 articulo_delete(auxRubro);
		             }
		     }
		if ( datos  != NULL )
		    {
				parser_rubroFromText(datos, pArrayListRubro);
		        fclose(datos);
		    }
		    else
		    {
		        printf("\n\nNo se pudo realizar UwU.");
		    }

		    return 0;
}
Articulo* articulo_new(void) {
	Articulo *p=NULL;
	p = (Articulo*) malloc(sizeof(Articulo));
	return p;
	}


Articulo* articulo_newParametros(char* idStr,char* articuloStr,char* medidaStr, char* precioStr, char* rubroIdStr) {
	Articulo* punteroAr;
	punteroAr=articulo_new();
	if (punteroAr != NULL) {
		articulo_setIdTxt(punteroAr,idStr);
		articulo_setArticulo(punteroAr,articuloStr);
		articulo_setPrecioTxt(punteroAr,precioStr);
		articulo_setMedida(punteroAr,medidaStr);
		articulo_setRubroIdTxt(punteroAr,rubroIdStr);

		return punteroAr;
	}
	else
	{
		return NULL;
	}

}
Articulo* articulo_newParametrosS(int id,char* articulo, char* medida, float precio, int rubroId) {
	Articulo* punteroAr;
	punteroAr=articulo_new();
	if (punteroAr != NULL) {
				articulo_setId(punteroAr,id);
				articulo_setArticulo(punteroAr,articulo);
				articulo_setPrecio(punteroAr,precio);
				articulo_setMedida(punteroAr,medida);
				articulo_setRubroId(punteroAr,rubroId);

		return punteroAr;
	}
	else
	{
		return NULL;
	}

}



int articulo_criterioArt(void* item1, void* item2){
	int retorno=0;
	Articulo* a1;
	Articulo* a2;
	char Art1[LEN];
	char Art2[LEN];

	a1=(Articulo*)item1;
	a2=(Articulo*)item2;

	if(articulo_getArticulo(a1,Art1)==0 && articulo_getArticulo(a2,Art2)==0)
		{

			retorno=strcmpi(Art1, Art2);

		}

	return retorno;
}



void articulo_delete(Articulo* this){
	free(this);
}

int articulo_setId(Articulo* this,int id){
	int retorno=-1;

		if(this!=NULL && id>=0){
			retorno=0;
			this->id=id;
		}
		return retorno;
	}
int articulo_setIdTxt(Articulo* this,char*id){
	int retorno=-1;

		if(this!=NULL && id!=NULL ){
			retorno=0;
			this->id=atoi(id);
		}
		return retorno;
	}
int articulo_getId(Articulo* this,int* id){
	int retorno=-1;

	if(this!=NULL && id>=0){
		retorno=0;
		*id=this->id;

	}
	return retorno;

}


int articulo_setArticulo(Articulo* this,char* articulo){
	int retorno = -1;

			if(this !=NULL && articulo!=NULL ){
					strcpy(this->articulo,articulo);
					retorno=0;
			}

		return retorno;
	}

int articulo_getArticulo(Articulo* this,char* articulo){
	int retorno=-1;

		if(this!=NULL && articulo!=NULL){
			retorno=0;
			strcpy(articulo,this->articulo);
		}
		return retorno;
}

int articulo_setPrecio(Articulo* this,float precio){
	int retorno=-1;

			if(this!=NULL && precio>=0){
				retorno=0;
				this->precio=precio;
			}
			return retorno;
}
int articulo_setPrecioTxt(Articulo* this,char* precio){
	int retorno=-1;

			if(this!=NULL && precio!=NULL){
				retorno=0;
				this->precio=atof(precio);
			}
			return retorno;
}
int articulo_getPrecio(Articulo* this,float* precio){
	int retorno=-1;

		if(this!=NULL && precio>=0){
			retorno=0;
			*precio=this->precio;
		}
		return retorno;
}

int articulo_setMedida(Articulo* this,char* medida){
	int retorno = -1;

			if(this !=NULL && medida!=NULL ){
					strcpy(this->medida,medida);
					retorno=0;
			}

		return retorno;
	}

int articulo_getMedida(Articulo* this,char* medida){
	int retorno=-1;

		if(this!=NULL && medida!=NULL){
			retorno=0;
			strcpy(medida,this->medida);
		}
		return retorno;
}

int articulo_setRubroId(Articulo* this,int rubroId){
	int retorno=-1;

			if(this!=NULL && rubroId>=0){
				retorno=0;
				this->rubroId=rubroId;
			}
			return retorno;
}
int articulo_setRubroIdTxt(Articulo* this,char* rubroId){
	int retorno=-1;

			if(this!=NULL && rubroId!=NULL ){
				retorno=0;
				this->rubroId=atoi(rubroId);
			}
			return retorno;
}
int articulo_getRubroId(Articulo* this,int* rubroId){
	int retorno=-1;

		if(this!=NULL && rubroId>=0){
			retorno=0;
			*rubroId=this->rubroId;
		}
		return retorno;
}
int rubro_setId(Rubro* this,char* idR){
	int retorno=-1;

			if(this!=NULL && idR!=NULL){
				retorno=0;
				this->id=atoi(idR);
			}
			return retorno;
}
int rubro_getId(Rubro* this,int* idR){
	int retorno=-1;

		if(this!=NULL && idR>=0){
			retorno=0;
			*idR=this->id;
		}
		return retorno;
}
int rubro_setRubro(Rubro* this,char* rubro){
	int retorno = -1;

				if(this !=NULL && rubro!=NULL ){
						strcpy(this->rubro,rubro);
						retorno=0;
				}

			return retorno;
}
int rubro_getRubro(Rubro* this,char* rubro){
	int retorno=-1;

			if(this!=NULL && rubro!=NULL)
			{
				retorno=0;
				strcpy(rubro,this->rubro);
			}
			return retorno;

}

void aplicarDescuento(void* this){
	Articulo* das;
	int rubroIdAux;
	float precioAux;
	das=this;
	if(this!=NULL && articulo_getPrecio(das,&precioAux)==0 && articulo_getRubroId(das,&rubroIdAux)==0){
		if(precioAux>=120 && rubroIdAux==1 ){

			precioAux=precioAux-precioAux*0.20;
			articulo_setPrecio(das,precioAux);
		}
		if(precioAux<=200 && rubroIdAux==2 ){

					precioAux=precioAux-precioAux*0.10;
					articulo_setPrecio(das,precioAux);

				}
	}
}

int articulosMayo100(void* this){
	Articulo* das;
	float precioAux;
	int retorno=-1;
	das=this;
	if(this!=NULL && articulo_getPrecio(das,&precioAux)==0 ){
		if(precioAux>100 ){
			retorno=0;

		}
	}
	return retorno;
}

int articulosRubro1(void* this){
	Articulo* das;
		int retorno=-1,rubroIdAux;
		das=this;
		if(this!=NULL && articulo_getRubroId(das,&rubroIdAux)==0 ){
			if(rubroIdAux==1 ){
				retorno=0;

			}
		}
		return retorno;
	}

