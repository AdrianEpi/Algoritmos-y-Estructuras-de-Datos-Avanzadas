/*===================================================================================
=====================================================================================
	=                                                                              =
	=            Proyecto:      Práctica 4 Implementación de Búsqueda Tabla Hash   =
	=            Archivo:       explorationBase.hpp                                    =
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

#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iomanip>

/*------------------------------------------------*/

/*----------  DECLARACION DE FUNCIONES  ----------*/

#pragma once
#include "table.hpp"

/*------------------------------------------------*/

#define MAXTEST 1000

class Experiment {
	
	private:
		int dispersionSelector_;
		int explorationSelector_;
		unsigned cellNum_;
		unsigned blockNum_;
		double chargeFactor_;
		unsigned tryNum_;
		int saver_[2]; // Save max and min ammounts for testing
		DNI** bench_;
		Table<DNI>* table_;

	public:
		Experiment ();
		~Experiment ();

		// Getters & Setters
		int get_DispersionSelector (void) const;
		int get_ExplorationSelector (void) const;
		int get_CellNum (void) const;
		int get_BlockNum (void) const;
		double get_ChargeFactor (void) const;
		int get_TryNum (void) const;
		Table<DNI>* get_Table (void) const;


		void set_DispersionSelector (int newSelection);
		void set_ExplorationSelector (int newSelection);
		void set_CellNum (int cellNum);
		void set_BlockNum (int blockNum);
		void set_ChargeFactor (double chargeFactor);
		void set_TryNum (int tryNum);
		void set_Table (Table<DNI>* table);

		// Functions
		void initialize (void);
		void restart (void);
		void loadData (void);
		void testInsert (void);
		void testSearch (void);
		bool isPrime (unsigned number);
		unsigned findPrime (unsigned number);

		// Write
		void write (void);
		
};
