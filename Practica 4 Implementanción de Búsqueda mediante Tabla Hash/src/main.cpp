/*===================================================================================
=====================================================================================
	=                                                                              =
	=            Proyecto:      Práctica 4 Implementación de Búsqueda Tabla Hash   =
	=            Archivo:       main.cpp                                           =
	=            Autor:         Adrián Epifanio Rodríguez Hernández                =
	=            Fecha:         30/03/2020                                         =
	=            Asignatura:    Algoritmos y Estructuras de Datos Avazados         =
	=            Lenguaje:      C++                                                =
	=            Correo:        alu0101158280@ull.edu.es                           =
	=            Lugar:         Universidad De La Laguna                           =
	=                           Escuela Superior de Ingeniería y Tecnología        =
	=                                                                              =
=====================================================================================
===================================================================================*/
/*
* @Author: Adrián Epifanio
* @Date:   2020-03-30 14:20:30
* @Last Modified by:   Adrián Epifanio
* @Last Modified time: 2020-04-07 18:15:03
*/
/*----------  DECLARACION DE LIBRERIAS  ----------*/

#include <iostream>
#include <cstdlib>

/*------------------------------------------------*/

/*----------  DECLARACION DE FUNCIONES  ----------*/

#include "../include/cell.hpp"
#include "../include/table.hpp"
#include "../include/DNI.hpp"
#include "../include/experiment.hpp"

/*------------------------------------------------*/

/**
 * 
 * @brief      Main function
 *
 * @return     0 when program ends
 */
int main(void) {

	Experiment* Exp = new Experiment();
	Exp -> initialize();
	Exp -> loadData();
	Exp -> write();
	return 0;
}
