#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Cliente.h"
#include "Publicaciones.h"
#include "utn.h"
static const char TXT_TIPOS[2][8]={"ACTIVO","PAUSADO"};
/**
 * \brief Imprime los datos de un cliente
 * \param pElemento Puntero al producto que se busca imprimir
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int cli_imprimir(Cliente* pElemento)
{
	int retorno=-1;
	if(pElemento != NULL && pElemento->isEmpty == 0)
	{
		retorno=0;
		printf("\nID: %d | Nombre: %s | Apellido:  %s | CUIT:  %s\n",pElemento->id,pElemento->nombre,pElemento->apellido,pElemento->cuit);
	}
	return retorno;
}

/**
 * \brief Imprime el array de clientes
 * \param array Array de clientes a ser actualizado
 * \param limite Limite del array de clientes
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int cli_imprimirArray(Cliente* array,int limite)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0)
	{
		respuesta = 0;
		for(i=0;i<limite;i++)
		{
			cli_imprimir(&array[i]);
		}
	}
	return respuesta;
}

/**
 * \brief Inicializa el array
 * \param array Array de clientes a ser actualizado
 * \param limite Limite del array de clientes
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int cli_inicializarArray(Cliente* array,int limite)
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
 * \brief Da de alta una pantalla en una posicion del array
 * \param array Array de pantallas a ser actualizado
 * \param limite Limite del array de pantallas
 * \param indice Posicion a ser actualizada
 * \param id Identificador a ser asignado a la pantalla
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int cli_altaArray(Cliente* array,int limite, int indice, int* id)
{
	int respuesta = -1;
	Cliente bufferCliente;

	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && id != NULL)
	{
		if(	utn_getNombre(bufferCliente.nombre,NOMBRE_LEN,"\nIngrese Nombre\n","\nERROR\n",2) == 0 &&
			utn_getNombre(bufferCliente.apellido,APELLIDO_LEN,"\nIngrese Apellido\n","\nERROR\n",2) == 0 &&
			utn_getCuit(bufferCliente.cuit,CUIT_LEN,"\nIngrese CUIT\n","\nERROR\n",2) == 0)
		{
			respuesta = 0;
			bufferCliente.id = *id;
			bufferCliente.isEmpty = 0;
			array[indice] = bufferCliente;
			(*id)++;
		}
	}
	return respuesta;
}

/**
 * \brief Actualiza los datos de un cliente en una posicion del array
 * \param array Array de clientes a ser actualizado
 * \param limite Limite del array de clientes
 * \param indice Posicion a ser actualizada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int cli_modificarArray(Cliente* array,int limite, int indice)
{
	int respuesta = -1;
	Cliente bufferCliente;

	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && array[indice].isEmpty == 0)
	{
		if(utn_getNombre(bufferCliente.nombre,NOMBRE_LEN,"\nIngrese Nombre\n","\nERROR\n",2) == 0 &&
				utn_getNombre(bufferCliente.apellido,APELLIDO_LEN,"\nIngrese Apellido\n","\nERROR\n",2) == 0 &&
				utn_getCuit(bufferCliente.cuit,CUIT_LEN,"\nIngrese CUIT\n","\nERROR\n",2) == 0)
		{
			respuesta = 0;
			bufferCliente.id = array[indice].id;
			bufferCliente.isEmpty = 0;
			array[indice] = bufferCliente;
		}
	}
	return respuesta;
}

/**
 * \brief Actualiza una posicion del array
 * \param array Array de clientes a ser actualizado
 * \param limite Limite del array de clientes
 * \param indice Posicion a ser actualizada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int cli_bajaArray(Cliente* array,int limite, int indice)
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
* \param array cliente Array de cliente
* \param limite int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int cli_buscarId(Cliente array[], int limite, int valorBuscado)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0 && valorBuscado >= 0)
	{
		for(i=0;i<limite;i++)
		{
			if(array[i].id == valorBuscado && array[i].isEmpty==0)
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
 * \param array Array de clientes
 * \param limite Limite del array de clientes
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 *
 */
int cli_getEmptyIndex(Cliente* array,int limite)
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




/**
 * \brief Da de alta una pantalla en una posicion del array
 * \param array Array de pantallas a ser actualizado
 * \param limite Limite del array de pantallas
 * \param indice Posicion a ser actualizada
 * \param id Identificador a ser asignado a la pantalla
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int cli_altaForzadaArray(Cliente* array,int limite, int indice, int* id,char* nombre,char* apellido,char* cuit)

{
	int respuesta = -1;
	Cliente bufferClientes;

	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && id != NULL)
	{
			strncpy(bufferClientes.nombre,nombre,NOMBRE_LEN);
			strncpy(bufferClientes.apellido,apellido,APELLIDO_LEN);
			strncpy(bufferClientes.cuit,cuit,CUIT_LEN);
			respuesta = 0;
			bufferClientes.id = *id;
			bufferClientes.isEmpty = 0;
			array[indice] = bufferClientes;
			(*id)++;
	}
	return respuesta;
}
/*Recorro el array de publicaciones, comparo que el id de cliente en el array de publicaciones coincide con el de idclientes
 * que valide que este en estado ACTIVO y que aumente el contador para ese idCliente que pase
 *
 */
int cli_cantidadPublicacionesActivas(Publicacion* arrayPublicacion, int limitePublicaciones,int idCliente)
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
/*
 *
 */
int cli_imprimirArrayClientesActivos(Cliente* arrayClientes,int limiteClientes,Publicacion* arrayPublicaciones,int limitePublicaciones)
{
	int respuesta = -1;
	int i;


	if(arrayClientes != NULL && limiteClientes > 0)
	{
		respuesta = 0;
		for(i=0;i<limiteClientes;i++)
		{
          cli_imprimir2(&arrayClientes[i],arrayPublicaciones,limitePublicaciones);
		}
	}
	return respuesta;
}


int cli_imprimir2(Cliente* pElemento, Publicacion* arrayPublicaciones,int limitePublicaciones)
{
    int retorno = -1;
	int resultado;
	if(pElemento != NULL && pElemento->isEmpty == 0)
	{
		resultado = cli_cantidadPublicacionesActivas(arrayPublicaciones,limitePublicaciones,pElemento->id);
          retorno = 0;
		printf("\nID: %d | Nombre: %s | Apellido:  %s | CUIT:  %s",pElemento->id,pElemento->nombre,pElemento->apellido,pElemento->cuit);
		printf("\nCantidad de publicaciones activas: %d\n", resultado);
	}
	return retorno;
}


int cli_bajaClientePublicacion(Publicacion* arrayPublicacion, int limitePublicaciones,int idCliente)
{

	int retorno = -1;
	int i;


	for(i=0;i<limitePublicaciones;i++)
	{
		if(arrayPublicacion[i].idCliente == idCliente && arrayPublicacion[i].isEmpty == 0)
		{
			arrayPublicacion[i].isEmpty = 1;
		}
	}retorno = 0;
	return retorno;
}
int cli_clienteycuit(Publicacion* arrayPublicacion, int limitePublicaciones,int idCliente)
{

	int retorno = -1;
	int i;


	for(i=0;i<limitePublicaciones;i++)
	{
		if(arrayPublicacion[i].idCliente == idCliente && arrayPublicacion[i].isEmpty == 0)
		{
			printf("\nIDPublicacion: %d | IDCliente: %d | Estado: %s | Rubro: %d | Archivo: %s ",arrayPublicacion[i].id,arrayPublicacion[i].idCliente,TXT_TIPOS[arrayPublicacion[i].estado],arrayPublicacion[i].rubro,arrayPublicacion[i].archivo);
			retorno = 0;
		}
	}
	return retorno;
}
int cli_imprimirPub(Cliente* pElemento, Publicacion* arrayPublicaciones,int limitePublicaciones)
{
    int retorno = -1;

	if(pElemento != NULL && pElemento->isEmpty == 0)
	{
		if(cli_clienteycuit(arrayPublicaciones,limitePublicaciones,pElemento->id)==0)
		{

          printf("\nPertenece a CUIT:  %s\n",pElemento->cuit);
		}


	}retorno = 0;
	return retorno;
}
int cli_imprimirArrayPub(Cliente* arrayClientes,int limiteClientes,Publicacion* arrayPublicaciones,int limitePublicaciones)
{
	int respuesta = -1;
	int i;


	if(arrayClientes != NULL && limiteClientes > 0)
	{
		respuesta = 0;
		for(i=0;i<limiteClientes;i++)
		{
			cli_imprimirPub(&arrayClientes[i],arrayPublicaciones,limitePublicaciones);
		}
	}
	return respuesta;
}

