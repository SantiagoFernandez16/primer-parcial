#ifndef INSTRUMENTO_H
#define INSTRUMENTO_H
#define LEN_INSTRUMENTOS 50

#define CUERDAS 1
#define VIENTO_MADERA 2
#define VIENTO_METAL 3
#define PERCUSION 4

typedef struct
{
    int idInstrumento;
    int isEmpty;

    char nombreInstrumento[LEN_INSTRUMENTOS];
    int tipoInstrumento;

    int idMusico;

}Instrumento;
#endif // INSTRUMENTO_H


int instrumento_Inicializar(Instrumento array[], int size);
int instrumento_buscarEmpty(Instrumento array[], int size, int* posicion);
int instrumento_buscarID(Instrumento array[], int size, int valorBuscado, int* posicion);
int instrumento_buscarInt(Instrumento array[], int size, int valorBuscado, int* posicion);
int instrumento_buscarString(Instrumento array[], int size, char* valorBuscado, int* indice);
int instrumento_alta(Instrumento array[], int size, int* contadorID);
int instrumento_baja(Instrumento array[], int sizeArray);
int instrumento_bajaValorRepetidoInt(Instrumento array[], int sizeArray, int valorBuscado);
int instrumento_modificar(Instrumento array[], int sizeArray);
int instrumento_ordenarPorString(Instrumento array[],int size);
int instrumento_listar(Instrumento array[], int size);
int instrumento_mostrarTipo(int tipoInstrumento);


