/*===================================================================================
=====================================================================================
	=                                                                              =
	=            Proyecto:      Práctica 1 Implementación de Estructuras de Datos  =
	=            Archivo:       list_t.hpp                                         =
	=            Autor:         Adrián Epifanio Rodríguez Hernández                =
	=            Fecha:         13/02/2020                                         =
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
#include <cassert>

/*------------------------------------------------*/

/*----------  DECLARACION DE FUNCIONES  ----------*/

#include "node_t.hpp"

/*------------------------------------------------*/

template <class TDato>

class List_t//Doubly linked list
{
	private:
		/*===============================
		=            Attribs            =
		===============================*/
		
		Node_t<TDato>* head_;
		Node_t<TDato>* tail_;
		int size_;		
		
		/*=====  End of Attribs  ======*/
		

	public:
		/*===========================================
		=            Builder & Destroyer            =
		===========================================*/
		/**
		 * @brief      Constructs a new instance.
		 */
		List_t():
		head_(NULL), tail_(NULL), size_(0)
		{}

		/**
		 * @brief      Destroys the object.
		 */
		~List_t(void)
		{
			Node_t<TDato>* aux = NULL;
			while(head_ != NULL) 
			{
				aux = head_;
				head_ = head_ -> get_next();
				delete aux;
				aux = NULL;
			}
			size_ = 0;
			head_ = NULL;
			tail_ = NULL;
		}		
		
		/*=====  End of Builder & Destroyer  ======*/
		
		

		/*=========================================
		=            Setters & Getters            =
		=========================================*/
		/**
		 * @brief      Gets the head node.
		 *
		 * @return     The head.
		 */
		Node_t<TDato>* get_head(void)
		{
			return head_;
		}

		/**
		 * @brief      Gets the tail node.
		 *
		 * @return     The tail.
		 */
		Node_t<TDato>* get_tail(void)
		{
			return tail_;
		}

		/**
		 * @brief      Gets the size.
		 *
		 * @return     The size.
		 */
		int get_size(void)
		{
			return size_;
		}

		/**
		 * @brief      Sets the head.
		 *
		 * @param      head  The head
		 */
		void set_head(Node_t<TDato>* head)
		{
			head_ = head;
		}

		/**
		 * @brief      Sets the tail.
		 *
		 * @param      tail  The tail
		 */
		void set_tail(Node_t<TDato>* tail)
		{
			tail_ = tail;
		}

		/**
		 * @brief      Sets the size.
		 *
		 * @param[in]  size  The size
		 */
		void set_size(int size)
		{
			size_ = size;
		}		
		
		/*=====  End of Setters & Getters  ======*/
		
		

		/*=================================
		=            Functions            =
		=================================*/
		/**
		 * @brief      Determines if empty.
		 *
		 * @return     True if empty, False otherwise.
		 */
		bool isEmpty(void)
		{
			if(head_ == NULL)
			{
				assert(tail_ == NULL);
				assert(size_ == 0);
				return true;
			} 
			else 
			   return false;
		}

		/**
		 * @brief      Insert a node on the head
		 *
		 * @param      node  The node
		 */
		void insert_head(Node_t<TDato>* node) 
		{
			assert(node != NULL);
			if (isEmpty()) 
			{
				head_ = node;
				tail_ = head_;
			}
			else 
			{
				head_ -> set_prev(node);
				node -> set_next(head_);
				head_ = node;
			}
			size_++;
		}

		/**
		 * @brief      Insert a node on the tail
		 *
		 * @param      node  The node
		 */
		void insert_tail(Node_t<TDato>* node) 
		{
			assert(node != NULL);
			if (isEmpty()) 
			{
				head_ = node;
				tail_ = head_;
			} 
			else 
			{
				tail_ -> set_next(node);
				node -> set_prev(tail_);
				tail_ = node;
			}
			size_++;
		}

		/**
		 * @brief      Extracts the node on the head
		 *
		 * @return     The head's node
		 */
		Node_t<TDato>* extract_head(void) 
		{
	        assert(!isEmpty());
	        Node_t<TDato>* aux = head_;
	        head_ = head_ -> get_next();
	        if (head_)
	            head_ -> set_prev(NULL);
	        else
	            tail_ = NULL;
	        size_--;
			aux -> set_next(NULL);
			aux -> set_prev(NULL);
	        return aux;
	    }

	    /**
	     * @brief      Extracts the node on the tail
	     *
	     * @return     The tail's node
	     */
	    Node_t<TDato>* extract_tail(void) 
	    {
	        assert(!isEmpty());
	        Node_t<TDato>* aux = tail_;
	        tail_ = tail_ -> get_prev();
	        if (tail_ != NULL)
	            tail_ -> set_next(NULL);
	        else
	            head_ = NULL;
	        size_--;
			aux -> set_next(NULL);
			aux -> set_prev(NULL);
	        return aux;
	    }

	    /**
	     * @brief      Removes the specified node.
	     *
	     * @param      node  The node
	     */
	    void remove(Node_t<TDato>* node) 
	    {
		    assert(node != NULL);
	        if (node -> get_prev() != NULL)
	            node -> get_prev() -> set_next(node -> get_next());
	        else
	            head_ = node -> get_next();
	        if (node -> get_next() != NULL)
	            node -> get_next() -> set_prev(node -> get_prev());
	        else
	            tail_ = node -> get_prev();

			delete node;
	        size_--;
	    }

	    /**
	     * @brief      Extracts a node from the list
	     *
	     * @param      node  The node
	     *
	     * @return     Extracted node
	     */
	    Node_t<TDato> extract_Node(Node_t<TDato>* node) 
	    {
		    assert(node != NULL);
	        if (node -> get_prev() != NULL)
	            node -> get_prev() -> set_next(node -> get_next());
	        else
	            head_ = node -> get_next();
	        if (node -> get_next() != NULL)
	            node -> get_next() -> set_prev(node -> get_prev());
	        else
	            tail_ = node -> get_prev();

	        size_--;
	        return node;
	    }

	    /**
	     * @brief      Finds a node.
	     *
	     * @param      node  The node
	     */
	    void find_Node(Node_t<TDato>* node)
	    {

	    	assert(node != NULL);

	    	if(isEmpty())
	    		std::cout << "Node not found" << std::endl;
	    	else
	    	{
	    		Node_t<TDato>* aux = get_head();
	    		for(int i = 0; i < size_; i++)
	    		{
	    			if(aux -> get_data() == node -> get_data())
	    				return true;
	    			else
	    				/*if(aux -> get_next() == NULL)
	    					return false;
	    				else*/
	    				aux -> get_next();
	    		}
	    	}
	    }		
		
		/*=====  End of Functions  ======*/
		
		

	    /*====================================
	    =            Read & Write            =
	    ====================================*/
	    /**
		 * @brief      Prints or write the vector
		 *
		 * @param      cout  The cout
		 *
		 * @return     The file in case it's by file
		 */
	    std::ostream& write(std::ostream& cout) 
	    {			
	        Node_t<TDato>* aux = head_;
	        while (aux != NULL) {
	            aux -> write(cout);
	            aux = aux -> get_next();
	        }
			return cout;
	    }
	    
	    /*=====  End of Read & Write  ======*/
	    	    
};