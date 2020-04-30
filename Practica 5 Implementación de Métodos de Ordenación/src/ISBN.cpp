/*===================================================================================
=====================================================================================
	=                                                                              =
	=            Proyecto:      Práctica 5 Implementación de Métodos de Ordenación =
	=            Archivo:       ISBN.cpp                                            =
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
* @Last Modified time: 2020-04-30 08:31:30
*/
/*----------  DECLARACION DE FUNCIONES  ----------*/

#include "../include/ISBN.hpp"

/*------------------------------------------------*/ 
/**
 * @brief      Constructs a new instance.
 */
ISBN::ISBN () {
	set_Code(0);
}

/**
 * @brief      Constructs a new instance.
 *
 * @param[in]  code  The code
 */
ISBN::ISBN (unsigned code) {
	set_Code (code);
}

/**
 * @brief      Constructs a new instance.
 *
 * @param      copy  The copy
 */
ISBN::ISBN (const ISBN& copy) {
	set_Code(copy.get_Code());
}

/**
 * @brief      Destroys the object.
 */
ISBN::~ISBN () {
	set_Code(0);
}

/**
 * @brief      Gets the code.
 *
 * @return     The code.
 */
int ISBN::get_Code (void) const {
	return code_;
}

/**
 * @brief      Sets the code.
 *
 * @param[in]  code  The code
 */
void ISBN::set_Code (int code) {
	code_ = code;
}

/**
 * @brief      Modulus operator.
 *
 * @param[in]  n     number
 *
 * @return     The result of the modulus
 */
unsigned ISBN::operator% (unsigned number) {
	return code_ % number; 
}
/**
 * @brief      Equality operator.
 *
 * @param      ISBN   The ISBN
 *
 * @return     The result of the equality
 */
bool ISBN::operator== (ISBN& ISBN) const {
	if (get_Code() == ISBN.get_Code())
		return true;
	return false;
}

/**
 * @brief      Less-than-or-equal comparison operator.
 *
 * @param      ISBN   The ISBN
 *
 * @return     The result of the less-than-or-equal comparison
 */
bool ISBN::operator<= (ISBN& ISBN) const {
	if (get_Code() <= ISBN.get_Code())
		return true;
	return false;
}

/**
 * @brief      Greater-than-or-equal comparison operator.
 *
 * @param      ISBN   The ISBN
 *
 * @return     The result of the greater-than-or-equal comparison
 */
bool ISBN::operator>= (ISBN& ISBN) const {
	if (get_Code() >= ISBN.get_Code())
		return true;
	return false;
}

/**
 * @brief      Inequality operator.
 *
 * @param      ISBN   The ISBN
 *
 * @return     The result of the inequality
 */
bool ISBN::operator!= (ISBN& ISBN) const {
	if (get_Code() != ISBN.get_Code())
		return true;
	return false;
}

/**
 * @brief      Assignment operator.
 *
 * @param      ISBN   The ISBN
 *
 * @return     The result of the assignment
 */
ISBN& ISBN::operator= (ISBN& ISBN) {
	set_Code(ISBN.get_Code());
	return *this;
}

/**
 * @brief      Equality operator.
 *
 * @param[in]  code  The code
 *
 * @return     The result of the equality
 */
bool ISBN::operator== (int code) const {
	if (get_Code() == code)
		return true;
	return false;
}
/**
 * @brief      USnsigned long operator.
 *
 * @return     The result of the assignment
 */
ISBN::operator unsigned long () {
	return get_Code();
}

/**
 * @brief      Writes the ISBN by console
 *
 * @param[in]  os    The output stream
 *
 * @return     The stream
 */
std::ostream& ISBN::write (std::ostream& os) const {
	os << get_Code();
	return os;
}