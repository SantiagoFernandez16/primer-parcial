#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "intrumentos.h"
#include "musicos.h"
#include "orquesta.h"
//#include <stdio_ext.h>


int informe_mostrarOrquestaMasCincoMusicos(Orquesta *arrayOrquesta, int sizeOrquesta, Musico *arrayMusicos, int sizeMusico)
{
    int retorno =-1;
    int i;
    int j;
    int contador=0;
    if (arrayOrquesta!=NULL && arrayMusicos!=NULL && sizeMusico>0 && sizeOrquesta>0)
    {
        printf("\n");
        for(i=0;i<sizeOrquesta;i++)
        {
            if(!arrayOrquesta[i].isEmpty)
            {
                contador=0;
                for(j=0;j<sizeMusico;j++)
                {
                    if (!arrayMusicos[j].isEmpty && arrayOrquesta[i].idOrquesta==arrayMusicos[j].idOrquesta)
                    {
                        contador++;
                    }
                }
                if (contador>=5)
                {
                    printf("\n");
                    printf("\n Id orquesta tiene mas de 5 music: %d",arrayOrquesta[i].idOrquesta);
                    printf("\n nombre orquesta: %s",arrayOrquesta[i].nombreOrquesta);
                    printf("\n lugar orquesta: %s",arrayOrquesta[i].lugarOrquesta);
                    orquesta_mostrarTipo(arrayOrquesta[i].tipoOrquesta);

                }
            }
        }
        retorno=0;
    }
    return retorno;
}

int informe_mostrarMusicoMastreintaAno(Musico *arrayMusicos, int sizeMusico,
                                        Orquesta *arrayOrquesta, int sizeOrquesta,
                                        Instrumento *arrayInstrumento, int sizeInstrumento)
{
    int retorno =-1;
    int i;
    int j;
    int k;
    if (arrayOrquesta!=NULL && arrayMusicos!=NULL && sizeMusico>0 && sizeOrquesta>0 && sizeInstrumento>0 && arrayInstrumento!=NULL)
    {
        printf("\n");
        for(i=0;i<sizeMusico;i++)
        {
            if (!arrayMusicos[i].isEmpty && arrayMusicos[i].edadMusico>30)
            {
                printf("\n");
                printf("\n id Musico mas de 30: %d",arrayMusicos[i].idMusico);
                printf("\n nombre Musico mas de 30: %s",arrayMusicos[i].nombreMusico);
                printf("\n apellido Musico mas de 30: %s",arrayMusicos[i].apellidoMusico);
                printf("\n edad Musico mas de 30: %d",arrayMusicos[i].edadMusico);
                orquesta_buscarID(arrayOrquesta,sizeOrquesta,arrayMusicos[i].idOrquesta,&j);
                printf("\n orquesta Musico mas de 30: %s",arrayOrquesta[j].nombreOrquesta);
                instrumento_buscarID(arrayInstrumento,sizeInstrumento,arrayMusicos[i].idInstrumento,&k);
                printf("\n instrumento Musico mas de 30: %s",arrayInstrumento[k].nombreInstrumento);
            }
        }
        retorno=0;
    }
    return retorno;
}

int informe_imprimirPorLugar(Orquesta *arrayOrquesta, int sizeOrquesta)
{
    int retorno =-1;
    int i;
    char auxLugar[20];
    if (arrayOrquesta!=NULL && sizeOrquesta>0)
    {
        printf("\n");
        utn_getTexto("\nIngrese el lugar de la orquesta a buscar: ","\nError",1,20,1,auxLugar);

        for(i=0;i<sizeOrquesta;i++)
        {
            if(!arrayOrquesta[i].isEmpty && strncmp(arrayOrquesta[i].lugarOrquesta,auxLugar,sizeof(arrayOrquesta[i].lugarOrquesta))==0)
            {
                printf("\n");
                printf("\n Id orquesta: %d",arrayOrquesta[i].idOrquesta);
                printf("\n nombre orquesta: %s",arrayOrquesta[i].nombreOrquesta);
                printf("\n lugar orquesta: %s",arrayOrquesta[i].lugarOrquesta);
                orquesta_mostrarTipo(arrayOrquesta[i].tipoOrquesta);
            }
        }
        retorno =0;
    }
    return retorno;
}

int informe_mostrarOrquestaCompleta(Orquesta *arrayOrquesta, int sizeOrquesta,
                                    Musico *arrayMusicos, int sizeMusico,
                                    Instrumento *arrayInstrumento, int sizeInstrumento)
{
    int retorno =-1;
    int i;
    int j;
    int posicionInstrumento;
    int cantCuerdas;
    int cantViento;
    int cantPercusion;
    if (arrayOrquesta!=NULL && arrayMusicos!=NULL && sizeMusico>0 && sizeOrquesta>0 && sizeInstrumento>0 && arrayInstrumento!=NULL)
    {
        printf("\n");
        for (i=0;i<sizeOrquesta;i++)
        {
            if(!arrayOrquesta[i].isEmpty)
            {
                cantCuerdas=0;
                cantViento=0;
                cantPercusion=0;
                for(j=0;j<sizeMusico;j++)
                {
                    if (!arrayMusicos[j].isEmpty && arrayOrquesta[i].idOrquesta==arrayMusicos[j].idOrquesta)
                    {
                        instrumento_buscarID(arrayInstrumento,sizeInstrumento,arrayMusicos[j].idInstrumento,&posicionInstrumento);
                        switch(arrayInstrumento[posicionInstrumento].tipoInstrumento)
                        {
                            case CUERDAS:
                                cantCuerdas++;
                                break;
                            case VIENTO_MADERA:
                                cantViento++;
                                break;
                            case VIENTO_METAL:
                                cantViento++;
                                break;
                            case PERCUSION:
                                cantPercusion++;
                                break;
                        }
                    }
                }
                if (cantCuerdas>=5 && cantViento>=3 && cantPercusion>=2)
                {
                    printf("\n ID orquesta completa: %d",arrayOrquesta[i].idOrquesta);
                }
            }
        }
        retorno =0;
    }
    return retorno;
}

int informe_orquestaMasMusicos(Orquesta *arrayOrquesta, int sizeOrquesta,
                                    Musico *arrayMusicos, int sizeMusico)
{
    int retorno =-1;
    int i;
    int j;
    int cantMaxMusicos;
    int cantMusicos;
    int flag=0;
    if (arrayOrquesta!=NULL && arrayMusicos!=NULL && sizeMusico>0 && sizeOrquesta>0)
    {
        for (i=0;i<sizeOrquesta;i++)
        {
            cantMusicos=0;
            if(!arrayOrquesta[i].isEmpty)
            {
                for (j=0;j<sizeMusico;j++)
                {
                    if (!arrayMusicos[j].isEmpty && arrayMusicos[j].idOrquesta==arrayOrquesta[i].idOrquesta)
                    {
                        cantMusicos++;
                    }
                }
                arrayOrquesta[i].cantidadMusicos=cantMusicos;
                if (flag==0 || cantMaxMusicos<cantMusicos)
                {
                    cantMaxMusicos=cantMusicos;
                    flag=1;
                }
            }
        }
        for(i=0;i<sizeOrquesta;i++)
        {
            if(!arrayOrquesta[i].isEmpty && arrayOrquesta[i].cantidadMusicos==cantMaxMusicos)
            {
                printf("\n");
                printf("\n Id orquesta mas Musicos: %d",arrayOrquesta[i].idOrquesta);
                printf("\n nombre orquesta: %s",arrayOrquesta[i].nombreOrquesta);
                printf("\n lugar orquesta: %s",arrayOrquesta[i].lugarOrquesta);
                printf("\n Cantidad de musicos: %d",arrayOrquesta[i].cantidadMusicos);
                orquesta_mostrarTipo(arrayOrquesta[i].tipoOrquesta);
            }
        }
        retorno=0;
    }
    return retorno;
}

int informe_musicosDeCuerdas(Musico *arrayMusico, int sizeMusico,
                             Instrumento *arrayInstrumento, int sizeInstrumento)
{
    int retorno=-1;
    int i;
    int auxIdInstrumento;
    if (arrayMusico!=NULL && sizeMusico>0 && sizeInstrumento>0 && arrayInstrumento!=NULL)
    {
        printf("\n");
        musico_ordenarPorString(arrayMusico,sizeMusico);
        for (i=0;i<sizeMusico;i++)
        {
            if(!arrayMusico[i].isEmpty)
            {
                instrumento_buscarID(arrayInstrumento,sizeInstrumento,arrayMusico[i].idInstrumento,&auxIdInstrumento);
                if (arrayInstrumento[auxIdInstrumento].tipoInstrumento==CUERDAS)
                {
                    printf("\n");
                    printf("\nToca cuerdas :");
                    printf("\n Nombre: %s",arrayMusico[i].nombreMusico);
                    printf("\n Apellido: %s",arrayMusico[i].apellidoMusico);
                    printf("\n Edad: %d",arrayMusico[i].edadMusico);
                    printf("\n Nombre instrumento: %s",arrayInstrumento[auxIdInstrumento].nombreInstrumento);
                }
            }
        }
        retorno=0;
    }
    return retorno;
}

int informe_promedioMusicosPorOrquesta(Orquesta *arrayOrquesta,int sizeOrquesta,
                                       Musico *arrayMusico,int sizeMusico)
{
    int retorno=-1;
    int cantidadMusicos;
    int cantidadDeOrquestas;
    if (arrayOrquesta!=NULL && arrayMusico!=NULL && sizeMusico>0 && sizeOrquesta>0)
    {
        printf("\n");
        cantidadMusicos=musico_cantidadMusicos(arrayMusico,sizeMusico);
        cantidadDeOrquestas=orquesta_cantidadDeOrquestas(arrayOrquesta,sizeOrquesta);
        if (cantidadDeOrquestas==0)
        {
            printf("\nNo hay orquestas.");
            retorno=-1;
        }
        else
        {
           printf("\n El promedio de musicos por orquesta es %.2f", (float)cantidadMusicos/cantidadDeOrquestas);
           retorno=0;
        }

    }
    return retorno;
}

int informe_mostarMusicoPorUnaOrquesta(Orquesta *arrayOrquesta,int sizeOrquesta,
                                       Musico *arrayMusico,int sizeMusico,
                                       Instrumento *arrayInstrumento, int sizeInstrumento)
{
    int retorno=-1;
    int i;
    int auxIdOrquesta;
    int posicionOrquesta;
    int auxIdInstrumento;
    if (arrayOrquesta!=NULL && arrayMusico!=NULL && sizeMusico>0 && sizeOrquesta>0 && sizeInstrumento>0 && arrayInstrumento!=NULL)
    {
        orquesta_listar(arrayOrquesta,sizeOrquesta);
        utn_getUnsignedInt("\nIngrese el ID de la orquesta: ","idIncorrecto",1,sizeof(int),0,30000,1,&auxIdOrquesta);
        if(orquesta_buscarID(arrayOrquesta,sizeOrquesta,auxIdOrquesta,&posicionOrquesta)==0)
        {
            for (i=0;i<sizeMusico;i++)
            {
                if (!arrayMusico[i].isEmpty && arrayMusico[i].idOrquesta==auxIdOrquesta)
                {
                instrumento_buscarID(arrayInstrumento,sizeInstrumento,arrayMusico[i].idInstrumento,&auxIdInstrumento);
                printf("\n");
                printf("\n Nombre : %s",arrayMusico[i].nombreMusico);
                printf("\n Apellido: %s",arrayMusico[i].apellidoMusico);
                printf("\n Edad: %d",arrayMusico[i].edadMusico);
                printf("\n Nombre instrumento: %s",arrayInstrumento[auxIdInstrumento].nombreInstrumento);
                instrumento_mostrarTipo(arrayInstrumento[auxIdInstrumento].tipoInstrumento);
                }
            }
        }
        else
        {
            printf("\n Orquesta no encontrada.");
        }
    }
    return retorno;
}
