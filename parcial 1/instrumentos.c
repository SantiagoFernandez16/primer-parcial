#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "intrumentos.h"


/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array instrumento Array of instrumento
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int instrumento_Inicializar(Instrumento array[], int size)                                    //cambiar instrumento
{
    int retorno=-1;
    if(array!= NULL && size>0)
    {
        for(;size>0;size--)
        {
            array[size-1].isEmpty=1;
        }
        retorno=0;
    }
    return retorno;
}

//*****************************************
//Buscar
//Int
/** \brief Busca el primer lugar vacio en un array
* \param array instrumento Array de instrumento
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int instrumento_buscarEmpty(Instrumento array[], int size, int* posicion)                    //cambiar instrumento
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0 && posicion!=NULL)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param array instrumento Array de instrumento
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int instrumento_buscarID(Instrumento array[], int size, int valorBuscado, int* posicion)                    //cambiar instrumento
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idInstrumento==valorBuscado)                                                   //cambiar campo ID
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}
/** \brief Busca un int en un array y devuelve la posicion en que se encuentra
* \param array instrumento Array de instrumento
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int instrumento_buscarInt(Instrumento array[], int size, int valorBuscado, int* posicion)                    //cambiar instrumento
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].tipoInstrumento==valorBuscado)                                                   //cambiar campo tipoInstrumento
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

//String
/** \brief Busca un string en un array
* \param array instrumento Array de instrumento
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int instrumento_buscarString(Instrumento array[], int size, char* valorBuscado, int* indice)                    //cambiar instrumento
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(strcmp(array[i].nombreInstrumento,valorBuscado)==0)                                        //cambiar campo nombreInstrumento
            {
                *indice=i;
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}

//*****************************************
//Alta
/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param array instrumento Array de instrumento
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int instrumento_alta(Instrumento array[], int size, int* contadorID)                          //cambiar instrumento
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(instrumento_buscarEmpty(array,size,&posicion)==-1)                          //cambiar instrumento
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
             (*contadorID)++;
            array[posicion].idInstrumento=*contadorID;
            array[posicion].isEmpty=0;
            utn_getUnsignedInt("\nIngrese tipo: \n1-Cuerdas\n2-viento-madera\n3-Viento-metal\n4-percusion\n : ","\nError",1,sizeof(int),1,4,1,&array[posicion].tipoInstrumento);
            utn_getName("\nIngrese nombre de instrumento: ","\nError",1,sizeof(int),1,array[posicion].nombreInstrumento);
            printf("\n Posicion: %d\n ID: %d\n tipo: %d\n nombre: %s",
                   posicion,
                   array[posicion].idInstrumento,
                   array[posicion].tipoInstrumento,
                   array[posicion].nombreInstrumento);
        }
    }
    return retorno;
}

//*****************************************
//Baja valor unico
/** \brief Borra un elemento del array por ID
* \param array instrumento Array de instrumento
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int instrumento_baja(Instrumento array[], int sizeArray)                                      //cambiar instrumento
{
    int retorno=-1;
    int posicion;
    int id;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a cancelar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);          //cambiar si no se busca por ID
        if(instrumento_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            array[posicion].isEmpty=1;
            array[posicion].idInstrumento=0;                                                                   //cambiar campo id
            array[posicion].tipoInstrumento=0;                                                               //cambiar campo tipoInstrumento
            strcpy(array[posicion].nombreInstrumento,"");                                                   //cambiar campo nombreInstrumento
            retorno=0;
        }
    }
    return retorno;
}

//Baja valor repetido
/** \brief Borra todos los elemento del array que contengan el valor buscado
* \param array instrumento Array de instrumento
* \param size int Tamaño del array
* \param valorBuscado int Valor a buscar en el array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int instrumento_bajaValorRepetidoInt(Instrumento array[], int sizeArray, int valorBuscado) //cuando hay que dar de baja todas las posiciones en las que se encuentra ese int
{
    int retorno=-1;
    int i;
    if(array!=NULL && sizeArray>0)
    {
        for(i=0;i<sizeArray;i++)
        {
            if(array[i].idInstrumento==valorBuscado)                                                        //cambiar si no se busca por ID
            {
                array[i].isEmpty=1;
                array[i].idInstrumento=0;                                                                   //cambiar campo id
                array[i].tipoInstrumento=0;                                                               //cambiar campo tipoInstrumento
                strcpy(array[i].nombreInstrumento,"");                                                   //cambiar campo nombreInstrumento
            }
        }
        retorno=0;
    }
    return retorno;
}



//*****************************************
//Modificar
/** \brief Busca un elemento por ID y modifica sus campos
* \param array instrumento Array de instrumento
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int instrumento_modificar(Instrumento array[], int sizeArray)          ///cambiar instrumento
{
    int retorno=-1;
    int posicion;
    int id;                                                           ///cambiar si no se busca por ID
    char opcion;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a modificar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);   ///cambiar si no se busca por ID
        if(instrumento_buscarID(array,sizeArray,id,&posicion)==-1)                    ///cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                               ///cambiar si no se busca por ID
        }
        else
        {
            do
            {       //copiar printf de alta
                printf("\n Posicion: %d\n ID: %d\n tipoInstrumento: %d\n nombreInstrumento: %s",
                       posicion, array[posicion].idInstrumento,array[posicion].tipoInstrumento,array[posicion].nombreInstrumento);
                utn_getChar("\nModificar: A B  S(salir)","\nError",'A','Z',1,&opcion);
                switch(opcion)
                {
                    case 'A':
                        utn_getUnsignedInt("\n: ","\nError",1,sizeof(int),1,1,1,&array[posicion].tipoInstrumento);  ///mensaje + cambiar campo tipoInstrumento
                        break;
                    case 'B':
                        utn_getName("\n: ","\nError",1,sizeof(int),1,array[posicion].nombreInstrumento);     ///mensaje + cambiar campo nombreInstrumento
                        break;
                    case 'S':
                        break;
                    default:
                        printf("\nOpcion no valida");
                }
            }while(opcion!='S');
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Ordenar
/** \brief Ordena por campo XXXXX los elementos de un array
* \param array instrumento Array de instrumento
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*
*/
int instrumento_ordenarPorString(Instrumento array[],int size)                              ///cambiar instrumento
{
    int retorno=-1;
    int i, j;
    char bufferString[sizeof(int)];                               ///cambiar campo nombreInstrumento
    int bufferId;
    int bufferIsEmpty;

    int bufferInt;                                              ///cambiar buffer int

    if(array!=NULL && size>=0)
    {
        for (i = 1; i < size; i++)
        {
            strcpy(bufferString,array[i].nombreInstrumento);                      //cambiar campo nombreInstrumento
            bufferId=array[i].idInstrumento;                                   //cambiar campo id
            bufferIsEmpty=array[i].isEmpty;

            bufferInt=array[i].tipoInstrumento;                                //cambiar campo tipoInstrumento


            j = i - 1;
            while ((j >= 0) && strcmp(bufferString,array[j].nombreInstrumento)<0)         //cambiar campo nombreInstrumento                 //Si tiene mas de un criterio se lo agrego, Ej. bufferInt<array[j].tipoInstrumento
            {                                                                                                               //buffer < campo ascendente   buffer > campo descendente
                strcpy(array[j + 1].nombreInstrumento,array[j].nombreInstrumento);          //cambiar campo nombreInstrumento
                array[j + 1].idInstrumento=array[j].idInstrumento;                                //cambiar campo id
                array[j + 1].isEmpty=array[j].isEmpty;

                array[j + 1].tipoInstrumento=array[j].tipoInstrumento;                        //cambiar campo tipoInstrumento

                j--;
            }
            strcpy(array[j + 1].nombreInstrumento,bufferString);                     //cambiar campo nombreInstrumento
            array[j + 1].idInstrumento=bufferId;                                        //cambiar campo id
            array[j + 1].isEmpty=bufferIsEmpty;

            array[j + 1].tipoInstrumento=bufferInt;                                                        //cambiar campo tipoInstrumento
        }
        retorno=0;
    }
    return retorno;
}

//*****************************************
//Listar
/** \brief Lista los elementos de un array
* \param array instrumento Array de instrumento
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int instrumento_listar(Instrumento array[], int size)                      //cambiar instrumento
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else
                printf("\n ID: %d\n tipoInstrumento: %d\n nombreInstrumento: %s",
                       array[i].idInstrumento,array[i].tipoInstrumento,array[i].nombreInstrumento);      //cambiar todos
        }
        retorno=0;
    }
    return retorno;
}

