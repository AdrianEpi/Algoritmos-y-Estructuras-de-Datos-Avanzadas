/*===================================================================================
=====================================================================================
	=                                                                              =
	=            Proyecto:      Práctica 2 El juego de la vida                     =
	=            Archivo:       tablero.hpp                                        =
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

#include <vector>
#include <cassert>

/*------------------------------------------------*/

/*----------  DECLARACION DE FUNCIONES  ----------*/

#pragma once
#include "celula.hpp"


/*------------------------------------------------*/

class Celula;

class Tablero
{
	private:
		// Attribs
		Celula** malla_;
		unsigned turnos_total_;
		unsigned turno_actual_;
		unsigned columnas_;
		unsigned filas_;
		int cambianEstado;

	public:
		// Builders & Destroyer
		Tablero ();
		Tablero (int N, int M, int turnos);
		~Tablero ();

		// Getters & Setters
		Celula** get_Malla (void) const;
		unsigned get_TurnosTotal (void);
		unsigned get_TurnoActual (void);
		unsigned get_Columnas (void) const;
		unsigned get_Filas (void);

		void set_Malla (Celula** malla);
		void set_TurnosTotal (int turno);
		void set_TurnoActual (int turno);
		void set_Columnas (int columna);
		void set_Filas (int filas);		

		// Functions
		void actualizar (int estado, int i, int j);
		void crearCelulasInicio (void);
		void inicializar (int N, int M, int turnos);

		void juegoDeLaVida (void);
		void siguienteTurno (void);

		// Write
		void write (void);
};