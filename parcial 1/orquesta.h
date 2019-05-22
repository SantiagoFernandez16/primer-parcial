#ifndef ORQUESTA_H
#define ORQUESTA_H
#define LEN 20
typedef struct
{
    int idOrquesta;
    int isEmpty;

    char nombreOrquesta[LEN];
    int tipoOrquesta;
    char lugarOrquesta[LEN];

}Orquesta;
#endif // ORQUESTA_H


int orquesta_Inicializar(Orquesta array[], int size);
int orquesta_buscarEmpty(Orquesta array[], int size, int* posicion);
int orquesta_buscarID(Orquesta array[], int size, int valorBuscado, int* posicion);
int orquesta_buscarInt(Orquesta array[], int size, int valorBuscado, int* posicion);
int orquesta_buscarString(Orquesta array[], int size, char* valorBuscado, int* indice);
int orquesta_alta(Orquesta array[], int size, int* contadorID);
int orquesta_baja(Orquesta array[], int sizeArray);
int orquesta_bajaValorRepetidoInt(Orquesta array[], int sizeArray, int valorBuscado);
int orquesta_modificar(Orquesta array[], int sizeArray);
int orquesta_ordenarPorString(Orquesta array[],int size);
int orquesta_listar(Orquesta array[], int size);
