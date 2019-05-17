#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "informes.h"
#include "instrumento.h"
#include "musico.h"
#include "orquesta.h"


/** \brief Lista los elementos de dos arrays vinculados
* \param arrayA Musico Array de Musico
* \param arrayB Instrumento Array de Instrumento
* \param sizeI int Tamaño del arrayA
* \param sizeJ int Tamaño del arrayB
* \return int Return (-1) si Error [Invalid length or NULL pointer] - (0) Ok
*
*/
int Informes_listarMusicos(Musico arrayA[], Instrumento arrayB[], int sizeI, int sizeJ)
{
    int retorno=-1;
    int i;
    int j;
    if(arrayA!=NULL && sizeI>=0 && arrayB!=NULL && sizeJ>=0)
    {
        for(i=0;i<sizeI;i++)                                                                            //Obtengo la posicion de la primer entidad
        {
            if(arrayA[i].isEmpty!=1)
            {
                Instrumento_buscarID(arrayB,sizeJ,arrayA[i].idInst,&j);                           //Obtengo la posicion de la 2da entidad buscando por el campo en comun


                printf("\n ID: %d   Nombre: %s  Apellido: %s    Edad: %d    Nombre instrumento: %s     Tipo instrumento: ",
                       arrayA[i].idUnico,arrayA[i].nombre,arrayA[i].apellido,arrayA[i].edad,arrayB[j].nombre);
                if(arrayB[j].tipo==1)
                    printf("Cuerdas");
                else if(arrayB[j].tipo==2)
                    printf("Viento-madera");
                else if(arrayB[j].tipo==3)
                    printf("Viento-metal");
                else if(arrayB[j].tipo==4)
                    printf("Percusion");
                else
                    printf("Desconocido");

            }
        }
        retorno=0;
    }
    return retorno;
}
