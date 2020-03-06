#pragma once
#include <iostream>
class Tablero;
class Celula 
{
	
	private:
		//enum estado_{muerta = 0, viva = 1};
		int estado_;
		std::pair<int, int> posicion_; //(i, j)
		int num_vecinas_vivas_;


	public:
		Celula(){};
		Celula(int i, int j);
		~Celula(){};

		int get_Estado(void) const;
		std::pair<int, int> get_Posicion(void);
		int get_VecinasVivas(void);

		void set_Estado(int estado);
		void set_Posicion(std::pair<int, int> pos);
		void set_Posicion(int i, int j);
		void set_VecinasVivas(int num);

		int actualizarEstado(void);
		int contarVecinas(const Tablero& board);

		friend std::ostream& operator<<(std::ostream& cout, const Celula celuu);
		Celula operator=(int estado);
};