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

//A listar orquesta
//Orquestas de un lugar en particular ingresado por el usuario, imprimir ID orquesta, nombre, tipo y lugar
/** \brief Lista los elementos de un array
* \param array Orquesta Array de Orquesta
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int Informes_a(Orquesta array[], int size)
{
    int retorno=-1;
    int i;
    char criterio[TEXT_SIZE];
    if(array!=NULL && size>=0)
    {
        utn_getTexto("\nLugar: ","\nError",1,TEXT_SIZE,1,criterio);
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty!=1 && strcmp(array[i].lugar,criterio)==0)
            {
                printf("\n ID: %d   Nombre: %s  Lugar: %s   Tipo: ",
                       array[i].idUnico,array[i].nombre,array[i].lugar);
                if(array[i].tipo==1)
                    printf("Sinfonica");
                else if(array[i].tipo==2)
                    printf("Filarmonica");
                else if(array[i].tipo==3)
                    printf("Camara");
                else
                    printf("Desconocido");
            }
        }
        retorno=0;
    }
    return retorno;
}

//*****************************************
//B Listar musico: menores de 25 años, mostrar id, nombre apellido, edad, nombre instrumento, nombre orquesta

/** \brief Busca un valor y lista los elementos de dos arrays vinculados
* \param arrayA Musico Array de Musico
* \param arrayB Orquesta Array de Orquesta
* \param arrayC Instrumento Array de Instrumento
* \param sizeI int Tamaño del arrayA
* \param sizeJ int Tamaño del arrayB
* \param sizek int Tamaño del arrayC
* \param criterio char* Puntero al valor que debe contener el elemento del array para que se liste
* \return int Return (-1) si Error [Invalid length or NULL pointer] - (0) Ok
*
*/
int Informes_b(Musico arrayA[], Orquesta arrayB[], Instrumento arrayC[], int sizeI, int sizeJ, int sizek)  //Valores de dos arrays. Si es valor repetido se vuelve a imprimir
{
    int retorno=-1;
    int i;
    int j;
    int k;
    if(arrayA!=NULL && sizeI>=0 && arrayB!=NULL && sizeJ>=0 && arrayC!=NULL && sizek>=0)
    {
        printf("\nMusicos con menos de 25 años:");
        for(i=0;i<sizeI;i++)                                                                            //Obtengo la posicion de la primer entidad
        {
            if(arrayA[i].isEmpty!=1 && arrayA[i].edad<25)
            {
                Orquesta_buscarID(arrayB,sizeJ,arrayA[i].idOrq,&j);
                Instrumento_buscarID(arrayC,sizek,arrayA[i].idInst,&k);
                printf("\n ID: %d   Nombre: %s  Apellido: %s    Edad: %d    Nombre instrumento: %s  Nombre orquesta:    %s",
                       arrayA[i].idUnico,arrayA[i].nombre,arrayA[i].apellido,arrayA[i].edad,arrayC[k].nombre,arrayB[j].nombre);
            }
        }
        retorno=0;
    }
    return retorno;
}

//C Listar orquestas con menos de 6 musicos, imprime ID orquesta, nombre, tipo y lugar
/** \brief Busca un valor repetido y lo lista una sola vez, junto con otros elementos de dos arrays vinculados
* \param arrayA Orquesta Array de Orquesta
* \param arrayB Musico Array de Musico
* \param sizeI int Tamaño del arrayA
* \param sizeJ int Tamaño del arrayB
* \return int Return (-1) si Error [Invalid length or NULL pointer] - (0) Ok
*
*/
int Informes_c(Orquesta arrayA[], Musico arrayB[], int sizeI, int sizeJ)         //cambiar Tipo
{
    int retorno=-1;
    int i;
    int j;
    int contador=0;

    if(arrayA!=NULL && sizeI>=0 && arrayB!=NULL && sizeJ>=0)
    {
        printf("\nOrquestas con menos de 6 musicos:");
        for(i=0;i<sizeI;i++)
        {
            if(arrayA[i].isEmpty==1)
                continue;                                                                 //Si ese valor ya aparecio > continue
            else
            {
                for(j=0,contador=0;j<sizeJ;j++)                                                            //Recorro por segunda vez el mismo array
                {
                    if(arrayB[j].isEmpty!=1 && arrayA[i].idUnico==arrayB[j].idOrq)     //Busco todas las veces que aparece ese id
                    {
                        contador++;
                    }
                }
                if (contador<6)
                {
                    printf("\n ID: %d   Nombre: %s  Lugar: %s   Tipo: ",
                           arrayA[i].idUnico,arrayA[i].nombre,arrayA[i].lugar);
                    if(arrayA[i].tipo==1)
                        printf("Sinfonica");
                    else if(arrayA[i].tipo==2)
                        printf("Filarmonica");
                    else if(arrayA[i].tipo==3)
                        printf("Camara");
                    else
                        printf("Desconocido");
                }
            }
        }
        retorno=0;
    }
    return retorno;
}

//D Listar instrumentos de una orquesta
/** \brief Busca un valor y lista los elementos de dos arrays vinculados
* \param arrayA Musico Array de Musico
* \param arrayB Orquesta Array de Orquesta
* \param arrayC Instrumento Array de Instrumento
* \param sizeI int Tamaño del arrayA
* \param sizeJ int Tamaño del arrayB
* \param sizek int Tamaño del arrayC
* \return int Return (-1) si Error [Invalid length or NULL pointer] - (0) Ok
*
*/
int Informes_d(Orquesta arrayA[], Musico arrayB[], Instrumento arrayC[], int sizeI, int sizeJ, int sizek)  //Valores de dos arrays. Si es valor repetido se vuelve a imprimir
{
    int retorno=-1;
    int i;
    int j;
    int k;
    int criterio;
    if(arrayA!=NULL && sizeI>=0 && arrayB!=NULL && sizeJ>=0 && arrayC!=NULL && sizek>=0)
    {
        utn_getUnsignedInt("\nID orquesta: ","\nError",1,sizeof(int),1,&criterio);
        printf("\nInstrumentos:");

        for(i=0;i<sizeI;i++)                                                                            //Obtengo la posicion de la primer entidad
        {
            if(arrayA[i].isEmpty!=1 && arrayA[i].idUnico==criterio)
            {
                Musico_buscarOrq(arrayB,sizeJ,arrayA[i].idUnico,&j);

                Instrumento_buscarID(arrayC,sizek,arrayB[i].idInst,&k);

                printf("\nNombre: %s  Tipo: ",arrayC[k].nombre);
                if(arrayC[k].tipo==1)
                    printf("Cuerdas");
                else if(arrayC[k].tipo==2)
                    printf("Viento-madera");
                else if(arrayC[k].tipo==3)
                    printf("Viento-metal");
                else if(arrayC[k].tipo==4)
                    printf("Percusion");
                else
                    printf("Desconocido");
                printf("  Nombre musico: %s",arrayB[j].nombre);

            }
        }
        retorno=0;
    }
    return retorno;
}

//E
/** \brief Busca un valor repetido y lo lista una sola vez, junto con otros elementos de dos arrays vinculados
* \param arrayA Orquesta Array de Orquesta
* \param arrayB Musico Array de Musico
* \param sizeI int Tamaño del arrayA
* \param sizeJ int Tamaño del arrayB
* \return int Return (-1) si Error [Invalid length or NULL pointer] - (0) Ok
*
*/
//Lista un campo que se repite, lo imprime una sola vez y calcula contador y acumulado
int Informes_e(Orquesta arrayA[], Musico arrayB[], Instrumento arrayC[], int sizeI, int sizeJ, int sizek)         //cambiar Tipo
{
    int retorno=-1;
    int i;
    int j;
    int k;
    int contadorCuerda=0;
    int contadorViento=0;
    int contadorPerc=0;

    if(arrayA!=NULL && sizeI>=0 && arrayB!=NULL && sizeJ>=0 && arrayC!=NULL && sizek>=0)
    {
        printf("\nOrquestas completas:");
        for(i=0;i<sizeI;i++)
        {
            if(arrayA[i].isEmpty==1)
                continue;                                                                 //Si ese valor ya aparecio > continue
            else
            {
                for(j=0,contadorCuerda=0, contadorViento=0, contadorPerc=0;j<sizeJ;j++)                                                            //Recorro por segunda vez el mismo array
                {
                    if(arrayB[j].isEmpty!=1 && arrayA[i].idUnico==arrayB[j].idOrq)     //Busco todas las veces que aparece ese id
                    {
                        Musico_buscarOrq(arrayB,sizeJ,arrayA[i].idUnico,&j);
                        Instrumento_buscarID(arrayC,sizek,arrayB[j].idInst,&k);
                        if(arrayC[k].tipo==1)
                            contadorCuerda++;
                        else if(arrayC[k].tipo==2 || arrayC[k].tipo==3)
                            contadorViento++;
                        else if(arrayC[k].tipo==4)
                            contadorPerc++;
                    }
                }
                if (contadorCuerda>=4 && contadorViento>=4 && contadorPerc>=1)
                {
                    printf("\n ID: %d   Nombre: %s  Lugar: %s   Tipo: ",
                           arrayA[i].idUnico,arrayA[i].nombre,arrayA[i].lugar);
                    if(arrayA[i].tipo==1)
                        printf("Sinfonica");
                    else if(arrayA[i].tipo==2)
                        printf("Filarmonica");
                    else if(arrayA[i].tipo==3)
                        printf("Camara");
                    else
                        printf("Desconocido");
                }
            }
        }
        retorno=0;
    }
    return retorno;
}

//F
/** \brief Busca un maximo de ocurrencia y acumulado
* \param arrayA Orquesta Array de Orquesta
* \param arrayB Musico Array de Musico
* \param sizeI int Tamaño del arrayA
* \param sizeJ int Tamaño del arrayB
* \return int Return (-1) si Error [Invalid length or NULL pointer] - (0) Ok
*
*/
int Informes_f(Orquesta arrayA[], Musico arrayB[], int sizeI, int sizeJ)
{
    int retorno=-1;
    int i;
    int j;
    int minContador=0;
    int contador=0;
    //int iMinContador [sizeI];
    int posicion;

    if(arrayA!=NULL && sizeI>=0 && arrayB!=NULL && sizeJ>=0)
    {
        for(i=0;i<sizeI;i++)
        {
            if(arrayA[i].isEmpty==1)
                continue;                                                                 //Si ese valor ya aparecio > continue
            else
            {
                for(j=0,contador=0;j<sizeJ;j++)                                                            //Recorro por segunda vez el mismo array
                {
                    if(arrayB[j].isEmpty!=1 && arrayA[i].idUnico==arrayB[j].idOrq)     //Busco todas las veces que aparece ese id
                    {
                        contador++;
                    }
                }

                if(contador<minContador || i==0)
                {
                    minContador=contador;
                    //iMinContador[i-1]=-1;                       //Si mas de un cuit tiene la mayor facturacion
                    //iMinContador[i]=i;
                    posicion=i;
                }
                /*
                else if(contador==minContador)
                    iMinContador[i]=i;
                else
                    iMinContador[i]=-2;  */                       //Para marcar los lugares vacios

            }
        }


        printf("\nMenor cantidad de musicos: %d \nOrquestas: ",minContador);
        printf("\n ID: %d   Nombre: %s  Lugar: %s   Tipo: ",
                       arrayA[posicion].idUnico,arrayA[posicion].nombre,arrayA[posicion].lugar);
                if(arrayA[posicion].tipo==1)
                    printf("Sinfonica");
                else if(arrayA[posicion].tipo==2)
                    printf("Filarmonica");
                else if(arrayA[posicion].tipo==3)
                    printf("Camara");
                else
                    printf("Desconocido");
        /*
        for(;iMinContador[i]!=-1 || i<0;i--)
        {
            if(iMinContador[i]!=-2)                         //Salteo los vacios
            {
                printf("\n ID: %d   Nombre: %s  Lugar: %s   Tipo: ",
                       arrayA[iMinContador[i]].idUnico,arrayA[iMinContador[i]].nombre,arrayA[iMinContador[i]].lugar);
                if(arrayA[iMinContador[i]].tipo==1)
                    printf("Sinfonica");
                else if(arrayA[iMinContador[i]].tipo==2)
                    printf("Filarmonica");
                else if(arrayA[iMinContador[i]].tipo==3)
                    printf("Camara");
                else
                    printf("Desconocido");
            }
        }*/

        retorno=0;
    }
    return retorno;
}

//G
/** \brief Busca un valor repetido y lo lista una sola vez, junto con otros elementos de dos arrays vinculados
* \param arrayA Orquesta Array de Orquesta
* \param arrayB Musico Array de Musico
* \param sizeI int Tamaño del arrayA
* \param sizeJ int Tamaño del arrayB
* \return int Return (-1) si Error [Invalid length or NULL pointer] - (0) Ok
*
*/
int Informes_g(Orquesta arrayA[], Instrumento arrayB[], int sizeI, int sizeJ)         //cambiar Tipo
{
    int retorno=-1;
    int i;
    int contadorOrq=0;
    int contadorInst=0;
    int promedio;

    if(arrayA!=NULL && sizeI>=0 && arrayB!=NULL && sizeJ>=0)
    {
        for(i=0;i<sizeI;i++)
        {
            if(arrayA[i].isEmpty!=1)
                contadorOrq++;
        }
        for(i=0;i<sizeJ;i++)
        {
            if(arrayB[i].isEmpty!=1)
                contadorInst++;
        }

        promedio=contadorInst/contadorOrq;

        printf("\nPromedio de instrumentos por orquesta: %d",promedio);
        retorno=0;
    }
    return retorno;
}


//H
/** \brief Lista los elementos de dos arrays vinculados
* \param arrayA Musico Array de Musico
* \param arrayB Instrumento Array de Instrumento
* \param sizeI int Tamaño del arrayA
* \param sizeJ int Tamaño del arrayB
* \return int Return (-1) si Error [Invalid length or NULL pointer] - (0) Ok
*
*/
int Informes_h(Musico arrayA[], Instrumento arrayB[], int sizeI, int sizeJ)
{
    int retorno=-1;
    int i;
    int j;
    if(arrayA!=NULL && sizeI>=0 && arrayB!=NULL && sizeJ>=0)
    {
        Musico_ordenarPorApelldio(arrayA,sizeI);
        for(i=0;i<sizeI;i++)                                                                            //Obtengo la posicion de la primer entidad
        {
            if(arrayA[i].isEmpty!=1)
            {
                Instrumento_buscarID(arrayB,sizeJ,arrayA[i].idInst,&j);                           //Obtengo la posicion de la 2da entidad buscando por el campo en comun
                if(arrayB[j].tipo!=2 && arrayB[j].tipo!=3)
                {
                    printf("\nNombre: %s  Apellido: %s    Edad: %d    Nombre instrumento: %s     Tipo instrumento: ",
                           arrayA[i].nombre,arrayA[i].apellido,arrayA[i].edad,arrayB[j].nombre);
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
        }
        retorno=0;
    }
    return retorno;
}
