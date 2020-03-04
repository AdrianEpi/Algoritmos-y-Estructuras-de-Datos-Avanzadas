
#include <iostream>

class Celula 
{
	
	private:
		//enum estado_{muerta = 0, viva = 1};
		int estado_;
		std::pair<int, int> posicion_; //(i, j)


	public:
		Celula(){};
		Celula(int i, int j);
		~Celula(){};

		int get_Estado(void) const;
		std::pair<int, int> get_Posicion(void);

		void set_Estado(int estado);
		void set_Posicion(std::pair<int, int> pos);
		void set_Posicion(int i, int j);

		int actualizarEstado(void);
		//int contarVecinas(const Tablero&);

		friend std::ostream& operator<<(std::ostream& cout, const Celula cel);
		Celula operator=(int estado);
};