#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "orquesta.h"
#include "musicos.h"
#include "intrumentos.h"
#include "informes.h"

#define QTY_ORQUESTA 50
#define QTY_MUSICO 1000
#define QTY_INSTRUMENTOS 20

int main()
{
    int opcion;
    int contadorIdOrquesta=0;
    int auxIdCancelado=0;
    int contadorIdMusico=0;
    int contadorIdInstrumento=0;
    char opcionInformes;


    Orquesta arrayOrquesta[QTY_ORQUESTA];
    Musico arrayMusico[QTY_MUSICO];
    Instrumento arrayInstrumento[QTY_INSTRUMENTOS];

    orquesta_Inicializar(arrayOrquesta,QTY_ORQUESTA);
    musico_Inicializar(arrayMusico,QTY_MUSICO);
    instrumento_Inicializar(arrayInstrumento,QTY_INSTRUMENTOS);


    arrayInstrumento[1].idInstrumento=1;
    arrayInstrumento[1].isEmpty=0;
    strncpy(arrayInstrumento[1].nombreInstrumento,"inst1",sizeof(arrayInstrumento[1].nombreInstrumento));
    arrayInstrumento[1].tipoInstrumento=1;

    arrayInstrumento[2].idInstrumento=2;
    arrayInstrumento[2].isEmpty=0;
    strncpy(arrayInstrumento[2].nombreInstrumento,"inst2",sizeof(arrayInstrumento[2].nombreInstrumento));
    arrayInstrumento[2].tipoInstrumento=2;

    arrayInstrumento[3].idInstrumento=3;
    arrayInstrumento[3].isEmpty=0;
    strncpy(arrayInstrumento[3].nombreInstrumento,"inst3",sizeof(arrayInstrumento[3].nombreInstrumento));
    arrayInstrumento[3].tipoInstrumento=2;

    arrayInstrumento[4].idInstrumento=4;
    arrayInstrumento[4].isEmpty=0;
    strncpy(arrayInstrumento[4].nombreInstrumento,"inst4",sizeof(arrayInstrumento[4].nombreInstrumento));
    arrayInstrumento[4].tipoInstrumento=3;

    arrayInstrumento[5].idInstrumento=5;
    arrayInstrumento[5].isEmpty=0;
    strncpy(arrayInstrumento[5].nombreInstrumento,"inst5",sizeof(arrayInstrumento[5].nombreInstrumento));
    arrayInstrumento[5].tipoInstrumento=4;

    arrayOrquesta[1].idOrquesta=1;
    arrayOrquesta[1].isEmpty=0;
    strncpy(arrayOrquesta[1].nombreOrquesta,"Orquesta1",sizeof(arrayOrquesta[1].nombreOrquesta));
    strncpy(arrayOrquesta[1].lugarOrquesta,"Lugar1",sizeof(arrayOrquesta[4].lugarOrquesta));
    arrayOrquesta[1].tipoOrquesta=1;

    arrayOrquesta[2].idOrquesta=2;
    arrayOrquesta[2].isEmpty=0;
    strncpy(arrayOrquesta[2].nombreOrquesta,"Orquesta2",sizeof(arrayOrquesta[1].nombreOrquesta));
    strncpy(arrayOrquesta[2].lugarOrquesta,"Lugar1",sizeof(arrayOrquesta[4].lugarOrquesta));
    arrayOrquesta[2].tipoOrquesta=2;

    arrayOrquesta[3].idOrquesta=3;
    arrayOrquesta[3].isEmpty=0;
    strncpy(arrayOrquesta[3].nombreOrquesta,"Orquesta3",sizeof(arrayOrquesta[1].nombreOrquesta));
    strncpy(arrayOrquesta[3].lugarOrquesta,"Lugar2",sizeof(arrayOrquesta[4].lugarOrquesta));
    arrayOrquesta[3].tipoOrquesta=3;

    arrayOrquesta[4].idOrquesta=4;
    arrayOrquesta[4].isEmpty=0;
    strncpy(arrayOrquesta[4].nombreOrquesta,"Orquesta4",sizeof(arrayOrquesta[1].nombreOrquesta));
    strncpy(arrayOrquesta[4].lugarOrquesta,"Lugar2",sizeof(arrayOrquesta[4].lugarOrquesta));
    arrayOrquesta[4].tipoOrquesta=3;


    strncpy(arrayMusico[1].apellidoMusico,"Amus1",sizeof(arrayMusico[1].apellidoMusico));
    strncpy(arrayMusico[1].nombreMusico,"Mus1",sizeof(arrayMusico[6].nombreMusico));
    arrayMusico[1].edadMusico=30;
    arrayMusico[1].idInstrumento=2;
    arrayMusico[1].idOrquesta=1;
    arrayMusico[1].idMusico=1;
    arrayMusico[1].isEmpty=0;

    strncpy(arrayMusico[2].apellidoMusico,"Amus2",sizeof(arrayMusico[1].apellidoMusico));
    strncpy(arrayMusico[2].nombreMusico,"Mus2",sizeof(arrayMusico[6].nombreMusico));
    arrayMusico[2].edadMusico=20;
    arrayMusico[2].idInstrumento=5;
    arrayMusico[2].idOrquesta=2;
    arrayMusico[2].idMusico=2;
    arrayMusico[2].isEmpty=0;

    strncpy(arrayMusico[3].apellidoMusico,"Amus3",sizeof(arrayMusico[1].apellidoMusico));
    strncpy(arrayMusico[3].nombreMusico,"Mus3",sizeof(arrayMusico[6].nombreMusico));
    arrayMusico[3].edadMusico=25;
    arrayMusico[3].idInstrumento=2;
    arrayMusico[3].idOrquesta=4;
    arrayMusico[3].idMusico=3;
    arrayMusico[3].isEmpty=0;

    strncpy(arrayMusico[4].apellidoMusico,"Amus4",sizeof(arrayMusico[1].apellidoMusico));
    strncpy(arrayMusico[4].nombreMusico,"Mus4",sizeof(arrayMusico[6].nombreMusico));
    arrayMusico[4].edadMusico=27;
    arrayMusico[4].idInstrumento=1;
    arrayMusico[4].idOrquesta=4;
    arrayMusico[4].idMusico=4;
    arrayMusico[4].isEmpty=0;

    strncpy(arrayMusico[5].apellidoMusico,"Amus5",sizeof(arrayMusico[1].apellidoMusico));
    strncpy(arrayMusico[5].nombreMusico,"Mus5",sizeof(arrayMusico[6].nombreMusico));
    arrayMusico[5].edadMusico=22;
    arrayMusico[5].idInstrumento=3;
    arrayMusico[5].idOrquesta=1;
    arrayMusico[5].idMusico=5;
    arrayMusico[5].isEmpty=0;

    strncpy(arrayMusico[6].apellidoMusico,"Amus6",sizeof(arrayMusico[1].apellidoMusico));
    strncpy(arrayMusico[6].nombreMusico,"Mus6",sizeof(arrayMusico[6].nombreMusico));
    arrayMusico[6].edadMusico=35;
    arrayMusico[6].idInstrumento=4;
    arrayMusico[6].idOrquesta=3;
    arrayMusico[6].idMusico=6;
    arrayMusico[6].isEmpty=0;

    do
    {
        utn_getUnsignedInt("\n\n1) Alta Orquesta \n2) Baja Orquesta \n3) Listar Orquesta \n4) Alta del Musico \n5) Modificar Musico \n6) Baja de Musico\n7) Lstar Musicos\n8) Alta Instrumento\n9) Listar Instrumentos\n10) Informes\n11) Salir\n",
                      "\nError",1,3000,1,11,1,&opcion);
        switch(opcion)
        {
            case 1:
                orquesta_alta(arrayOrquesta,QTY_ORQUESTA,&contadorIdOrquesta);
                break;

            case 2:
                orquesta_baja(arrayOrquesta,QTY_ORQUESTA,&auxIdCancelado);
                musico_bajaValorRepetidoInt(arrayMusico,QTY_MUSICO,auxIdCancelado);
                break;

            case 3:
                orquesta_listar(arrayOrquesta,QTY_ORQUESTA);

            case 4:
                musico_alta(arrayMusico,QTY_MUSICO,&contadorIdMusico,arrayOrquesta,QTY_ORQUESTA);
                break;

            case 5:
                musico_modificar(arrayMusico,QTY_MUSICO,arrayOrquesta,QTY_ORQUESTA);
                break;

            case 6:
                musico_baja(arrayMusico,QTY_MUSICO);
                break;

            case 7:
                musico_listar(arrayMusico,QTY_MUSICO);
                break;
             case 8://alta instrumento
                instrumento_alta(arrayInstrumento,QTY_INSTRUMENTOS,&contadorIdInstrumento);
                break;
            case 9://imprimir musicos
                instrumento_listar(arrayInstrumento,QTY_INSTRUMENTOS);
                break;
            case 10://INFORMES
                do
                {
                    utn_getChar("\nInformes: \nA \nB \nC \nD \nE \nF \nG \nH \nS(salir)","\nError\n",'A','Z',1,&opcionInformes);
                    switch(opcionInformes)
                    {
                        case 'A':
                            informe_mostrarOrquestaMasCincoMusicos(arrayOrquesta,QTY_ORQUESTA,arrayMusico,QTY_MUSICO);
                            break;
                        case 'B':
                            informe_mostrarMusicoMastreintaAno(arrayMusico,QTY_MUSICO,arrayOrquesta,QTY_ORQUESTA,arrayInstrumento,QTY_INSTRUMENTOS);
                            break;
                        case 'C':
                            informe_imprimirPorLugar(arrayOrquesta, QTY_ORQUESTA);
                            break;
                        case 'D':
                            informe_mostrarOrquestaCompleta(arrayOrquesta,QTY_ORQUESTA,arrayMusico,QTY_MUSICO,arrayInstrumento,QTY_INSTRUMENTOS);
                            break;
                        case 'E':
                            informe_mostarMusicoPorUnaOrquesta(arrayOrquesta,QTY_ORQUESTA,arrayMusico,QTY_MUSICO,arrayInstrumento,QTY_INSTRUMENTOS);
                            break;
                        case 'F':
                            informe_orquestaMasMusicos(arrayOrquesta,QTY_ORQUESTA,arrayMusico,QTY_MUSICO);
                            break;
                        case 'G':
                            informe_musicosDeCuerdas(arrayMusico,QTY_MUSICO,arrayInstrumento,QTY_INSTRUMENTOS);
                            break;
                        case 'H':
                            informe_promedioMusicosPorOrquesta(arrayOrquesta,QTY_ORQUESTA,arrayMusico,QTY_MUSICO);
                            break;
                        case 'S':
                            break;
                        default:
                            printf("\nOpcion no valida");
                    }
                }while(opcionInformes!='S');
                    /*informe_mostrarOrquestaMasCincoMusicos(arrayOrquesta,QTY_ORQUESTA,
                                                           arrayMusico,QTY_MUSICO);
                    informe_mostrarMusicoMastreintaAno(arrayMusico,QTY_MUSICO,
                                                        arrayOrquesta,QTY_ORQUESTA,
                                                        arrayInstrumento,QTY_INSTRUMENTO);
                    informe_imprimirPorLugar(arrayOrquesta, QTY_ORQUESTA);
                    informe_mostrarOrquestaCompleta(arrayOrquesta,QTY_ORQUESTA,
                                                    arrayMusico,QTY_MUSICO,
                                                    arrayInstrumento,QTY_INSTRUMENTO);
                    informe_orquestaMasMusicos(arrayOrquesta,QTY_ORQUESTA,
                                               arrayMusico,QTY_MUSICO);
                    informe_musicosDeCuerdas(arrayMusico,QTY_MUSICO,
                                            arrayInstrumento,QTY_INSTRUMENTO);
                    informe_promedioMusicosPorOrquesta(arrayOrquesta,QTY_ORQUESTA,
                                                       arrayMusico,QTY_MUSICO);
                    informe_mostarMusicoPorUnaOrquesta(arrayOrquesta,QTY_ORQUESTA,
                                                       arrayMusico,QTY_MUSICO,
                                                       arrayInstrumento,QTY_INSTRUMENTO);*/
                break;
                //salir
            case 11:
                break;
            default:
                printf("\nOpcion no valida");
        }
    }
    while(opcion!=11);
    return 0;
}
