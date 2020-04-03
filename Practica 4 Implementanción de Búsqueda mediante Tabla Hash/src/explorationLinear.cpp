/*===================================================================================
=====================================================================================
	=                                                                              =
	=            Proyecto:      Práctica 4 Implementación de Búsqueda Tabla Hash   =
	=            Archivo:       explorationLinear.cpp                              =
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
* @Date:   2020-04-02 20:51:19
* @Last Modified by:   Adrián Epifanio
* @Last Modified time: 2020-04-03 15:07:09
*/
/*----------  DECLARACION DE FUNCIONES  ----------*/

#include "../include/explorationLinear.hpp"

/*------------------------------------------------*/

/**
 * @brief      Constructs a new instance.
 */
template <class T>
ExplorationLinear<T>::ExplorationLinear() {

}

/**
 * @brief      Destroys the object.
 */
template <class T>
ExplorationLinear<T>::~ExplorationLinear() {

}

/**
 * @brief      Function call operator.
 *
 * @param[in]  size  The size
 * @param[in]  pos   The position
 * @param[in]  data  The data
 *
 * @tparam     T     The data type.
 *
 * @return     The result of the function call
 */
template <class T>
int ExplorationLinear<T>::operator() (int size, int pos, const T& data) {
	return ((data.get_Code() + pos) % size);
}