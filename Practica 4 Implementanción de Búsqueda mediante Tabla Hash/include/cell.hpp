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
		int usability_; /* 0 -> empty cell (never has been used)
		                 * 1 -> cell in use
		                 * -1 -> empty cell but has been prevously used
		                 */
		

	public:
		// Builders & Destroyer
		Cell ();
		Cell (int blockNumber);
		~Cell ();

		// Getters & Setters
		int get_BlockNumber (void) const;
		T get_Block (void) const;
		int get_Usability (void) const;

		void set_BlockNumber (int blockNumber);
		void set_Block (T block);
		void set_Usability (int usability);

		// Functions
		bool insertData (T data);
		bool search (T data);
		bool isFull (void) const;

		// Read & Write
		std::ostream write (std::ostream os) const;

};