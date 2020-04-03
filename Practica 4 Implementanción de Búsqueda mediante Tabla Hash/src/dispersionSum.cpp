/*===================================================================================
=====================================================================================
	=                                                                              =
	=            Proyecto:      Práctica 4 Implementación de Búsqueda Tabla Hash   =
	=            Archivo:       dispersionSum.cpp                                 =
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
* @Date:   2020-04-02 21:02:04
* @Last Modified by:   Adrián Epifanio
* @Last Modified time: 2020-04-03 14:33:11
*/
/*----------  DECLARACION DE FUNCIONES  ----------*/

#include "../include/dispersionSum.hpp"

/*------------------------------------------------*/

/**
 * @brief      Constructs a new instance.
 */
template <class T>
DispersionSum<T>::DispersionSum () {

}

/**
 * @brief      Destroys the object.
 */
template <class T>
DispersionSum<T>::~DispersionSum () {

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
int DispersionSum<T>::operator() (const T& data, int size) {
	int d = 0;
	unsigned long x = data.get_Code();
	while ( x > 0) {
		d += (x % 10);
		x /= 10;
	}
	return (d % size);
}
