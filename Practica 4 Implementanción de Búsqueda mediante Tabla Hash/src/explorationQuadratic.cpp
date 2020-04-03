/*===================================================================================
=====================================================================================
	=                                                                              =
	=            Proyecto:      Práctica 4 Implementación de Búsqueda Tabla Hash   =
	=            Archivo:       explorationQuadratic.cpp                           =
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
* @Date:   2020-04-02 20:47:17
* @Last Modified by:   Adrián Epifanio
* @Last Modified time: 2020-04-03 15:08:58
*/
/*----------  DECLARACION DE FUNCIONES  ----------*/

#include "../include/explorationQuadratic.hpp"

/*------------------------------------------------*/

/**
 * @brief      Constructs a new instance.
 */
template <class T>
ExplorationQuadratic<T>::ExplorationQuadratic() {

}

/**
 * @brief      Destroys the object.
 */
template <class T>
ExplorationQuadratic<T>::~ExplorationQuadratic() {

}

/**
 * @brief      Function call operator.
 *
 * @param[in]  size  The size
 * @param[in]  pos   The position
 * @param[in]  data  The data
 *
 * @tparam     T     The data type
 *
 * @return     The result of the function call
 */
template <class T>
int ExplorationQuadratic<T>::operator() (int size, int pos, const T& data) {
	return ((data.get_Code() + pow(pos, 2)) % size);
}