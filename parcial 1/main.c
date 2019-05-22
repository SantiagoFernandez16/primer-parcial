#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "orquesta.h"
#define QTY_ORQUESTA 50

int main()
{
    int opcion;
    int contadorIdorquesta=0;

    Orquesta arrayOrquesta[QTY_ORQUESTA];
    orquesta_Inicializar(arrayOrquesta,QTY_ORQUESTA);

    do
    {
        utn_getUnsignedInt("\n\n1) Alta \n2) Modificar \n3) Baja \n4) Listar \n5) Ordenar \n6) Salir\n",
                      "\nError",1,sizeof(int),1,11,1,&opcion);
        switch(opcion)
        {
            case 1:
                orquesta_alta(arrayOrquesta,QTY_ORQUESTA,&contadorIdorquesta);
                break;

            case 2:
                //orquesta_modificar(arrayOrquesta,QTY_ORQUESTA);
                break;

            case 3:
                orquesta_baja(arrayOrquesta,QTY_ORQUESTA);

            case 4:
                orquesta_listar(arrayOrquesta,QTY_ORQUESTA);
                break;

            case 5:
                //orquesta_orquestaPorString(arrayOrquesta,QTY_ORQUESTA);
                break;

            case 6:
                break;
            default:
                printf("\nOpcion no valida");
        }
    }
    while(opcion!=6);
    return 0;
}
