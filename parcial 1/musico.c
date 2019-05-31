#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "orquesta.h"
#include "musicos.h"


/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array musico Array of musico
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int musico_Inicializar(Musico array[], int size)                                    //cambiar musico
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
* \param array musico Array de musico
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int musico_buscarEmpty(Musico array[], int size, int* posicion)                    //cambiar musico
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
* \param array musico Array de musico
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int musico_buscarID(Musico array[], int size, int valorBuscado, int* posicion)                    //cambiar musico
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idMusico==valorBuscado)                                                   //cambiar campo ID
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
* \param array musico Array de musico
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int musico_buscarInt(Musico array[], int size, int valorBuscado, int* posicion)                    //cambiar musico
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].edadMusico==valorBuscado)                                                   //cambiar campo edadMusico
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
* \param array musico Array de musico
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int musico_buscarString(Musico array[], int size, char* valorBuscado, int* indice)                    //cambiar musico
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(strcmp(array[i].nombreMusico,valorBuscado)==0)                                        //cambiar campo nombreMusico
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
* \param array musico Array de musico
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int musico_alta(Musico array[], int size, int* contadorID,Orquesta arrayOrquesta[], int sizeOrquesta)
{
    int retorno=-1;
    int posicion;

    int auxOrquesta;
    int auxPosIdOrquesta;

    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(musico_buscarEmpty(array,size,&posicion)==-1)                          //cambiar musico
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
             (*contadorID)++;
            array[posicion].idMusico=*contadorID;
            array[posicion].isEmpty=0;
            utn_getUnsignedInt("\nIngrese edad: ","\nError",1,sizeof(int),1,200,5,&array[posicion].edadMusico);
            orquesta_listar(arrayOrquesta,sizeOrquesta);
            utn_getUnsignedInt("\nIngrese ID de orquesta: ","\nError",1,sizeof(int),0,30000,1,&auxOrquesta);
            retorno=0;
        }
         if (orquesta_buscarID(arrayOrquesta,sizeOrquesta,auxOrquesta,&auxPosIdOrquesta)==-1)
            {
                printf("\nID incorrecto.");
            }
            else
            {
                array[posicion].idOrquesta = auxOrquesta;

            utn_getUnsignedInt("\nIngrese tipo: \n1-Cuerdas\n2-viento-madera\n3-Viento-metal\n4-percusion\n ","\nError",1,sizeof(int),1,4,1,&array[posicion].idMusico);
            utn_getName("Ingrese nombre\n: ","\nError",1,sizeof(int),1,array[posicion].nombreMusico);
            utn_getName("Ingrese apellido\n: ","\nError",1,sizeof(int),1,array[posicion].apellidoMusico);
            printf("\n Posicion: %d\n ID: %d\n edad: %d\n IdOrquesta: %d\n IdInstrumento: %d\n nombre: %s\n apellido: %s",
                   posicion, array[posicion].idOrquesta,
                   array[posicion].edadMusico,
                   array[posicion].idMusico,
                   array[posicion].nombreMusico,
                   array[posicion].apellidoMusico);
    }
    return retorno;


}

//*****************************************
//Baja valor unico
/** \brief Borra un elemento del array por ID
* \param array musico Array de musico
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int musico_baja(Musico array[], int sizeArray)                                      //cambiar musico
{
    int retorno=-1;
    int posicion;
    int id;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a cancelar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);          //cambiar si no se busca por ID
        if(musico_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            array[posicion].isEmpty=1;
            array[posicion].idMusico=0;                                                                   //cambiar campo id
            array[posicion].edadMusico=0;                                                               //cambiar campo edadMusico
            strcpy(array[posicion].nombreMusico,"");                                                   //cambiar campo nombreMusico
            strcpy(array[posicion].apellidoMusico,"");                                               //cambiar campo apellidoMusico
            retorno=0;
        }
    }
    return retorno;
}

//Baja valor repetido
/** \brief Borra todos los elemento del array que contengan el valor buscado
* \param array musico Array de musico
* \param size int Tamaño del array
* \param valorBuscado int Valor a buscar en el array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int musico_bajaValorRepetidoInt(Musico array[], int sizeArray, int valorBuscado) //cuando hay que dar de baja todas las posiciones en las que se encuentra ese int
{
    int retorno=-1;
    int i;
    if(array!=NULL && sizeArray>0)
    {
        for(i=0;i<sizeArray;i++)
        {
            if(array[i].idMusico==valorBuscado)                                                        //cambiar si no se busca por ID
            {
                array[i].isEmpty=1;
                array[i].idMusico=0;                                                                   //cambiar campo id
                array[i].edadMusico=0;                                                               //cambiar campo edadMusico
                strcpy(array[i].nombreMusico,"");                                                   //cambiar campo nombreMusico
                strcpy(array[i].apellidoMusico,"");                                               //cambiar campo apellidoMusico
            }
        }
        retorno=0;
    }
    return retorno;
}



//*****************************************
//Modificar
/** \brief Busca un elemento por ID y modifica sus campos
* \param array musico Array de musico
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int musico_modificar(Musico array[], int sizeArray)          ///cambiar musico
{
    int retorno=-1;
    int posicion;
    int id;                                                           ///cambiar si no se busca por ID
    char opcion;
    if(array!=NULL && sizeArray>0)
    {
        musico_listar(array,sizeArray);
        utn_getUnsignedInt("\nID a modificar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);   ///cambiar si no se busca por ID
        if(musico_buscarID(array,sizeArray,id,&posicion)==-1)                    ///cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                               ///cambiar si no se busca por ID
        }
        else
        {
            do
            {       //copiar printf de alta
                printf("\n Posicion: %d\n ID: %d\n edadMusico: %d\n nombreMusico: %s\n apellidoMusico: %s",
                       posicion, array[posicion].idMusico,array[posicion].edadMusico,array[posicion].nombreMusico,array[posicion].apellidoMusico);
                utn_getChar("\nModificar: A B C  S(salir)","\nError",'A','Z',1,&opcion);
                switch(opcion)
                {
                    case 'A':
                        utn_getUnsignedInt("\n: ","\nError",1,sizeof(int),1,1,1,&array[posicion].edadMusico);  ///mensaje + cambiar campo edadMusico
                        break;
                    case 'B':
                        utn_getName("\n: ","\nError",1,sizeof(int),1,array[posicion].nombreMusico);     ///mensaje + cambiar campo nombreMusico
                        break;
                    case 'C':
                        utn_getTexto("\n: ","\nError",1,sizeof(int),1,array[posicion].apellidoMusico);    ///mensaje + cambiar campo apellidoMusico
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

//***************************************
//Ordenar
/**
* \brief Ordena por campo XXXXX los elementos de un array
* \param array musico Array de musico
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*
*/
int musico_ordenarPorString(Musico array[],int size)
{
    int i, j;
    char bufferString[sizeof(int)];
    int bufferId;
    int bufferIsEmpty;
    int retorno=-1;

    int bufferInt;
    char bufferApellidoMusico[sizeof(int)];
    if(array!=NULL && size>=0)
    {
        for (i = 1; i < size; i++)
        {
            strcpy(bufferString,array[i].nombreMusico);                      //cambiar campo nombreMusico
            bufferId=array[i].idMusico;                                   //cambiar campo id
            bufferIsEmpty=array[i].isEmpty;

            bufferInt=array[i].edadMusico;                                //cambiar campo edadMusico
            strcpy(bufferApellidoMusico,array[i].apellidoMusico);          //cambiar campo apellidoMusico


            j = i - 1;
            while ((j >= 0) && strcmp(bufferString,array[j].nombreMusico)<0)         //cambiar campo nombreMusico                 //Si tiene mas de un criterio se lo agrego, Ej. bufferInt<array[j].edadMusico
            {                                                                                                               //buffer < campo ascendente   buffer > campo descendente
                strcpy(array[j + 1].nombreMusico,array[j].nombreMusico);          //cambiar campo nombreMusico
                array[j + 1].idMusico=array[j].idMusico;                                //cambiar campo id
                array[j + 1].isEmpty=array[j].isEmpty;

                array[j + 1].edadMusico=array[j].edadMusico;                        //cambiar campo edadMusico
                strcpy(array[j + 1].apellidoMusico,array[j].apellidoMusico);  //cambiar campo apellidoMusico

                j--;
            }
            strcpy(array[j + 1].nombreMusico,bufferString);                     //cambiar campo nombreMusico
            array[j + 1].idMusico=bufferId;                                        //cambiar campo id
            array[j + 1].isEmpty=bufferIsEmpty;

            array[j + 1].edadMusico=bufferInt;                                                        //cambiar campo edadMusico
            strcpy(array[j + 1].apellidoMusico,bufferApellidoMusico);                                  //cambiar campo apellidoMusico
        }
        retorno=0;
    }
    return retorno;
}

//****************************************
//Listar
/** \brief Lista los elementos de un array
* \param array musico Array de musico
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
/*int musico_listar(Musico array[], int size)
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
                printf("\n Posicion: %d\n ID: %d\n edad: %d\n IdOrquesta: %d\n IdInstrumento: %d\n nombre: %s\n apellido: %s",
                       i, array[i].idMusico,
                       array[i].edadMusico,
                       array[i].IdOrquesta,
                       array[i].IdInstrumento,
                       array[i].nombre,array[i].apellidoMusico);
        }
        retorno=0;
    }
    return retorno;
}*/


