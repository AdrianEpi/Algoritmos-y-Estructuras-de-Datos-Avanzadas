/*====================================================================================================
======================================================================================================
	=                                                                                           =
	=            Proyecto:      Práctica 6 Implementación de un Árbol Binario de Busqueda ABB   =
	=            Archivo:       Queue.hpp                                                       =
	=            Autor:         Adrián Epifanio Rodríguez Hernández                             =
	=            Fecha:         05/05/2020                                                      =
	=            Asignatura:    Algoritmos y Estructuras de Datos Avazados                      =
	=            Lenguaje:      C++                                                             =
	=            Correo:        alu0101158280@ull.edu.es                                        =
	=            Lugar:         Universidad De La Laguna                                        =
	=                           Escuela Superior de Ingeniería y Tecnología                     =
	=                                                                                           =
======================================================================================================
=====================================================================================================*/
/*----------  DECLARACION DE LIBRERIAS  ----------*/

#include <cstdio>
#include <vector>
#include <cassert>

/*------------------------------------------------*/

/*----------  DECLARACION DE FUNCIONES  ----------*/

#pragma once
#include "NodeBB.hpp"

/*------------------------------------------------*/

template <class T>
class Queue	{

	private:
		int size_;
		std::vector<int> levels_;
		std::vector<NodeBB<T>*> nodes_;

	public:
		// Builder & Destroyer
		Queue (void);
		~Queue (void);

		// Getters & Setters
		int get_Size (void);
		std::vector<NodeBB<T>> get_Levels (void);
		std::vector<NodeBB<T>*> get_Nodes (void);

		void set_Size (int size);
		void set_Levels (std::vector<NodeBB<T>> levels);
		void set_Nodes (std::vector<NodeBB<T>*> nodes);

		// Functinos
		void insert (NodeBB<T>* node, int level);
		void extract (NodeBB<T>*& node, int& level);
		bool isEmpty (void);
};

/**
 * @brief      Constructs a new object.
 *
 * @tparam     T     The data type
  */
template <class T>
Queue<T>::Queue (void) {
	set_Size(0);
	levels_.clear();
	nodes_.clear();
}

/**
 * @brief      Destroy the object.
 *
 * @tparam     T     The data type
  */
template <class T>
Queue<T>::~Queue (void) {
	levels_.clear();
	nodes_.clear();
}

/**
 * @brief      Gets the size.
 *
 * @tparam     T     The data type.
 *
 * @return     The size.
 */
template <class T>
int Queue<T>::get_Size (void) {
	return size_;
}

/**
 * @brief      Gets the levels.
 *
 * @tparam     T     The data type.
 *
 * @return     The levels.
 */
template <class T>
std::vector<NodeBB<T>> Queue<T>::get_Levels (void) {
	return levels_;
}

/**
 * @brief      Gets the nodes.
 *
 * @tparam     T     The data type.
 *
 * @return     The nodes.
 */
template <class T>
std::vector<NodeBB<T>*> Queue<T>::get_Nodes (void) {
	return nodes_;
}

/**
 * @brief      Sets the size.
 *
 * @param[in]  size  The size
 *
 * @tparam     T     The data type.
 */
template <class T>
void Queue<T>::set_Size (int size) {
	size_ = size;
}

/**
 * @brief      Sets the levels.
 *
 * @param[in]  levels  The levels
 *
 * @tparam     T       The data type.
 */
template <class T>
void Queue<T>::set_Levels (std::vector<NodeBB<T>> levels) {
	levels_ = levels;
}

/**
 * @brief      Sets the nodes.
 *
 * @param[in]  nodes  The nodes
 *
 * @tparam     T      The data type.
 */
template <class T>
void Queue<T>::set_Nodes (std::vector<NodeBB<T>*> nodes) {
	nodes_ = nodes;
}

/**
 * @brief      Inserts a node at the back of the queue.
 *
 * @param      node   The node
 * @param[in]  level  The level
 *
 * @tparam     T      The data type.
 */
template <class T>
void Queue<T>::insert (NodeBB<T>* node, int level) {
	nodes_.push_back(node);
	levels_.push_back(level);
	size_++;
}

/**
 * @brief      Extracts a node from the head of the queue.
 *
 * @param      node   The node
 * @param      level  The level
 *
 * @tparam     T      The data type.
 */
template <class T>
void Queue<T>::extract (NodeBB<T>*& node, int& level) {
	assert(size_ >= 1);
	node = nodes_[0];
	level = levels_[0];
	nodes_.erase(nodes_.begin());
	levels_.erase(levels_.begin());
	size_--;
}

/**
 * @brief      Determines if empty.
 *
 * @tparam     T     The data type.
 *
 * @return     True if empty, False otherwise.
 */
template <class T>
bool Queue<T>::isEmpty (void) {
	if (get_Size() >= 1) {
		return false;
	}
	else {
		return true;
	}
}

