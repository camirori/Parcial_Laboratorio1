#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Entrega.h"
#include "Informes.h"
#include "utn.h"

int main()
{
    //int opcion;
    //int ultimoId=0;
    //int flag=0;

    LinkedList* lista= ll_newLinkedList();
    controllerEntrega_loadFromText("data.csv",lista);
    informeEntrega_saveAsText("informes.txt",lista);

    /*
    do
    {
        if(utn_getUnsignedInt("\n\n1) \n2) \n3)  \n4)  \n5)  \n6) Salir\n",                   //cambiar
                                "\nError",1,sizeof(int),1,&opcion)!=0)
            opcion=6;   //salir
        else
        {
            switch(opcion)
            {
                case 1:
                    printf("\n");
                    if(0)
                        flag=1;
                    break;

                case 2:
                    printf("\n");
                    if(flag==0)
                    {
                        printf("\n");
                    }
                    else

                    break;

                case 3:
                    printf("\n");
                    break;

                case 4:
                    printf("\n");
                    break;

                case 5:
                    printf("\n");
                    break;

                case 6://Salir
                    break;
                default:
                    printf("\nOpcion no valida");
            }
        }
    }while(opcion!=6);*/
    return 0;
}
