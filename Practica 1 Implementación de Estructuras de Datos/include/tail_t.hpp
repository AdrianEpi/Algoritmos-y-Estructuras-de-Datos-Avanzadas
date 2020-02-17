/*===================================================================================
=====================================================================================
	=                                                                              =
	=            Proyecto:      Práctica 1 Implementación de Estructuras de Datos  =
	=            Archivo:       tail_t.hpp                                         =
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
/*----------  DECLARACION DE FUNCIONES  ----------*/

//#include "list_t.hpp"

/*------------------------------------------------*/

template <class TDato>

class Tail_t
{
	private:
		/*===============================
		=            Attribs            =
		===============================*/
		
		List_t<TDato>* tail_;
		int size_;
		
		/*=====  End of Attribs  ======*/

	public:
		/*============================================
		=            Builders & Destroyer            =
		============================================*/
		/**
		 * @brief      Constructs a new instance.
		 */
		Tail_t(void):
		tail_(NULL), size_(0)
		{}

		/**
		 * @brief      Constructs a new instance.
		 *
		 * @param[in]  size  The size
		 */
		Tail_t(int size):
		tail_(NULL), size_(size)
		{
			size_ = size;
		}

		/**
		 * @brief      Constructs a new instance.
		 *
		 * @param      tail  The tail
		 */
		Tail_t(List_t<TDato>* tail):
		tail_(NULL), size_(tail -> get_size())
		{
			tail_ = tail;
			size_ = tail -> get_size();
		}

		/**
		 * @brief      Destroys the object.
		 */
		~Tail_t(void)
		{}
		
		/*=====  End of Builders & Destroyer  ======*/
		
		

		/*=========================================
		=            Setters & Getters            =
		=========================================*/
		/**
		 * @brief      Gets the tail.
		 *
		 * @return     The tail.
		 */
		List_t<TDato> get_tail(void)
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
		 * @brief      Sets the tail.
		 *
		 * @param[in]  tail  The tail
		 */
		void set_tail(List_t<TDato> tail)
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
		 * @brief      Push a node into the tail
		 *
		 * @param      node  The node
		 */
		void push(Node_t<TDato>* node)
		{
			if(tail_ -> get_size() < size_)
				if((tail_ -> find_Node(node)) == false)
					tail_ -> insert_head(node);
			else
				FIFO(node);
		}

		/**
		 * @brief      Inserts a node aplying FIFO (First In First Out)
		 *
		 * @param      node  The node
		 */
		void FIFO(Node_t<TDato>* node)
		{
			if(((tail_ -> find_Node(node)) == false) && (tail_ -> get_size() < size_))
			{
				Node_t<TDato>* trash;
				trash = tail_ -> extract_tail();
				tail_->insert_head(node);
			}
		}
		
		/*=====  End of Functions  ======*/

};
