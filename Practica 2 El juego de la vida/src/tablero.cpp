/*
* @Author: Adrián Epifanio
* @Date:   2020-03-02 08:56:36
* @Last Modified by:   Adrián Epifanio
* @Last Modified time: 2020-03-03 17:16:59
*/
#include "../include/tablero.hpp"

/**
 * @brief      Constructs a new instance.
 *
 * @param[in]  N       Thw rows
 * @param[in]  M       The columns
 * @param[in]  turnos  The turnos
 */
Tablero::Tablero(int N, int M, int turnos)
{
	assert(N > 2 && M > 2);
	inicializar(N+2, M+2, turnos);
}


/**
 * @brief      Gets the malla.
 *
 * @return     The malla.
 */
std::vector<std::vector<Celula>> Tablero::get_Malla(void)
{
	return malla_;
}

/**
 * @brief      Gets the turnos total.
 *
 * @return     The turnos total.
 */
unsigned Tablero::get_TurnosTotal(void)
{
	return turnos_total_;
}

/**
 * @brief      Gets the turno actual.
 *
 * @return     The turno actual.
 */
unsigned Tablero::get_TurnoActual(void)
{
	return turno_actual_;
}

/**
 * @brief      Gets the columnas.
 *
 * @return     The columnas.
 */
unsigned Tablero::get_Columnas(void)
{
	return columnas_;
}

/**
 * @brief      Gets the filas.
 *
 * @return     The filas.
 */
unsigned Tablero::get_Filas(void)
{
	return filas_;
}

/**
 * @brief      Sets the malla.
 *
 * @param[in]  malla  The malla
 */
void Tablero::set_Malla(std::vector<std::vector<Celula>> malla)
{
	malla_ = malla;
}

/**
 * @brief      Sets the turnos total.
 *
 * @param[in]  turno  The turno
 */
void Tablero::set_TurnosTotal(int turno)
{
	turnos_total_ = turno;
}

/**
 * @brief      Sets the turno actual.
 *
 * @param[in]  turno  The turno
 */
void Tablero::set_TurnoActual(int turno)
{
	turno_actual_ = turno;
}

/**
 * @brief      Sets the columnas.
 *
 * @param[in]  columna  The columna
 */
void Tablero::set_Columnas(int columna)
{
	columnas_ = columna;
}

/**
 * @brief      Sets the filas.
 *
 * @param[in]  filas  The filas
 */
void Tablero::set_Filas(int filas)
{
	filas_ = filas;
}

/**
 * @brief      Reserva memoria e nicializa el tablero a 0
 *
 * @param[in]  N       The rows
 * @param[in]  M       The columns
 * @param[in]  turnos  The turnos
 */
void Tablero::inicializar(int N, int M, int turnos)
{
	set_Columnas(M);
	set_Filas(N);
	malla_.resize(get_Filas());
	for(int i = 0; i < malla_.size(); i++)
		malla_[i].resize(get_Columnas());


	for(int i = 0; i < get_Filas(); i++)
		for(int j = 0; j < get_Columnas(); j++)
		{
			malla_[i][j].set_J(j);
			malla_[i][j].set_I(i);
			malla_[i][j].set_Estado(0);

		}

	set_TurnoActual(0);
	set_TurnosTotal(turnos);
}