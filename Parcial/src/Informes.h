/*
 * Informes.h
 *
 *  Created on: 9 may. 2020
 *      Author: sampini
 */

#ifndef INFORMES_H_
#define INFORMES_H_

int info_cantidadPublicacionesActivas(Publicacion* arrayPublicacion, int limitePublicaciones,int idCliente);
int info_cantidadPublicacionesPausadas(Publicacion* arrayPublicacion, int limitePublicaciones,int idCliente);
int info_cantidadPublicaciones(Publicacion* arrayPublicacion, int limitePublicaciones,int idCliente);
int info_calcularActivosMayor(Cliente* arrayClientes,int limitesClientes,Publicacion* arrayPublicaciones,int limitePublicaciones);
int info_calcularPausadoMayor(Cliente* arrayClientes,int limitesClientes,Publicacion* arrayPublicaciones,int limitePublicaciones);
int info_calcularMayorPublicaciones(Cliente* arrayClientes,int limitesClientes,Publicacion* arrayPublicaciones,int limitePublicaciones);
int info_listaRubro(Publicacion* arrayPublicaciones,int limitePublicaciones,int auxiliar);
int info_cantidadPublicacionesActivasConRubro(Publicacion* arrayPublicacion, int limitePublicaciones,int rubro);
int info_calcularActivosMayorMenorPub(Publicacion* arrayPublicaciones,int limitesPublicaciones);
#endif /* INFORMES_H_ */
