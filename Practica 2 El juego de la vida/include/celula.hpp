
#include <iostream>

class Celula 
{
	
	private:
		//enum estado_{muerta = 0, viva = 1};
		int estado_;
		int i_;
		int j_;
		int siguiente_estado_;

	public:
		Celula(){};
		~Celula(){};

		int get_Estado(void) const;
		int get_I(void);
		int get_J(void);
		int get_SiguienteEstado(void);

		void set_Estado(int estado);
		void set_I(int i);
		void set_J(int j);
		void set_SiguienteEstado(int siguiente_estado);


		int actualizarEstado(void);
		//int contarVecinas(const Tablero&);

		Celula operator<<(std::ostream& cout);
		Celula operator=(int estado);
};