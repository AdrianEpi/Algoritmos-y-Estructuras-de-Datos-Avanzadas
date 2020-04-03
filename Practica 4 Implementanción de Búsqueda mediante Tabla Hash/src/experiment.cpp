/*===================================================================================
=====================================================================================
	=                                                                              =
	=            Proyecto:      Práctica 4 Implementación de Búsqueda Tabla Hash   =
	=            Archivo:       explorationDouble.cpp                              =
	=            Autor:         Adrián Epifanio Rodríguez Hernández                =
	=            Fecha:         30/03/2020                                         =
	=            Asignatura:    Algoritmos y Estructuras de Datos Avazados         =
	=            Lenguaje:      C++                                                =
	=            Correo:        alu0101158280@ull.edu.es                           =
	=            Lugar:         Universidad De La Laguna                           =
	=                           Escuela Superior de Ingeniería y Tecnología        =
	=                                                                              =
=====================================================================================
===================================================================================*/
/*
* @Author: Adrián Epifanio
* @Date:   2020-04-03 15:20:55
* @Last Modified by:   Adrián Epifanio
* @Last Modified time: 2020-04-03 16:40:26
*/
/*----------  DECLARACION DE FUNCIONES  ----------*/

#include "../include/experiment.hpp"

/*------------------------------------------------*/


/**
 * @brief      Constructs a new instance.
 */
Experiment::Experiment() {
	set_CellNum(0);
	set_BlockNum(0);
	set_ChargeFactor(0.0);
	set_TryNum(0);
	set_Table(NULL);
}

/**
 * @brief      Destroys the object.
 */
Experiment::~Experiment() {

}

/**
 * @brief      Gets the cell number.
 *
 * @return     The cell number.
 */
int Experiment::get_CellNum(void) const {
	return cellNum_;
}

/**
 * @brief      Gets the block number.
 *
 * @return     The block number.
 */
int Experiment::get_BlockNum(void) const {
	return blockNum_;
}

/**
 * @brief      Gets the charge factor.
 *
 * @return     The charge factor.
 */
double Experiment::get_ChargeFactor(void) const {
	return chargeFactor_;
}

/**
 * @brief      Gets the try number.
 *
 * @return     The try number.
 */
int Experiment::get_TryNum(void) const {
	return tryNum_;
}

/**
 * @brief      Gets the table.
 *
 * @return     The table.
 */
Table<DNI>* Experiment::get_Table(void) const {
	return table_; 
}

/**
 * @brief      Sets the cell number.
 *
 * @param[in]  cellNum  The cell number
 */
void Experiment::set_CellNum(int cellNum) {
	cellNum_ = cellNum;	
}

/**
 * @brief      Sets the block number.
 *
 * @param[in]  blockNum  The block number
 */
void Experiment::set_BlockNum(int blockNum) {
	blockNum_ = blockNum;
}

/**
 * @brief      Sets the charge factor.
 *
 * @param[in]  chargeFactor  The charge factor
 */
void Experiment::set_ChargeFactor(double chargeFactor) {
	chargeFactor_ = chargeFactor;
}

/**
 * @brief      Sets the try number.
 *
 * @param[in]  tryNum  The try number
 */
void Experiment::set_TryNum(int tryNum) {
	tryNum_ = tryNum;
}

/**
 * @brief      Sets the table.
 *
 * @param      table  The table
 */
void Experiment::set_Table(Table<DNI>* table) {
	table_ = table; 
}

void Experiment::initialize(void) {
	int aux;
	std::cout << std::endl << "Intoduce the cells number: ";
	std::cin >> aux;
	assert(aux >= 1);
	set_CellNum(aux);
	std::cout << std::endl << "Intoduce the blocks per cell: ";
	std::cin >> aux;
	assert(aux >= 1);
	set_CellNum(aux);

	int dispersionSelector = selectDispersion();
	int explorationSelector = selectExploration();

	if (explorationSelector == 2) {
		if(isPrime(get_CellNum()) == false) {
			set_CellNum(findPrime(get_CellNum()));
			std::cout << std::endl << "WARNING, for Quadratic exploration a prime numbers of cells is needed. The cells number will be changed to: " << get_CellNum() << std::endl;
		}
	}
	std::cout << std::endl << "Intoduce the charge factor: ";
	std::cin >> aux;
	assert(aux >= 0.0);
	set_CellNum(aux);
	table_ = new Table<DNI>(get_CellNum(), get_BlockNum(), explorationSelector, dispersionSelector);
}

void Experiment::restart(void) {
	this -> ~Experiment();
	initialize();
}

void Experiment::loadData(void) {

}

void Experiment::testInserts(void) {

}

void Experiment::testSearchs(void) {

}

/**
 * @brief      Determines whether the specified number is prime.
 *
 * @param[in]  number  The number
 *
 * @return     True if the specified number is prime, False otherwise.
 */
bool Experiment::isPrime(unsigned number) {
	for (int i = 2; i <= sqrt(number); i++)
		if((number % i) == 0)
			return false;
	return true;
}

/**
 * @brief      Finds a prime.
 *
 * @param[in]  number  The number
 *
 * @return     The prime number
 */
unsigned Experiment::findPrime(unsigned number) {
	bool prime;
	for (int i = (number - 1); i > 2; i--) {
		prime = true;
		for (int j = 2; j < i; j++)
			if ((i % j) != 0)
				prime = false;
		
		if (prime == true)
			return i;
	}
}

/**
 * @brief      Prints the menu for selecting the dispersion.
 *
 * @return     The dispersion choice
 */
int Experiment::selectDispersion (void) const {
	int selector = 0;
	while (selector <= 0 || selector >= 4) {
		system("clear");
		std::cout << std::endl << "Please select the dispersion: " << std::endl;
		std::cout << "1. Sum Dispersion" << std::endl;
		std::cout << "2. Module Dispersion" << std::endl;
		std::cout << "3. PseudoRandom Dispersion" << std::endl;
		std::cin >> selector;
	}
	return selector;
}

/**
 * @brief      Prints the menu for selecting the exploration.
 *
 * @return     The exploration choice.
 */
int Experiment::selectExploration (void) const {
	int selector = 0;
	while (selector <= 0 || selector >= 5) {
		system("clear");
		std::cout << std::endl << "Please select the exploration: " << std::endl;
		std::cout << "1. Linear Exploration" << std::endl;
		std::cout << "2. Quadratic Exploration" << std::endl;
		std::cout << "3. Double Exploration" << std::endl;
		std::cout << "4. ReDispersion Exploration" << std::endl;
		std::cin >> selector;
	}
	return selector;
}

void Experiment::write(void) {

}
