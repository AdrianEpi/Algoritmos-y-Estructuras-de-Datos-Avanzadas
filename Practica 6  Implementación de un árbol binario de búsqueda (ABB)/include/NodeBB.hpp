#pragma once
#include <cstdio>
#include <iostream>

template <class T>
class NodeBB {

	private:
		T data_;
		NodeBB* left_;
		NodeBB* right_;

	public:
		// Builders & Destroyer
		NodeBB (void);
		NodeBB (const T data, NodeBB<T>* left=NULL, NodeBB<T>* right=NULL);
		virtual ~NodeBB (void);

		// Getters & Setters
		T get_Data (void) const;
		NodeBB*& get_Left (void) const;
		NodeBB*& get_Right (void) const;

		void set_Data (T data);
		void set_Left (NodeBB* left);
		void set_Right (NodeBB* right);

		// Write
		void write(void) const;
};

/**
 * @brief      Constructs a new object.
 *
 * @tparam     T     The data type
  */
template <class T>
NodeBB<T>::NodeBB (void) {
	set_Left(NULL);
	set_Right(NULL);
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
NodeBB<T>::NodeBB (const T data, NodeBB<T>* left, NodeBB<T>* right) {
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
NodeBB<T>::~NodeBB (void) {
	if (left_ != NULL){
		delete left_;
		left_ = NULL;
	}
	if (right_ != NULL){
		delete right_;
		right_ = NULL;
	}
}


/**
 * @brief      Gets the data.
 *
 * @tparam     T     The data type.
 *
 * @return     The data.
 */
template <class T>
T NodeBB<T>::get_Data (void) const {
	return data_;
}


/**
 * @brief      Gets the left.
 *
 * @tparam     T     The data type.
 *
 * @return     The left.
 */
template <class T>
NodeBB<T>*& NodeBB<T>::get_Left (void) const {
	return left_;
}

/**
 * @brief      Gets the right.
 *
 * @tparam     T     The data type.
 *
 * @return     The right.
 */
template <class T>
NodeBB<T>*& NodeBB<T>::get_Right (void) const {
	return right_;
}


/**
 * @brief      Sets the data.
 *
 * @param[in]  data  The data
 *
 * @tparam     T     The data type.
 */
template <class T>
void NodeBB<T>::set_Data (T data) {
	data_ = data;
}


/**
 * @brief      Sets the left.
 *
 * @param      left  The left
 *
 * @tparam     T     The data type.
 */
template <class T>
void NodeBB<T>::set_Left (NodeBB* left) {
	left_ = left;
}


/**
 * @brief      Sets the right.
 *
 * @param      right  The right
 *
 * @tparam     T      The data type.
 */
template <class T>
void NodeBB<T>::set_Right (NodeBB* right) {
	right_ = right;
}

/**
 * @brief      Prints the node on screen
 *
 * @tparam     T     The data type.
 */
template <class T>
void NodeBB<T>::write(void) const {
	if (this == NULL){
		std::cout << "[.]";
	}
	else{
		std::cout << "[" << data_ << "]";
	}
}