/*
 * Ejemplos secuenciales de uso de memoria
 * por Artemio Urbina
 *
 * Ejemplo 2b de uso de memoria dinámica
 *
 * Este ejemplo tiene la intención de
 * demostrar new y delete.
 *
 * En este caso utilizamos excepciones
 * para validar el error si new falla.
 *
 */

#include <iostream>
#include <new> // Para uso de std::bad_alloc

using namespace std;

#define MAX_SIZE 10000000000000

int main() {
	// inicializamos en nullptr, es buena práctica
	// que siempre nos ayudará.
	long int* arrayPtr = nullptr;

	cout	<< "Pidiendo: "
			<< (sizeof(long int) * MAX_SIZE) / (1024 * 1024 * 1024)
			<< " Gbytes\n";

	// pedimos la cantidad de memoria que necesitamos
	// en este caso MAX_SIZE elementso de tipo int.
	// usamos try/catch para controlar la exepcion en 
	// lugar de revisar el apuntador que nos regresa.
	try {
		arrayPtr = new long int[MAX_SIZE];

		cout << "Tenemos la memoria. llenando el arreglo con long ints...\n";
		for (long int i = 0; i < MAX_SIZE; i++)
			arrayPtr[i] = i;
		}
	catch (const std::bad_alloc& e) {
		std::cerr << "No hay memoria: " << e.what() << std::endl;
		return 1;
	}

	cout << arrayPtr[MAX_SIZE / 2] << "\n";

	cout << "Presiona ENTER para terminar";
	cin.ignore();

	delete [] arrayPtr;
	arrayPtr = nullptr;

	return 0;
}