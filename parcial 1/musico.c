#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "musicos.h"
#include "orquesta.h"
#include "intrumentos.h"



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
* \param size int Tama�o del array
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
* \param size int Tama�o del array
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
* \param size int Tama�o del array
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
* \param size int Tama�o del array
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
* \param size int Tama�o del array
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
            utn_getUnsignedInt("\nIngrese edad: ","\nError",1,200,1,200,5,&array[posicion].edadMusico);
            orquesta_listar(arrayOrquesta,sizeOrquesta);
            utn_getUnsignedInt("\nIngrese ID de orquesta: ","\nError",1,200,0,30000,1,&auxOrquesta);
            retorno=0;
        }
         if (orquesta_buscarID(arrayOrquesta,sizeOrquesta,auxOrquesta,&auxPosIdOrquesta)==-1)
            {
                printf("\nID incorrecto.");
            }
            else
            {
                array[posicion].idOrquesta = auxOrquesta;

            utn_getUnsignedInt("\nIngrese tipo: \n1-Cuerdas\n2-viento-madera\n3-Viento-metal\n4-percusion\n ","\nError",1,200,1,4,1,&array[posicion].idMusico);
            utn_getName("Ingrese nombre\n: ","\nError",1,200,1,array[posicion].nombreMusico);
            utn_getName("Ingrese apellido\n: ","\nError",1,200,1,array[posicion].apellidoMusico);
            printf("\n ID: %d\n edad: %d\n IdOrquesta: %d\n IdInstrumento: %d\n nombre: %s\n apellido: %s",
                   posicion, array[posicion].idMusico,
                   array[posicion].edadMusico,
                   array[posicion].idOrquesta,
                   array[posicion].nombreMusico,
                   array[posicion].apellidoMusico);
            }
    }
    return retorno;


}

//*****************************************
//Baja valor unico
/** \brief Borra un elemento del array por ID
* \param array musico Array de musico
* \param size int Tama�o del array
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
        utn_getUnsignedInt("\nID a cancelar: ","\nError",1,200,1,sizeArray,1,&id);          //cambiar si no se busca por ID
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
* \param size int Tama�o del array
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
* \param size int Tama�o del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int musico_modificar(Musico array[], int sizeArray,Orquesta arrayOrquesta[],int sizeOrquesta)         ///cambiar musico
{
    int retorno=-1;
    int posicion;
    int id;                                                           ///cambiar si no se busca por ID
    char opcion;
    int aux;
    int auxIdOrquesta;
    if(array!=NULL && sizeArray>0)
    {
        musico_listar(array,sizeArray);
        utn_getUnsignedInt("\nID a modificar: ","\nError\n",1,200,1,200000,1,&id);               ///cambiar si no se busca por ID
        if(musico_buscarID(array,sizeArray,id,&posicion)==-1)                                       ///cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                         ///cambiar si no se busca por ID
        }
        else
        {
            do
            {       //copiar printf de alta
                printf("\n Posicion: %d\n ID: %d\n edadMusico: %d\n nombreMusico: %s\n apellidoMusico: %s\n idOrquesta %d\n idInstrumento %d\n",
                       posicion, array[posicion].idMusico,array[posicion].edadMusico,array[posicion].nombreMusico,array[posicion].apellidoMusico,array[posicion].idOrquesta,array[posicion].idInstrumento);
                utn_getChar("\nModificar: \nA) Edad \nB) \nS(salir)","\nError\n",'A','Z',1,&opcion);
                switch(opcion)
                {
                    case 'A':
                        utn_getUnsignedInt("\n: ","\nError",1,200,1,1,1,&array[posicion].edadMusico);                               ///mensaje + cambiar campo edadMusico
                        break;
                    case 'B':
                        orquesta_listar(arrayOrquesta,sizeOrquesta);
                        utn_getUnsignedInt("\nIngrese ID de orquesta: ","\nError",1,200,0,30000,1,&auxIdOrquesta);
                        if (orquesta_buscarID(arrayOrquesta,sizeOrquesta,auxIdOrquesta,&aux)==-1)
                        {
                            printf("\nNo existe este ID de orquesta");
                        }
                        else
                        {
                            array[posicion].idOrquesta = auxIdOrquesta;
                        }
                        break;
                    case 'S':
                        break;
                    default:
                        printf("\nOpcion no valida");
                }
            }while(opcion!='S');
            retorno=0;
        }
        return retorno;
    }
    return retorno;
}

//***************************************
//Ordenar
/**
* \brief Ordena por campo XXXXX los elementos de un array
* \param array musico Array de musico
* \param size int Tama�o del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*
*/
int musico_ordenarPorString(Musico array[],int size)
{
    int i, j;
    char bufferStringNombreMusico[20000];
    int bufferIdMusico;
    int bufferIsEmpty;
    int retorno=-1;

    int bufferEdadMusico;
    char bufferApellidoMusico[20000];
    if(array!=NULL && size>=0)
    {
        for (i = 1; i < size; i++)
        {
            strcpy(bufferStringNombreMusico,array[i].nombreMusico);                      //cambiar campo nombreMusico
            bufferIdMusico=array[i].idMusico;                                   //cambiar campo id
            bufferIsEmpty=array[i].isEmpty;

            bufferEdadMusico=array[i].edadMusico;                                //cambiar campo edadMusico
            strcpy(bufferApellidoMusico,array[i].apellidoMusico);          //cambiar campo apellidoMusico


            j = i - 1;
            while ((j >= 0) && strcmp(bufferStringNombreMusico,array[j].nombreMusico)<0)         //cambiar campo nombreMusico                 //Si tiene mas de un criterio se lo agrego, Ej. bufferEdadMusico<array[j].edadMusico
            {                                                                                                               //buffer < campo ascendente   buffer > campo descendente
                strcpy(array[j + 1].nombreMusico,array[j].nombreMusico);          //cambiar campo nombreMusico
                array[j + 1].idMusico=array[j].idMusico;                                //cambiar campo id
                array[j + 1].isEmpty=array[j].isEmpty;

                array[j + 1].edadMusico=array[j].edadMusico;                        //cambiar campo edadMusico
                strcpy(array[j + 1].apellidoMusico,array[j].apellidoMusico);  //cambiar campo apellidoMusico

                j--;
            }
            strcpy(array[j + 1].nombreMusico,bufferStringNombreMusico);                     //cambiar campo nombreMusico
            array[j + 1].idMusico=bufferIdMusico;                                        //cambiar campo id
            array[j + 1].isEmpty=bufferIsEmpty;

            array[j + 1].edadMusico=bufferEdadMusico;                                                        //cambiar campo edadMusico
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
* \param size int Tama�o del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int musico_listar(Musico array[], int size)
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
                printf("\n ID: %d\n edad: %d\n Orquesta %d\n Instrumento %d\n nombre: %s\n apellido: %s",
                       array[i].idMusico,
                       array[i].edadMusico,
                       array[i].idOrquesta,
                       array[i].idInstrumento,
                       array[i].nombreMusico,
                       array[i].apellidoMusico);
        }
        retorno=0;
    }
    return retorno;
}

int musico_cantidadMusicos(Musico array[], int size)
{
    int i;
    int cantidadMusicos=0;
    for (i=0;i<size;i++)
    {
        if (!array[i].isEmpty)
        {
            cantidadMusicos++;
        }
    }
    return cantidadMusicos;
}

