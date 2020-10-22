#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "electrodomesticos.h"
#include "utn.h"
#include "servicio.h"
#include "reparacion.h"
#define MAX 5


int main()
{
	setbuf(stdout,NULL);
    int opcion=0,flag1=0,flag2=0;
    char seguir ='s';
    eElec elec[MAX];
    eRep reparacion[MAX];
    eCli clientes[MAX]={{0,"Rodrigo","Bianchi"},{0,"Guido","Campostrini"},{0,"Agustin","Funes"},{0,"Tomas","Mandziuck"},{0,"Federico","Mandziuck"}};
    eMarca marcas[5] = {{1000,"Wirpoll"},{1001,"Sony"},{1002,"Liliana"},{1003,"Gafa"},{1004,"Philips"}};
    eSer servicios[4] ={{20000,"Garantia",250},{20001,"Mantenimiento",500},{20002,"Repuestos",400},{20003,"Refaccion",600}};


    initElec(elec,MAX);
    initRep(reparacion,MAX);


    do
    {

        printf("1- Alta Electrodomestico \n2- Lista Electrodomesticos\n3- listar marcas\n4- listar servicios\n5- Baja Electrodomestico\n6- Modificar Electrodomestico\n7- Alta Reparacion\n8- listar Reparaciones\n9- Salir");
        utn_getInt(&opcion, "\n", "opcion no valida", 1,9,3);
        switch(opcion)
        {
        case 1:

            AltaElec(elec,MAX);
            system("cls");
            break;
        case 2:
            flag1=AllEmptyElec(elec, MAX);
            if(flag1==0){
            system("cls");
            ordenarMoySe(elec,MAX);
            mostrarTodosElec(elec,MAX);
            break;
            }
            else{
                printf("\nse debe ingresar un dato primero\n");
                break;
            }
        case 3:
            system("cls");
            mostrarTodosMarca(marcas,5);
            break;
        case 4:
             system("cls");
             mostrarTodosServicios(servicios,4);
             break;
        case 5:
            flag1=AllEmptyElec(elec, MAX);
            if(flag1==0){
            system("cls");
            Baja(elec, MAX);
            break;
            }
            else{
                printf("\nse debe ingresar un dato primero\n");
                break;
            }
        case 6:
            flag1=AllEmptyElec(elec, MAX);
            if(flag1==0){
            Modificacion(elec, MAX);
            break;
            }
            else{
                printf("\nse debe ingresar un dato primero\n");
                break;
            }
        case 7:

               AltaRep(reparacion,clientes,MAX);
               system("cls");
               break;

        case 8:

              flag2=AllEmptyRep(reparacion, MAX);
              if(flag2==0){
              system("cls");
              mostrarTodosRep(reparacion,MAX);
              break;
               }
              else{
                  printf("\nse debe ingresar un dato primero\n");
                  break;
                  }
        case 9:
            seguir='n';
            break;
        }
    }
    while(seguir=='s');

    return 0;
}
