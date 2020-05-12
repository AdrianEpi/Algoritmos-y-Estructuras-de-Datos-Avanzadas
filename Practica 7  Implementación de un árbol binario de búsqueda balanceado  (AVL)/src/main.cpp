/*====================================================================================================
======================================================================================================
	=                                                                                           =
	=            Proyecto:      Práctica 6 Implementación de un Árbol Binario de Busqueda ABB   =
	=            Archivo:       main.cpp                                                        =
	=            Autor:         Adrián Epifanio Rodríguez Hernández                             =
	=            Fecha:         05/05/2020                                                      =
	=            Asignatura:    Algoritmos y Estructuras de Datos Avazados                      =
	=            Lenguaje:      C++                                                             =
	=            Correo:        alu0101158280@ull.edu.es                                        =
	=            Lugar:         Universidad De La Laguna                                        =
	=                           Escuela Superior de Ingeniería y Tecnología                     =
	=                                                                                           =
======================================================================================================
=====================================================================================================*/
/*
* @Author: Adrián Epifanio
* @Date:   2020-05-05 13:37:55
* @Last Modified by:   Adrian Epifanio
* @Last Modified time: 2020-05-12 20:34:16
*/
/*----------  DECLARACION DE FUNCIONES  ----------*/

#include "../include/Counter.hpp"
#include "../include/DNI.hpp"
#include "../include/TreeBB.hpp"
#include "../include/TreeAVL.hpp"

/*------------------------------------------------*/

int main(void){
	int option = -1;
	Counter trash;
	while (option != 0) {
		std::cout << std::endl << " \t\tMenu:";
		std::cout << std::endl << "\t 1. Demostration Mode";
		std::cout << std::endl << "\t 2. Statistic Mode";
		std::cout << std::endl << "\t 0. Exit" << std::endl;
		std::cin >> option;

		switch (option) {
			case 1: {
				system("clear");
				TreeAVL<DNI> tree_;
				tree_.write();
				int option2 = -1;
				while (option2 != 0) {
					std::cout << std::endl << std::endl << "\t\tChoose an option:";
					std::cout << std::endl << "\t1. Insert";
					std::cout << std::endl << "\t2. Delete";
					std::cout << std::endl << "\t0. Exit" << std::endl;
					std::cin >> option2;

					switch (option2) {
						case 1:{
							unsigned code;
							std::cout << "Introduce the code to insert: ";
							std::cin >> code;
							DNI newDNI(code);
							tree_.insert(newDNI, trash);
							std::cout << std::endl;
							tree_.write();
							break;
						}

						case 2: {
							unsigned code;
							std::cout << "Introduce the code to remove: ";
							std::cin >> code;
							DNI newDNI(code);
							tree_.remove(newDNI);
							std::cout << std::endl;
							tree_.write();
							break;
						}

						case 0: {
							exit(0);
							break;
						}
					}
				}
				break;
			}

			case 2: {
				srand(time(NULL));
				int n;
				int nTests;
				std::vector<DNI> testBench_;
				TreeAVL<DNI> tree_;

				std::cout << std::endl << "\t\tStatistic Mode";
				std::cout << std::endl << "\tIntroduce the size of the tree ";
				std::cin >> n;
				std::cout << std::endl << "\tIntroduce the ammount of tests ";
				std::cin >> nTests;
				assert(n > nTests && nTests >= 0);
				testBench_.clear();

				// Generate DNI
				for (int i = 0; i < (2 * n); i++) {
					DNI newDNI((rand() % 50000000) + 30000000);
					testBench_.push_back(newDNI);
				}

				// Insert in tree
				for (int i = 0; i < n; i++) {
					tree_.insert(testBench_[i], trash);
				}
				
				// Searching Tests
				int random;
				Counter searchCounter;
				searchCounter.start();
				for (int i = 0; i < nTests; i++) {
					searchCounter.start();
					random = (rand() % n) + n;
					tree_.search(testBench_[random], searchCounter);
					searchCounter.stop();
				}

				// Inserting Tests
				Counter insertCounter;
				insertCounter.start();
				for (int i = 0; i < nTests; i++) {
					insertCounter.start();
					random = (rand() % n) + n;
					tree_.insert(testBench_[random], insertCounter);
					insertCounter.stop();
				}

				// Printing Results
				std::cout << std::endl << "\t\t Compartions Number" << std::endl;
				std::cout << std::endl << "\t\t Number of elements: " << n;
				std::cout << std::endl << "\t\t Numbrt of tests: " << nTests << std::endl;
				std::cout << std::endl << std::setw(25) << "Minimum" << std::setw(10) << "Medium" << std::setw(10) << "Meximum" << std::endl;
				std::cout << std::endl << std::setw(15) << "Busqueda" << std::setw(10) << searchCounter.get_Min() << std::setw(10) << searchCounter.get_Accum() / nTests << std::setw(10) << searchCounter.get_Max() << std::endl;
                std::cout << std::endl << std::setw(15) << "Insercion" << std::setw(10) << insertCounter.get_Min() << std::setw(10) << insertCounter.get_Accum() / nTests << std::setw(10) << insertCounter.get_Max() << std::endl << std::endl << std::endl;
                exit(0);
				break;
			}

			case 0:{
				exit(0);
			}
		}
	}

}