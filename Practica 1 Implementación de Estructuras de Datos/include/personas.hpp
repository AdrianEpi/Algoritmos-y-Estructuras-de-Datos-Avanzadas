//#include "vector_t.hpp"
class Persona
{
	public:
		std::string name_;
		//Vector_t<Persona>* hijos_;
		int edad_;

	public:
		Persona(){};
		~Persona(){};
		std::ostream& write(std::ostream& cout)
		{
				cout << "Nombre: " << name_ << std::endl;
				cout << "Edad: " << edad_ << std::endl;
		}
};
