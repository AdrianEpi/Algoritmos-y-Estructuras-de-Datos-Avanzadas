/*===================================================================================
=====================================================================================
	=                                                                              =
	=            Proyecto:      Práctica 3 El juego de la vida generalizado        =
	=            Archivo:       celula2.cpp                                        =
	=            Autor:         Adrián Epifanio Rodríguez Hernández                =
	=            Fecha:         16/03/2020                                         =
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
* @Date:   2020-03-19 09:22:27
* @Last Modified by:   Adrián Epifanio
* @Last Modified time: 2020-03-20 10:19:49
*/
#include "../include/celula2.hpp"

/**
 * @brief      Constructs a new instance.
 */
Celula2::Celula2 () {
	std::cout << std::endl << "Error, no se puede crear una Celula2 sin posición." << std::endl;
	exit(0);
}
/**
 * @brief      Constructs a new instance.
 *
 * @param[in]  i     position i
 * @param[in]  j     position j
 */
Celula2::Celula2 (int i, int j):
Celula(1, i, j) {

}

/**
 * @brief      Destroys the object.
 */
Celula2::~Celula2 () {

}

/**
 * @brief      Gets the state.
 *
 * @return     The state.
 */
int Celula2::getEstado (void) const {
	return 2;
}

/**
 * @brief      Counts the alive neighbours
 *
 * @param[in]  board  The board
 *
 * @return     The number of alive neighbours
 */
int Celula2::contarVecinas (const Tablero& board) {
	int counter = 0;
	for (int i = get_Posicion().first - 1; i <= get_Posicion().first + 1; i++)
		for (int j = get_Posicion().second - 1; j <= get_Posicion().second + 1; j++)
			if (i != get_Posicion().first || j != get_Posicion().second)
				if (board.get_Malla()[i * board.get_Columnas() + j]->getEstado() == 2)
					counter++;

 	set_VecinasVivas(counter);
	return get_VecinasVivas();
}

/**
 * @brief      Updates the state of the cell
 *
 * @return     The new state of the cell
 */
int Celula2::actualizarEstado (void) {
	if (get_VecinasVivas() == 2 || get_VecinasVivas() == 4 || get_VecinasVivas() == 5)
		return 2;
	else
		return 0;
}

/**
 * @brief      Prints on screen the cell type
 *
 * @param      os    The output stream
 *
 * @return     The output stream
 */
std::ostream& Celula2::mostrar (std::ostream& os) const {
	os << getEstado();
	return os;
}