/*===================================================================================
=====================================================================================
	=                                                                              =
	=            Proyecto:      Práctica 4 Implementación de Búsqueda Tabla Hash   =
	=            Archivo:       dispersionBase.hpp                                 =
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
/*----------  DECLARACION DE LIBRERIAS  ----------*/

#include <iostream>

/*------------------------------------------------*/

/*----------  DECLARACION DE FUNCIONES  ----------*/

#pragma once

/*------------------------------------------------*/

template <class T>
class DispersionBase {

	public:
		// Builder & Destroyer
		DispersionBase ();
		virtual ~DispersionBase ();

		// Function
		virtual unsigned disperse (T& data, unsigned size) = 0;
		
};

/**
 * @brief      Constructs a new instance.
 */
template <class T>
DispersionBase<T>::DispersionBase () {

}

/**
 * @brief      Destroys the object.
 */
template <class T>
DispersionBase<T>::~DispersionBase () {

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
unsigned DispersionBase<T>::disperse (T& data, unsigned size) {

}