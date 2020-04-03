/*===================================================================================
=====================================================================================
	=                                                                              =
	=            Proyecto:      Práctica 4 Implementación de Búsqueda Tabla Hash   =
	=            Archivo:       explorationLinear.hpp                              =
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
/*----------  DECLARACION DE LIBRERIAS  ----------*/

#include <iostream>

/*------------------------------------------------*/

/*----------  DECLARACION DE FUNCIONES  ----------*/

#pragma once
#include "explorationBase.hpp"

/*------------------------------------------------*/

 

template <class T>
class ExplorationLinear : public ExplorationBase<T> {
	
	public:
		// Builder & Destroyer
		ExplorationLinear();
		virtual ~ExplorationLinear();

		// Operator Overload
		int operator() (int size, int pos, const T& data);

};