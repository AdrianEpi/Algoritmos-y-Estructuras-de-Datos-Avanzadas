/*===================================================================================
=====================================================================================
	=                                                                              =
	=            Proyecto:      Práctica 2 El juego de la vida                     =
	=            Archivo:       celula.cpp                                         =
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
* @Date:   2020-03-02 08:56:45
* @Last Modified by:   Adrián Epifanio
* @Last Modified time: 2020-03-20 10:14:37
*/
/*----------  DECLARACION DE FUNCIONES  ----------*/

#include "../include/celula.hpp"

/*------------------------------------------------*/

/**
 * @brief      Constructs a new instance.
 */
Celula::Celula () {
	std::cout << std::endl << "Error, la célua no se puede inicializar vacía, se requiere el estado y las posiciones." << std::endl;
}

/**
 * @brief      Constructs a new instance.
 *
 * @param[in]  i     position i
 * @param[in]  j     position j
 */
Celula::Celula (int i, int j):
posicion_(0, 0) {
	set_Posicion(i, j);
	createCelula(0, i, j);	// La creamos por defecto vacía
}

/**
 * @brief      Constructs a new instance.
 *
 * @param[in]  estado  The state
 * @param[in]  i       position i
 * @param[in]  j       position j
 */
Celula::Celula (int estado, int i, int j):
posicion_(0, 0) {
	set_Posicion(i, j);
	createCelula(estado, i, j);
}

/**
 * @brief      Destroys the object.
 */
Celula::~Celula () {

}

/**
 * @brief      Gets the position.
 *
 * @return     The position.
 */
std::pair<int, int> Celula::get_Posicion (void) const {
	return posicion_;
}

/**
 * @brief      Gets the alive neighbours.
 *
 * @return     The alive neighbours.
 */
int Celula::get_VecinasVivas (void) const {
	return num_vecinas_vivas_;
}

int Celula::getEstado () const {

}

/**
 * @brief      Sets the position.
 *
 * @param[in]  pos   The new value
 */
void Celula::set_Posicion (std::pair<int, int> pos) {
	posicion_ = pos;
}

/**
 * @brief      Sets the poticion.
 *
 * @param[in]  i     The new i
 * @param[in]  j     The new j
 */
void Celula::set_Posicion (int i, int j) {
	posicion_ = std::make_pair(i, j);
}

/**
 * @brief      Sets the alive neighbours.
 *
 * @param[in]  num   The new alive neighbours
 */
void Celula::set_VecinasVivas (int num) {
	num_vecinas_vivas_ = num;
}

/**
 * @brief      Creates a cell.
 *
 * @param[in]  estado  The state
 * @param[in]  i       Position i
 * @param[in]  j       Position j
 *
 * @return     { description_of_the_return_value }
 */
Celula* Celula::createCelula (int estado, int i, int j) {
	Celula *newCelula;
	return newCelula;
}

/**
 * @brief      Count the number of neighbours alive.
 *
 * @param[in]  board  The board
 *
 * @return     The number of neighbours alive.
 */
int Celula::contarVecinas (const Tablero& board) {
	int counter = 0;
	for(int i = get_Posicion().first - 1; i <= get_Posicion().first + 1; i++)
		for(int j = get_Posicion().second - 1; j <= get_Posicion().second + 1; j++)
			if(i != get_Posicion().first || j != get_Posicion().second)
				if(board.get_Malla()[i * board.get_Columnas() + j]->getEstado() != 0)
					counter++;

 	set_VecinasVivas(counter);
	return get_VecinasVivas();
}

/**
 * @brief      Updates the state of a cell
 *
 * @return     The new cell state
 */
int Celula::actualizarEstado (void) {
  if (get_VecinasVivas() == 3)
    return 1;
  
  else if (get_VecinasVivas() == 3 || get_VecinasVivas() == 6 || get_VecinasVivas() == 8)
    return 2;
  
  else if (get_VecinasVivas() == 3 || get_VecinasVivas() == 4 || get_VecinasVivas() == 6)
    return 3;
  
  else
    return 0;

}

/**
 * @brief      Prints an empty char on screen because the cell if dead
 *
 * @param      os    output stream
 *
 * @return     The output stream
 */
std::ostream& Celula::mostrar (std::ostream& os) const {
	os << ' ';
	return os;
}