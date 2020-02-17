/*===================================================================================
=====================================================================================
	=                                                                              =
	=            Proyecto:      Práctica 1 Implementación de Estructuras de Datos  =
	=            Archivo:       stack_t.hpp                                        =
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
#include <iomanip>

/*------------------------------------------------*/

/*----------  DECLARACION DE FUNCIONES  ----------*/

#include "list_t.hpp"

/*------------------------------------------------*/

template <class TDato>

class Stack_t
{
	private:
		/*===============================
		=            Attribs            =
		===============================*/
		
		List_t<TDato>    list_;
		
		/*=====  End of Attribs  ======*/
		
		
	public:	
		/*===========================================
		=            Builder & Destroyer            =
		===========================================*/
		
		/**
		 * @brief      Constructs a new instance.
		 */
		Stack_t(void):
		list_() {}

		/**
		 * @brief      Destroys the object.
		 */
		~Stack_t(void) {}		
		
		/*=====  End of Builder & Destroyer  ======*/
		


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
			return list_.isEmpty();
		}

		/**
		 * @brief      Gets the data of the top of the stack
		 *
		 * @return     data from the top of the stack
		 */
		TDato top(void)
		{
			assert(!isEmpty());
			Node_t<TDato>* node = list_.get_head();
			TDato data = node -> get_data();
			return (data);
		}

		/**
		 * @brief      Pops the object.
		 */
		void pop(void)
		{
			assert(!isEmpty());			
			Node_t<TDato>* node = list_.extract_head();
			delete node;
		}

		/**
		 * @brief      Push data into the stack
		 *
		 * @param[in]  dato  The dato
		 */
		void push(TDato dato)
		{
			Node_t<TDato>* node = new Node_t<TDato>(dato);
			list_.insert_head(node);
		}
				
		/*=====  End of Functions  ======*/
		
		

		/*====================================
		=            Read & Write            =
		====================================*/
		
		/**
		 * @brief      Prints by console or writes in a file the stack data
		 *
		 * @param      cout  The cout
		 *
		 * @return     The file in case it's by file
		 */
		std::ostream& write(std::ostream& cout)
		{
			Node_t<TDato>* aux = list_.get_head();
			while(aux != NULL)
			{
				cout << " │ " << std::setw(2) << aux -> get_data() << "  │" << std::endl;
				aux = aux -> get_next();
			}
			cout << " └─────┘" << std::endl; 
		}
		
		/*=====  End of Read & Write  ======*/
		
		
};