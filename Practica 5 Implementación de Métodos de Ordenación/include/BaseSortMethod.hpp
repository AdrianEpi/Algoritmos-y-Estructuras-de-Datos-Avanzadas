/*===================================================================================
=====================================================================================
	=                                                                              =
	=            Proyecto:      Práctica 5 Implementación de Métodos de Ordenación =
	=            Archivo:       BaseSortMethod.hpp                                 =
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
class BaseSortMethod {

	private:
		Counter counter_;
		bool statisticMode_;

	public:
		// Builder & Destroyer
		BaseSortMethod ();
		virtual ~BaseSortMethod ();

		// Getter & Setter 
		Counter get_Counter (void) const;
		bool get_StatisticMode (void) const;

		void set_Counter (Counter counter);
		void set_StatisticMode (bool mode);

		// Functions
		virtual void sort (std::vector<T>& vector, int size) = 0;
};


/**
 * @brief      Constructs a new instance.
 * 
 * @tparam     T     The data type
 */
template <class T>
BaseSortMethod<T>::BaseSortMethod () {
	//std::cout << "Created Correctly";
}

/**
 * @brief      Destroys the object.
 * 
 * @tparam     T     The data type
 */
template <class T>
BaseSortMethod<T>::~BaseSortMethod () {
}

/**
 * @brief      Gets the counter.
 *
 * @tparam     T     The data type
 *
 * @return     The counter.
 */
template <class T>
Counter BaseSortMethod<T>::get_Counter (void) const {
	return counter_;
}

/**
 * @brief      Gets the statistic mode.
 *
 * @tparam     T     The data type
 *
 * @return     The statistic mode.
 */
template <class T>
bool BaseSortMethod<T>::get_StatisticMode (void) const {
	return statisticMode_;
}

/**
 * @brief      Sets the counter.
 *
 * @param[in]  counter  The counter
 *
 * @tparam     T        The data type
 */
template <class T>
void BaseSortMethod<T>::set_Counter (Counter counter) {
	counter_ = counter;
}

/**
 * @brief      Sets the statistic mode.
 *
 * @param[in]  mode  The mode
 *
 * @tparam     T     The data type
 */
template <class T>
void BaseSortMethod<T>::set_StatisticMode (bool mode) {
	statisticMode_ = mode;
}
/**
 * @brief      Sort Method base
 *
 * @param[in]  vector  The vector
 * @param[in]  size    The size
 *
 * @tparam     T       The data type
 */
template <class T>
void BaseSortMethod<T>::sort (std::vector<T>& vector, int size) {
}