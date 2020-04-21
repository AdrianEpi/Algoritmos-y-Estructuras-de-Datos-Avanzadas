/*===================================================================================
=====================================================================================
	=                                                                              =
	=            Proyecto:      Práctica 5 Implementación de Métodos de Ordenación =
	=            Archivo:       ShellSortMethod.hpp                                =
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
class ShellSortMethod : public BaseSortMethod<T> {

	public:
		// Builder & Destroyer
		ShellSortMethod ();
		virtual ~ShellSortMethod ();

		// Functions
		void sort (std::vector<T>& vector, int size);
};


/**
 * @brief      Constructs a new instance.
 * 
 * @tparam     T     The data type
 */
template <class T>
ShellSortMethod<T>::ShellSortMethod () {
}

/**
 * @brief      Destroys the object.
 * 
 * @tparam     T     The data type
 */
template <class T>
ShellSortMethod<T>::~ShellSortMethod () {
}

/**
 * @brief      Sort Method Shell sort
 *
 * @param[in]  vector  The vector
 * @param[in]  size    The size
 *
 * @tparam     T       The data type
 */
template <class T>
void ShellSortMethod<T>::sort (std::vector<T>& vector, int size) {
	T aux;
	int j;
	int it = 0;
	int d = size;
	while (d > 0) {
		d = d / 2;
		for (int i = d; i < size; i++) {
			aux = vector[i];
			j = i;
			it++;
			if (get_StatisticMode() == 0) {
				getchar();
				std::cout << "Iteration: " << it << std::endl;
				for (int k = 0 ; k < size; k++) {
					std::cout << vector[k] << " ";
				}
				std::cout << std::endl;
			}
			while ((j >= d) && (aux < vector[j-d])) {		
				vector[j] = vector[j-d];
				j = j - d;
			}
			vector[j] = aux;
		}
	}
}