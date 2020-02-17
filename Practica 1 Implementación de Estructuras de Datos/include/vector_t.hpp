/*===================================================================================
=====================================================================================
	=                                                                              =
	=            Proyecto:      Práctica 1 Implementación de Estructuras de Datos  =
	=            Archivo:       vector_t.hpp                                       =
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

#include <cstdio>
#include <iomanip>
#include <cassert>
#include <iostream>

/*------------------------------------------------*/


template <class TDato>

class Vector_t
{
	private: 
		/*===============================
		=            Attribs            =
		===============================*/

		int size_;
		TDato* vector_;
		
		/*=====  End of Attribs  ======*/
				

	public:
		/*============================================
		=            Builders & Destroyer            =
		============================================*/
		/**
		 * @brief      Constructs a new instance.
		 */
		Vector_t(void):
		vector_(NULL), size_(0)
		{}

		/**
		 * @brief      Constructs a new instance.
		 *
		 * @param[in]  size  The size
		 */
		Vector_t(int size):
		vector_(NULL), size_(size)
		{
			build(size_);
		}

		/**
		 * @brief      Constructs a new instance by copying another vector_t
		 *
		 * @param[in]  v     A Vector_t
		 */
		Vector_t(const Vector_t& v):
		vector_(NULL), size_(v.size_)
		{
			build(size_);
			for (int i = 0; i < size_; i++)
				vector_[i] = v.vector_[i];
		}

		/**
		 * @brief      Destroys the object.
		 */
		~Vector_t(void)
		{
			destroy();
		}
		
		/*=====  End of Builders & Destroyer  ======*/
		

		
		/*=================================
		=            Functions            =
		=================================*/
		void build(int size)
		{
		    vector_ = new TDato[size];
		}

		void destroy(void)
		{
		    if (vector_ != NULL){
		        delete [] vector_;
		        vector_ = NULL;
		    }
		}
		/**
		 * @brief      Resize vector's size
		 *
		 * @param[in]  size  The size
		 */
		void resize(int size)
		{
			assert(size >= 0);
			destroy();
			size_ = size;
			build(size_);
		}

		/**
		 * @brief      Gets the size.
		 *
		 * @return     The size.
		 */
		int get_size(void) const
		{
			return size_;
		}

		/**
		 * @brief      Returns the value on a specific position at the vector
		 *
		 * @param[in]  i     Position at the vector
		 *
		 * @return     Value at i position
		 */
		TDato& at(int i)
		{
			assert(i < size_);
			return vector_[i];
		}

		/**
		 * @brief      Returns the value on a specific position at the vector
		 *
		 * @param[in]  i     Position at the vector
		 *
		 * @return     Value at i position
		 */
		TDato at(int i) const
		{
			assert(i < size_);
			return vector_[i];
		}
		
		/*=====  End of Functions  ======*/
		
	

		/*=========================================
		=            Operators Oveload            =
		=========================================*/
		/**
		 * @brief      Array indexer operator.
		 *
		 * @param[in]  i     Position at the vector
		 *
		 * @return     The result of the array indexer
		 */
		TDato& operator[](int i)
		{
			return at(i);
		}

		/**
		 * @brief      Array indexer operator.
		 *
		 * @param[in]  i     Position at the vector
		 *
		 * @return     The result of the array indexer
		 */
		TDato  operator[](int i) const
		{
			return at(i);
		}


		/**
		 * @brief      Addition operator.
		 *
		 * @param      v1    The v 1
		 *
		 * @return     The result of the addition
		 */
		Vector_t operator+(Vector_t& v1)
		{
			assert(v1.get_size() == size_);

			Vector_t aux(size_);
			for (int i = 0; i < size_; i++)
				aux[i] = v1[i] + vector_[i];
			return aux;
		}


		/**
		 * @brief      Subtraction operator.
		 *
		 * @param      v1    The v 1
		 *
		 * @return     The result of the subtraction
		 */
		Vector_t operator-(Vector_t& v1)
		{
			assert(v1.get_size() == size_);

			Vector_t aux(size_);
			for (int i = 0; i < size_; i++)
				aux[i] = v1[i] - vector_[i];
			return aux;
		}


		/**
		 * @brief      Assignment operator.
		 *
		 * @param[in]  v     The new vector
		 *
		 * @return     The result of the assignment
		 */
		Vector_t& operator=(const Vector_t& v)
		{
		    resize(v.size_);
		    
		    for(int i = 0; i < size_; i++)
		        vector_[i] = v.vector_[i];
		        
		     return *this;
		}

		/**
		 * @brief      Bitwise left shift operator.
		 *
		 * @param      cout  The cout
		 * @param[in]  v     New vector to write
		 *
		 * @return     The result of the bitwise left shift
		 */
		/*std::ostream& operator<<(std::ostream& cout, const Vector_t& v)
		{
			v.write(cout);
		}*/

		/**
		 * @brief      Bitwise right shift operator.
		 *
		 * @param      cin   The cin
		 * @param      v     New vector to read
		 *
		 * @return     The result of the bitwise right shift
		 */
		/*std::istream& operator>>(std::istream& cin, Vector_t& v)
		{
			v.read(cin);
		}*/
		
		/*=====  End of Operators Oveload  ======*/
		


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
		std::ostream& write(std::ostream& cout) const
		{
			cout << std::setw(3) << size_ << std::endl;
			for(int i = 0; i < size_; i++)
					cout << std::setw(3) << vector_[i] << " ";
			cout << std::endl;
		}

		/**
		 * @brief      Reads a vector from console or from file
		 *
		 * @param      cin   The cin
		 *
		 * @return     The file in case it's by file
		 */
		std::istream& read(std::istream& cin)
		{
			//std::cout << "Type the size of the vector: " << std::endl;
			cin >> size_;
			resize(size_);
			for(int i = 0; i < size_; i++)
				cin >> vector_[i];
		}
		
		/*=====  End of Read & Write  ======*/
};

