/*===================================================================================
=====================================================================================
	=                                                                              =
	=            Proyecto:      Práctica 5 Implementación de Métodos de Ordenación =
	=            Archivo:       SortAlgorithm.hpp                                  =
	=            Autor:         Adrián Epifanio Rodríguez Hernández                =
	=            Fecha:         21/04/2020                                         =
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

/*------------------------------------------------*/

/*----------  DECLARACION DE FUNCIONES  ----------*/

#pragma once
#include "DNI.hpp"
#include "Counter.hpp"

/*------------------------------------------------*/
template <class T>
class SortAlgorithm {

	private:
		Counter counter_;

	public:
		// Builder & Destroyer
		SortAlgorithm ();
		virtual ~SortAlgorithm ();

		// Getter & Setter 
		Counter get_Counter (void) const;

		void set_Counter (Counter counter);

		// Functions
		virtual void sort (std::vector<DNI> vector, int size) = 0;
};


/**
 * @brief      Constructs a new instance.
 * 
 * @tparam     T     The data type
 */
template <class T>
SortAlgorithm<T>::SortAlgorithm () {
	std::cout << "Created Correctly";
}

/**
 * @brief      Destroys the object.
 * 
 * @tparam     T     The data type
 */
template <class T>
SortAlgorithm<T>::~SortAlgorithm () {
}

/**
 * @brief      Gets the counter.
 *
 * @tparam     T     The data type
 *
 * @return     The counter.
 */
template <class T>
Counter SortAlgorithm<T>::get_Counter (void) const {
	return counter_;
}

/**
 * @brief      Sets the counter.
 *
 * @param[in]  counter  The counter
 *
 * @tparam     T        The data type
 */
template <class T>
void SortAlgorithm<T>::set_Counter (Counter counter) {
	counter_ = counter;
}

/**
 * @brief      Sort Algorithm base
 *
 * @param[in]  vector  The vector
 * @param[in]  size    The size
 *
 * @tparam     T       The data type
 */
template <class T>
void SortAlgorithm<T>::sort (std::vector<DNI> vector, int size) {
}