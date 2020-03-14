/*===================================================================================
=====================================================================================
	=                                                                              =
	=            Proyecto:      Práctica 2 El juego de la vida                     =
	=            Archivo:       tablero.cpp                                        =
	=            Autor:         Adrián Epifanio Rodríguez Hernández                =
	=            Fecha:         02/03/2020                                         =
	=            Asignatura:    Algoritmos y Estructuras de Datos Avazados         =
	=            Lenguaje:      C++                                                =
	=            Correo:        alu0101158280@ull.edu.es                           =
	=            Lugar:         Universidad De La Laguna                           =
	=                           Escuela Superior de Ingeniería y Tecnología        =
	=                                                                              =
=====================================================================================
===================================================================================*/
/*
* @Author: Adrián Epifanio
* @Date:   2020-03-02 08:56:36
* @Last Modified by:   Adrián Epifanio
* @Last Modified time: 2020-03-14 09:10:49
*/
/*----------  DECLARACION DE FUNCIONES  ----------*/

#include "../include/tablero.hpp"

/*------------------------------------------------*/

/**
 * @brief      Constructs a new instance.
 *
 * @param[in]  N       Thw rows
 * @param[in]  M       The columns
 * @param[in]  turnos  The turnos
 */
Tablero::Tablero(int N, int M, int turnos) {
	assert(N > 2 && M > 2);
	assert(turnos >= 1);
	inicializar(N, M, turnos);
	crearCelulasInicio();
	juegoDeLaVida();
	cambianEstado = 0;
}


/**
 * @brief      Gets the malla.
 *
 * @return     The malla.
 */
Celula** Tablero::get_Malla(void) const {
	return malla_;
}

/**
 * @brief      Gets the turnos total.
 *
 * @return     The turnos total.
 */
unsigned Tablero::get_TurnosTotal(void) {
	return turnos_total_;
}

/**
 * @brief      Gets the turno actual.
 *
 * @return     The turno actual.
 */
unsigned Tablero::get_TurnoActual(void) {
	return turno_actual_;
}

/**
 * @brief      Gets the columnas.
 *
 * @return     The columnas.
 */
unsigned Tablero::get_Columnas(void) const {
	return columnas_;
}

/**
 * @brief      Gets the filas.
 *
 * @return     The filas.
 */
unsigned Tablero::get_Filas(void) {
	return filas_;
}

/**
 * @brief      Sets the malla.
 *
 * @param[in]  malla  The malla
 */
void Tablero::set_Malla(Celula** malla) {
	malla_ = malla;
}

/**
 * @brief      Sets the turnos total.
 *
 * @param[in]  turno  The turno
 */
void Tablero::set_TurnosTotal(int turno) {
	turnos_total_ = turno;
}

/**
 * @brief      Sets the turno actual.
 *
 * @param[in]  turno  The turno
 */
void Tablero::set_TurnoActual(int turno) {
	turno_actual_ = turno;
}

/**
 * @brief      Sets the columnas.
 *
 * @param[in]  columna  The columna
 */
void Tablero::set_Columnas(int columna) {
	columnas_ = columna;
}

/**
 * @brief      Sets the filas.
 *
 * @param[in]  filas  The filas
 */
void Tablero::set_Filas(int filas) {
	filas_ = filas;
}

/**
 * @brief      Pregunta al usuario con cuantas celulas vivas quiere empezar y sus respectivas posiciones
 */
void Tablero::crearCelulasInicio(void) {
	int counter = 0;
	std::cout << "¿Con cuántas células vivas quiere empezar?";
	std::cin >> counter;
	std::cout << "Indique las posiciones (i , j) de la célula: " << std::endl;
	for(;counter > 0; counter--) {
		int pos_i= 0, pos_j=0;
		std::cout << "[" << counter << "]: ";
		std::cin >> pos_i >> pos_j;
		malla_[pos_i * get_Columnas() + pos_j]->set_Estado(1);
	}
}

/**
 * @brief      Reserva memoria e nicializa el tablero a 0
 *
 * @param[in]  N       The rows
 * @param[in]  M       The columns
 * @param[in]  turnos  The turnos
 */
void Tablero::inicializar(int N, int M, int turnos) {
	set_Columnas(M+2);
	set_Filas(N+2);
	malla_ = new Celula*[(N + 2) * (M + 2)];
	for(int i = 0; i < N + 2; i++) 
		for(int j = 0; j < M + 2; j++)
			malla_[i * (M + 2) + j] = new Celula(i, j);
	
	set_TurnoActual(0);
	set_TurnosTotal(turnos);
}


/**
 * @brief      Ejecuta el juego de la vida
 */
void Tablero::juegoDeLaVida(void) {
	set_TurnoActual(0);
	for(int i = 0; i < get_TurnosTotal(); i++) {
		std::cout << std::endl << "Turno: " << get_TurnoActual() + 1 << std::endl;
		if(i > 0)
			std::cout << "Cambian " << cambianEstado << " celulas." << std::endl;
		
		write();
		siguienteTurno();
		turno_actual_++;
	}
}

/**
 * @brief      Actualiza el tablero al siguiente turno
 */
void Tablero::siguienteTurno(void) {
	int counter = 0;
	for(int i = 1; i < get_Filas() - 1; i++)
		for(int j = 1; j < get_Columnas() - 1; j++)
			malla_[i * get_Columnas() + j] -> contarVecinas(*this);

	for(int i = 1; i < get_Filas() -1; i++)
		for(int j = 1; j < get_Columnas() -1; j++)
			if((malla_[i * get_Columnas() + j] -> actualizarEstado()) == 1)
				counter++;

	cambianEstado = counter;
}



/**
 * @brief      Writes by console the map
 */
void Tablero::write(void) {
	for(int i = 1; i < get_Filas() - 1; i++) {
		for(int j = 1; j < get_Columnas() - 1; j++)
			std::cout << *malla_[i * get_Columnas() + j] << " ";

		std::cout << std::endl;
	}
}