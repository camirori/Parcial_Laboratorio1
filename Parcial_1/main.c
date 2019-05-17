#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "orquesta.h"
#include "instrumento.h"
#include "musico.h"
#include "informes.h"


#define QTY_ORQ 50  //50
#define QTY_INST 20  //20
#define QTY_MUSICO 100  //100

int cargarDatos(Instrumento arrayInst[], Musico arrayMusico[], Orquesta arrayOrq[], int *contadorIdOrq, int *contadorIdInst, int *contadorIdMusico);


int main()
{
    int opcion;
    int contadorIdOrq=0;
    int contadorIdInst=0;
    int contadorIdMusico=0;
    int flagOrq=0;
    int flagMusico=0;
    int flagInst=0;

    Orquesta arrayOrq[QTY_ORQ];
    Orquesta_inicializar(arrayOrq,QTY_ORQ);

    Instrumento arrayInst[QTY_INST];
    Instrumento_inicializar(arrayInst,QTY_INST);

    Musico arrayMusico[QTY_MUSICO];
    Musico_inicializar(arrayMusico,QTY_MUSICO);

    cargarDatos(arrayInst, arrayMusico, arrayOrq, &contadorIdOrq, &contadorIdInst, &contadorIdMusico);

    do
    {
        if(utn_getUnsignedInt("\n\n1) Agregar orquesta \n2) Eliminar Orquesta \n3) Imprimir orquestas \n4) Agregar musico \n5) Modificar musico \n6) Eliminar musico \n7) Imprimir musicos\n8) Agregar instrumento\n9) Imprimir instrumentos\n10) Salir\n",                   //cambiar
                                "\nError",1,3,1,&opcion)!=0)
            opcion=10;   //salir
        else
        {
            switch(opcion)
            {
                case 1: //Alta orquesta
                    if(Orquesta_alta(arrayOrq,QTY_ORQ,&contadorIdOrq)==0)                   //cambiar
                        flagOrq=1;
                    break;

                case 2: //Baja orquesta
                    if(flagOrq==0)
                    {
                        printf("\nAun no se ha dado de alta ninguna orquesta");
                    }
                    else
                        Orquesta_baja(arrayOrq,QTY_ORQ,arrayMusico,QTY_MUSICO);                   //cambiar
                    break;

                case 3: //Listar orquesta
                    if(flagOrq==0)
                    {
                        printf("\nAun no se ha dado de alta ninguna orquesta");
                    }
                    else
                        Orquesta_listar(arrayOrq,QTY_ORQ);                   //cambiar
                    break;

                case 4: //Alta musico
                    if(Musico_alta(arrayMusico,QTY_MUSICO,&contadorIdMusico)==0)                   //cambiar
                        flagMusico=1;
                    break;

                case 5: //Modificar musico
                    if(flagMusico==0)
                    {
                        printf("\nAun no se ha dado de alta ningun musico");
                    }
                    else
                        Musico_modificar(arrayMusico,QTY_MUSICO);                   //cambiar
                    break;

                case 6: //Baja musico
                    if(flagMusico==0)
                    {
                        printf("\nAun no se ha dado de alta ningun musico");
                    }
                    else
                        Musico_baja(arrayMusico,QTY_MUSICO);                   //cambiar
                    break;

                case 7: //Listar musicos
                    if(flagMusico==0)
                    {
                        printf("\nAun no se ha dado de alta ningun musico");
                    }
                    else
                        Informes_listarMusicos(arrayMusico, arrayInst, QTY_MUSICO, QTY_INST);
                    break;

                case 8: // Alta instrumento
                    if(Instrumento_alta(arrayInst,QTY_INST,&contadorIdInst)==0)                   //cambiar
                        flagInst=1;
                    break;

                case 9: //Listar instrumento
                    if(flagInst==0)
                    {
                        printf("\nAun no se ha dado de alta ningun instrumento");
                    }
                    else
                        Instrumento_listar(arrayInst,QTY_INST);                   //cambiar
                    break;

                case 10://Salir
                    break;
                default:
                    printf("\nOpcion no valida");
            }
        }
    }while(opcion!=10);
    return 0;
}


int cargarDatos(Instrumento arrayInst[], Musico arrayMusico[], Orquesta arrayOrq[], int *contadorIdOrq, int *contadorIdInst, int *contadorIdMusico)
{
    int i=0;
    //musico
    arrayMusico[i].isEmpty=0;
    arrayMusico[i].idUnico=*contadorIdMusico;
    arrayMusico[i].edad=25;
    arrayMusico[i].idOrq=*contadorIdOrq;
    arrayMusico[i].idInst=*contadorIdInst;
    strcpy(arrayMusico[i].nombre,"Federico");
    strcpy(arrayMusico[i].apellido,"Mechi");
    (*contadorIdMusico)++;

    //orquesta
    arrayOrq[i].isEmpty=0;
    arrayOrq[i].idUnico=*contadorIdOrq;
    arrayOrq[i].tipo=0;
    strcpy(arrayOrq[i].nombre,"Orquesta primera");
    strcpy(arrayOrq[i].lugar,"Avellaneda");
    (*contadorIdOrq)++;

    //instrumento
    arrayInst[i].isEmpty=0;
    arrayInst[i].idUnico=*contadorIdInst;
    arrayInst[i].tipo=1;
    strcpy(arrayInst[i].nombre,"Guitarra");
    (*contadorIdInst)++;

    i++;
    //musico
    arrayMusico[i].isEmpty=0;
    arrayMusico[i].idUnico=*contadorIdMusico;
    arrayMusico[i].edad=24;
    arrayMusico[i].idOrq=*contadorIdOrq;
    arrayMusico[i].idInst=*contadorIdInst;
    strcpy(arrayMusico[i].nombre,"Camila");
    strcpy(arrayMusico[i].apellido,"Rori");
    (*contadorIdMusico)++;

    //orquesta
    arrayOrq[i].isEmpty=0;
    arrayOrq[i].idUnico=*contadorIdOrq;
    arrayOrq[i].tipo=0;
    strcpy(arrayOrq[i].nombre,"Orquesta segunda");
    strcpy(arrayOrq[i].lugar,"Quilmes");
    (*contadorIdOrq)++;

    //instrumento
    arrayInst[i].isEmpty=0;
    arrayInst[i].idUnico=*contadorIdInst;
    arrayInst[i].tipo=1;
    strcpy(arrayInst[i].nombre,"Flauta");
    (*contadorIdInst)++;
    return 0;
}

/*
Entidades:
    Orquesta
        ID
        Nombre
        Lugar
        Tipo

    Musico
        ID musico
        Nombre
        Apellido
        Edad
        ID orquesta
        ID instrumento

    Instrumento
        ID
        Nombre
        Tipo

Falta: validar tipos, no mayor a 3 o 4


*/


