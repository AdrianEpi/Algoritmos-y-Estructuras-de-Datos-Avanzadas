/*===================================================================================
=====================================================================================
	=                                                                              =
	=            Proyecto:      Práctica 4 Implementación de Búsqueda Tabla Hash   =
	=            Archivo:       explorationDouble.hpp                              =
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

/*------------------------------------------------*/

/*----------  DECLARACION DE FUNCIONES  ----------*/

#pragma once
#include "explorationBase.hpp"

/*------------------------------------------------*/

template <class T>
class ExplorationDouble : public ExplorationBase<T> {


	public:
		// Builder & Destroyer
		ExplorationDouble();
		virtual ~ExplorationDouble();

		// Functions
		unsigned explorate(const T& data, unsigned pos, unsigned size);
		unsigned findPrime(unsigned number);

};


/**
 * @brief      Constructs a new instance.
 */
template <class T>
ExplorationDouble<T>::ExplorationDouble () {

}

/**
 * @brief      Destroys the object.
 */
template <class T>
ExplorationDouble<T>::~ExplorationDouble () {

}

/**
 * @brief      Searchs the cells to find one where store the data
 *
 * @param[in]  size  The size
 * @param[in]  pos   The position
 * @param[in]  data  The data
 *
 * @tparam     T     The data type.
 *
 * @return     The cell position
 */
template <class T>
unsigned ExplorationDouble<T>::explorate (const T& data, unsigned pos, unsigned size) {
	unsigned prime = findPrime(data.get_Code());
	int fx = prime - (data.get_Code() % prime);
	return ((data.get_Code() + pos * fx) % size);
}


/**
 * @brief      Finds a the biggest prime number.
 *
 * @param[in]  number  The number
 *
 * @tparam     T       The data type
 *
 * @return     The prime number
 */
template <class T>
unsigned ExplorationDouble<T>::findPrime(unsigned number) {
	bool prime;
	for (unsigned i = (number - 1); i > 2; i--) {
		prime = true;
		for (int j = 2; j < i; j++)
			if ((i % j) != 0)
				prime = false;
		
		if (prime == true)
			return i;
	}
}
