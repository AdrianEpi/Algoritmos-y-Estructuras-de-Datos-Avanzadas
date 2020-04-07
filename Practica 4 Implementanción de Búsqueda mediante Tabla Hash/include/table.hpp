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
/*----------  DECLARACION DE LIBRERIAS  ----------*/

#include <iostream>
#include <vector>
#include <cassert>

/*------------------------------------------------*/

/*----------  DECLARACION DE FUNCIONES  ----------*/

#pragma once
#include "cell.hpp"
#include "explorationLinear.hpp"
#include "explorationQuadratic.hpp"
#include "explorationDouble.hpp"
#include "explorationReDispersion.hpp"
#include "dispersionSum.hpp"
#include "dispersionModule.hpp"
#include "dispersionPseudoRandom.hpp"
#include "DNI.hpp"

/*------------------------------------------------*/

template <class T>
class Table {

	private:
		unsigned cellNum_;
		Cell<T>** cell_;
		ExplorationBase<T>* fExploration_;
		DispersionBase<T>* fDispersion_;
		
	public:
		// Builder & Destroyer
		Table (unsigned cellNum, unsigned blockNum, int explorationSelector, int dispersionSelector);
		~Table ();
		
		// Getters & Setters
		int get_CellNumber (void) const;
		DispersionBase<T>* get_Dispersion (void) const;
		ExplorationBase<T>* get_Exploration (void) const;
		
		void set_CellNumber (int number);
		void set_Dispersion (DispersionBase<T>* dispersion);
		void set_Exploracion (ExplorationBase<T>* exploration);

		// Functions
		bool insert (T& data) const;
		bool search (T& data) const;		
		bool insert (T& data, int& counter) const; // For counting
		bool search (T& data, int& counter) const; // For counting
		
		// Write
		void write (void) const;
};

/**
 * @brief      Constructs a new instance.
 *
 * @param[in]  cellNum              The cell number
 * @param[in]  blockNum	            The block number
 * @param[in]  explorationSelector  The exploration selector
 * @param[in]  dispersionSelector   The dispersion selector
 *
 * @tparam     T                    The data type
 */
template <class T>
Table<T>::Table (unsigned cellNum, unsigned blockNum, int explorationSelector, int dispersionSelector) {
	cellNum_ = cellNum;
	cell_ = new Cell<T>* [cellNum];
	for (int i = 0;i<cellNum_;i++)
		cell_[i] = new Cell<T>(blockNum);

	switch (explorationSelector) {
		case 1:
			fExploration_ = new ExplorationLinear<T>();
			break;
		
		case 2:
			fExploration_ = new ExplorationQuadratic<T>();
			break;
		
		case 3:
			fExploration_ = new ExplorationDouble<T>();
			break;
		
		case 4:
			fExploration_ = new ExplorationReDispersion<T>();
			break;
		
		default:
			break;
	}
	switch (dispersionSelector) {
		case 1:
			fDispersion_ = new DispersionModule<T>();
			break;
		
		case 2:
			fDispersion_ = new DispersionSum<T>();
			break;
		
		case 3:
			fDispersion_ = new DispersionPseudoRandom<T>();
			break;
		
		default:
			break;
	}
}

/**
 * @brief      Destroys the object.
 *
 * @tparam     T     The data type
 */
template <class T>
Table<T>::~Table () {
	if (cell_ != NULL) {
		for (int i = 0; i < cellNum_; i++) {
			if (cell_[i] != NULL) {
				delete cell_[i];
				cell_[i] = NULL;
			}
		}
		delete [] cell_;
	}
}

/**
 * @brief      Gets the cell number.
 *
 * @tparam     T     The data type
 *
 * @return     The cell number.
 */
template <class T>
int Table<T>::get_CellNumber (void) const {
	return cellNum_;
}

/**
 * @brief      Gets the dispersion.
 *
 * @tparam     T     The data type
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
 * @tparam     T     The data type
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
 * @tparam     T       The data type
 */
template <class T>
void Table<T>::set_CellNumber (int number) {
	cellNum_ = number;
}

/**
 * @brief      Sets the dispersion.
 *
 * @param      dispersion  The dispersion
 *
 * @tparam     T           The data type
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
 * @tparam     T            The data type
 */
template <class T>
void Table<T>::set_Exploracion (ExplorationBase<T>* exploration) {
	fExploration_ = exploration;
}


/**
 * @brief      Inserts the data
 *
 * @param      data  The data
 *
 * @tparam     T     The data type
 *
 * @return     true if it has been inserted, false otherwise
 */
template <class T>
bool Table<T>::insert (T& data) const {
	bool inserted = false;
	int i = 0;
	while ((inserted == false) && (i < cellNum_)) {
		inserted = cell_[fExploration_ -> explorate(fDispersion_ -> disperse(data, cellNum_), i, cellNum_)] -> insert(data);
		if (inserted == false) {
			//std::cout << std::endl << "Colision detected with element: ";
			//data.write(std::cout);
			i++;
		}
	}
	if (inserted)
		return true;
	else
	  return false;
}

/**
 * @brief      Search the data
 *
 * @param      data  The data
 *
 * @tparam     T     The data type
 *
 * @return     true if it has been found, false otherwise
 */
template <class T>
bool Table<T>::search (T& data) const
{
	bool find = false;
	bool isFull = false;
	int i = 0;
	while ((find == false) && (i < cellNum_) && (isFull == false)) {
		find = cell_[fExploration_ -> explorate(fDispersion_ -> disperse(data, cellNum_), i, cellNum_)] -> search(data);
		isFull = (cell_[fExploration_ -> explorate(fDispersion_ -> disperse(data, cellNum_), i, cellNum_)] -> isFull());
		if (find == false)
			i++;
	}
	return find;
}

/**
 * @brief      Inserts the data
 *
 * @param      data     The data
 * @param      counter  The counter
 *
 * @tparam     T        The data type
 *
 * @return     true if it has been inserted, false otherwise
 */
template <class T>
bool Table<T>::insert (T& data, int& counter) const {
	bool inserted = false;
	int i = 0;
	while ((inserted == false) && (i < cellNum_)) {
		inserted = cell_[fExploration_ -> explorate(fDispersion_ -> disperse(data, cellNum_), i, cellNum_)] -> insert(data);
		if (inserted == false) {
			std::cout << std::endl << "Colision detected with element: ";
			data.write(std::cout);
			i++;
		}
	}
	counter = i;
	if (inserted)
		return true;
	else
	  return false;
}

/**
 * @brief      Search the data
 *
 * @param      data     The data
 * @param      counter  The counter
 *
 * @tparam     T        The data type
 *
 * @return     true if it has been found, false otherwise
 */
template <class T>
bool Table<T>::search (T& data, int& counter) const {
	bool find = false;
	bool isFull = false;
	int i = 0;
	while ((find == false) && (i < cellNum_) && (isFull == false)) {
		find = cell_[fExploration_ -> explorate(fDispersion_ -> disperse(data, cellNum_), i, cellNum_)] -> search(data);
		isFull = (cell_[fExploration_ -> explorate(fDispersion_ -> disperse(data, cellNum_), i, cellNum_)] -> isFull());
		if (find == false)
			i++;
	}
	counter = i;
	return find;
}

/**
 * @brief      Prints on screen the table
 *
 * @tparam     T     The data type
 */
template <class T>
void Table<T>::write (void) const {
	for (int i = 0; i < cellNum_; i++) {
		if (i < 10)
			std::cout << "| " << i << "|";
		else
			std::cout << "|" << i << "|";
		cell_[i] -> write();
		std::cout << std::endl;
	}
}