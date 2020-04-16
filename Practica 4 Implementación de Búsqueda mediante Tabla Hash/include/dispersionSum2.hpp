/*===================================================================================
=====================================================================================
	=                                                                              =
	=            Proyecto:      Práctica 4 Implementación de Búsqueda Tabla Hash   =
	=            Archivo:       dispersionSum2.hpp                                 =
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
class DispersionSum2 : public DispersionBase<T> {

	public:
		// Builder & Destroyer
		DispersionSum2 ();
		virtual ~DispersionSum2 ();

		// Function
		unsigned disperse (T& data, unsigned size);
};


/**
 * @brief      Constructs a new instance.
 */
template <class T>
DispersionSum2<T>::DispersionSum2 () {

}

/**
 * @brief      Destroys the object.
 */
template <class T>
DispersionSum2<T>::~DispersionSum2 () {

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
unsigned DispersionSum2<T>::disperse(T& data, unsigned size) {
	unsigned number = 0;
	int aux = data.get_Code();
	while(aux != 0) {
        int extNum = aux % 100;
        aux /= 100;
        number += extNum;
    }
	return number;
}
