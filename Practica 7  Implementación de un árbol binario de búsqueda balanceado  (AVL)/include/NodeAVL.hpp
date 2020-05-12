/*================================================================================================================
==================================================================================================================
	=                                                                                                       =
	=            Proyecto:      Práctica 7 Implementación de un Árbol Binario de Busqueda  Balanceado AVL   =
	=            Archivo:       NodeAVL.hpp                                                                 =
	=            Autor:         Adrián Epifanio Rodríguez Hernández                                         =
	=            Fecha:         12/05/2020                                                                  =
	=            Asignatura:    Algoritmos y Estructuras de Datos Avazados                                  =
	=            Lenguaje:      C++                                                                         =
	=            Correo:        alu0101158280@ull.edu.es                                                    =
	=            Lugar:         Universidad De La Laguna                                                    =
	=                           Escuela Superior de Ingeniería y Tecnología                                 =
	=                                                                                                       =
=================================================================================================================
===============================================================================================================*/
/*----------  DECLARACION DE FUNCIONES  ----------*/

#pragma once
#include "NodeBB.hpp"

/*------------------------------------------------*/

template <class T>
class NodeAVL : public NodeBB<T> {
	
	private:
		int balanceFactor_;

	public: 
		// Builder & Destroyer
		NodeAVL (void);
		NodeAVL (const T data, NodeAVL<T>* left=NULL, NodeAVL<T>* right=NULL);
		~NodeAVL (void);

		// Getters & Setters
		int get_BalanceFactor (void);

		void set_BalanceFactor (int balanceFactor);

};

/**
 * @brief      Constructs a new object.
 *
 * @tparam     T     The data type
  */
template <class T>
NodeAVL<T>::NodeAVL (void) {
	NodeBB<T>::set_Left(NULL);
	NodeBB<T>::set_Right(NULL);
}

/**
 * @brief      Constructs a new object.
 * 
 * @param[in]  data  The data
 * @param[in]  left  The data
 * @param[in]  right  The data
 *
 * @tparam     T     The data type
 */
template <class T>
NodeAVL<T>::NodeAVL (const T data, NodeAVL<T>* left, NodeAVL<T>* right) {
	set_Left(left);
	set_Right(right);
	set_Data(data);
}

/**
 * @brief      Destroy the object.
 *
 * @tparam     T     The data type
  */
template <class T>
NodeAVL<T>::~NodeAVL (void) {
}

/**
 * @brief      Gets the balance factor.
 *
 * @tparam     T     The data type.
 *
 * @return     The balance factor.
 */
template <class T>
int NodeAVL<T>::get_BalanceFactor (void) {
	return balanceFactor_;
}

/**
 * @brief      Sets the balance factor.
 *
 * @param[in]  balanceFactor  The balance factor
 *
 * @tparam     T              The data type.
 */
template <class T>
void NodeAVL<T>::set_BalanceFactor (int balanceFactor) {
	balanceFactor_ = balanceFactor;
}