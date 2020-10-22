
#ifndef ELECTRODOMESTICOS_H_
#define ELECTRODOMESTICOS_H_



#endif /* ELECTRODOMESTICOS_H_ */

typedef struct
{
    int Id;
    int serie;
    float IdMarca;
    float modelo;
    int isEmpty;
} eElec;

typedef struct
{
    int Id;
    char Marca [15];
} eMarca;

/** \brief A la variable isEmpty de la estructura de eElec le pone un 1
 *
 * \param array eElec
 * \param tamanio del array
 * \return 0
 *
 */
void AltaElec(eElec elec[],int cant);
/** \brief Recorre todos los indices del array electrodomesticos y ejecuta la funcion mostrarUno
 *
 * \param array eElec
 * \param tamanio del array
 * \return 0
 *
 */
void mostrarTodosElec (eElec elec[],int cant);
/** \brief Muestra los datos de un electrodomestico del indice indicado
 *
 * \param array eElec
 * \return 0
 *
 */

void mostrarUnoElec(eElec elec);

/** \brief Ejecuta el ordenamiento de burbuja por modelo y serie de forma ascendiente
 *
 * \param array eElec
 * \param tamanio del array
 * \return 0
 *
 */
void ordenarMoySe(eElec elec[],int cant);

/** \brief Busca un espacio vacio en el array eElec y pide datos para cargar
 *
 * \param array eElec
 * \param tamanio del array
 * \return 0
 *
 */
void initElec (eElec elec[], int cant);
/** \brief Muestra todos los datos de los electrodomesticos te pide que elijas uno por id y abre un menu para elegir que dato modificar
 *
 * \param array eElec
 * \param tamanio del array
 * \return 0
 *
 */

void Modificacion (eElec elec[], int cant);
/** \brief Da la baja logica al electrodomestico deseado reemplazando el 0 por un 1
 *
 * \param array eElec
 * \param tamanio del array
 * \return 0
 *
 */
void Baja (eElec elec[], int cant);
/** \brief revisa que todos los indices del array eElec tengan un 1 en isEmpty
 *
 * \param array eElec
 * \param tamanio del array
 * \return flag 1 si estan vacios 0 si no
 *
 */

int AllEmptyElec(eElec elec[], int cant);
/** \brief Recorre todos los indices del array marcas y ejecuta la funcion mostrarUno
 *
 * \param array eElec
 * \param tamanio del array
 * \return 0
 *
 */
void mostrarTodosMarca(eMarca marca[],int cant);
/** \brief Muestra los datos de un electrodomestico del indice indicado
 *
 * \param array eElec
 * \return 0
 *
 */

void mostrarUnoMarca(eMarca marcas);
