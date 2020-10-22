#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "electrodomesticos.h"
#include "utn.h"
#define MAX 5

void AltaElec(eElec elec[], int cant)
{
    int i;
    for(i=0; i<cant; i++)
    {

        if(elec[i].isEmpty==1)
        {

            elec[i].Id =(i+1);
            utn_getInt(&elec[i].serie, "\ningresar Serie:1 a 5", "Serie no valida", 1,5,90);
            utn_getFloat(&elec[i].IdMarca, "\ningresar Marca:\n1000 Wirpool\n1001 Sony\n1002 Liliana\n1003 Gafa\n1004 Philips\n", "Marca no valida", 1000,1004,90);
            utn_getFloat(&elec[i].modelo, "\ningresar modelo:1980 a 2020", "modelo no valido", 1980,2020,90);
            elec[i].isEmpty=0;
            printf("\nId:%d\nSerie:%d\nIdMarca:%.0f\nModelo:%.0f\n",elec[i].Id, elec[i].serie, elec[i].IdMarca,elec[i].modelo);
            system("pause");
            break;
        }

    }


}



void mostrarTodosElec(eElec elec[],int cant)
{
    int i;

    for(i=0; i<cant; i++)
    {

    	if(elec[i].isEmpty==0)
    	        {
    	            mostrarUnoElec(elec[i]);
    	        }

    }

}

void mostrarUnoElec(eElec elec)
{
    printf("\nId:%d\nSerie:%d\nIdMarca:%.0f\nModelo:%.0f\n",elec.Id, elec.serie, elec.IdMarca,elec.modelo);
}

void mostrarTodosMarca(eMarca marca[],int cant)
{
    int i;

    for(i=0; i<cant; i++)
    {

    	mostrarUnoMarca(marca[i]);

    }

}

void mostrarUnoMarca(eMarca marcas)
{
    printf("\nId:%d\nMarca:%s\n",marcas.Id, marcas.Marca);
}


void ordenarMoySe(eElec elec[],int cant)
{
    int i,j;
    eElec auxelec;
    for(i=0; i<cant-1; i++)
    {
        for(j=i+1; j<cant; j++)
        {
            if(elec[i].modelo>elec[j].modelo)
            {
                auxelec=elec[i];
                elec[i]=elec[j];
                elec[j]=auxelec;
            }
            else
            {
                if(elec[i].modelo==elec[j].modelo && elec[i].serie==elec[j].serie)
            {
                    auxelec=elec[i];
                    elec[i]=elec[j];
                    elec[j]=auxelec;
                }
            }
        }
        break;
    }

}

void initElec (eElec elec[], int cant)
{

    int i;
    for(i=0; i<cant; i++)
    {
        elec[i].isEmpty=1;
    }

}

 void Baja (eElec elec[], int cant)
{
    int auxId;
    int flag=0,i;
    char rta;
    mostrarTodosElec(elec, MAX);
    fflush(stdin);
    utn_getInt(&auxId, "que Id desea buscar?", "Id no encontrado", 1, 3, 3);
    for(i=0; i<cant; i++)
    {
        if(auxId==elec[i].Id)
        {
            printf("\nId:%d\nSerie:%d\nMarca:%.0f\nModelo:%.0f\nempty:%d\n",elec[i].Id, elec[i].serie, elec[i].IdMarca,elec[i].modelo, elec[i].isEmpty);
            do
            {
                printf("\nDesea borrar este registro s/n");
                fflush(stdin);
                scanf("%c",&rta);
                rta=tolower(rta);
            }
            while( rta != 's' && rta != 'n' );
            if(rta=='s')
            {
                elec[i].isEmpty=1;
            }
            else
            {
                printf("\nno se dio de baja\n");
            }

        }
        flag=1;

    }
    if (flag==0)
    {
        printf("no existe dato\n");
    }

}

void Modificacion (eElec elec[], int cant)
{
    int auxId;
    int flag=0,i,OP;
    char seguir='s',rta;
    mostrarTodosElec(elec, MAX);
    fflush(stdin);
    utn_getInt(&auxId, "Que Id desea buscar?", "Id no encontrado", 1, 3, 3);
    for(i=0; i<cant; i++)
    {
        if(auxId==elec[i].Id)
        {
            printf("\nId:%d\nSerie:%d\nMarca:%.0f\nModelo:%.0f\n",elec[i].Id, elec[i].serie, elec[i].IdMarca,elec[i].modelo);
            do
            {
                printf("\ndesea modificar este registro s/n");
                fflush(stdin);
                scanf("%c",&rta);
            }
            while(rta!='s'&&rta!='n');
            if(rta=='s')
            {
                do
                {

                    printf("\nQue desea modificar ?\n1- Serie\n2- Marca\n3- Modelo\n4-salir\n");
                    utn_getInt(&OP, "\ningresar opcion", "opcion no valida", 1,5,3);
                    switch(OP)
                    {


                    case 1:
                    	utn_getInt(&elec[i].serie, "\ningresar modelo:1 a 5", "Serie no valida", 1,5,3);
                        system("cls");
                        break;

                    case 2:
                    	utn_getFloat(&elec[i].IdMarca, "\ningresar modelo:\n1000 Wirpool\n1001 Sony\n1002 Liliana\n1003 Gafa\n1004 Philips\n", "modelo no valido", 1000,1004,3);
                        system("cls");
                        break;

                    case 3:
                    	utn_getFloat(&elec[i].modelo, "\ningresar modelo:1980 a 2020", "modelo no valido", 1980,2020,3);
                        system("cls");
                        break;
                    case 4:
                        seguir='n';
                        break;
                    }
                }
                while(seguir=='s');
            }
            else
            {
                printf("no se Modifico");
            }
        }
        flag=1;
    }
    if (flag==0)
    {
        printf("no existe dato");
    }
}

int AllEmptyElec(eElec elec[], int cant)
{

    int i;
    int flag=1;
    for(i=0; i<cant; i++)
    {
        if(elec[i].isEmpty!=1)
        {
            flag=0;
        }
    }
    return flag;
}

