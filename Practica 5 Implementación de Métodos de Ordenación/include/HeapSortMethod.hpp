/*===================================================================================
=====================================================================================
	=                                                                              =
	=            Proyecto:      Práctica 5 Implementación de Métodos de Ordenación =
	=            Archivo:       HeapSortMethod.hpp                                 =
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
class HeapSortMethod : public BaseSortMethod<T> {

	public:
		// Builder & Destroyer
		HeapSortMethod ();
		virtual ~HeapSortMethod ();

		// Functions
		void sort (std::vector<T>& vector, int size);
		void order (int pos, std::vector<T>& vector,int size);
};


/**
 * @brief      Constructs a new instance.
 * 
 * @tparam     T     The data type
 */
template <class T>
HeapSortMethod<T>::HeapSortMethod () {
}

/**
 * @brief      Destroys the object.
 * 
 * @tparam     T     The data type
 */
template <class T>
HeapSortMethod<T>::~HeapSortMethod () {
}

/**
 * @brief      Sort Method Heap sort
 *
 * @param[in]  vector  The vector
 * @param[in]  size    The size
 *
 * @tparam     T       The data type
 */
template <class T>
void HeapSortMethod<T>::sort (std::vector<T>& vector, int size) {
	for (int i = (size / 2) -1; i >= 0; i--) {
		order(i, vector, size);
	}
	for (int i = size - 1; i >= 0 ; i--) {
		T aux = vector[0];
		vector[0] = vector[i];
		vector[i] = aux;
		order(0, vector, i);
	}
}

/**
 * @brief      Orders the vector
 *
 * @param[in]  pos     The position
 * @param      vector  The vector
 * @param[in]  size    The size
 *
 * @tparam     T       The data type
 */
template <class T>
void HeapSortMethod<T>::order (int pos, std::vector<T>& vector,int size) {
	int aux = pos;
	int h1 = 2 * pos + 1;
	int h2 = 2 * pos + 2;
	
	if (BaseSortMethod<T>::get_StatisticMode() == false) {
		std::cin.get();
		for (int k = 0; k < size; k++) {
			std::cout << vector[k] << " ";
		}
		std::cout << std::endl;
	}
	
	BaseSortMethod<T>::incrementateCounter();
	if((h1 < size) && (vector[h1] > vector[aux])) {
		aux = h1;
	}

	BaseSortMethod<T>::incrementateCounter();
	if((h2 < size) && (vector[h2] > vector[aux])) {
		aux = h2;
	}

	if(aux != pos){
		T temp = vector[pos];
		vector[pos] = vector[aux];
		vector[aux] = temp;
		order(aux,vector,size);
	}
}