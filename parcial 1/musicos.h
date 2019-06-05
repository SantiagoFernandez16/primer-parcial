#ifndef MUSICO_H
#define MUSICO_H
#define LEN_MUS 50
#include "orquesta.h"

typedef struct
{
    int idMusico;
    int isEmpty;

    int edadMusico;
    char nombreMusico[LEN_MUS];
    char apellidoMusico[LEN_MUS];

    int idOrquesta;
    int idInstrumento;

}Musico;
#endif // MUSICO_H


int musico_Inicializar(Musico array[], int size);
int musico_buscarEmpty(Musico array[], int size, int* posicion);
int musico_buscarID(Musico array[], int size, int valorBuscado, int* posicion);
int musico_buscarInt(Musico array[], int size, int valorBuscado, int* posicion);
int musico_buscarString(Musico array[], int size, char* valorBuscado, int* indice);
int musico_alta(Musico array[], int size, int* contadorID,Orquesta arrayOrquesta[], int sizeOrquesta);
int musico_baja(Musico array[], int sizeArray);
int musico_bajaValorRepetidoInt(Musico array[], int sizeArray, int valorBuscado);
int musico_modificar(Musico array[], int sizeArray);
int musico_ordenarPorString(Musico array[],int size);
int musico_listar(Musico array[], int size);

