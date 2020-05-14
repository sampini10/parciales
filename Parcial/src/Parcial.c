/*
 ============================================================================
 Name        : Parcial.c
 Author      : Sampini
 Version     :
 Copyright   :
 Description :
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "Cliente.h"
#include "Publicaciones.h"
#include "Informes.h"
#define CANTIDAD_CLIENTES 100
#define CANTIDAD_PUBLICACIONES 1000


int main(void) {

	setbuf(stdout,NULL);

	Cliente arrayClientes[CANTIDAD_CLIENTES];
	Publicacion arrayPublicaciones[CANTIDAD_PUBLICACIONES];
	int idClientes = 0;
	int opcion;
	int auxiliarIndice;
	int auxiliarId;
	int idPublicaciones = 0;
	int auxiliarIndicePub;
	int auxiliarIdPub;
	int auxiliarRubro;
	int opcion2;



	cli_inicializarArray(arrayClientes,CANTIDAD_CLIENTES);
	pub_inicializarArray(arrayPublicaciones,CANTIDAD_PUBLICACIONES);

	/*if(cli_inicializarArray(arrayClientes,CANTIDAD_CLIENTES) == 0)
		{
			printf("Array inicializado correctamente. \n");
		}
    if(pub_inicializarArray(arrayPublicaciones,CANTIDAD_PUBLICACIONES)==0)
            {
    			printf("Array inicializado correctamente. \n");
    		}*/
        cli_altaForzadaArray(arrayClientes,CANTIDAD_CLIENTES,0,&idClientes,"nicolas","sampini","20357641781");
        cli_altaForzadaArray(arrayClientes,CANTIDAD_CLIENTES,1,&idClientes,"jorge","sampini","2935764121");
        cli_altaForzadaArray(arrayClientes,CANTIDAD_CLIENTES,2,&idClientes,"pedro","sampini","25357641771");
        cli_altaForzadaArray(arrayClientes,CANTIDAD_CLIENTES,3,&idClientes,"gustavo","sampini","30357641781");
        cli_altaForzadaArray(arrayClientes,CANTIDAD_CLIENTES,4,&idClientes,"gerardo","sampini","50357641781");
        cli_altaForzadaArray(arrayClientes,CANTIDAD_CLIENTES,5,&idClientes,"fernando","sampini","40311241");

        pub_altaForzadaArray(arrayPublicaciones,CANTIDAD_PUBLICACIONES,0,&idPublicaciones,0,"nada",2);
        pub_altaForzadaArray(arrayPublicaciones,CANTIDAD_PUBLICACIONES,1,&idPublicaciones,1,"nada",5);
        pub_altaForzadaArray(arrayPublicaciones,CANTIDAD_PUBLICACIONES,2,&idPublicaciones,1,"nada",3);
        pub_altaForzadaArray(arrayPublicaciones,CANTIDAD_PUBLICACIONES,3,&idPublicaciones,2,"nada",1);
        pub_altaForzadaArray(arrayPublicaciones,CANTIDAD_PUBLICACIONES,4,&idPublicaciones,3,"nada",4);
        pub_altaForzadaArray(arrayPublicaciones,CANTIDAD_PUBLICACIONES,5,&idPublicaciones,2,"nada",4);
        pub_altaForzadaArray(arrayPublicaciones,CANTIDAD_PUBLICACIONES,6,&idPublicaciones,2,"nada",4);
        pub_altaForzadaArray(arrayPublicaciones,CANTIDAD_PUBLICACIONES,7,&idPublicaciones,2,"nada",2);
        pub_altaForzadaArray(arrayPublicaciones,CANTIDAD_PUBLICACIONES,8,&idPublicaciones,5,"nada",4);
        pub_altaForzadaArray(arrayPublicaciones,CANTIDAD_PUBLICACIONES,9,&idPublicaciones,4,"nada",4);

	do
		{
			if(!utn_getNumero(&opcion,"\n1.Cargar un cliente"
					"\n2.Modificar un cliente"
					"\n3.Baja de cliente"
					"\n4.Contratar una publicacion"
				    "\n5.Pausar una publicacion"
					"\n6.Reanudar una publicacion"
					"\n7.Imprimir clientes"
					"\n8.Imprimir publicaciones"
					"\n9.Informar clientes"
					"\n10.Informar publicaciones"
					"\n11.Salir\n",
					"\nError opcion invalida",1,14,2) )
			{
				switch(opcion)
				{
				case 1:
					auxiliarIndice = cli_getEmptyIndex(arrayClientes,CANTIDAD_CLIENTES);//busca en el array la posicion vacia
					if(auxiliarIndice >= 0)
					{
						if(cli_altaArray(arrayClientes,CANTIDAD_CLIENTES,auxiliarIndice,&idClientes) == 0)//valida los datos que le solicito al usuario para poder guardarlos
						{
							printf("\nCarga realizada con exito\n");
						}
					}
					else
					{
						printf("\nSin espacio en Clientes\n");
					}
					break;
				case 2:
					cli_imprimirArray(arrayClientes,CANTIDAD_CLIENTES);//imprime el array de clientes
					if(!utn_getNumero(&auxiliarId,"\nIngrese el ID del Cliente:\n","\nID no es valido, ingrese nuevamente\n",0,idClientes,1))//pido id, verifica que sea valido el ingreso
					{
						auxiliarIndice = cli_buscarId(arrayClientes,CANTIDAD_CLIENTES,auxiliarId);//busca en el array el id
						if (auxiliarIndice >= 0 &&
								!cli_modificarArray(arrayClientes,CANTIDAD_CLIENTES,auxiliarIndice))
						{
							printf("\nModificacion realizada con exito.\n");
						}
					}
					break;
				case 3:
					cli_imprimirArray(arrayClientes,CANTIDAD_CLIENTES);
					if(!utn_getNumero(&auxiliarId,"\nIngrese el ID que desea eliminar\n","\nID no es valido, ingrese nuevamente\n",0,idClientes,1))
					{
						auxiliarIndice = cli_buscarId(arrayClientes,CANTIDAD_CLIENTES,auxiliarId);
						if(auxiliarIndice >= 0 &&
								!cli_bajaArray(arrayClientes,CANTIDAD_CLIENTES,auxiliarIndice) &&
								!cli_bajaClientePublicacion(arrayPublicaciones,CANTIDAD_PUBLICACIONES,auxiliarIndice))

						{
							printf("\nBaja realizada con exito.\n");
						}
					}
					break;
				case 4:
					auxiliarIndicePub = pub_getEmptyIndex(arrayPublicaciones,CANTIDAD_PUBLICACIONES);
					if (auxiliarIndicePub >= 0)
					{
						cli_imprimirArray(arrayClientes,CANTIDAD_CLIENTES);
						if (utn_getNumero(&auxiliarId, "\nIngrese ID de cliente: ", "Error ID invalido",0,idClientes,2)== 0 &&
								cli_buscarId(arrayClientes,CANTIDAD_CLIENTES,auxiliarId) != -1)
						{
							pub_altaArray(arrayPublicaciones,CANTIDAD_PUBLICACIONES,auxiliarIndicePub,&idPublicaciones,auxiliarId);
						     printf("\nCarga realizada con exito\n ");

						}
						else
						{
							printf("\nEl ID no existe\n");
						}
					}
					break;
				case 5:
					pub_imprimirArray(arrayPublicaciones,CANTIDAD_PUBLICACIONES);
					if(!utn_getNumero(&auxiliarIdPub,"\nIngrese IDPublicacion a pausar","\nError ID",0,idPublicaciones,2))
					{
						auxiliarIndicePub = pub_buscarId(arrayPublicaciones,CANTIDAD_PUBLICACIONES,auxiliarIdPub);
												if(auxiliarIndicePub != -1)
												{
													pub_pausaArray(arrayPublicaciones,CANTIDAD_PUBLICACIONES,auxiliarIndicePub);
													printf("\nPublicacion pausada\n");
												}
					}
					break;
				case 6:
					pub_imprimirArray(arrayPublicaciones,CANTIDAD_PUBLICACIONES);
							if(!utn_getNumero(&auxiliarIdPub,"\nIngrese IDPublicacion a reanudar","\nError ID",0,idPublicaciones,2))
								{
								 auxiliarIndicePub = pub_buscarId(arrayPublicaciones,CANTIDAD_PUBLICACIONES,auxiliarIdPub);
									if(auxiliarIndicePub != -1)
										{
											pub_reanudarArray(arrayPublicaciones,CANTIDAD_PUBLICACIONES,auxiliarIndicePub);
											printf("\nPublicacion reanudada\n");
										}
								}
                    break;
				case 7:
					cli_imprimirArrayClientesActivos(arrayClientes,CANTIDAD_CLIENTES,arrayPublicaciones,CANTIDAD_PUBLICACIONES);
					break;
				case 8:
					cli_imprimirArrayPub(arrayClientes,CANTIDAD_CLIENTES,arrayPublicaciones,CANTIDAD_PUBLICACIONES);
					break;

				case 9:
					info_calcularActivosMayor(arrayClientes,CANTIDAD_CLIENTES,arrayPublicaciones,CANTIDAD_PUBLICACIONES);
					info_calcularPausadoMayor(arrayClientes,CANTIDAD_CLIENTES,arrayPublicaciones,CANTIDAD_PUBLICACIONES);
					info_calcularMayorPublicaciones(arrayClientes,CANTIDAD_CLIENTES,arrayPublicaciones,CANTIDAD_PUBLICACIONES);
                      break;
				case 10:
					do{
						if(!utn_getNumero(&opcion2,"\n1.Cantidad publicaciones por rubro"
								                    "\n2.Rubro con mayor publicaciones activas y rubro con menos publicaciones activas"
								                     "\n3.Salir al menu principal\n",
													 "\nNo es una opcion valida",1,3,2))
						{switch(opcion2)

						{
						case 1:
				           	if(!utn_getNumero(&auxiliarRubro,"\nIngrese Rubro: ","\nRubro no valido: ",1,5,2))
									{
								      info_listaRubro(arrayPublicaciones,CANTIDAD_PUBLICACIONES,auxiliarRubro);
										 }
				           	break;
						case 2:
						      info_calcularActivosMayorMenorPub(arrayPublicaciones,CANTIDAD_PUBLICACIONES);
						      break;
                         }
						}
					}while (opcion2 != 3);



				}
			}

		}while (opcion != 11);

	return EXIT_SUCCESS;
}
