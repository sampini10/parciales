/*
 * Informes.c
 *
 *  Created on: 9 may. 2020
 *      Author: sampini
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Cliente.h"
#include "Publicaciones.h"
#include "Informes.h"
#include "utn.h"


int info_calcularActivosMayor(Cliente* arrayClientes,int limitesClientes,Publicacion* arrayPublicaciones,int limitePublicaciones)
{
	int retorno = -1;
	int i;
	int auxiliarActivo = 0;
	int activoMaximo;
	int indiceClienteMaximo;
	int flag = 0;


	for(i=0;i<limitesClientes;i++)
		{
         if(arrayClientes[i].isEmpty == 0)
         {

         auxiliarActivo = info_cantidadPublicacionesActivas(arrayPublicaciones,limitePublicaciones,arrayClientes[i].id);

			if(flag == 0 || (auxiliarActivo > activoMaximo))
			{
                flag = 1;
				activoMaximo = auxiliarActivo;
				indiceClienteMaximo = i;
			}
          }

         retorno = 0;
		}
	 if(activoMaximo == 0)
	      {
	    	  printf("\nNO SE ENCONTRO PUBLICACIONES ACTIVAS\n");
	      }
	 else
	 {
		printf("\nCliente con mas publicaciones activas: ID: %d | Cantidad:  %d  \n",arrayClientes[indiceClienteMaximo].id,activoMaximo);
	 }
		return retorno;
}
int info_calcularPausadoMayor(Cliente* arrayClientes,int limitesClientes,Publicacion* arrayPublicaciones,int limitePublicaciones)
{
	int retorno = -1;
	int i;
	int auxiliarPausado = 0;
	int pausadoMaximo;
	int indiceClientePausado;
	int flag = 0;


	for(i=0;i<limitesClientes;i++)
		{
         if(arrayClientes[i].isEmpty == 0)
         {

         auxiliarPausado = info_cantidadPublicacionesPausadas(arrayPublicaciones,limitePublicaciones,arrayClientes[i].id);

			if(flag == 0 || (auxiliarPausado > pausadoMaximo))
			{
                flag = 1;
				pausadoMaximo = auxiliarPausado;
				indiceClientePausado = i;
			}
          }

         retorno = 0;
		}
      if(pausadoMaximo == 0)
      {
    	  printf("\nNO SE ENCONTRO PUBLICACIONES PAUSADAS\n");
      }
      else
    	  {
    	  printf("\nCliente con mas publicaciones pausadas: ID: %d | Cantidad:  %d  \n",arrayClientes[indiceClientePausado].id,pausadoMaximo);
    	  }
		return retorno;
}
int info_calcularMayorPublicaciones(Cliente* arrayClientes,int limitesClientes,Publicacion* arrayPublicaciones,int limitePublicaciones)
{
	int retorno = -1;
	int i;
	int auxiliarMaximo = 0;
	int maximoPublicaciones;
	int indiceClienteMaxPub;
	int flag = 0;


	for(i=0;i<limitesClientes;i++)
		{
         if(arrayClientes[i].isEmpty == 0)
         {

         auxiliarMaximo = info_cantidadPublicaciones(arrayPublicaciones,limitePublicaciones,arrayClientes[i].id);

			if(flag == 0 || (auxiliarMaximo > maximoPublicaciones))
			{
                flag = 1;
				maximoPublicaciones = auxiliarMaximo;
				indiceClienteMaxPub = i;
			}
          }

         retorno = 0;
		}
	 if(maximoPublicaciones == 0)
	      {
	    	  printf("\nNO SE ENCONTRO PUBLICACIONES \n");
	      }
	 else
	 {
		printf("\nCliente con mas publicaciones: ID: %d | Cantidad:  %d  \n",arrayClientes[indiceClienteMaxPub].id,maximoPublicaciones);
	 }
		return retorno;
}

int info_cantidadPublicacionesActivas(Publicacion* arrayPublicacion, int limitePublicaciones,int idCliente)
{

	int contador = 0;
	int i;


	for(i=0;i<limitePublicaciones;i++)
	{
		if(arrayPublicacion[i].idCliente == idCliente && arrayPublicacion[i].isEmpty == 0 && arrayPublicacion[i].estado == 0)
		{
			contador++;
		}
	}
	return contador;
}
int info_cantidadPublicacionesPausadas(Publicacion* arrayPublicacion, int limitePublicaciones,int idCliente)
{

	int contador = 0;
	int i;


	for(i=0;i<limitePublicaciones;i++)
	{
		if(arrayPublicacion[i].idCliente == idCliente && arrayPublicacion[i].isEmpty == 0 && arrayPublicacion[i].estado == 1)
		{
			contador++;
		}
	}
	return contador;
}
int info_cantidadPublicaciones(Publicacion* arrayPublicacion, int limitePublicaciones,int idCliente)
{

	int contador = 0;
	int i;


	for(i=0;i<limitePublicaciones;i++)
	{
		if(arrayPublicacion[i].idCliente == idCliente && arrayPublicacion[i].isEmpty == 0)
		{
			contador++;
		}
	}
	return contador;
}
/* ACA FUNCIONES DE INFORMES DE PUBLICACIONES
 * ***/

int info_listaRubro(Publicacion* arrayPublicaciones,int limitePublicaciones,int auxiliar)
{
	int retorno = -1;
    int listaRubro[limitePublicaciones];
	int i;
	int j;
    int flagExisteRubro;
	int indiceRubroLibre = 0;
    int auxiliarMayor;

	for(i=0;i<limitePublicaciones;i++)
		{
			flagExisteRubro = 0;
			if(arrayPublicaciones[i].isEmpty == 0)
			{
				for(j=0;j<indiceRubroLibre;j++)
				{
					if(arrayPublicaciones[i].rubro == listaRubro[j])
					{
						flagExisteRubro = 1;
						break;
					}
				}
				if(flagExisteRubro == 0)
				{
					listaRubro[indiceRubroLibre] = arrayPublicaciones[i].rubro;
					indiceRubroLibre++;
				}
			}
		}

	for(j=0;j<indiceRubroLibre;j++)
	{
	   if(listaRubro[j] == auxiliar)
	   {
		   auxiliarMayor = info_cantidadPublicacionesActivasConRubro(arrayPublicaciones,limitePublicaciones,listaRubro[j]);
		   printf("\nRubro: %d | Cantidad de publicaciones activas: %d\n",listaRubro[j],auxiliarMayor);
	   }


	}

return retorno;
}
int info_cantidadPublicacionesActivasConRubro(Publicacion* arrayPublicacion, int limitePublicaciones,int rubro)
{

	int contador = 0;
	int i;


	for(i=0;i<limitePublicaciones;i++)
	{
		if(arrayPublicacion[i].rubro == rubro && arrayPublicacion[i].isEmpty == 0 && arrayPublicacion[i].estado == 0)
		{
			contador++;
		}
	}
	return contador;
}
int info_calcularActivosMayorMenorPub(Publicacion* arrayPublicaciones,int limitesPublicaciones)
{
	int retorno = -1;
	int i;
	int auxiliarActivo = 0;
	int activoMaximo;
	int indiceClienteMaximo;
	int auxiliarActivoMenor = 0;
	int activoMenor;
	int indiceClienteMenor;
	int flagMaximo = 0;
	int flagMinimo = 0;


	for(i=0;i<limitesPublicaciones;i++)
		{
         if(arrayPublicaciones[i].isEmpty == 0)
         {

         auxiliarActivo = info_cantidadPublicacionesActivasConRubro(arrayPublicaciones,limitesPublicaciones,arrayPublicaciones[i].rubro);
         auxiliarActivoMenor = info_cantidadPublicacionesActivasConRubro(arrayPublicaciones,limitesPublicaciones,arrayPublicaciones[i].rubro);

			if(flagMaximo == 0 || (auxiliarActivo > activoMaximo))
			{
                flagMaximo = 1;
				activoMaximo = auxiliarActivo;
				indiceClienteMaximo = i;
			}
			if(flagMinimo == 0 || (auxiliarActivoMenor < activoMenor))
			{   flagMinimo = 1;
			    activoMenor = auxiliarActivoMenor;
			    indiceClienteMenor = i;
			}
          }

         retorno = 0;
		}
	 if(activoMaximo == 0)
	      {
	    	  printf("\nNO SE ENCONTRO PUBLICACIONES ACTIVAS\n");
	      }
	 else
	 {
		printf("\nRubro con mas publicaciones activas: Rubro: %d | Cantidad:  %d  \n",arrayPublicaciones[indiceClienteMaximo].rubro,activoMaximo);
		printf("\nRubro con menos publicaciones activas: Rubro: %d | Cantidad:  %d  \n",arrayPublicaciones[indiceClienteMenor].rubro,activoMenor);
	 }
		return retorno;
}
