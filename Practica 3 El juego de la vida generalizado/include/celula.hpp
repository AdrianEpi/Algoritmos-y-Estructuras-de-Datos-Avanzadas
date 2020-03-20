/*===================================================================================
=====================================================================================
	=                                                                              =
	=            Proyecto:      Práctica 2 El juego de la vida                     =
	=            Archivo:       celula.hpp                                         =
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
#include "tablero.hpp"
/*------------------------------------------------*/

class Tablero;

class Celula 
{
	
	private:
		std::pair<int, int> posicion_; // (i, j)
		int num_vecinas_vivas_;


	public:
		// Builders & Destroyer
		Celula ();
		Celula (int i, int j);
		Celula (int estado, int i, int j);
		~Celula ();

		// Getters & Setters
		std::pair<int, int> get_Posicion (void) const;
		int get_VecinasVivas (void) const;
		virtual int getEstado () const;

		void set_Posicion (std::pair<int, int> pos);
		void set_Posicion (int i, int j);
		void set_VecinasVivas (int num);

		// Functions
		static Celula* createCelula (int estado, int i, int j);
		virtual int contarVecinas (const Tablero& board);
		virtual int actualizarEstado (void); // Reglas de nacimiento
		virtual std::ostream& mostrar (std::ostream&) const;
};

