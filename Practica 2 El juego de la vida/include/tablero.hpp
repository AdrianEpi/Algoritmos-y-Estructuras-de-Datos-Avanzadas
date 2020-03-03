
#include <vector>
#include <cassert>
#include "celula.hpp"

class Tablero
{
	private:
		std::vector<std::vector<Celula>> malla_;
		unsigned turnos_total_;
		unsigned turno_actual_;
		unsigned columnas_;
		unsigned filas_;

	public:
		Tablero(){};
		Tablero(int N, int M, int turnos);
		~Tablero(){};

		std::vector<std::vector<Celula>> get_Malla(void);
		unsigned get_TurnosTotal(void);
		unsigned get_TurnoActual(void);
		unsigned get_Columnas(void);
		unsigned get_Filas(void);

		void set_Malla(std::vector<std::vector<Celula>> malla);
		void set_TurnosTotal(int turno);
		void set_TurnoActual(int turno);
		void set_Columnas(int columna);
		void set_Filas(int filas);		

		void inicializar(int N, int M, int turnos);



};