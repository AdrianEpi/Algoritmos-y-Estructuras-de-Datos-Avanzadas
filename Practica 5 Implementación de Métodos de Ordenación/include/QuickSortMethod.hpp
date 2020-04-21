/*===================================================================================
=====================================================================================
	=                                                                              =
	=            Proyecto:      Práctica 5 Implementación de Métodos de Ordenación =
	=            Archivo:       QuickSortMethod.hpp                                =
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
class QuickSortMethod : public BaseSortMethod<T> {

	public:
		// Builder & Destroyer
		QuickSortMethod ();
		virtual ~QuickSortMethod ();

		// Functions
		void sort (std::vector<T>& vector, int size);
		void quickSort(std::vector<T>& vector, int start, int end);
};


/**
 * @brief      Constructs a new instance.
 * 
 * @tparam     T     The data type
 */
template <class T>
QuickSortMethod<T>::QuickSortMethod () {
}

/**
 * @brief      Destroys the object.
 * 
 * @tparam     T     The data type
 */
template <class T>
QuickSortMethod<T>::~QuickSortMethod () {
}

/**
 * @brief      Sort Method QuickSort
 *
 * @param[in]  vector  The vector
 * @param[in]  size    The size
 *
 * @tparam     T       The data type
 */
template <class T>
void QuickSortMethod<T>::sort (std::vector<T>& vector, int size) {
	quickSort(vector, 0, size);
}

/**
 * @brief      Uses QuickSort for ordering the vector
 *
 * @param      vector  The vector
 * @param[in]  start   The start
 * @param[in]  end     The end
 *
 * @tparam     T       The data type
 */
template <class T>
void QuickSortMethod<T>::quickSort(std::vector<T>& vector, int start, int end) {
	int tmpStart = start;
	int tmpEnd = end;
	T pivot = vector[(tmpStart + tmpEnd) / 2];
	if(BaseSortMethod<T>::get_StatisticMode() == false) {
		std::cin.get();
		std::cout << "Pivot:" << pivot << ", i =" << tmpStart << ", f=" << tmpEnd << std::endl;
		for(int k = 0; k < vector.size(); k++){
			std::cout<<" "<<vector[k];
		}
		std::cout << std::endl;
	}
	
	while (tmpStart <= tmpEnd) {
		while (vector[tmpStart] < pivot) {
			BaseSortMethod<T>::incrementateCounter();
			tmpStart++;
			if (BaseSortMethod<T>::get_StatisticMode() == false) {
				std::cin.get();
				std::cout << "Pivot:" << pivot << ", i =" << tmpStart << ", f=" << tmpEnd << std::endl;
				for (int k = 0; k < vector.size(); k++) {
					std::cout << " " << vector[k];
				}
				std::cout << std::endl;
			}
		}

		while (vector[tmpEnd] > pivot) {
			BaseSortMethod<T>::incrementateCounter();
			tmpEnd--;
			if (BaseSortMethod<T>::get_StatisticMode() == false) {
				std::cin.get();
				std::cout << "Pivot:" << pivot << ", i =" << tmpStart << ", f=" << tmpEnd << std::endl;				
				for (int k = 0; k < vector.size(); k++) {
					std::cout << " " << vector[k];
				}
				std::cout << std::endl;
			}
		}
		if (tmpStart <= tmpEnd) {
			T aux;
			aux = vector[tmpStart];
			vector[tmpStart] = vector[tmpEnd];
			vector[tmpEnd] = aux;
			tmpStart++;
			tmpEnd--;
			if(BaseSortMethod<T>::get_StatisticMode() == 0){
				std::cin.get();
				std::cout << "Pivot:" << pivot << ", i =" << tmpStart << ", f=" << tmpEnd << std::endl;				
				for(int k = 0; k < vector.size(); k++){
					std::cout << " " << vector[k];
				}
				std::cout << std::endl;
			}
		}
	}
	if(start < tmpEnd) {
		quickSort(vector, start, tmpEnd);
	}

	if(tmpStart < end) {
		quickSort(vector, tmpStart, end);
	}
}
