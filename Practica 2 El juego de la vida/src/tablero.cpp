/*
* @Author: Adrián Epifanio
* @Date:   2020-03-02 08:56:36
* @Last Modified by:   Adrián Epifanio
* @Last Modified time: 2020-03-04 17:59:30
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
Celula** Tablero::get_Malla(void)
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
void Tablero::set_Malla(Celula** malla)
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
	set_Columnas(M+2);
	set_Filas(N+2);
	malla_ = new Celula*[(N + 2) * (M + 2)];
	for(int i = 0; i < N + 2; i++) 
		for(int j = 0; j < M + 2; j++)
			malla_[i * (M + 2) + j] = new Celula(i, j);

	/*for(int i = 0; i < N + 2; i++) 
		for(int j = 0; j < M + 2; j++)
			malla_[i][j] = 0;*/

	write();
	
	set_TurnoActual(0);
	set_TurnosTotal(turnos);
}

/**
 * @brief      Writes by console the map
 */
void Tablero::write(void)
{
	for(int i = 0; i < get_Columnas() * get_Filas(); i++)
	{
		//std::cout << *malla_[i] << " ";
		//if(malla_[i]->get_Estado() == 0)
		//	std::cout << malla_[i];
	}
}