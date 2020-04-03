/*
* @Author: Adrián Epifanio
* @Date:   2020-03-30 14:20:30
* @Last Modified by:   Adrián Epifanio
* @Last Modified time: 2020-04-03 19:38:59
*/

#include "../include/table.hpp"
#include "../include/DNI.hpp"
#include "../include/cell.hpp"
#include "../include/experiment.hpp"

int main (void) {
	/*
El programa principal realizará la siguiente secuencia de pasos:
	Solicita los parámetros para crear una tabla hash:
		a. Número de celdas, nCeldas. El número de posiciones de la tabla hash.
		b. Tamaño de la celda, nClaves. El número de claves que se pueden almacenar en
			cada celda.
		c. Función de dispersión, fDispersion. Opciones: módulo, suma y pseudoaleatoria.
		d. Función de exploración, fExploracion. Opciones: lineal, cuadrática, dispersión
			doble y re-dispersión
	2. Solicita los parámetros del experimento:
		a. Factor de carga, factor. Valor entre 0 y 1 que se corresponde al cociente entre el
			número de valores de clave almacenados y el número de valores que es posible
			almacenar en la tabla.
		b. Número de pruebas, nPruebas. Número de repeticiones de la operación, inserción
			o búsqueda, que se realiza en el experimento.
	

	*/
Table<int>* asd();
int a = asd->get_CellNumber();
}