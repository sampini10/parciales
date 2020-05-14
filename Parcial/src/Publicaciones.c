#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Cliente.h"
#include "Publicaciones.h"
#include "utn.h"
static const char TXT_TIPOS[2][8]={"ACTIVO","PAUSADO"};
/**
 * \brief Imprime los datos de un contratacion
 * \param pElemento Puntero al producto que se busca imprimir
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int pub_imprimir(Publicacion* pElemento)
{
	int retorno=-1;
	if(pElemento != NULL && pElemento->isEmpty == 0)
	{
		retorno=0;
		printf("\nIDPublicacion: %d | IDCliente: %d | Estado: %s | Rubro: %d | Archivo: %s \n",pElemento->id,pElemento->idCliente,TXT_TIPOS[pElemento->estado],pElemento->rubro,pElemento->archivo);
	}
	return retorno;
}

/**
 * \brief Imprime el array de contrataciones
 * \param array Array de contrataciones a ser actualizado
 * \param limite Limite del array de contrataciones
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int pub_imprimirArray(Publicacion* array,int limite)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0)
	{
		respuesta = 0;
		for(i=0;i<limite;i++)
		{
			pub_imprimir(&array[i]);

		}
	}
	return respuesta;
}

/**
 * \brief Inicializa el array
 * \param array Array de contrataciones a ser actualizado
 * \param limite Limite del array de contrataciones
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int pub_inicializarArray(Publicacion* array,int limite)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0)
	{
		respuesta = 0;
		for(i=0;i<limite;i++)
		{
			array[i].isEmpty = 1;
		}
	}
	return respuesta;
}

/**
 * \brief Da de alta un contratacion en una posicion del array
 * \param array Array de contrataciones a ser actualizado
 * \param limite Limite del array de contrataciones
 * \param indice Posicion a ser actualizada
 * \param id Identificador a ser asignado al contratacion
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int pub_altaArray(Publicacion* array,int limite, int indice, int* idPublicacion, int idCliente)
{
	int respuesta = -1;
	Publicacion bufferPublicacion;

	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && idPublicacion != NULL)
	{
		if(	utn_getNumero(&bufferPublicacion.rubro,"\nIngrese numero de rubro(1-5)","\nRubro invalido",1,5,2)== 0 &&
			utn_getDescripcion(bufferPublicacion.archivo,ARCHIVO_LEN,"\nIngrese archivo (maximo 64 caracteres) ", "\nExcede caracteres",2)==0)
		{
			respuesta = 0;
			bufferPublicacion.estado = 0;
			bufferPublicacion.idCliente = idCliente;
			bufferPublicacion.id = *idPublicacion;
			bufferPublicacion.isEmpty = 0;
			array[indice] = bufferPublicacion;
			(*idPublicacion)++;
		}
	}
	return respuesta;
}

/**
 * \brief Da de alta un contratacion en una posicion del array de manera forzada
 * \param array Array de contrataciones a ser actualizado
 * \param limite Limite del array de contrataciones
 * \param indice Posicion a ser actualizada
 * \param id Identificador a ser asignado al contratacion
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int pub_altaForzadaArray(Publicacion* array,int limite, int indice, int* idPublicacion, int idCliente,char* archivo,int rubro)
{
	int respuesta = -1;
	Publicacion bufferPublicacion;

	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && idPublicacion != NULL)
	{
		strncpy(bufferPublicacion.archivo,archivo,ARCHIVO_LEN);
		bufferPublicacion.rubro = rubro;
		bufferPublicacion.idCliente = idCliente;
        respuesta = 0;
        bufferPublicacion.estado = 0;
		bufferPublicacion.id = *idPublicacion;
		bufferPublicacion.isEmpty = 0;
		array[indice] = bufferPublicacion;
		(*idPublicacion)++;

	}
	return respuesta;
}

/**
 * \brief Actualiza una posicion del array
 * \param array Array de contrataciones a ser actualizado
 * \param limite Limite del array de contrataciones
 * \param indice Posicion a ser actualizada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int pub_bajaArray(Publicacion* array,int limite, int indice)
{
	int respuesta = -1;
	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && array[indice].isEmpty == 0)
	{
		array[indice].isEmpty = 1;
		respuesta = 0;
	}
	return respuesta;
}


/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param array contratacion Array de contratacion
* \param limite int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int pub_buscarId(Publicacion array[], int limite, int valorBuscado)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0 && valorBuscado >= 0)
	{
		for(i=0;i<limite;i++)
		{
			if(array[i].id == valorBuscado  && array[i].isEmpty==0)
			{
				respuesta = i;
				break;
			}
		}
	}
	return respuesta;
}

/**
 * \brief Buscar primer posicion vacia
 * \param array Array de contrataciones
 * \param limite Limite del array de contrataciones
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 *
 */
int pub_getEmptyIndex(Publicacion* array,int limite)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0)
	{
		for(i=0;i<limite;i++)
		{
			if(array[i].isEmpty == 1)
			{
				respuesta = i;
				break;
			}
		}
	}
	return respuesta;
}

int pub_pausaArray(Publicacion* array,int limite, int indice)
{
	int retorno = -1;
	int estado;

	if(array != NULL && limite > 0 && indice < limite && indice >= 0)
		{
		if (!utn_getNumero(&estado,"\nIngrese 1 para pausar publicacion (0 para salir):","\nOpcion invalida.",0,1,2))
			{
				if(estado == 1)
				{
				retorno = 0;
				array[indice].estado = 1;
				}
				else
				{
					retorno = 0;
				}

		    }

		}

  return retorno;
}

int pub_reanudarArray(Publicacion* array,int limite, int indice)
  {
  	int retorno = -1;
  	int estado;

  	if(array != NULL && limite > 0 && indice < limite && indice >= 0)
  		{
  		if (!utn_getNumero(&estado,"\nIngrese 1 para reanudar publicacion (0 para salir):","\nOpcion invalida.",0,1,2))
  			{
  				if(estado == 1)
  				{
  				retorno = 0;
  				array[indice].estado = 0;
  				}
  				else
  				{
  					retorno = 0;
  				}

  		    }

  		}

    return retorno;
  }

