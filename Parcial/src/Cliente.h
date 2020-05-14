/*
 * Cliente.h
 *
 *
 *      Author:Sampini
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_
#include "Publicaciones.h"

#define NOMBRE_LEN 30
#define APELLIDO_LEN 30
#define CUIT_LEN 30



typedef struct
{
	char nombre[NOMBRE_LEN];
	char apellido[APELLIDO_LEN];
	char cuit[CUIT_LEN];
	int isEmpty;
	int id;

}Cliente;

int cli_imprimir(Cliente* auxProducto);
int cli_inicializarArray(Cliente* array,int limite);
int cli_altaArray(Cliente* array,int limite, int indice, int* id);
int cli_getEmptyIndex(Cliente* array,int limite);
int cli_imprimirArray(Cliente* array,int limite);
int cli_buscarId(Cliente array[], int limite, int valorBuscado);
int cli_modificarArray(Cliente* array,int limite, int indice);
int cli_bajaArray(Cliente* array,int limite, int indice);
int cli_altaForzadaArray(Cliente* array,int limite, int indice, int* id,char* nombre,char* apellido,char* cuit);
int cli_imprimirArrayClientesActivos(Cliente* arrayClientes,int limiteClientes,Publicacion* arrayPublicaciones,int limitePublicaciones);
int cli_cantidadPublicacionesActivas(Publicacion* arrayPublicacion, int limitePublicaciones,int idCliente);
int cli_imprimir2(Cliente* pElemento, Publicacion* arrayPublicaciones,int limitePublicaciones);
int cli_bajaClientePublicacion(Publicacion* arrayPublicacion, int limitePublicaciones,int idCliente);
int cli_clienteycuit(Publicacion* arrayPublicacion, int limitePublicaciones,int idCliente);
int cli_imprimirPub(Cliente* pElemento, Publicacion* arrayPublicaciones,int limitePublicaciones);
int cli_imprimirArrayPub(Cliente* arrayClientes,int limiteClientes,Publicacion* arrayPublicaciones,int limitePublicaciones);
#endif /* CLIENTE_H_ */
