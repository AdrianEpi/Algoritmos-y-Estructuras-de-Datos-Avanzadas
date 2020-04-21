/*===================================================================================
=====================================================================================
	=                                                                              =
	=            Proyecto:      Práctica 5 Implementación de Métodos de Ordenación =
	=            Archivo:       InsertionMethod.hpp                                =
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
class InsertionMethod : public BaseSortMethod<T> {

	public:
		// Builder & Destroyer
		InsertionMethod ();
		virtual ~InsertionMethod ();

		// Functions
		void sort (std::vector<T>& vector, int size);
};


/**
 * @brief      Constructs a new instance.
 * 
 * @tparam     T     The data type
 */
template <class T>
InsertionMethod<T>::InsertionMethod () {
}

/**
 * @brief      Destroys the object.
 * 
 * @tparam     T     The data type
 */
template <class T>
InsertionMethod<T>::~InsertionMethod () {
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
void InsertionMethod<T>::sort (std::vector<T>& vector, int size) {
	T temp;
	int aux;
	for (int i = 1; i < size; i++) {
		temp = vector[i];
		if (get_StatisticMode() == false) {
			std::cout << std::endl << "i = " << i << " ";
			for (int j = 0; j < size; j++) {
				std::cout << vector[j] << " ";
			}
		}
		aux = i - 1;
		while (( aux >= 0) && (temp < vector[aux])) {
			vector[aux + 1] = vector[aux];
			aux--;
		}
		if (get_StatisticMode() == false) {
			std::cout << " j = " << aux + 1;
		}
		vector[aux + 1] = temp;
	}
}