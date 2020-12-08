#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "articulo.h"
#include "controller.h"
#include "utn.h"

int main() {
	int option = 0, flag = 0, flag2 = 0;

	LinkedList *listaArticulos = ll_newLinkedList();
	LinkedList *listaRubro = ll_newLinkedList();
	hardcodear_Rubros("rubro.txt", listaRubro);
	do {
		utn_getInt(&option,
				"\n1. Cargar los datos de los articulos desde el archivo data.csv (modo texto)\n"
						"2. Listar articulos\n"
						"3. Ordenar articulos\n"
						"4. aplicar descuentos\n"
						"5. Guardar los datos de los articulos en el archivo data.csv (modo texto)\n"
						"6. Guardar los datos de los articulos mapeados en el archivo mapeado.csv (modo texto)\n"
						"7. Informes\n"
						"8. Salir\n", "opcion no valida", 1, 8, 90);
		switch (option) {
		case 1:
			controller_loadFromText("Datos_SP_LABO1.csv", listaArticulos);
			flag = 1;
			break;

		case 2:
			if (flag == 1) {
				controller_ListArticulo(listaArticulos, listaRubro);
				break;
			} else {
				printf("se debe cargar una lista primero");
				break;
			}
		case 3:
			if (flag == 1) {
				controller_sortArticulo(listaArticulos);
				break;
			} else {
				printf("se debe cargar una lista primero");
				break;
			}
		case 4:
			if (flag == 1) {
				contoller_mapArticulos(listaArticulos);
				flag2 = 1;
				break;
			} else {
				printf("se debe cargar una lista primero");
				break;
			}
		case 5:

			if (flag == 1) {
				controller_saveAsText("data.csv", listaArticulos);
				break;
			} else {
				printf("se debe cargar una lista primero");
				break;
			}
		case 6:
			if (flag == 1 && flag2 == 1) {
				controller_saveAsText("mapeado.csv", listaArticulos);
				break;
			}
			if (flag2 == 0) {
				printf(
						"tiene que aplicar el mapeado antes de poder guardar con esta opcion");
				break;
			} else {
				printf("se debe cargar una lista primero");
				break;
			}
		case 7:
			if (flag == 1) {
				contoller_informes(listaArticulos);
				break;
			} else {
				printf("se debe cargar una lista primero");
				break;
			}
		}
	} while (option != 8);
	return 0;
}
