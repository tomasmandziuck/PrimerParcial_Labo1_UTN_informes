#ifndef PARSER_H_
#define PARSER_H_

/** \brief Parsea los datos los datos de los empleados desde el archivo Datos_SP_LABO1.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return 0
 *
 */
int  parser_articuloFromText(FILE* pFile , LinkedList* pArrayListEmployee);
/** \brief Parsea los datos los datos de los Rubros desde el archivo rubro.txt (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return 0
 *
 */
int parser_rubroFromText(FILE* pFile , LinkedList* pArrayListRubro);


#endif
