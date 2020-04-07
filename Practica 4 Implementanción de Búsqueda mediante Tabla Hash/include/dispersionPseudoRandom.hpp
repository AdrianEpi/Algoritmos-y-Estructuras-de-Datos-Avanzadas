/*===================================================================================
=====================================================================================
	=                                                                              =
	=            Proyecto:      Práctica 4 Implementación de Búsqueda Tabla Hash   =
	=            Archivo:       dispersionPseudoRandom.hpp                         =
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

#include <cstdlib>

/*------------------------------------------------*/

/*----------  DECLARACION DE FUNCIONES  ----------*/

#pragma once
#include "dispersionBase.hpp"

/*------------------------------------------------*/

template <class T>
class DispersionPseudoRandom : public DispersionBase<T> {
	public:
		// Builder & Destroyer
		DispersionPseudoRandom ();
		virtual ~DispersionPseudoRandom ();

		// Function
		unsigned disperse (T& data, unsigned size);
};

/**
 * @brief      Constructs a new instance.
 */
template <class T>
DispersionPseudoRandom<T>::DispersionPseudoRandom () {

}

/**
 * @brief      Destroys the object.
 */
template <class T>
DispersionPseudoRandom<T>::~DispersionPseudoRandom () {

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
unsigned DispersionPseudoRandom<T>::disperse (T& data, unsigned size) {
	srand(unsigned(data.get_Code()));
	return rand() % size;
}

