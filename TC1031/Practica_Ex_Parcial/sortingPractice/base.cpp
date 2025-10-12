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

    while(answer!=8){
        cout << "Menu. Elegir una opcion:" << endl;
        cout << "1. Cambiar tamaño del arreglo." << endl;
        cout << "2. Imprimir arreglo." << endl;
        cout << "3. BubbleSort." << endl;
        cout << "4. SelectionSort." << endl;
        cout << "5. InsertionSort." << endl;
        cout << "6. MergeSort." << endl;
        cout << "7. QuickSort." << endl;
        cout << "8. Salir." << endl;
        cin >> answer;
        switch(answer){
            case 1:{
                cout << "Ingrese el tamanio que desee del areglo: ";
                int size = 0;
                cin >> size;
                myTest.setSize(size);
            } break;
            case 2:{
                cout << "El arreglo es:" << endl;
                myTest.printData();
            } break;
            case 3:{
                cout << "Bubblesorting..." << endl;
                myTest.bubbleSort();
            }break;
            case 4:{
                cout << "Selectionsorting..." << endl;
                myTest.selectionSort();
            }break;
            case 5:{
                cout << "Insertionsorting..." << endl;
                myTest.selectionSort();
            }break;
            case 6:{
                cout << "Mergesorting..." << endl;
                myTest.prepMergeSort();
            }break;
            case 7:{
                cout << "Quicksorting..." << endl;
                myTest.prepQuickSort();
            }break;

        }
    }
    return 0;
}