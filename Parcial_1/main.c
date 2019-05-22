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
    int contadorIdOrq=1;
    int contadorIdInst=1;
    int contadorIdMusico=1;
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
        if(utn_getUnsignedInt("\n\n1) Agregar orquesta \n2) Eliminar Orquesta \n3) Imprimir orquestas \n4) Agregar musico \n5) Modificar musico \n6) Eliminar musico \n7) Imprimir musicos\n8) Agregar instrumento\n9) Imprimir instrumentos\n10) Siguiente menu\n",                   //cambiar
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

    do
    {
        if(utn_getUnsignedInt("\nInformes: \n1) A \n2) B \n3) C \n4) D \n5) E \n6) F \n7) G\n8) H\n9) Salir\n",                   //cambiar
                                "\nError",1,3,1,&opcion)!=0)
            opcion=10;   //salir
        else
        {
            switch(opcion)
            {
                case 1: //Alta orquesta
                    Informes_a(arrayOrq, QTY_ORQ);
                    break;

                case 2: //Baja orquesta
                    Informes_b(arrayMusico, arrayOrq, arrayInst, QTY_MUSICO, QTY_ORQ, QTY_INST);
                    break;

                case 3: //Listar orquesta
                    Informes_c(arrayOrq, arrayMusico, QTY_ORQ, QTY_MUSICO);
                    break;

                case 4: //Alta musico
                    Informes_d(arrayOrq, arrayMusico, arrayInst, QTY_ORQ, QTY_MUSICO, QTY_INST);
                    break;

                case 5: //Modificar musico
                    Informes_e(arrayOrq, arrayMusico, arrayInst, QTY_ORQ, QTY_MUSICO, QTY_INST);
                    break;

                case 6: //Baja musico
                    Informes_f(arrayOrq, arrayMusico, QTY_ORQ, QTY_MUSICO);
                    break;

                case 7: //Listar musicos
                    Informes_g(arrayOrq, arrayInst, QTY_ORQ, QTY_INST);
                    break;

                case 8: //Listar instrumento
                    Informes_h(arrayMusico, arrayInst, QTY_MUSICO, QTY_INST);
                    break;

                case 9://Salir
                    break;
                default:
                    printf("\nOpcion no valida");
            }
        }
    }while(opcion!=9);

    return 0;
}


int cargarDatos(Instrumento arrayInst[], Musico arrayMusico[], Orquesta arrayOrq[], int *contadorIdOrq, int *contadorIdInst, int *contadorIdMusico)
{
    int i=0;
        //instrumento
    arrayInst[i].isEmpty=0;
    arrayInst[i].idUnico=*contadorIdInst;
    arrayInst[i].tipo=1;
    strcpy(arrayInst[i].nombre,"Inst 1");
    (*contadorIdInst)++;
    i++;

    arrayInst[i].isEmpty=0;
    arrayInst[i].idUnico=*contadorIdInst;
    arrayInst[i].tipo=2;
    strcpy(arrayInst[i].nombre,"Inst 2");
    (*contadorIdInst)++;
    i++;

    arrayInst[i].isEmpty=0;
    arrayInst[i].idUnico=*contadorIdInst;
    arrayInst[i].tipo=3;
    strcpy(arrayInst[i].nombre,"Inst 3");
    (*contadorIdInst)++;
    i++;

    arrayInst[i].isEmpty=0;
    arrayInst[i].idUnico=*contadorIdInst;
    arrayInst[i].tipo=3;
    strcpy(arrayInst[i].nombre,"Inst 3");
    (*contadorIdInst)++;
    i++;

    arrayInst[i].isEmpty=0;
    arrayInst[i].idUnico=*contadorIdInst;
    arrayInst[i].tipo=4;
    strcpy(arrayInst[i].nombre,"Inst 4");
    (*contadorIdInst)++;
    i++;

    i=0;
    //musico
    arrayMusico[i].isEmpty=0;
    arrayMusico[i].idUnico=*contadorIdMusico;
    arrayMusico[i].edad=30;
    arrayMusico[i].idOrq=2;
    arrayMusico[i].idInst=1;
    strcpy(arrayMusico[i].nombre,"Mus1");
    strcpy(arrayMusico[i].apellido,"AMus1");
    (*contadorIdMusico)++;
    i++;
    //musico
    arrayMusico[i].isEmpty=0;
    arrayMusico[i].idUnico=*contadorIdMusico;
    arrayMusico[i].edad=20;
    arrayMusico[i].idOrq=5;
    arrayMusico[i].idInst=2;
    strcpy(arrayMusico[i].nombre,"Mus2");
    strcpy(arrayMusico[i].apellido,"AMus2");
    (*contadorIdMusico)++;
    i++;
    //musico
    arrayMusico[i].isEmpty=0;
    arrayMusico[i].idUnico=*contadorIdMusico;
    arrayMusico[i].edad=25;
    arrayMusico[i].idOrq=2;
    arrayMusico[i].idInst=4;
    strcpy(arrayMusico[i].nombre,"Mus3");
    strcpy(arrayMusico[i].apellido,"AMus3");
    (*contadorIdMusico)++;
    i++;
    //musico
    arrayMusico[i].isEmpty=0;
    arrayMusico[i].idUnico=*contadorIdMusico;
    arrayMusico[i].edad=27;
    arrayMusico[i].idOrq=1;
    arrayMusico[i].idInst=4;
    strcpy(arrayMusico[i].nombre,"Mus4");
    strcpy(arrayMusico[i].apellido,"AMus4");
    (*contadorIdMusico)++;
    i++;
    //musico
    arrayMusico[i].isEmpty=0;
    arrayMusico[i].idUnico=*contadorIdMusico;
    arrayMusico[i].edad=22;
    arrayMusico[i].idOrq=3;
    arrayMusico[i].idInst=1;
    strcpy(arrayMusico[i].nombre,"Mus5");
    strcpy(arrayMusico[i].apellido,"AMus5");
    (*contadorIdMusico)++;
    i++;
    //musico
    arrayMusico[i].isEmpty=0;
    arrayMusico[i].idUnico=*contadorIdMusico;
    arrayMusico[i].edad=35;
    arrayMusico[i].idOrq=4;
    arrayMusico[i].idInst=3;
    strcpy(arrayMusico[i].nombre,"Mus6");
    strcpy(arrayMusico[i].apellido,"AMus6");
    (*contadorIdMusico)++;
    i++;

    i=0;
    //orquesta
    arrayOrq[i].isEmpty=0;
    arrayOrq[i].idUnico=*contadorIdOrq;
    arrayOrq[i].tipo=1;
    strcpy(arrayOrq[i].nombre,"Orquesta1");
    strcpy(arrayOrq[i].lugar,"Lugar1");
    (*contadorIdOrq)++;
    i++;
    //orquesta
    arrayOrq[i].isEmpty=0;
    arrayOrq[i].idUnico=*contadorIdOrq;
    arrayOrq[i].tipo=2;
    strcpy(arrayOrq[i].nombre,"Orquesta2");
    strcpy(arrayOrq[i].lugar,"Lugar1");
    (*contadorIdOrq)++;
    i++;
    //orquesta
    arrayOrq[i].isEmpty=0;
    arrayOrq[i].idUnico=*contadorIdOrq;
    arrayOrq[i].tipo=3;
    strcpy(arrayOrq[i].nombre,"Orquesta3");
    strcpy(arrayOrq[i].lugar,"Lugar2");
    (*contadorIdOrq)++;
    i++;
    //orquesta
    arrayOrq[i].isEmpty=0;
    arrayOrq[i].idUnico=*contadorIdOrq;
    arrayOrq[i].tipo=2;
    strcpy(arrayOrq[i].nombre,"Orquesta4");
    strcpy(arrayOrq[i].lugar,"Lugar3");
    (*contadorIdOrq)++;
    i++;


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


