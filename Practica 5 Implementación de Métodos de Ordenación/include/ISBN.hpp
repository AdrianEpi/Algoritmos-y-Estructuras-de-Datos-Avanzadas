/*===================================================================================
=====================================================================================
	=                                                                              =
	=            Proyecto:      Práctica 5 Implementación de Métodos de Ordenación =
	=            Archivo:       ISBN.hpp                                            =
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
#include <iomanip>

/*------------------------------------------------*/

/*----------  DECLARACION DE FUNCIONES  ----------*/

#pragma once

/*------------------------------------------------*/

class ISBN {

	private:
		int code_;
		
	public:
		// Builders & Destroyer
		ISBN ();
		ISBN (unsigned value);
		ISBN (const ISBN& copy);
		~ISBN ();
		
		// Getter & Setter
		int get_Code (void) const;
		void set_Code (int code);
		
		// Operators Overload
		unsigned operator % (unsigned n);
		bool operator== (ISBN& number) const;
		bool operator<= (ISBN& ISBN) const;
		bool operator>= (ISBN& ISBN) const;
		bool operator!= (ISBN& ISBN) const;
		bool operator== (int number) const;
		ISBN& operator= (ISBN& ISBN);
		operator unsigned long ();
		
		// Read & Write
		std::ostream& write (std::ostream& os) const;
};


