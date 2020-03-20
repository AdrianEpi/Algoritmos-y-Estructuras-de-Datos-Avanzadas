/*===================================================================================
=====================================================================================
	=                                                                              =
	=            Proyecto:      Práctica 3 El juego de la vida generalizado        =
	=            Archivo:       celula3.hpp                                        =
	=            Autor:         Adrián Epifanio Rodríguez Hernández                =
	=            Fecha:         16/03/2020                                         =
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
#include "celula.hpp"

/*------------------------------------------------*/

class Tablero;

class Celula3 : public Celula {

	public:
		// Builders & Destroyer
		Celula3 ();
		Celula3 (int i, int j);
		~Celula3 ();

		// Getters & Setters
		int getEstado (void) const;

		// Functions
    	int contarVecinas (const Tablero& board);
    	int actualizarEstado (void); 

    	// Read & Write
    	std::ostream& mostrar (std::ostream& os) const;
};