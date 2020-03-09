#pragma once
#include <vector>
#include <cassert>
#include "celula.hpp"

class Tablero
{
	private:
		Celula** malla_;
		unsigned turnos_total_;
		unsigned turno_actual_;
		unsigned columnas_;
		unsigned filas_;
		int cambianEstado;

	public:
		Tablero(){};
		Tablero(int N, int M, int turnos);
		~Tablero(){};

		Celula** get_Malla(void) const;
		unsigned get_TurnosTotal(void);
		unsigned get_TurnoActual(void);
		unsigned get_Columnas(void) const;
		unsigned get_Filas(void);

		void set_Malla(Celula** malla);
		void set_TurnosTotal(int turno);
		void set_TurnoActual(int turno);
		void set_Columnas(int columna);
		void set_Filas(int filas);		

		void crearCelulasInicio(void);
		void inicializar(int N, int M, int turnos);

		void juegoDeLaVida(void);
		void siguienteTurno(void);

		void write(void);



};