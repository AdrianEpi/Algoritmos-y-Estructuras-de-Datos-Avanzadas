#include "../include/vector_t.hpp"
#include "../include/stack_t.hpp"
#include "../include/tail_t.hpp"
#include "../include/personas.hpp"

int main()
{
	/*Vector_t<int> v1(5), v2(5);
	v1.resize(10);
	v2.resize(10);
	v1[0] = 3;
	v2[1] = 3;
	v2[6] = 1;	
	v1 = v1 + v2;
	v1.write(std::cout);*/
	Vector_t<Persona> persona;

	Persona pedro, manuel, raquel;
	pedro.name_ = "Pedro";
	pedro.edad_ = 0;
	manuel.name_ = "Manuel";
	manuel.edad_ = 2;
	raquel.name_ = "Raquel";
	raquel.edad_ = 5;
	persona.resize(3);
	persona[0] = pedro;
	persona[1] = manuel;
	persona[2] = raquel;

	std::cout << persona.get_size();
		for(int i = 0; i < persona.get_size(); i++)
			persona[i].write(std::cout);
}