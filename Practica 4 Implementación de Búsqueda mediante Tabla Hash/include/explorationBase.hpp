/*===================================================================================
=====================================================================================
	=                                                                              =
	=            Proyecto:      Práctica 4 Implementación de Búsqueda Tabla Hash   =
	=            Archivo:       explorationBase.hpp                                    =
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
class ExplorationBase {

	public:
		// Builder & Destroyer
		ExplorationBase();
		virtual ~ExplorationBase();

		// Function
		virtual unsigned explorate(const T& data, unsigned pos, unsigned size)=0;
};

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
unsigned ExplorationBase<T>::explorate (const T& data, unsigned pos, unsigned size) {

}
