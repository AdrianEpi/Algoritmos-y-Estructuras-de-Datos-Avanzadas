/*===================================================================================
=====================================================================================
	=                                                                              =
	=            Proyecto:      Práctica 4 Implementación de Búsqueda Tabla Hash   =
	=            Archivo:       table.hpp                                          =
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
#include "cell.hpp"

/*------------------------------------------------*/

template <class T>

class Table {
	
	private:
		int cellNumber_;
		// Cell<T> cell_;

	public:
		Table ();
		Table (int cellNumber, int blockNumber, int explorationSelector);
		~Table ();

		bool insertData (T& data) const;
		bool searchData (T& data) const;

		std::ostream write (std::ostream os) const;


};