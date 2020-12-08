
#ifndef CONTROLER_H_
#define CONTROLER_H_
/** \brief Abre el archivo en modo texto y llena una linkedlist cono todos sus elementos
 *
 * \param string nombre de archivo a abrir
 * \param LinkedList* Puntero a la lista
 * \return 0
*/
int controller_loadFromText(char* path , LinkedList* pArrayListArticulo);
/** \brief imprime por pantalla todos los elementos del linkedlist cargado
 *
 * \param LinkedList* Puntero a la lista
 * \return 0
*/
int controller_ListArticulo(LinkedList* pArrayListArticulo,LinkedList* pArrayListRubro);
/** \brief ordena a los Articulos segun el criterio articulo de manera acendente
 *
 * \param LinkedList* Puntero a la lista
 * \return 0
*/
int controller_sortArticulo(LinkedList* pArrayListArticulo);
/** \brief guarda los datos del linkedlist en un archivo en modo texto, si el archivo no existe crea uno
 *
 * \param string nombre de archivo donde guardar
 * \param LinkedList* Puntero a la lista
 * \return 0
*/
int controller_saveAsText(char* path , LinkedList* pArrayListArticulo);
/** \brief Abre el archivo rubros en modo texto y llena una linkedlist cono todos sus elementos
 *
 * \param string nombre de archivo a abrir
 * \param LinkedList* Puntero a la lista
 * \return 0
*/
int hardcodear_Rubros(char* path , LinkedList* pArrayListRubro);
/** \brief aplica un descuento a los articulos de la lista deseados
 *
 * \param LinkedList* Puntero a la lista
 * \return 0
*/
int contoller_mapArticulos(LinkedList *pArrayListArticulo);
/** \brief recorre la lista de articulos y hace un conteo de los que cumplen las condiciones de la funcion
 *
 * \param LinkedList* Puntero a la lista
 * \return 0
*/
int contoller_informes(LinkedList *pArrayListArticulo);
#endif
