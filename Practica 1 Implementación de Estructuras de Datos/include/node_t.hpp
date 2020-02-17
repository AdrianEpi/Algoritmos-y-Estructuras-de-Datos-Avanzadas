/*===================================================================================
=====================================================================================
	=                                                                              =
	=            Proyecto:      Práctica 1 Implementación de Estructuras de Datos  =
	=            Archivo:       node_t.hpp                                         =
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

/*------------------------------------------------*/

template <class TDato>

class Node_t
{
	private: 
		/*===============================
		=            Attribs            =
		===============================*/
		
		TDato data_;
		Node_t* next_;
		Node_t* prev_;
				
		/*=====  End of Attribs  ======*/
		
	public:
		/*============================================
		=            Builders & Destroyer            =
		============================================*/
		/**
		 * @brief      Constructs a new instance.
		 */
		Node_t(void):
		data_(), next_(NULL), prev_(NULL)
		{}

		/**
		 * @brief      Constructs a new instance.
		 *
		 * @param[in]  data  The data
		 */
		Node_t(const TDato& data):
		data_(), next_(NULL), prev_(NULL)
		{
			data_ = data;
		}

		/**
		 * @brief      Destroys the object.
		 */
		~Node_t(void)
		{}		
		
		/*=====  End of Builders & Destroyer  ======*/
		
		

		/*=========================================
		=            Setters & Getters            =
		=========================================*/
		/**
		 * @brief      Gets the data.
		 *
		 * @return     The data.
		 */
		TDato get_data(void)
		{
			return data_;
		}

		/**
		 * @brief      Gets the next.
		 *
		 * @return     The next.
		 */
		Node_t* get_next(void)
		{
			return next_;
		}

		/**
		 * @brief      Gets the previous.
		 *
		 * @return     The previous.
		 */
		Node_t* get_prev(void)
		{
			return prev_;
		}
		/**
		 * @brief      Sets the data.
		 *
		 * @param[in]  data  The data
		 */
		void set_data(TDato data)
		{
			data_ = data;
		}

		/**
		 * @brief      Sets the next.
		 *
		 * @param      next  The next
		 */
		void set_next(Node_t* next)
		{
			next_ = next;
		}

		/**
		 * @brief      Sets the previous.
		 *
		 * @param      prev  The previous
		 */
		void set_prev(Node_t* prev)
		{
			prev_ = prev;
		}
		
		/*=====  End of Setters & Getters  ======*/
		
		

		/*====================================
		=            Read & Write            =
		====================================*/
		/**
		 * @brief      Prints by console or writes in a file the node data
		 *
		 * @param      cout  The cout
		 *
		 * @return     The file in case it's by file
		 */
		std::ostream& write(std::ostream& cout) const
		{
			cout << data_;
			return cout;
		}
				
		/*=====  End of Read & Write  ======*/
		
};