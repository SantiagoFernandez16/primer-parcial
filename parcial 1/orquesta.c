#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "musicos.h"
#include "orquesta.h"
#define SINFONICA 1
#define FILARMONICA 2
#define CAMARA 3


/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array orquesta Array of orquesta
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int orquesta_Inicializar(Orquesta array[], int size)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>0)
    {
        for(i=0;i<size;i++)
        {
            array[i].isEmpty=1;
        }
        retorno=0;
    }
    return retorno;
}

//*****************************************

/** \brief Busca el primer lugar vacio en un array
* \param array orquesta Array de orquesta
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int orquesta_buscarEmpty(Orquesta array[], int size, int* posicion)
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
* \param array orquesta Array de orquesta
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int orquesta_buscarID(Orquesta array[], int size, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idOrquesta==valorBuscado)
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
* \param array orquesta Array de orquesta
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int orquesta_buscarInt(Orquesta array[], int size, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].tipoOrquesta==valorBuscado)
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
* \param array orquesta Array de orquesta
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int orquesta_buscarString(Orquesta array[], int size, char* valorBuscado, int* indice)
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(strcmp(array[i].nombreOrquesta,valorBuscado)==0)
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
* \param array orquesta Array de orquesta
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int orquesta_alta(Orquesta array[], int size, int* contadorID)
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(orquesta_buscarEmpty(array,size,&posicion)==-1)
        {
            printf("\nNo hay lugares vacios\n");
        }
        else
        {
            (*contadorID)++;
            array[posicion].idOrquesta=*contadorID;
            array[posicion].isEmpty=0;
            utn_getUnsignedInt("\nIngrese tipo de Orquesta \n1-sinfonica\n2-filarmonica\n3-camara \n","\n Error\n",1,200,1,3,1,&array[posicion].tipoOrquesta);
            utn_getName("Ingrese la orquesta: ","\nError\n",1,200,1,array[posicion].nombreOrquesta);
            utn_getTexto("Ingrese el lugar de la orquesta: ","\nError\n",1,200,1,array[posicion].lugarOrquesta);
            printf("\n Posicion: %d\n ID: %d\n tipoOrquesta: %d\n nombreOrquesta: %s\n lugarOrquesta: %s",
                   posicion,array[posicion].idOrquesta,array[posicion].tipoOrquesta,array[posicion].nombreOrquesta,array[posicion].lugarOrquesta);
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Baja valor unico
/** \brief Borra un elemento del array por ID
* \param array orquesta Array de orquesta
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int orquesta_baja(Orquesta array[],int sizeArray, int *idCancelado)                                      //cambiar orquesta
{
    int retorno=-1;
    int posicion;
    int id;
    if(array!=NULL && sizeArray>0)
    {
        orquesta_listar(array,sizeArray);
        utn_getUnsignedInt("\nID a cancelar: ","\nError\n",1,200,1,20000,1,&id);          //cambiar si no se busca por ID
        if(orquesta_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
             array[posicion].isEmpty=1;
            *idCancelado = posicion;
            retorno=0;
        }
    }
    return retorno;
}


/** \brief Borra todos los elemento del array que contengan el valor buscado
* \param array orquesta Array de orquesta
* \param size int Tamaño del array
* \param valorBuscado int Valor a buscar en el array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int orquesta_bajaValorRepetidoInt(Orquesta array[], int sizeArray, int valorBuscado) //cuando hay que dar de baja todas las posiciones en las que se encuentra ese int
{
    int retorno=-1;
    int i;
    if(array!=NULL && sizeArray>0)
    {
        for(i=0;i<sizeArray;i++)
        {
            if(array[i].idOrquesta==valorBuscado)                                                        //cambiar si no se busca por ID
            {
                array[i].isEmpty=1;
                array[i].idOrquesta=0;                                                                   //cambiar campo id
                array[i].tipoOrquesta=0;                                                               //cambiar campo tipoOrquesta
                strcpy(array[i].nombreOrquesta,"");                                                   //cambiar campo nombreOrquesta
                strcpy(array[i].lugarOrquesta,"");                                               //cambiar campo lugarOrquesta
            }
        }
        retorno=0;
    }
    return retorno;
}



//*****************************************
//Modificar
/* \brief Busca un elemento por ID y modifica sus campos
* \param array orquesta Array de orquesta
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*
int orquesta_modificar(Orquesta array[], int sizeArray)          ///cambiar orquesta
{
    int retorno=-1;
    int posicion;
    int id;                                                           ///cambiar si no se busca por ID
    char opcion;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a modificar: ","\nError\n",1,200,1,sizeArray,1,&id);   ///cambiar si no se busca por ID
        if(orquesta_buscarID(array,sizeArray,id,&posicion)==-1)                    ///cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                               ///cambiar si no se busca por ID
        }
        else
        {
            do
            {
                printf("\n Posicion: %d\n ID: %d\n tipoOrquesta: %d\n nombreOrquesta: %s\n lugarOrquesta: %s\n",
                       posicion, array[posicion].idOrquesta,array[posicion].tipoOrquesta,array[posicion].nombreOrquesta,array[posicion].lugarOrquesta);
                utn_getChar("\nModificar: A B C  S(salir)","\nError\n",'A','Z',1,&opcion);
                switch(opcion)
                {
                    case 'A':
                        utn_getUnsignedInt("\n: ","\nError\n",1,200,1,1,1,&array[posicion].tipoOrquesta);
                        break;
                    case 'B':
                        utn_getName("\n: ","\nError\n",1,200,1,array[posicion].nombreOrquesta);
                        break;
                    case 'C':
                        utn_getTexto("\n: ","\nError\n",1,200,1,array[posicion].lugarOrquesta);
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



 \brief Ordena por campo XXXXX los elementos de un array
* \param array orquesta Array de orquesta
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*
*
int orquesta_ordenarPorString(Orquesta array[],int size)
{
    int retorno=-1;
    int i, j;
    char bufferString[sizeof(int)];
    int bufferId;
    int bufferIsEmpty;

    int bufferInt;
    char bufferLongString[sizeof(int)];

    if(array!=NULL && size>=0)
    {
        for (i = 1; i < size; i++)
        {
            strcpy(bufferString,array[i].nombreOrquesta);                      //cambiar campo nombreOrquesta
            bufferId=array[i].idOrquesta;                                   //cambiar campo id
            bufferIsEmpty=array[i].isEmpty;

            bufferInt=array[i].tipoOrquesta;                                //cambiar campo tipoOrquesta
            strcpy(bufferLongString,array[i].lugarOrquesta);          //cambiar campo lugarOrquesta


            j = i - 1;
            while ((j >= 0) && strcmp(bufferString,array[j].nombreOrquesta)<0)         //cambiar campo nombreOrquesta                 //Si tiene mas de un criterio se lo agrego, Ej. bufferInt<array[j].tipoOrquesta
            {                                                                                                               //buffer < campo ascendente   buffer > campo descendente
                strcpy(array[j + 1].nombreOrquesta,array[j].nombreOrquesta);          //cambiar campo nombreOrquesta
                array[j + 1].idOrquesta=array[j].idOrquesta;                                //cambiar campo id
                array[j + 1].isEmpty=array[j].isEmpty;

                array[j + 1].tipoOrquesta=array[j].tipoOrquesta;                        //cambiar campo tipoOrquesta
                strcpy(array[j + 1].lugarOrquesta,array[j].lugarOrquesta);  //cambiar campo lugarOrquesta

                j--;
            }
            strcpy(array[j + 1].nombreOrquesta,bufferString);                     //cambiar campo nombreOrquesta
            array[j + 1].idOrquesta=bufferId;                                        //cambiar campo id
            array[j + 1].isEmpty=bufferIsEmpty;

            array[j + 1].tipoOrquesta=bufferInt;                                                        //cambiar campo tipoOrquesta
            strcpy(array[j + 1].lugarOrquesta,bufferLongString);                                  //cambiar campo lugarOrquesta
        }
        retorno=0;
    }
    return retorno;
}

//Listar

*\brief Lista los elementos de un array
*\param array orquesta Array de orquesta
*\param size int Tamaño del array
*\return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int orquesta_listar(Orquesta array[], int size)
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
                printf("\n\n Posicion: %d\n ID: %d\n nombre: %s\n lugar: %s",
                                       i, array[i].idOrquesta,
                                       array[i].nombreOrquesta,
                                       array[i].lugarOrquesta);
                                       orquesta_mostrarTipo(array[i].tipoOrquesta);      //cambiar todos
        }
        retorno=0;
    }
    return retorno;
}
/** \brief Muestra el tipo de orquesta en forma de texto por pantalla.
* \param tipoOrquesta int tipo de orquesta
* \return int Return (0)
*
*/
int orquesta_mostrarTipo(int tipoOrquesta)
{
    printf("\n");
    switch (tipoOrquesta)
    {
        case SINFONICA:
            printf(" Tipo :Sinfonica");
            break;
        case FILARMONICA:
            printf(" Tipo :Filarmonica");
            break;
        case CAMARA:
            printf(" Tipo :Camara");
            break;
    }
    return 0;
}
