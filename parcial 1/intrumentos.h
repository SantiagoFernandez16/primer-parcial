#ifndef INSTRUMENTO_H
#define INSTRUMENTO_H
#define LEN 50
typedef struct
{
    int idInstrumento;
    int isEmpty;

    char nombreInstrumento[LEN];
    char tipoIntrumento;

}Instrumento;
#endif // INSTRUMENTO_H


int intrumento_Inicializar(Instrumento array[], int size);
int intrumento_buscarEmpty(Instrumento array[], int size, int* posicion);
int intrumento_buscarID(Instrumento array[], int size, int valorBuscado, int* posicion);
int intrumento_buscarInt(Instrumento array[], int size, int valorBuscado, int* posicion);
int intrumento_buscarString(Instrumento array[], int size, char* valorBuscado, int* indice);
int intrumento_alta(Instrumento array[], int size, int* contadorID);
int intrumento_baja(Instrumento array[], int sizeArray);
int intrumento_bajaValorRepetidoInt(Instrumento array[], int sizeArray, int valorBuscado);
int intrumento_modificar(Instrumento array[], int sizeArray);
int intrumento_ordenarPorString(Instrumento array[],int size);
int intrumento_listar(Instrumento array[], int size);

