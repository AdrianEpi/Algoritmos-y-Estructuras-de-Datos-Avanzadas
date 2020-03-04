/*
* @Author: Adrián Epifanio
* @Date:   2020-03-02 08:56:45
* @Last Modified by:   Adrián Epifanio
* @Last Modified time: 2020-03-04 18:02:06
*/
#include "../include/celula.hpp"


/**
 * @brief      Constructs a new instance.
 *
 * @param[in]  i     position i
 * @param[in]  j     position j
 */
Celula::Celula(int i, int j)
{
	set_Posicion(i, j);
}

/**
 * @brief      Gets the estado.
 *
 * @return     The estado.
 */
int Celula::get_Estado(void) const
{
	return estado_;
}

/**
 * @brief      Gets the posicion.
 *
 * @return     The posicion.
 */
std::pair<int, int> Celula::get_Posicion(void)
{
	return posicion_;
}

/**
 * @brief      Sets the estado.
 *
 * @param[in]  estado  The estado
 */
void Celula::set_Estado(int estado)
{
	estado_ = estado;
}

/**
 * @brief      Sets the posicion.
 *
 * @param[in]  pos   The new value
 */
void Celula::set_Posicion(std::pair<int, int> pos)
{
	posicion_ = pos;
}

/**
 * @brief      Sets the posicion.
 *
 * @param[in]  i     The new value
 * @param[in]  j     The new value
 */
void Celula::set_Posicion(int i, int j)
{
	posicion_ = std::make_pair(i, j);
}

/**
 * @brief      Assignment operator.
 *
 * @param[in]  estado  The estado
 *
 * @return     The result of the assignment
 */
Celula Celula::operator=(int estado)
{
	estado_ = estado;
	return *this;
}

/**
 * @brief      Bitwise left shift operator.
 *
 * @param      cout  The cout
 *
 * @return     The result of the bitwise left shift
 */
std::ostream& Celula::operator<<(std::ostream& cout, const Celula cel)
{
	if(cel.get_Estado() == 0)
		cout << 0;
	else
		cout << 'X';

	return cout;
}