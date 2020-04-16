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
* @Last Modified time: 2020-04-16 08:31:29
*/
/*----------  DECLARACION DE FUNCIONES  ----------*/

#include "../include/experiment.hpp"

/*------------------------------------------------*/

/**
 * @brief      Constructs a new instance.
 */
Experiment::Experiment () {
	set_CellNum(0);
	set_BlockNum(0);
	set_ChargeFactor(0.0);
	set_Table(NULL);
}

/**
 * @brief      Destroys the object.
 */
Experiment::~Experiment () {
	set_CellNum(0);
	set_BlockNum(0);
	set_ChargeFactor(0.0);
	if (table_) {
		delete table_;
		set_Table(NULL);
	}
}

/**
 * @brief      Gets the cell number.
 *
 * @return     The cell number.
 */
int Experiment::get_CellNum (void) const {
	return cellNum_;
}

/**
 * @brief      Gets the block number.
 *
 * @return     The block number.
 */
int Experiment::get_BlockNum (void) const {
	return blockNum_;
}

/**
 * @brief      Gets the charge factor.
 *
 * @return     The charge factor.
 */
double Experiment::get_ChargeFactor (void) const {
	return chargeFactor_;
}

/**
 * @brief      Gets the try number.
 *
 * @return     The try number.
 */
int Experiment::get_TryNum (void) const {
	return tryNum_;
}

/**
 * @brief      Gets the table.
 *
 * @return     The table.
 */
Table<DNI>* Experiment::get_Table (void) const {
	return table_; 
}

/**
 * @brief      Sets the cell number.
 *
 * @param[in]  cellNum  The cell number
 */
void Experiment::set_CellNum (int cellNum) {
	cellNum_ = cellNum;	
}

/**
 * @brief      Sets the block number.
 *
 * @param[in]  blockNum  The block number
 */
void Experiment::set_BlockNum (int blockNum) {
	blockNum_ = blockNum;
}

/**
 * @brief      Sets the charge factor.
 *
 * @param[in]  chargeFactor  The charge factor
 */
void Experiment::set_ChargeFactor (double chargeFactor) {
	chargeFactor_ = chargeFactor;
}

/**
 * @brief      Sets the try number.
 *
 * @param[in]  tryNum  The try number
 */
void Experiment::set_TryNum (int tryNum) {
	tryNum_ = tryNum;
}

/**
 * @brief      Sets the table.
 *
 * @param      table  The table
 */
void Experiment::set_Table (Table<DNI>* table) {
	table_ = table; 
}

/**
 * @brief      Initializes the object.
 */
void Experiment::initialize (void) {
	std::cout << "Introduce the cells number: ";
	std::cin >> cellNum_;
	std::cout << "Introduce the blocks ammount per cell: ";
	std::cin >> blockNum_;
	do {
		std::cout << "Introduce the exploration function" << std::endl;
		std::cout << "1. Linear" << std::endl;
		std::cout << "2. Quadratic" << std::endl;
		std::cout << "3. Double" << std::endl;
		std::cout << "4. ReDispersion" << std::endl;
		std::cin >> explorationSelector_;
		if (explorationSelector_ == 2) {
			if (isPrime(get_CellNum()) == false) {
				set_CellNum(findPrime(get_CellNum()));
				std::cout << "WARNING. The Quadratic exploration needs a prime ammount of cells it will be set to: " << get_CellNum() << std::endl;
			}
		}
		std::cout << "Introduce the dispersion function" << std::endl;
		std::cout << "1. Module" << std::endl;
		std::cout << "2. Sum" << std::endl;
		std::cout << "3. PseudoRandom" << std::endl;
		std::cout << "4. Sum2" << std::endl;
		std::cin >> dispersionSelector_;

		std::cout << "Introduce the charge factor: ";
		std::cin >> chargeFactor_;				
		table_ = new Table<DNI>(get_CellNum(), get_BlockNum(), explorationSelector_ , dispersionSelector_);
	}while (table_ == NULL);

	unsigned aux;
	aux =  (get_ChargeFactor() * get_CellNum() * get_BlockNum());
	bench_ = new DNI*[aux];
	for (int i = 0; i < aux; i++)
		bench_[i] = new DNI((rand() % 50000000) + 30000000);

	std::cout << std::endl << "Introduce the number of attemps for search and insert tests: ";
	std::cin >> tryNum_;
}

/**
 * @brief      Restart the experiment
 */
void Experiment::restart (void) {
	this -> ~Experiment();
	initialize();
}

/**
 * @brief      Loads a data.
 */
void Experiment::loadData (void) {
	int i = 0;
	double p = 0.0;
	while ((table_ -> insert(*bench_[i])) && (fabs(p - chargeFactor_) > 0.1)) {
		i++;
		p = (double(i) / double(cellNum_ * blockNum_));
	}
	std::cout << std::endl << std::endl << "\t\tORIGINAL TABLE" << std::endl;
	table_ -> write();
}

/**
 * @brief      Test the insertions.
 */
void Experiment::testInsert (void) {
	saver_[0] = MAXTEST;
	saver_[1] = 1;
	int aux;
	int i = 0;
	int N = (get_ChargeFactor() * get_CellNum() * blockNum_);
	int j = 0;
	while ((i < tryNum_) && (j < N)) {
		table_ -> insert(*bench_[j], aux);
		i++;
		j++;
		if (aux < saver_[0])
			saver_[0] = aux;
		if (aux > saver_[1])
			saver_[1] = aux;
	}
}

/**
 * @brief      Test the searching.
 */
void Experiment::testSearch (void) {
	saver_[0] = MAXTEST;
	saver_[1] = 1;
	int comp;
	int i = 0;
	int j = 0;
	int N = (get_ChargeFactor() * get_CellNum() * blockNum_);
	while ((i < tryNum_) && (j < N))	{
		table_ -> search(*bench_[j], comp);
		i++;
		j++;
		if (comp < saver_[0])
			saver_[0] = comp;
		if (comp > saver_[1])
			saver_[1] = comp;
	}
}

/**
 * @brief      Determines whether the specified number is prime.
 *
 * @param[in]  number  The number
 *
 * @return     True if the specified number is prime, False otherwise.
 */
bool Experiment::isPrime (unsigned number) {
	for (int i = 2; i <= sqrt(number); i++)
		if ((number % i) == 0)
			return false;
	
	return true;
}

/**
 * @brief      Finds a prime.
 *
 * @param[in]  number  The number
 *
 * @return     The biggest prime lower than the number
 */
unsigned Experiment::findPrime(unsigned number) {
	unsigned max;
	bool isPrime;
	for (int i = number - 1; i > 2; i--) {
		isPrime = true;
		for (int j = 2; j < i; j++) {
			if ((i % j) == 0)
				isPrime = false;
			max = i;
		}
		if (isPrime)
			return max;
	}
}

/**
 * @brief      Prints the data on screen
 */
void Experiment::write (void) {
	int testInsert_[3];
	int testSearch_[3];
	std::string exploration;
	testSearch();
	testSearch_[0] = saver_[0];
	testSearch_[1] = (saver_[0] + saver_[1]) / 2;
	testSearch_[2] = saver_[1];
	testInsert();
	testInsert_[0] = saver_[0];
	testInsert_[1] = (saver_[0] + saver_[1]) / 2;
	testInsert_[2] = saver_[1];
	switch (explorationSelector_) {
		case 1:
			exploration = "Linear";
			break;
		
		case 2:
			exploration = "Quadratic";
			break;
		
		case 3:
			exploration = "Double";
			break;
		
		case 4:
			exploration = "ReDispersion";
			break;
	}
	std::cout << std::endl << std::endl << "\t\t UPDATED TABLE" << std::endl;
	table_ -> write();
	std::cout << std::endl;
	std::cout << std::endl << std::endl << "\tRESULTS OF THE EXPERIMENT  -" << std::endl << std::endl << "Cells\tBlocks\t\tExploration\tChargeFactor\tNumberOfAttemps" << std::endl << cellNum_ << "\t  " << blockNum_ << "\t\t  " << exploration << "\t  " << chargeFactor_ << "\t\t  " << tryNum_ << std::endl << std::endl << "Comparations\tMinimum\t\tMedium\t\tMaximum" << std::endl;
	std::cout << "Searching:\t  " << testSearch_[0] << "\t\t  " << testSearch_[1] << "\t\t  " << testSearch_[2] << std::endl;
	std::cout << "Insertions:\t  " << testInsert_[0] << "\t\t  " << testInsert_[1] << "\t\t  " << testInsert_[2] << std::endl;
	std::cout << std::endl;
}