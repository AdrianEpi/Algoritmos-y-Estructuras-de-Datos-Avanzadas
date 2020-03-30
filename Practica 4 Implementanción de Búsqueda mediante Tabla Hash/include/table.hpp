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
#include <vector>

/*------------------------------------------------*/

/*----------  DECLARACION DE FUNCIONES  ----------*/

#pragma once
#include "cell.hpp"

/*------------------------------------------------*/

template <class T>

class Table {
	
	private:
		int cellNumber_;
		std::vector<Cell<T>> cells_;
		//fDispersion //Recibe como parámetro un valor X del tipo Clave y retorna un valor en el intervalo [0..nCeldas-1] que indica la posición de la celda dentro de vCelda que debería contener valor X del tipo Clave. El constructor de la tabla hash recibe un parámetro que le indica la función de dispersión a instanciar.
		//fExploracion //Recibe como parámetros un valor X del tipo Clave y el número del intento de exploración (i>0), que se incrementa en cada llamada a esta función. En el i-ésimo intento de exploración la función retorna el desplazamiento, respecto a la posición dada por la función de dispersión, de la celda dentro de vCelda que debería contener valor X del tipo Clave. El constructor de la tabla hash recibe un parámetro que le indica la función de exploración a instanciar. 		//

	public:
		// Builders & Destroyer
		Table ();
		Table (int cellNumber, int blockNumber, int explorationSelector);
		~Table ();

		// Getters & Setters
		int get_CellNumber (void) const;
		std::vector<Cell<T>> get_Cells (void) const;

		void set_CellNumber (int number);
		void set_Cells (std::vector<Cell<T>> cell);

		// Functions
		bool insertData (T& data) const;
		bool searchData (T& data) const;

		// Read & Write
		std::ostream write (std::ostream os) const;


};