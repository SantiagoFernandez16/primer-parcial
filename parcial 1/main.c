#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "orquesta.h"
#include "musicos.h"
#include "intrumentos.h"

#define QTY_ORQUESTA 50
#define QTY_MUSICO 1000
#define QTY_INSTRUMENTOS 20


int main()
{
    int opcion;
    int contadorIdorquesta=0;
    //int auxIdCancelado;
    //int contadorIdOrquesta=0;
    //int contadorIdMusico=0;
    //int contadorIdInstrumento=0;

    Orquesta arrayOrquesta[QTY_ORQUESTA];
    //Musico arrayMusico[QTY_MUSICO];
    //Instrumento arrayInstrumento[QTY_INSTRUMENTOS];


    do
    {
        utn_getUnsignedInt("\n\n1) Alta \n2) Baja \n3) Listar \n4) Alta del Musico \n5) Modificar Musico \n6) Baja de Musico\n7) Lstar Musicos\n8) Alta Instrumento\n9) Listar Instrumentos\10) Salir",
                      "\nError",1,sizeof(int),1,11,1,&opcion);
        switch(opcion)
        {
            case 1:
                orquesta_alta(arrayOrquesta,QTY_ORQUESTA,&contadorIdorquesta);
                break;

            case 2:
                orquesta_baja(arrayOrquesta,QTY_ORQUESTA);
               //musico_bajaValorRepetidoInt(arrayMusico,QTY_MUSICO,auxIdCancelado);
                break;

            case 3:
                orquesta_listar(arrayOrquesta,QTY_ORQUESTA);

            case 4:
               // musico_alta(arrayMusico,QTY_MUSICO,&contadorIdMusico,arrayOrquesta,QTY_ORQUESTA);
                break;

            case 5:
                //musico_modificar(arrayMusico,QTY_MUSICO,arrayOrquesta,QTY_ORQUESTA);
                break;

            case 6:
               // musico_baja(arrayMusico,QTY_MUSICO);
                break;

            case 7:
               // musico_listar(arrayMusico,QTY_MUSICO);
                break;
             case 8://alta instrumento
               // instrumento_alta(arrayInstrumento,QTY_INSTRUMENTOS,&contadorIdInstrumento);
                break;
            case 9://imprimir musicos
               // instrumento_listar(arrayInstrumento,QTY_INSTRUMENTOS);
                break;
            case 10://Salir
                break;
            default:
                printf("\nOpcion no valida");
        }
    }
    while(opcion!=6);
    return 0;
}
