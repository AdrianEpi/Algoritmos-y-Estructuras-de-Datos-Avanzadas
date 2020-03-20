/*===================================================================================
=====================================================================================
	=                                                                              =
	=            Proyecto:      Práctica 3 El juego de la vida generalizado        =
	=            Archivo:       main.cpp                                           =
	=            Autor:         Adrián Epifanio Rodríguez Hernández                =
	=            Fecha:         16/03/2020                                         =
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
* @Date:   2020-03-02 08:56:58
* @Last Modified by:   Adrián Epifanio
* @Last Modified time: 2020-03-20 11:25:11
*/
/*----------  DECLARACION DE LIBRERIAS  ----------*/

#include <iostream>

/*------------------------------------------------*/

/*----------  DECLARACION DE FUNCIONES  ----------*/

#include "../include/tablero.hpp"

/*------------------------------------------------*/

/**
 * @brief      Main program
 */
int main() {
	int filas = 0;
	int columnas = 0;
	int turnos = 1;
	std::cout << "Indique la cantidad de filas: ";
	std::cin >> filas;
	std::cout << "Indique la cantidad de columnas: ";
	std::cin >> columnas;
	std::cout << "Indique la cantidad de turnos del juego: ";
	std::cin >> turnos;
	Tablero juego(filas, columnas, turnos);
};
// Prueba de ejecución
// 20 20 20 5 1 10 10 1 10 11 1 11 11 1 12 11 1 11 12