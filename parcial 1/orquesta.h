#ifndef ORQUESTA_H
#define ORQUESTA_H
#define LEN 20
#define SINFONICA 1
#define FILARMONICA 2
#define CAMARA 3
typedef struct
{
    int idOrquesta;
    int isEmpty;

    char nombreOrquesta[LEN];
    int tipoOrquesta;
    char lugarOrquesta[LEN];
    int cantidadMusicos;


}Orquesta;
#endif // ORQUESTA_H


int orquesta_Inicializar(Orquesta array[], int size);
int orquesta_buscarEmpty(Orquesta array[], int size, int* posicion);
int orquesta_buscarID(Orquesta array[], int size, int valorBuscado, int* posicion);
int orquesta_buscarInt(Orquesta array[], int size, int valorBuscado, int* posicion);
int orquesta_buscarString(Orquesta array[], int size, char* valorBuscado, int* indice);
int orquesta_alta(Orquesta array[], int size, int* contadorID);
int orquesta_baja(Orquesta array[], int sizeArray, int *idCancelado);
int orquesta_bajaValorRepetidoInt(Orquesta array[], int sizeArray, int valorBuscado);
int orquesta_modificar(Orquesta array[], int sizeArray);
int orquesta_ordenarPorString(Orquesta array[],int size);
int orquesta_listar(Orquesta array[], int size);
int orquesta_mostrarTipo(int tipoOrquesta);
int orquesta_cantidadDeOrquestas(Orquesta array[], int size);


