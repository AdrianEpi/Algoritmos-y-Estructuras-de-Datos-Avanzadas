/*===================================================================================
=====================================================================================
	=                                                                              =
	=            Proyecto:      Práctica 2 El juego de la vida                     =
	=            Archivo:       celula.hpp                                         =
	=            Autor:         Adrián Epifanio Rodríguez Hernández                =
	=            Fecha:         02/03/2020                                         =
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

/*----------  DECLARACION DE FUNCIONES  ----------*/

#pragma once

/*------------------------------------------------*/

class Tablero;
class Celula 
{
	
	private:
		// Attribs
		int estado_;
		std::pair<int, int> posicion_; //(i, j)
		int num_vecinas_vivas_;


	public:
		// Builders & Destroyer
		Celula(){};
		Celula(int i, int j);
		~Celula(){};

		// Getters & Setters
		int get_Estado(void) const;
		std::pair<int, int> get_Posicion(void);
		int get_VecinasVivas(void);

		void set_Estado(int estado);
		void set_Posicion(std::pair<int, int> pos);
		void set_Posicion(int i, int j);
		void set_VecinasVivas(int num);

		// Functions
		int actualizarEstado(void);
		int contarVecinas(const Tablero& board);

		// Operatos overload
		friend std::ostream& operator<<(std::ostream& cout, const Celula celuu);
		Celula operator=(int estado);
};