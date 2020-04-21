/*===================================================================================
=====================================================================================
	=                                                                              =
	=            Proyecto:      Práctica 5 Implementación de Métodos de Ordenación =
	=            Archivo:       Counter.cpp                                        =
	=            Autor:         Adrián Epifanio Rodríguez Hernández                =
	=            Fecha:         21/04/2020                                         =
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
* @Date:   2020-04-21 09:27:28
* @Last Modified by:   Adrián Epifanio
* @Last Modified time: 2020-04-21 09:48:26
*/
/*----------  DECLARACION DE FUNCIONES  ----------*/

#include "../include/Counter.hpp"

/*------------------------------------------------*/

/**
 * @brief      Constructs a new instance.
 */
Counter::Counter () {
	reset();
}

/**
 * @brief      Destroys the object.
 */
Counter::~Counter () {
}

/**
 * @brief      Gets the accum.
 *
 * @return     The accum.
 */
int Counter::get_Accum (void) const {
	return accum_;
}

/**
 * @brief      Gets the maximum.
 *
 * @return     The maximum.
 */
int Counter::get_Max (void) const {
	return max_;
}

/**
 * @brief      Gets the minimum.
 *
 * @return     The minimum.
 */
int Counter::get_Min (void) const {
	return min_;
}

/**
 * @brief      Gets the local accum.
 *
 * @return     The local accum.
 */
int Counter::get_LocalAccum (void) const {
	return localAccum_;
}

/**
 * @brief      Sets the accum.
 *
 * @param[in]  accum  The accum
 */
void Counter::set_Accum (int accum) {
	accum_ = accum;
}

/**
 * @brief      Sets the maximum.
 *
 * @param[in]  max   The new value
 */
void Counter::set_Max (int max) {
	max_ = max;
}

/**
 * @brief      Sets the minimum.
 *
 * @param[in]  min   The new value
 */
void Counter::set_Min (int min) {
	min_ = min;
}

/**
 * @brief      Sets the local accum.
 *
 * @param[in]  localAccum  The local accum
 */
void Counter::set_LocalAccum (int localAccum) {
	localAccum_ = localAccum;
}

/**
 * @brief      Starts the counter.
 */
void Counter::start (void) {
	set_Accum(0);
}

/**
 * @brief      Stops the counter.
 *
 * @return     The counter local ammount.
 */
int Counter::stop (void) {
	set_Min(localAccum_ < min_ ? localAccum_:min_);
	set_Max(localAccum_ > max_ ? localAccum_:max_);
	accum_ += localAccum_;
	return get_LocalAccum();
}

/**
 * @brief      Resets the object.
 */
void Counter::reset (void) {
	set_Min(std::numeric_limits<int>::max());
	set_Max(0);
	set_Accum(0);
	set_LocalAccum(0);
}

/**
 * @brief      Increment operator.
 *
 * @return     The result of the increment
 */
Counter& Counter::operator++ (void) {
	localAccum_++;
	return *this;
} 

