/*
* @Author: Adrián Epifanio
* @Date:   2020-03-02 08:56:45
* @Last Modified by:   Adrián Epifanio
* @Last Modified time: 2020-03-06 17:56:59
*/
#include "../include/celula.hpp"
#include "../include/tablero.hpp"


/**
 * @brief      Constructs a new instance.
 *
 * @param[in]  i     position i
 * @param[in]  j     position j
 */
Celula::Celula(int i, int j)
{
	set_Posicion(i, j);
	set_Estado(0);
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
 * @brief      Gets the vecinas vivas.
 *
 * @return     The vecinas vivas.
 */
int Celula::get_VecinasVivas(void)
{
	return num_vecinas_vivas_;
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
 * @brief      Sets the vecinas vivas.
 *
 * @param[in]  num   The new value
 */
void Celula::set_VecinasVivas(int num)
{
	num_vecinas_vivas_ = num;
}

/**
 * @brief      Actualiza el estado de la célula a viva o muerta
 *
 * @return     Nuevo estado de la célula
 */
int Celula::actualizarEstado(void) 
{
	if(get_Estado() == 0)
	{
		if(get_VecinasVivas() == 3)
			set_Estado(1);
	}
	else
	{
		if(get_VecinasVivas() == 2 || get_VecinasVivas() == 3)
			set_Estado(1);
		else
			set_Estado(0);
	}
	return get_Estado();
}

/**
 * @brief      Cuenta el número de vecinas vivas de una célula
 *
 * @param[in]  board  The board
 *
 * @return     numero de vecinas vivas
 */
int Celula::contarVecinas(const Tablero& board)
{
	int counter = 0;
	for(int i = get_Posicion().first - 1; i <= get_Posicion().first + 1; i++)
		for(int j = get_Posicion().second - 1; j <= get_Posicion().second + 1; j++)
			if(i != get_Posicion().first || j != get_Posicion().second)
				if(board.get_Malla()[i * board.get_Columnas() + j]->get_Estado() == 1)
					counter++;

 	set_VecinasVivas(counter);
	return get_VecinasVivas();
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
std::ostream& operator<<(std::ostream& cout, const Celula cel)
{
	if(cel.get_Estado() == 0)
		cout << "| ";
	else
		cout << "|X";

	return cout;
}