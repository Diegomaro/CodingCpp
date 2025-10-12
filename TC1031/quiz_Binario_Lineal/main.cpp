#include <iostream>
#include <ctime>
#include "sortTest.h"
#include "timer.h"

using namespace std;

bool changeSize(SortTest &myTest) {
	unsigned int size = 0;

	do {
		cout << "Dame el numero de datos a usar: ";
		cin >> size;

		if(size > 0 && !myTest.setSize(size))
			return false;
	} while(size == 0);

	return true;
}

int main() {
	Timer chrono;;
	char opcion;
	SortTest myTest;

	srand(time(0));

	if(!changeSize(myTest)) {
		cout << "Out of memory\n";
		return 0;
	}
	myTest.generateRandomNumbers();
	do {
		cout << "\nElije una opcion para el sort:" << endl;
		cout << "1) Cambiar Tamaño del Arreglo" << endl;	
		cout << "2) Bubble Sort" << endl;
		cout << "3) Insertion Sort" << endl;
		cout << "4) Selection Sort" << endl;
		cout << "5) Merge Sort" << endl;
		cout << "6) Quick Sort" << endl;
		cout << "7) Linear Search" << endl;
		cout << "8) Binary Search" << endl;
		cout << "9) Imprimir lista" << endl;
		cout << "A) Salir" << endl;
		cin >> opcion;

		if(opcion >= '2' && opcion <= '6') {
			myTest.generateRandomNumbers();
			if(myTest.getSize() <= 100) {
				cout << "El arreglo original es:" << endl;
				myTest.printData();
			}
			else
				cout << "Omitiendo imprimir arreglo de " << myTest.getSize() << " elementos\n";

			chrono.start();
		}

		switch(opcion) {
			case '1':
				if(!changeSize(myTest)) {
					cout << "Out of memory\n";
					return 0;
				}
			break;
			case '2':
				myTest.bubbleSort();
			break;
			case '3':
				myTest.insertionSort();
			break;
			case '4':
				myTest.selectionSort();
			break;
			case '5':
				myTest.mergeSort();
			break;
			case '6':
				myTest.quickSort();
			break;
			case '7':
				cout << "Ingresa valor a buscar: " << endl;
				if(true){
					int x = 0;
					cin >> x;
					int ans = myTest.linearSearch(x);
					if(ans==-1){
						cout << "No se pudo encontrar el valor!" << endl;
					} else{
						cout << "La posición del valor " << x << " es: " << ans << "." << endl;
					}
				}
			break;
			case '8':
				if(myTest.checkSort()){
					cout << "Ingresar valor a buscar: ";
					int x = 0;
					cin >> x;
					int ans = myTest.binarySearch(x);
					if(ans==-1){
						cout << "No se pudo encontrar el valor!" << endl;
					} else{
						cout << "La posición del valor " << x << " es: " << ans << "." << endl;
					}
				} else{
					cout << "El arreglo no esta ordenado!" << endl;
				}	
			break;	
			case '9':
				myTest.printData();
			break;
			default:
				cout << "Opcion Invalida\n";
			break;
		}

		if(opcion >= '2' && opcion <= '6') {
			chrono.stop();
			if(myTest.getSize() <= 100) {
				cout << "El arreglo ordenado  es:" << endl;
				myTest.printData();
			}
			
			chrono.report();
		}
		
	} while(opcion != 'A');

	return 0;
}
