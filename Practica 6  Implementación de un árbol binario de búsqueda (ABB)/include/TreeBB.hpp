/*====================================================================================================
======================================================================================================
	=                                                                                           =
	=            Proyecto:      Práctica 6 Implementación de un Árbol Binario de Busqueda ABB   =
	=            Archivo:       TreeBB.hpp                                                      =
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
/*----------  DECLARACION DE FUNCIONES  ----------*/

#pragma once
#include "Queue.hpp"
#include "NodeBB.hpp"
#include "Counter.hpp"

/*------------------------------------------------*/

template <class T>
class TreeBB {

	private:
		NodeBB<T>* root_;

	public:
		// Builders & Destroyer
		TreeBB(void);
		TreeBB(NodeBB<T>* root);
		~TreeBB(void);

		// Getter & Setter
		NodeBB<T>* get_Root(void);

		void set_Root(NodeBB<T>* root);

		// Functions
		NodeBB<T>* search(T data, Counter& counter);
		NodeBB<T>* searchBranch(NodeBB<T>* node, T data, Counter& counter);
		void insert(T data, Counter& counter);
		void insertBranch(NodeBB<T>*& node, T data, Counter& counter);
		void remove(T data);
		void removeBranch(NodeBB<T>*& node, T data);
		void prune(NodeBB<T>*& node);
		void raise(NodeBB<T>*& toRemove, NodeBB<T>*& toRaise);

		// Write
		//
		void write(void) const;
};

/**
 * @brief      Constructs a new object.
 *
 * @tparam     T     The data type
  */
template <class T>
TreeBB<T>::TreeBB(void) {
	set_Root(NULL);
}

/**
 * @brief      Constructs a new object.
 * 
 * @param      root  The root
 *
 * @tparam     T     The data type
  */
template <class T>
TreeBB<T>::TreeBB(NodeBB<T>* root) {
	set_Root(root);
}

/**
 * @brief      Destroy the object.
 *
 * @tparam     T     The data type
  */
template <class T>
TreeBB<T>::~TreeBB(void) {
	prune(root_);
}

/**
 * @brief      Gets the root.
 *
 * @tparam     T     The data type.
 *
 * @return     The root.
 */
template <class T>
NodeBB<T>* TreeBB<T>::get_Root(void) {
	return root_;
}

/**
 * @brief      Sets the root.
 *
 * @param      root  The root
 *
 * @tparam     T     The data type.
 */
template <class T>
void TreeBB<T>::set_Root(NodeBB<T>* root) {
	root_ = root;
}

/**
 * @brief      Searches for the first match.
 *
 * @param[in]  data     The data
 * @param      counter  The counter
 *
 * @tparam     T        The data type.
 *
 * @return     The node with the given data
 */
template <class T>
NodeBB<T>* TreeBB<T>::search(T data, Counter& counter) {
	NodeBB<T>* node = searchBranch(root_, data, counter);
	return node;

}

/**
 * @brief      Searchs a node in the given branch.
 *
 * @param      node     The node
 * @param[in]  data     The data
 * @param      counter  The counter
 *
 * @tparam     T        The data type.
 *
 * @return     The node with the given data
 */
template <class T>
NodeBB<T>* TreeBB<T>::searchBranch(NodeBB<T>* node, T data, Counter& counter) {
	counter.incrementation();
	if (node == NULL) {
		return NULL;
	}
	else if (data == node -> get_Data()) {
		return node;
	}
	else if (data < node -> get_Data()) {
		return searchBranch(node -> get_Left(), data, counter);
	}
	else if (data > node -> get_Data()) {
		return searchBranch(node -> get_Right(), data, counter);
	}
}

/**
 * @brief      Inserts a node.
 *
 * @param[in]  data     The data
 * @param      counter  The counter
 *
 * @tparam     T        The data type.
 */
template <class T>
void TreeBB<T>::insert(T data, Counter& counter) {
	insertBranch(root_, data, counter);
}

/**
 * @brief      Inserts a node in the given branch.
 *
 * @param      node     The node
 * @param[in]  data     The data
 * @param      counter  The counter
 *
 * @tparam     T        The data type.
 */
template <class T>
void TreeBB<T>::insertBranch(NodeBB<T>*& node, T data, Counter& counter) {
	counter.incrementation();
	if (node == NULL) {
		node = new NodeBB<T>(data);
	}
	else {
		if (data < node -> get_Data()) {
			insertBranch(node -> get_Left(), data, counter);
		}
		else if (data > node -> get_Data()) {
			insertBranch(node -> get_Right(), data, counter);
		}
	}
}

/**
 * @brief      Deletes a node.
 *
 * @param[in]  data  The data
 *
 * @tparam     T     The data type.
 */
template <class T>
void TreeBB<T>::remove(T data) {
	removeBranch(root_, data);
}

/**
 * @brief      Deletes a node from the branch given branch.
 *
 * @param      node  The node
 * @param[in]  data  The data
 *
 * @tparam     T     The data type.
 */
template <class T>
void TreeBB<T>::removeBranch(NodeBB<T>*& node, T data) {
	if (node != NULL) {
		if (data == node -> get_Data()) {
			if (node -> get_Right() == NULL) {
				node = node -> get_Left();
			}
			else if (node -> get_Left() == NULL) {
				node = node -> get_Right();
			}
			else {
				NodeBB<T>* tmp = node;
				raise(tmp, node -> get_Left());
			}
		}
		else {
			if (data < node -> get_Data()) {
				removeBranch(node -> get_Left(), data);
			}
			else if (data > node -> get_Data()) {
				removeBranch(node -> get_Right(), data);
			}
		}
	}
}

/**
 * @brief      Cuts and deletes the branch of the given node.
 *
 * @param      node  The node
 *
 * @tparam     T     The data type.
 */
template <class T>
void TreeBB<T>::prune(NodeBB<T>*& node) {
	if (node != NULL) {
		prune(node -> get_Left());
		prune(node -> get_Right());
		delete node;
		node = NULL;
	}
}

/**
 * @brief      Swaps the data to remove with the biggest of the specified branch
 *
 * @param      toRemove  To remove
 * @param      toRaise   To raise
 *
 * @tparam     T         The data type.
 */
template <class T>
void TreeBB<T>::raise(NodeBB<T>*& toRemove, NodeBB<T>*& toRaise) {
	if (toRaise -> get_Right() != NULL) {
		raise(toRemove, toRaise -> get_Right());
	} 
	else {
		toRemove -> set_Data(toRaise -> get_Data());
		toRemove = toRaise;
		toRaise = toRaise -> get_Left();
	}
}

/**
 * @brief      Prints the tree on screen.
 *
 * @tparam     T     The data type.
 */
template <class T>
void TreeBB<T>::write(void) const {
	Queue<T> queue;
	NodeBB<T>* node;
	int level = 0;
	int currentLevel = 0;
	queue.insert(root_, level);
	std::cout << std::endl << std::endl << "----- TREE -----" << std::endl << "Level 0: ";
	while (queue.isEmpty() != true) {
		queue.extract(node, level);
		if (level > currentLevel) {
			currentLevel = level;
			std::cout << std::endl << "Level " << currentLevel << ": ";
		}
		node -> write();
		if (node != NULL) {
			queue.insert(node -> get_Left(), level + 1);
			queue.insert(node -> get_Right(), level + 1);
		}
	}
}
