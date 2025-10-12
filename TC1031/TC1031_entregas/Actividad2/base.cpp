#include <iostream>
#include "sortTest.h"

using namespace std;

int main() {
    SortTest myTest;

    if(!myTest.createArray())  {
        cout << "No hay memoria\n";
        return 1;
    }
    int answer = 0;
    while(answer != 7){
        cout << "Elige una opción para el sort: " << endl;
        cout << "1. Cambiar tamaño del arreglo" << endl;
        cout << "2. BubbleSort" << endl;
        cout << "3. InsertionSort" << endl;
        cout << "4. SelectionSort" << endl;
        cout << "5. MergeSort" << endl;
        cout << "6. QuickSort" << endl;
        cout << "7. Salir" << endl << endl;
        cin >> answer;
        switch(answer){
            case 1: {
                cout << "Ingrese el valor de la lista que desee: ";
                int tempAns = 0;
                cin >> tempAns;
                myTest.setSize(tempAns);
                }
            break;
            case 2:{
                myTest.generateRandomNumbers();
                cout << "El arreglo es:" << endl;
                myTest.printData();
                cout << "BubbleSort..." << endl;
                myTest.bubbleSort();
                cout << "El arreglo ordenado es:" << endl;
                myTest.printData();
                }
            break;
            case 3: {
                myTest.generateRandomNumbers();
                cout << "El arreglo es:" << endl;
                myTest.printData();
                cout << "InsertionSort..." << endl;
                myTest.insertionSort();
                cout << "El arreglo ordenado es:" << endl;
                myTest.printData();
                }  
                break;
            case 4:{
                myTest.generateRandomNumbers();
                cout << "El arreglo es:" << endl;
                myTest.printData();
                cout << "SelectionSort..." << endl;
                myTest.selectionSort();
                cout << "El arreglo ordenado es:" << endl;
                myTest.printData();
                break;
                }
            case 5:{
                myTest.generateRandomNumbers();
                cout << "El arreglo es:" << endl;
                myTest.printData();
                cout << "MergeSort..." << endl;
                myTest.prepMergeSort();
                cout << "El arreglo ordenado es:" << endl;
                myTest.printData();
            }
                break;
            case 6: {
                myTest.generateRandomNumbers();
                cout << "El arreglo es:" << endl;
                myTest.printData();
                cout << "QuickSort..." << endl;
                myTest.prepQuickSort();
                cout << "El arreglo ordenado es:" << endl;
                myTest.printData();
                }
                break;
            case 7:
                break;
        }
    }
    return 0;
}