/*===================================================================================
=====================================================================================
	=                                                                              =
	=            Proyecto:      Práctica 4 Implementación de Búsqueda Tabla Hash   =
	=            Archivo:       explorationBase.cpp                                    =
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
* @Date:   2020-03-31 08:19:42
* @Last Modified by:   Adrián Epifanio
* @Last Modified time: 2020-04-03 15:05:29
*/
/*----------  DECLARACION DE FUNCIONES  ----------*/

#include "../include/explorationBase.hpp"

/*------------------------------------------------*/

/**
 * @brief      Constructs a new instance.
 */
template <class T>
ExplorationBase<T>::ExplorationBase () {

}

/**
 * @brief      Destroys the object.
 */
template <class T>
ExplorationBase<T>::~ExplorationBase () {

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
int ExplorationBase<T>::operator() (int size, int pos, const T& data) {

}
