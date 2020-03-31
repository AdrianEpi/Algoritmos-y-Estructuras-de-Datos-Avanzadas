/*===================================================================================
=====================================================================================
	=                                                                              =
	=            Proyecto:      Práctica 4 Implementación de Búsqueda Tabla Hash   =
	=            Archivo:       table.hpp                                          =
	=            Autor:         Adrián Epifanio Rodríguez Hernández                =
	=            Fecha:         30/03/2020                                         =
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
* @Date:   2020-03-30 14:20:39
* @Last Modified by:   Adrián Epifanio
* @Last Modified time: 2020-03-31 11:13:43
*/
/*----------  DECLARACION DE FUNCIONES  ----------*/

#include "../include/table.hpp"

/*------------------------------------------------*/


/**
 * @brief      Constructs a new instance.
 *
 * @tparam     T     { description }
 */
template <class T>
Table<T>::Table () {

}

/**
 * @brief      Constructs a new instance.
 *
 * @param[in]  cellNumber           The cell number
 * @param[in]  blockNumber          The block number
 * @param[in]  explorationSelector  The exploration selector
 *
 * @tparam     T                    { description }
 */
template <class T>
Table<T>::Table (int cellNumber, int blockNumber, int explorationSelector) {

}

/**
 * @brief      Destroys the object.
 *
 * @tparam     T     { description }
 */
template <class T>
Table<T>::~Table () {

}

/**
 * @brief      Gets the cell number.
 *
 * @tparam     T     { description }
 *
 * @return     The cell number.
 */
template <class T>
int Table<T>::get_CellNumber (void) const {
	return cellNumber_;
}

/**
 * @brief      Gets the cells.
 *
 * @tparam     T     { description }
 *
 * @return     The cells.
 */
template <class T>
std::vector<Cell<T>> Table<T>::get_Cells (void) const {
	return cells_;
}

/**
 * @brief      Gets the dispersion.
 *
 * @tparam     T     { description }
 *
 * @return     The dispersion.
 */
template <class T>
DispersionBase<T>* Table<T>::get_Dispersion (void) const {
	return fDispersion_;
}

/**
 * @brief      Gets the exploration.
 *
 * @tparam     T     { description }
 *
 * @return     The exploration.
 */
template <class T>
ExplorationBase<T>* Table<T>::get_Exploration (void) const {
	return fExploration_;
}

/**
 * @brief      Sets the cell number.
 *
 * @param[in]  number  The number
 *
 * @tparam     T       { description }
 */
template <class T>
void Table<T>::set_CellNumber (int number) {
	cellNumber_ = number;
}

/**
 * @brief      Sets the cells.
 *
 * @param[in]  cell  The cell
 *
 * @tparam     T     { description }
 */
template <class T>
void Table<T>::set_Cells (std::vector<Cell<T>> cell) {
	cells_ = cell;
}

/**
 * @brief      Sets the dispersion.
 *
 * @param      dispersion  The dispersion
 *
 * @tparam     T           { description }
 */
template <class T>
void Table<T>::set_Dispersion (DispersionBase<T>* dispersion) {
	fDispersion_ = dispersion;
}

/**
 * @brief      Sets the exploracion.
 *
 * @param      exploration  The exploration
 *
 * @tparam     T            { description }
 */
template <class T>
void Table<T>::set_Exploracion (ExplorationBase<T>* exploration) {
	fExploration_ = exploration;
}

template <class T>
bool Table<T>::insertData (T& data) const {

}

template <class T>
bool Table<T>::searchData (T& data) const {

}

template <class T>
std::ostream Table<T>::write (std::ostream os) const {

}
