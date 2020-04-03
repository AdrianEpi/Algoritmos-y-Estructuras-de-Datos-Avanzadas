/*===================================================================================
=====================================================================================
	=                                                                              =
	=            Proyecto:      Práctica 4 Implementación de Búsqueda Tabla Hash   =
	=            Archivo:       experiment.hpp                                     =
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
#include "table.hpp"

/*------------------------------------------------*/

class Experiment {

	private:
		int cellNum_;
		int blockNum_;
		double chargeFactor_;
		int tryNum_;
		int comp[2];
		std::vector<DNI> bench_;
		Table<DNI>* table_;

	public:
		// Builder & Destroyer
		Experiment ();
		~Experiment ();

		// Getters & Setters
		int get_CellNum (void) const;
		int get_BlockNum (void) const;
		double get_ChargeFactor (void) const;
		int get_TryNum (void) const;
		Table<DNI>* get_Table (void) const;

		void set_CellNum (int cellNum);
		void set_BlockNum (int blockNum);
		void set_ChargeFactor (double chargeFactor);
		void set_TryNum (int tryNum);
		void set_Table (Table<DNI>* table);

		// Functions
		void initialize (void);
		void restart (void);
		void loadData (void);
		void testInserts (void);
		void testSearchs (void);
		bool isPrime (unsigned number);
		unsigned findPrime (unsigned number);
		int selectDispersion (void) const;
		int selectExploration (void) const;

		// Write
		void write (void);
};