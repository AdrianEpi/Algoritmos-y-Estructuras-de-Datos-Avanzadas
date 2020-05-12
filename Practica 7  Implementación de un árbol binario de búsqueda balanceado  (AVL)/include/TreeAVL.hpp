/*================================================================================================================
==================================================================================================================
	=                                                                                                       =
	=            Proyecto:      Práctica 7 Implementación de un Árbol Binario de Busqueda  Balanceado AVL   =
	=            Archivo:       TreeAVL.hpp                                                                 =
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
#include "TreeBB.hpp"

/*------------------------------------------------*/

template <class T>
class TreeAVL : public TreeBB<T> {

	public:
		// Builders & Destroyer
		TreeAVL (void);
		TreeAVL (NodeBB<T>* root);
		~TreeAVL (void);

		// Functions
		void insert (T data, Counter& counter);
		void insertBalancing (NodeBB<T>*& node, NodeBB<T>*& newNode, bool& grow, Counter& counter);
		void insertReBalancingRight (NodeBB<T>*& node, bool& grow);
		void insertReBalancingLeft (NodeBB<T>*& node, bool& grow);
		void rotateLeftToLeft (NodeBB<T>*& node);
		void rotateRightToRight (NodeBB<T>*& node);
		void rotateLeftToRight (NodeBB<T>*& node);
		void rotateRightToLeft (NodeBB<T>*& node);
		void remove (T data);
		void remove (NodeBB<T>*& node, T data, bool& decreasses);
		void raise ( NodeBB<T>*& removed, NodeBB<T>*& newNode, bool& decreasses);
		void removeReBalancingLeft (NodeBB<T>*& node, bool& decreasses);
		void removeReBalancingRight (NodeBB<T>*& node, bool& decreasses);
};


/**
 * @brief      Constructs a new object.
 *
 * @tparam     T     The data type
  */
template <class T>
TreeAVL<T>::TreeAVL (void) {
	this -> root_ = new NodeBB<T>();
	this -> root_ = NULL;
}

/**
 * @brief      Constructs a new object.
 * 
 * @param      root  The root
 *
 * @tparam     T     The data type
  */
template <class T>
TreeAVL<T>::TreeAVL (NodeBB<T>* root) {
	TreeBB<T>(this -> root_);
}

/**
 * @brief      Destroy the object.
 *
 * @tparam     T     The data type
  */
template <class T>
TreeAVL<T>::~TreeAVL (void) {
	this -> prune(this -> root_);
}

/**
 * @brief      Inserts a new node.
 *
 * @param[in]  data     The data
 * @param      counter  The counter
 *
 * @tparam     T        The data type.
 */
template <class T>
void TreeAVL<T>::insert (T data, Counter& counter) {
	NodeBB<T>* newNode = new NodeBB<T>(data);
	newNode -> set_BalanceFactor(0);
	bool grow = false;
	insertBalancing(this -> root_, newNode, grow, counter);
}

/**
 * @brief      Inserts a node balancing to one side or other.
 *
 * @param      node     The node
 * @param      newNode  The new node
 * @param      grow     The grow
 * @param      counter  The counter
 *
 * @tparam     T        The data type.
 */
template <class T>
void TreeAVL<T>::insertBalancing (NodeBB<T>*& node, NodeBB<T>*& newNode, bool& grow, Counter& counter) {
	counter.incrementation();
	if (!node) {
		node = newNode;
		grow = true;
	}
	else {
		if (newNode -> get_Data() == node -> get_Data()) {
			std::cout << "Data already inserted" << std::endl; 
		}
		else if (newNode -> get_Data() < node -> get_Data()) {
			insertBalancing(node -> get_Left(), newNode, grow, counter);
			if (grow == true) {
				insertReBalancingLeft(node, grow);
			}
		}
		else {
			insertBalancing(node -> get_Right(), newNode, grow, counter);
			if (grow == true) {
				insertReBalancingRight(node, grow);
			}
		}
	}
}

/**
 * @brief      Inserts a node rebalancing to right.
 *
 * @param      node     The node
 * @param      grow     The grow
 *
 * @tparam     T        The data type.
 */
template <class T>
void TreeAVL<T>::insertReBalancingRight (NodeBB<T>*& node, bool& grow) {
	switch (node -> get_BalanceFactor()) {
		case 0:
			node -> set_BalanceFactor(-1);
			break;

		case 1:
			node -> set_BalanceFactor(0);
			grow = false;
			break;

		case -1:
			NodeBB<T>* newNode = node -> get_Right();
			if (newNode -> get_BalanceFactor() == -1) {
				rotateRightToRight(node);
			}
			else {
				rotateRightToLeft(node);
			}
			grow = false;
			break;
	}
}

/**
 * @brief      Inserts a node rebalancing to left.
 *
 * @param      node     The node
 * @param      grow     The grow
 *
 * @tparam     T        The data type.
 */
template <class T>
void TreeAVL<T>::insertReBalancingLeft (NodeBB<T>*& node, bool& grow) {
	switch (node -> get_BalanceFactor()) {
		case 0: {
			node -> set_BalanceFactor(1);
			break;
		}

		case 1: {
			NodeBB<T>* newNode = node -> get_Left();
			if (newNode -> get_BalanceFactor() == 1) {
				rotateLeftToLeft(node);
			}
			else {
				rotateLeftToRight(node);
			}
			grow = false;
			break;
		}

		case -1: {
			node -> set_BalanceFactor(0);
			grow = false;
			break;
		}
			
	}
}

/**
 * @brief      Rotates form left to left.
 *
 * @param      node  The node
 *
 * @tparam     T     The data type.
 */
template <class T>
void TreeAVL<T>::rotateLeftToLeft (NodeBB<T>*& node) {
	std::cout << std::endl << "Rotation Left to Left" << std::endl;
	NodeBB<T>* newNode = node -> get_Left();
	node -> set_Left(newNode -> get_Right());
	newNode -> set_Right(node);
	if (newNode -> get_BalanceFactor() == 1) {
		node -> set_BalanceFactor(0);
		newNode -> set_BalanceFactor(0);
	}
	else if (newNode -> get_BalanceFactor() == 0) {
		node -> set_BalanceFactor(1);
		newNode -> set_BalanceFactor(-1);
	}
	node = newNode;
}


/**
 * @brief      Rotates from right to right.
 *
 * @param      node  The node
 *
 * @tparam     T     The data type.
 */
template <class T>
void TreeAVL<T>::rotateRightToRight (NodeBB<T>*& node) {
	std::cout << std::endl << "Rotation Right to Right" << std::endl;
	NodeBB<T>* newNode = node -> get_Right();
	node -> set_Right(newNode -> get_Left());
	newNode -> set_Left(node);
	if (newNode -> get_BalanceFactor() == -1) {
		node -> set_BalanceFactor(0);
		newNode -> set_BalanceFactor(0);
	}
	else if (newNode -> get_BalanceFactor() == 0) {
		node -> set_BalanceFactor(-1);
		newNode -> set_BalanceFactor(1);
	}
	node = newNode;
}

/**
 * @brief      Rotates from left to right.
 *
 * @param      node  The node
 *
 * @tparam     T     The data type.
 */
template <class T>
void TreeAVL<T>::rotateLeftToRight (NodeBB<T>*& node) {
	std::cout << std::endl << "Rotation Left to Right" << std::endl;
	NodeBB<T>* newNodeA = node -> get_Left();
	NodeBB<T>* newNodeB = newNodeA -> get_Right();
	node -> set_Left(newNodeB -> get_Right());
	newNodeB -> set_Right(node);
	newNodeA -> set_Right(newNodeB -> get_Left());
	newNodeB -> set_Left(newNodeA);
	if(newNodeB -> get_BalanceFactor() == -1) {
		newNodeA -> set_BalanceFactor(1);
	} 
	else {
		newNodeA -> set_BalanceFactor(0);
	}
	if(newNodeB -> get_BalanceFactor() == 1) {
		node -> set_BalanceFactor(-1);
	}
	else {
		node -> set_BalanceFactor(0);
	}
	newNodeB -> set_BalanceFactor(0);
	node = newNodeB;
}

/**
 * @brief      Rotates from right to left.
 *
 * @param      node  The node
 *
 * @tparam     T     The data type.
 */
template <class T>
void TreeAVL<T>::rotateRightToLeft (NodeBB<T>*& node) {
	std::cout << std::endl << "Rotation Right to Left" << std::endl;
	NodeBB<T>* newNodeA = node -> get_Right();
	NodeBB<T>* newNodeB = newNodeA -> get_Left();
	node -> set_Right(newNodeB -> get_Left());
	newNodeB -> set_Left(node);
	newNodeA -> set_Left(newNodeB -> get_Right());
	newNodeB -> set_Right(newNodeA);
	if(newNodeB -> get_BalanceFactor() == 1) {
		newNodeA -> set_BalanceFactor(-1);
	} 
	else {
		newNodeA -> set_BalanceFactor(0);
	}
	if(newNodeB -> get_BalanceFactor() == -1) {
		node -> set_BalanceFactor(1);
	}
	else {
		node -> set_BalanceFactor(0);
	}
	newNodeB -> set_BalanceFactor(0);
	node = newNodeB;
}

template <class T>
void TreeAVL<T>::remove (T data) {
	bool decreasses = false;
	remove(this -> root_, data, decreasses);
}

/**
 * @brief      Removes a node from the tree.
 *
 * @param      node        The node
 * @param[in]  data        The data
 * @param      decreasses  The decreasses
 *
 * @tparam     T           The data type.
 */
template <class T>
void TreeAVL<T>::remove (NodeBB<T>*& node, T data, bool& decreasses) {
	if(!node) {
		std::cout << std::endl << "The node you're trying to remove is in AVL" << std::endl;
		return;
	}

	if(data < node -> get_Data()) {
		remove(node -> get_Left(), data, decreasses);
		if(decreasses) {
			removeReBalancingLeft(node, decreasses);
		}
	} 
	else if(data > node -> get_Data()) {
		remove(node -> get_Right(), data,decreasses);
		if(decreasses) {
			removeReBalancingRight(node, decreasses);
		}
	} 
	else {
		NodeBB<T>* removed = node;
		if(!node -> get_Left()) {
			node = node -> get_Right();
			decreasses = true;
		} 
		else if(!node -> get_Right()) {
			node = node -> get_Left();
			decreasses = true;
		} 
		else {
			raise(removed, node -> get_Left(), decreasses);
			if(decreasses) {
				removeReBalancingLeft(node, decreasses);
			}
		}
		delete removed;
	}
}

/**
 * @brief      Swaps the data to remove with the biggest of the specified branch.
 *
 * @param      removed     The removed
 * @param      newNode     The new node
 * @param      decreasses  The decreasses
 *
 * @tparam     T           The data type.
 */
template <class T>
void TreeAVL<T>::raise ( NodeBB<T>*& removed, NodeBB<T>*& newNode, bool& decreasses) {
	if (newNode -> get_Right()) {
		raise(removed, newNode -> get_Right(), decreasses);
		if (decreasses) {
			removeReBalancingRight(newNode, decreasses);
		}
	}
	else {
		removed -> set_Data(newNode -> get_Data());
		removed = newNode;
		newNode = newNode -> get_Left();
		decreasses = true;
	}
}

/**
 * @brief      Removes re balancing left.
 *
 * @param      node        The node
 * @param      decreasses  The decreasses
 *
 * @tparam     T           The data type.
 */
template <class T>
void TreeAVL<T>::removeReBalancingLeft (NodeBB<T>*& node, bool& decreasses) {
	NodeBB<T>* newNode = node -> get_Right();
	switch (node -> get_BalanceFactor()) {
		case 0:
			node -> set_BalanceFactor(-1);
			decreasses = false;
			break;

		case 1:
			node -> set_BalanceFactor(0);
			break;

		case -1:
			if (node -> get_BalanceFactor() > 0) {
				rotateRightToLeft(node);
			}
			else {
				if (newNode -> get_BalanceFactor() == 0) {
					decreasses = false;
				}
				rotateRightToRight(node);
			}
			break;
	}
}

/**
 * @brief      Removes re balancing right.
 *
 * @param      node        The node
 * @param      decreasses  The decreasses
 *
 * @tparam     T           The data type.
 */
template <class T>
void TreeAVL<T>::removeReBalancingRight (NodeBB<T>*& node, bool& decreasses) {
	NodeBB<T>* newNode = node -> get_Left();
	switch (node -> get_BalanceFactor()) {
		case 0:
			node -> set_BalanceFactor(1);
			decreasses = false;
			break;

		case 1:
			if (node -> get_BalanceFactor() < 0) {
				rotateLeftToRight(node);
			}
			else {
				if (newNode -> get_BalanceFactor() == 0) {
					decreasses = false;
				}
				rotateLeftToLeft(node);
			}
			break;

		case -1:
			node -> set_BalanceFactor(0);
			break;
	}
}
