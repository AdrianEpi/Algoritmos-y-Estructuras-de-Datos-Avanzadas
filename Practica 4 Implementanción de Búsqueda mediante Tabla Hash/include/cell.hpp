/*===================================================================================
=====================================================================================
	=                                                                              =
	=            Proyecto:      Práctica 4 Implementación de Búsqueda Tabla Hash   =
	=            Archivo:       cell.hpp                                           =
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

/*------------------------------------------------*/

template <class T>

class Cell {

	private:
		int blockNumber_;
		T* block_;

	public:
		Cell ();
		Cell (int block);
		~Cell ();

		int get_BlockNumber (void) const;
		T get_Block (void) const;

		void set_BlockNumber (int block);
		void set_Block (T block);

		bool insertData (T data);
		bool search (T data);
		bool isFull (void) const;

		std::ostream write (std::ostream os) const;

}