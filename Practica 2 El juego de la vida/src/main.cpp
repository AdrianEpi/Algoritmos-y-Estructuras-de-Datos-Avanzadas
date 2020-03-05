/*
* @Author: Adrián Epifanio
* @Date:   2020-03-02 08:56:58
* @Last Modified by:   Adrián Epifanio
* @Last Modified time: 2020-03-05 18:26:59
*/
#include "../include/tablero.hpp"
#include <iostream>

int main(){
	int filas = 0;
	int columnas = 0;
	int turnos = 1;
	std::cout << "Indique la cantidad de filas: ";
	std::cin >> filas;
	std::cout << "Indique la cantidad de columnas: ";
	std::cin >> columnas;
	std::cout << "Indique la cantidad de turnos del juego: ";
	std::cin >> turnos;
	Tablero juego(filas, columnas, turnos);
};