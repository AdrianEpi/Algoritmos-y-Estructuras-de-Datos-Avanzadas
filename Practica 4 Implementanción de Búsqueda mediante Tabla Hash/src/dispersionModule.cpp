/*===================================================================================
=====================================================================================
	=                                                                              =
	=            Proyecto:      Práctica 4 Implementación de Búsqueda Tabla Hash   =
	=            Archivo:       dispersionModule.cpp                                 =
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
* @Date:   2020-04-02 21:02:46
* @Last Modified by:   Adrián Epifanio
* @Last Modified time: 2020-04-03 14:34:15
*/
/*----------  DECLARACION DE FUNCIONES  ----------*/

#include "../include/dispersionModule.hpp"

/*------------------------------------------------*/

/**
 * @brief      Constructs a new instance.
 */
template <class T>
DispersionModule<T>::DispersionModule () {

}

/**
 * @brief      Destroys the object.
 */
template <class T>
DispersionModule<T>::~DispersionModule () {

}

/**
 * @brief      Searchs the cells to find one where store the data
 *
 * @param[in]  data  The data
 * @param[in]  size  The size
 *
 * @tparam     T     The data type.
 *
 * @return     The cell position
 */
template <class T>
int DispersionModule<T>::operator() (const T& data, int size) {
	return data.get_Code() % size;
}
