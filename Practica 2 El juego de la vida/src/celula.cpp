/*
* @Author: Adrián Epifanio
* @Date:   2020-03-02 08:56:45
* @Last Modified by:   Adrián Epifanio
* @Last Modified time: 2020-03-03 17:16:30
*/
#include "../include/celula.hpp"



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
 * @brief      Gets i.
 *
 * @return     I.
 */
int Celula::get_I(void)
{
	return i_;
}

/**
 * @brief      Gets the j.
 *
 * @return     The j.
 */
int Celula::get_J(void)
{
	return j_;
}

/**
 * @brief      Gets the siguiente estado.
 *
 * @return     The siguiente estado.
 */
int Celula::get_SiguienteEstado(void)
{
	return siguiente_estado_;
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
 * @brief      Sets i.
 *
 * @param[in]  i     The new value
 */
void Celula::set_I(int i)
{
	i_ = i;
}

/**
 * @brief      Sets the j.
 *
 * @param[in]  j     The new value
 */
void Celula::set_J(int j)
{
	j_ = j;
}

/**
 * @brief      Sets the siguiente estado.
 *
 * @param[in]  siguiente_estado  The siguiente estado
 */
void Celula::set_SiguienteEstado(int siguiente_estado)
{
	siguiente_estado_ = siguiente_estado;
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
}