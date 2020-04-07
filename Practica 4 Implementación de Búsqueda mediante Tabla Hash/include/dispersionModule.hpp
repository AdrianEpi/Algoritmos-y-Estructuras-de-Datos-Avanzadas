/*===================================================================================
=====================================================================================
	=                                                                              =
	=            Proyecto:      Práctica 4 Implementación de Búsqueda Tabla Hash   =
	=            Archivo:       dispersionModule.hpp                               =
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
#include "dispersionBase.hpp"

/*------------------------------------------------*/
template <class T>
class DispersionModule : public DispersionBase<T> {
	public:
		// Builder & Destroyer
		DispersionModule ();
		virtual ~DispersionModule ();

		// Function
		unsigned disperse (T& data, unsigned size);
};

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
unsigned DispersionModule<T>::disperse (T& data, unsigned size) {
	return data % size;
}