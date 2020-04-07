/*===================================================================================
=====================================================================================
	=                                                                              =
	=            Proyecto:      Práctica 4 Implementación de Búsqueda Tabla Hash   =
	=            Archivo:       explorationLinear.hpp                              =
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
#include "explorationBase.hpp"

/*------------------------------------------------*/


template <class T>
class ExplorationLinear : public ExplorationBase<T> {

	public:
		// Builder & Destroyer
		ExplorationLinear();
		virtual ~ExplorationLinear();

		// Function
		unsigned explorate(const T& data, unsigned pos, unsigned size);
};


/**
 * @brief      Constructs a new instance.
 */
template <class T>
ExplorationLinear<T>::ExplorationLinear () {

}

/**
 * @brief      Destroys the object.
 */
template <class T>
ExplorationLinear<T>::~ExplorationLinear () {

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
unsigned ExplorationLinear<T>::explorate (const T& data, unsigned pos, unsigned size) {
	return ((data.get_Code() + pos) % size);
}

