#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "orquesta.h"
#define QTY_TIPO 3

int main()
{
    int opcion;
    int contadorIdorquesta=0;

    Orquesta arrayOrquesta[QTY_TIPO];
    orquesta_Inicializar(arrayOrquesta,QTY_TIPO);

    do
    {
        utn_getUnsignedInt("\n\n1) Alta \n2) Modificar \n3) Baja \n4) Listar \n5) Ordenar \n6) Salir\n",
                      "\nError",1,sizeof(int),1,11,1,&opcion);
        switch(opcion)
        {
            case 1:
                orquesta_alta(arrayOrquesta,QTY_TIPO,&contadorIdorquesta);
                break;

            case 2:
                orquesta_modificar(arrayOrquesta,QTY_TIPO);
                break;

            case 3:
                orquesta_baja(arrayOrquesta,QTY_TIPO);

            case 4:
                orquesta_listar(arrayOrquesta,QTY_TIPO);
                break;

            case 5:
                //orquesta_orquestaPorString(arrayOrquesta,QTY_TIPO);
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
