#ifndef PUBLICACIONES_H_
#define PUBLICACIONES_H_
#include "Cliente.h"
#define ARCHIVO_LEN 65
#define TIPO_ACTIVO	0
#define TIPO_PAUSADO 1

typedef struct
{
	char archivo[ARCHIVO_LEN];
	int rubro;
	int isEmpty;
	int id;
	int idCliente;
	int estado;
}Publicacion;

int pub_imprimir(Publicacion* auxProducto);
int pub_inicializarArray(Publicacion* array,int limite);
int pub_altaArray(Publicacion* array,int limite, int indice, int* idContratacion, int idPantalla);
int pub_getEmptyIndex(Publicacion* array,int limite);
int pub_imprimirArray(Publicacion* array,int limite);
int pub_buscarId(Publicacion array[], int limite, int valorBuscado);
int pub_bajaArray(Publicacion* array,int limite, int indice);
int pub_pausaArray(Publicacion* array,int limite, int indice);
int pub_reanudarArray(Publicacion* array,int limite, int indice);
int pub_altaForzadaArray(Publicacion* array,int limite, int indice, int* idPublicacion, int idCliente,char* archivo,int rubro);



#endif /* PUBLICACIONES_H_ */
