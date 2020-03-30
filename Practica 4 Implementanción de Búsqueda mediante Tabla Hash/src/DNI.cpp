/*===================================================================================
=====================================================================================
	=                                                                              =
	=            Proyecto:      Práctica 4 Implementación de Búsqueda Tabla Hash   =
	=            Archivo:       DNI.cpp                                            =
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
* @Date:   2020-03-30 17:41:42
* @Last Modified by:   Adrián Epifanio
* @Last Modified time: 2020-03-30 18:59:21
*/
/*----------  DECLARACION DE FUNCIONES  ----------*/

#include "../include/DNI.hpp"

/*------------------------------------------------*/

/**
 * @brief      Constructs a new instance.
 */
DNI::DNI () {
	set_Code(0);
}

/**
 * @brief      Constructs a new instance.
 *
 * @param[in]  code  The code
 */
DNI::DNI (int code) {
	set_Code (code);
}

/**
 * @brief      Constructs a new instance.
 *
 * @param      copy  The copy
 */
DNI::DNI (DNI& copy) {
	set_Code(copy.get_Code());
}

/**
 * @brief      Destroys the object.
 */
DNI::~DNI () {

}

/**
 * @brief      Gets the code.
 *
 * @return     The code.
 */
int DNI::get_Code (void) const {
	return code_;
}

/**
 * @brief      Sets the code.
 *
 * @param[in]  code  The code
 */
void DNI::set_Code (int code) {
	code_ = code;
}

/**
 * @brief      Equality operator.
 *
 * @param      dni   The dni
 *
 * @return     The result of the equality
 */
bool DNI::operator== (DNI& dni) const {
	if (get_Code() == dni.get_Code())
		return true;
	return false;
}

/**
 * @brief      Less-than-or-equal comparison operator.
 *
 * @param      dni   The dni
 *
 * @return     The result of the less-than-or-equal comparison
 */
bool DNI::operator<= (DNI& dni) const {
	if (get_Code() <= dni.get_Code())
		return true;
	return false;
}

/**
 * @brief      Greater-than-or-equal comparison operator.
 *
 * @param      dni   The dni
 *
 * @return     The result of the greater-than-or-equal comparison
 */
bool DNI::operator>= (DNI& dni) const {
	if (get_Code() >= dni.get_Code())
		return true;
	return false;
}

/**
 * @brief      Inequality operator.
 *
 * @param      dni   The dni
 *
 * @return     The result of the inequality
 */
bool DNI::operator!= (DNI& dni) const {
	if (get_Code() != dni.get_Code())
		return true;
	return false;
}

/**
 * @brief      Assignment operator.
 *
 * @param      dni   The dni
 *
 * @return     The result of the assignment
 */
DNI& DNI::operator= (DNI& dni) {
	set_Code(dni.get_Code());
}

/**
 * @brief      USnsigned long operator.
 *
 * @return     The result of the assignment
 */
DNI::operator unsigned long () {
	return get_Code();
}



/**
 * @brief      Writes the DNI by console
 *
 * @param[in]  os    The ouput stream
 *
 * @return     The stream
 */
std::ostream DNI::write (std::ostream os) const {
	os << get_Code();
}
