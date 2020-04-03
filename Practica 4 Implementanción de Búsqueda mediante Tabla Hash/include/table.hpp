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
#include <cassert>

/*------------------------------------------------*/

/*----------  DECLARACION DE FUNCIONES  ----------*/

#pragma once
#include "cell.hpp"
#include "explorationBase.hpp"
#include "dispersionBase.hpp"
#include "explorationLinear.hpp"
#include "explorationQuadratic.hpp"
#include "explorationDouble.hpp"
#include "explorationReDispersion.hpp"
#include "dispersionSum.hpp"
#include "dispersionModule.hpp"
#include "dispersionPseudoRandom.hpp"

/*------------------------------------------------*/

template <class T>

class Table {
	
	private:
		int cellNumber_;
		int blockNumber_;
		std::vector<Cell<T>> cells_;
		DispersionBase<T>* fDispersion_; //Recibe como parámetro un valor X del tipo Clave y retorna un valor en el intervalo [0..nCeldas-1] que indica la posición de la celda dentro de vCelda que debería contener valor X del tipo Clave. El constructor de la tabla hash recibe un parámetro que le indica la función de dispersión a instanciar.
		ExplorationBase<T>* fExploration_; //Recibe como parámetros un valor X del tipo Clave y el número del intento de exploración (i>0), que se incrementa en cada llamada a esta función. En el i-ésimo intento de exploración la función retorna el desplazamiento, respecto a la posición dada por la función de dispersión, de la celda dentro de vCelda que debería contener valor X del tipo Clave. El constructor de la tabla hash recibe un parámetro que le indica la función de exploración a instanciar. 		//

	public:
		// Builders & Destroyer
		Table ();
		Table (int cellNumber, int blockNumber);
		~Table ();

		// Getters & Setters
		int get_CellNumber (void) const;
		int get_BlockNumber (void) const;
		std::vector<Cell<T>> get_Cells (void) const;
		DispersionBase<T>* get_Dispersion (void) const;
		ExplorationBase<T>* get_Exploration (void) const;

		void set_CellNumber (int number);
		void set_BlockNumber (int blockNumber);
		void set_Cells (std::vector<Cell<T>> cell);
		void set_Dispersion (DispersionBase<T>* dispersion);
		void set_Exploracion (ExplorationBase<T>* exploration);

		// Functions
		bool insertData (T& data) const;
		bool searchData (T& data) const;
		int selectDispersion (void) const;
		int selectExploration (void) const;

		// Read & Write
		std::ostream write (std::ostream os) const;


};