/*===================================================================================
=====================================================================================
	=                                                                              =
	=            Proyecto:      Práctica 5 Implementación de Métodos de Ordenación =
	=            Archivo:       Counter.hpp                                        =
	=            Autor:         Adrián Epifanio Rodríguez Hernández                =
	=            Fecha:         21/04/2020                                         =
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

#pragma once
#include <limits>

class Counter {

	private:
		int accum_;
		int max_;
		int min_;
		int localAccum_;

	public:
		// Builder & Destroyer
		Counter ();
		~Counter ();

		// Getters & Setters
		int get_Accum (void) const;
		int get_Max (void) const;
		int get_Min (void) const;
		int get_LocalAccum (void) const;

		void set_Accum (int accum);
		void set_Max (int max);
		void set_Min (int min);
		void set_LocalAccum (int localAccum);

		// Functions
		void start (void);
		int stop (void);
		void reset (void);
		void incrementation (void);
		
		// Operators Overload
		Counter& operator++ (void); 
		
};
