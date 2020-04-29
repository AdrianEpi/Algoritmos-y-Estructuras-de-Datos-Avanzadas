/*===================================================================================
=====================================================================================
	=                                                                              =
	=            Proyecto:      Práctica 5 Implementación de Métodos de Ordenación =
	=            Archivo:       BubbleSortMethod.hpp                               =
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
#include "BaseSortMethod.hpp"

/*------------------------------------------------*/
template <class T>
class BubbleSortMethod : public BaseSortMethod<T> {

	public:
		// Builder & Destroyer
		BubbleSortMethod ();
		virtual ~BubbleSortMethod ();

		// Functions
		void sort (std::vector<T>& vector, int size);
};


/**
 * @brief      Constructs a new instance.
 * 
 * @tparam     T     The data type
 */
template <class T>
BubbleSortMethod<T>::BubbleSortMethod () {
}

/**
 * @brief      Destroys the object.
 * 
 * @tparam     T     The data type
 */
template <class T>
BubbleSortMethod<T>::~BubbleSortMethod () {
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
void BubbleSortMethod<T>::sort (std::vector<T>& vector, int size) {
	T temp;
	int aux;
	for (int i = 1; i < size; i++) {
		for (int j = size - 1; j >= 1; j--) {
			if (BaseSortMethod<T>::get_StatisticMode() == false) {
				std::cin.get();
				std::cout << std::endl << "pos = (" << j << ", " << j - 1 << ") ";
				for (int k = 0; k < size; k++) {
					std::cout << " " << vector[k];
				}
				std::cout << std::endl;
			}
			BaseSortMethod<T>::incrementateCounter();
			if (vector[j] < vector [j - 1]) {
				// Swap
				temp = vector[j - 1];
				vector[j - 1] = vector[j];
				vector[j] = temp;

				if (BaseSortMethod<T>::get_StatisticMode() == false) {
					std::cout << "Swap: ";
					for (int k = 0; k < size; k++) {
						std::cout << " " << vector[k];
					}
				}
			}
		}
	}
}