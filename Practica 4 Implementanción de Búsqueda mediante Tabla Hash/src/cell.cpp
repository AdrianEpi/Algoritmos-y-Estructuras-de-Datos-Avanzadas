/*===================================================================================
=====================================================================================
	=                                                                              =
	=            Proyecto:      Práctica 4 Implementación de Búsqueda Tabla Hash   =
	=            Archivo:       cell.hpp                                           =
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
* @Date:   2020-03-30 14:20:48
* @Last Modified by:   Adrián Epifanio
* @Last Modified time: 2020-03-30 19:18:51
*/
/*----------  DECLARACION DE FUNCIONES  ----------*/

#include "../include/cell.hpp"

/*------------------------------------------------*/

/**
 * @brief      Constructs a new instance.
 *  
 * @tparam     T     The data type.
 * 
 */
template <class T>
Cell<T>::Cell () {
	set_Block(NULL);
	set_BlockNumber(0);
	set_Usability(0);
}

/**
 * @brief      Constructs a new instance.
 *
 * @param[in]  blockNumber  The block number
 * 
 * @tparam     T     The data type.
 * 
 */
template <class T>
Cell<T>::Cell (int blockNumber) {
	set_BlockNumber(blockNumber);
	block_ = new T[blockNumber_];
	set_Usability(0);
}

/**
 * @brief      Destroys the object.
 *   
 * @tparam     T     The data type.
 * 
 */
template <class T>
Cell<T>::~Cell () {
	if (block_ != NULL)
		delete [] block_;

	set_BlockNumber(0);
}


/**
 * @brief      Gets the block number.
 *
 * @tparam     T     The data type.
 *
 * @return     The block number.
 */
template <class T>
int Cell<T>::get_BlockNumber (void) const {
	return blockNumber_;
}

/**
 * @brief      Gets the block.
 *
 * @tparam     T     The data type.
 *
 * @return     The block.
 */
template <class T>
T Cell<T>::get_Block (void) const {
	return block_;
}

/**
 * @brief      Gets the usability.
 *
 * @tparam     T     The data type.
 *
 * @return     The usability.
 */
template <class T>
int Cell<T>::get_Usability (void) const {
	return usability_;
}

/**
 * @brief      Sets the block number.
 *
 * @param[in]  block  The block
 *
 * @tparam     T      The data type.
 */
template <class T>
void Cell<T>::set_BlockNumber (int blockNumber) {
	blockNumber_ = blockNumber; 
}

/**
 * @brief      Sets the block.
 *
 * @param[in]  block  The block
 *
 * @tparam     T      The data type.
 */
template <class T>
void Cell<T>::set_Block (T block) {
	block_ = block;
}

/**
 * @brief      Sets the usability.
 *
 * @param[in]  usability  The usability
 *
 * @tparam     T          The data type.
 */
template <class T>
void Cell<T>::set_Usability (int usability) {
	usability_ = usability;
}

/**
 * @brief      Inserts the data into de cell, in case it is not possible it return false
 *
 * @param[in]  data  The data
 *
 * @tparam     T     The data type.
 *
 * @return     True if it finds an empty place where store it and false in other case
 */
template <class T>
bool Cell<T>::insertData (T data) {
	for (int i = 0; i < get_BlockNumber(); i++) {
		if (block_[i] == 0) {
			block_[i] = data;
			return true;
		}
	}
	return false;
}

/**
 * @brief      Searches for the first match.
 *
 * @param[in]  data  The data
 *
 * @tparam     T     The data type.
 *
 * @return     True if found, False otherwise.
 */
template <class T>
bool Cell<T>::search (T data) {
	for (int i = 0; i < get_BlockNumber(); i++) {
		if (block_[i] == data) {
			return true;
		}
	}
	return false;
}

/**
 * @brief      Determines if full.
 *
 * @tparam     T     The data type.
 *
 * @return     True if full, False otherwise.
 */
template <class T>
bool Cell<T>::isFull (void) const {
	for (int i = 0; i < get_BlockNumber(); i++) {
		if (block_[i] == 0) {
			return false;
		}
	}
	return true;
}

/**
 * @brief      Prints the cell on screen
 *
 * @param[in]  os    The output stream.
 *
 * @tparam     T     The data type.
 *
 * @return     The output stream
 */
template <class T>
std::ostream Cell<T>::write (std::ostream os) const {
	for (int i = 0; i < get_BlockNumber(); i++) {
		os << block_[i].write(os) << "\t";
	}
}
