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
/*----------  DECLARACION DE LIBRERIAS  ----------*/

#include <iostream>
#include <iomanip>

/*------------------------------------------------*/

/*----------  DECLARACION DE FUNCIONES  ----------*/

#pragma once

/*------------------------------------------------*/

template <class T>
class Cell {

	private:
		unsigned blockNumber_;
		T* block_;
		
	public:
		// Builders & Destroyer
		Cell ();
		Cell (unsigned blockNumber);
		~Cell ();
		
		// Getters & Setters
		int get_BlockNumber (void) const;
		T get_Block (void) const;

		void set_BlockNumber (int blockNumber);
		void set_Block (T block);

		// Functions
		bool search (T data);
		bool insert (T data);		
		bool isFull (void) const;		
		
		// Read & Write
		void write (void) const;
};


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
Cell<T>::Cell (unsigned blockNumber) {
	set_BlockNumber(blockNumber);
	block_ = new T[blockNumber_];
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
	blockNumber_=0;
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
	for (int i = 0; i < blockNumber_; i++)
		if (block_[i] == data)
			return true;
	
	return false;
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
bool Cell<T>::insert (T data) {
	for (int i = 0; i < get_BlockNumber(); i++) {
		if (block_[i] == 0) {
			block_[i] = data;
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
bool Cell<T>::isFull () const {
  for (int i = 0;i < blockNumber_; i++)
    if (block_[i] == 0)
      return false;
  
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
void Cell<T>::write () const {
	for (int i = 0; i < blockNumber_; i++) {
		std::cout << std::setw(12);
		block_[i].write(std::cout);
	}
}