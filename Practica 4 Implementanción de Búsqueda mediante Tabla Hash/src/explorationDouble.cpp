/*===================================================================================
=====================================================================================
	=                                                                              =
	=            Proyecto:      Práctica 4 Implementación de Búsqueda Tabla Hash   =
	=            Archivo:       explorationDouble.cpp                              =
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
/*
* @Author: Adrián Epifanio
* @Date:   2020-04-02 20:51:29
* @Last Modified by:   Adrián Epifanio
* @Last Modified time: 2020-04-03 15:12:28
*/
/*----------  DECLARACION DE FUNCIONES  ----------*/

#include "../include/explorationDouble.hpp"

/*------------------------------------------------*/

/**
 * @brief      Constructs a new instance.
 */
template <class T>
ExplorationDouble<T>::ExplorationDouble() {

}

/**
 * @brief      Destroys the object.
 */
template <class T>
ExplorationDouble<T>::~ExplorationDouble() {

}

/**
 * @brief      Function call operator.
 *
 * @param[in]  size  The size
 * @param[in]  pos   The position
 *
 * @tparam     T     The data type
 *
 * @return     The result of the function call
 */
template <class T>
int ExplorationDouble<T>::operator() (int size, int pos, const T& data) {
	int prime = findPrime();
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
	for (int i = (number - 1); i > 2; i--) {
		prime = true;
		for (int j = 2; j < i; j++)
			if ((i % j) != 0)
				prime = false;
		
		if (prime == true)
			return i;
	}

}