/*===================================================================================
=====================================================================================
	=                                                                              =
	=            Proyecto:      Práctica 4 Implementación de Búsqueda Tabla Hash   =
	=            Archivo:       dispersionSum.hpp                                  =
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
class DispersionSum : public DispersionBase<T> {

	public:
		// Builder & Destroyer
		DispersionSum ();
		virtual ~DispersionSum ();

		// Function
		unsigned disperse (T& data, unsigned size);
};


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
unsigned DispersionSum<T>::disperse(T& data, unsigned size) {
	int d = 0;
	unsigned long x = data.get_Code();
	while (x > 0) {
		d += (x % 10);
		x /= 10;
	}
	return (d % size);
}
