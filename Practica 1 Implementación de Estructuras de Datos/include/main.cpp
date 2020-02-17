
#include "vector_t.hpp"

int main()
{
	Vector_t<int> v1(5), v2(5);
	Vector_t<char> v3(5), v4(5);
	//v1.resize(10);
	//v2.resize(5);
	v1[0] = 3;
	v2[1] = 3;
	v3[4] = 'a';
	v4[4] = 'b';	
	v4 = v4 + v3;
	v4.write(std::cout);
}
