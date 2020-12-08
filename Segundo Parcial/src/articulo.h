#ifndef ARTICULO_H_
#define ARTICULO_H_
typedef struct
{
    int id;
    char articulo[51];
    char medida[51];
    float precio;
    int rubroId;
}Articulo;

typedef struct
{
    int id;
    char rubro[51];
}Rubro;
/** \brief crea el espacio en memoria dinamica para un articulo
 *
 * \return puntero Articulo del espacio creado
*/
Articulo* articulo_new();
/** \brief crea el espacio en memoria dinamica para un Rubro
 *
 * \return puntero Articulo del espacio creado
*/
Rubro* rubro_new();
/** \brief llama a la funcion Articulo_new y le carga los datos pasados como cadena de caracteres
 *
 * \param char* Id
 * \param char* articulo
 * \param char* medida
 * \param char* precio
 * \param char* rubroId
 *
 * \return puntero  del espacio creado
*/
Articulo* articulo_newParametros(char* idStr,char* articuloStr,char* medidaStr, char* precioStr, char* rubroIdStr);
Rubro* rubro_newParametros(char* id,char* rubro);

/** \brief llama a la funcion Articulo_new y le carga los datos pasados en su formato adecuado
 *
 * \param int Id
 * \param char* articulo
 * \param char* medida
 * \param float precio
 * \param int rubroId
 *
 * \return puntero Articulo del espacio creado
*/
Articulo* articulo_newParametrosS(int id,char* articulo, char* medida, float precio, int rubroId);

int articulo_criterioArt(void* item1, void* item2);
/** \brief borra de la memoria dinamica al Articulo indicado a traves de un free()
 *
 * \param Articulo* articulo
 *
 * \return void
*/
void articulo_delete(Articulo* this);
/** \brief asigna el dato pasado en su lugar correspondiente del puntero Articulo indicado
 *
 * \param Articulo* articulo
 * \param int id
 *
 * \return 0
*/
int articulo_setId(Articulo* this,int id);
/** \brief asigna el dato pasado en su lugar correspondiente del puntero Articulo indicado
 *
 * \param Articulo* articulo
 * \param char* id
 *
 * \return 0
*/
int articulo_setIdTxt(Articulo* this,char* id);
/** \brief toma el dato del Articulo indicado y lo asigna en la variable que se le pasa
 *
 * \param Articulo* articulo
 * \param int* id
 *
 * \return 0
*/
int articulo_getId(Articulo* this,int* id);
/** \brief asigna el dato pasado en su lugar correspondiente del puntero Articulo indicado
 *
 * \param Articulo* articulo
 * \param char* articulo
 *
 * \return 0
*/
int articulo_setArticulo(Articulo* this,char* articulo);
/** \brief toma el dato del Articulo indicado y lo asigna en la variable que se le pasa
 *
 * \param Articulo* articulo
 * \param char* articulo
 *
 * \return 0
*/
int articulo_getArticulo(Articulo* this,char* articulo);
/** \brief asigna el dato pasado en su lugar correspondiente del puntero Articulo indicado
 *
 * \param Articulo* articulo
 * \param float precio
 *
 * \return 0
*/
int articulo_setPrecio(Articulo* this,float precio);
/** \brief asigna el dato pasado en su lugar correspondiente del puntero Articulo indicado
 *
 * \param Articulo* articulo
 * \param char* precio
 *
 * \return 0
*/
int articulo_setPrecioTxt(Articulo* this,char* precio);
/** \brief toma el dato del Articulo indicado y lo asigna en la variable que se le pasa
 *
 * \param Articulo* articulo
 * \param float* precio
 *
 * \return 0
*/
int articulo_getPrecio(Articulo* this,float* precio);
/** \brief asigna el dato pasado en su lugar correspondiente del puntero Articulo indicado
 *
 * \param Articulo* articulo
 * \param char* medida
 *
 * \return 0
*/
int articulo_setMedida(Articulo* this,char* medida);
/** \brief toma el dato del Articulo indicado y lo asigna en la variable que se le pasa
 *
 * \param Articulo* articulo
 * \param char* medida
 *
 * \return 0
*/
int articulo_getMedida(Articulo* this,char* medida);
/** \brief asigna el dato pasado en su lugar correspondiente del puntero Articulo indicado
 *
 * \param Articulo* articulo
 * \param int rubroId
 *
 * \return 0
*/
int articulo_setRubroId(Articulo* this,int rubroId);
/** \brief asigna el dato pasado en su lugar correspondiente del puntero Articulo indicado
 *
 * \param Articulo* articulo
 * \param char* rubroId
 *
 * \return 0
*/
int articulo_setRubroIdTxt(Articulo* this,char* rubroId);
/** \brief toma el dato del Articulo indicado y lo asigna en la variable que se le pasa
 *
 * \param Articulo* articulo
 * \param int* rubroId
 *
 * \return 0
*/
int articulo_getRubroId(Articulo* this,int* rubroId);
/** \brief asigna el dato pasado en su lugar correspondiente del puntero Rubro indicado
 *
 * \param Rubro* this
 * \param char* idR
 *
 * \return 0
*/
int rubro_setId(Rubro* this,char* idR);
/** \brief toma el dato del Rubro indicado y lo asigna en la variable que se le pasa
 *
 * \param Rubro* this
 * \param int* idR
 *
 * \return 0
*/
int rubro_getId(Rubro* this,int* idR);
/** \brief asigna el dato pasado en su lugar correspondiente del puntero Rubro indicado
 *
 * \param Rubro* this
 * \param char* rubro
 *
 * \return 0
*/
int rubro_setRubro(Rubro* this,char* rubro);
/** \brief toma el dato del Rubro indicado y lo asigna en la variable que se le pasa
 *
 * \param Rubro* this
 * \param char* rubro
 *
 * \return 0
*/
int rubro_getRubro(Rubro* this,char* rubro);

void aplicarDescuento(void* this);
int articulosMayo100(void* this);
int articulosRubro1(void* this);
#endif /* ARTICULO_H_ */
