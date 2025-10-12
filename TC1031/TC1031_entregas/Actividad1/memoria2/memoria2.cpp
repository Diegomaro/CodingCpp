/*
 * Ejemplos secuenciales de uso de memoria
 *
 * Ejemplo 2 de uso de memoria dinámica
 *
 * Este ejemplo tiene la intención de 
 * demostrar new y delete.
 *
 */

#include <iostream>

using namespace std;

#define MAX_SIZE 10000000000000

int main() {
    long int* arrayPtr = nullptr;

    cout << "Pidiendo: "
        << (sizeof(long int) * MAX_SIZE) / (1024 * 1024 * 1024)
        << " Gbytes\n";

    arrayPtr = new long int[MAX_SIZE];
    if (!arrayPtr) {
        cerr << "No hay suficiente memoria" << endl;
        return 1;
    }

    cout << "Tenemos la memoria. llenando el arreglo con long ints...\n";
    for (long int i = 0; i < MAX_SIZE; i++)
        arrayPtr[i] = i;

    cout << arrayPtr[MAX_SIZE / 2] << "\n";

    cout << "Revisa cuanto utiliza en el administrador de procesos de tu sistema operativo\n";
    cout << "Presiona ENTER para liberar la RAM y terminar";
    cin.ignore();

    delete [] arrayPtr;
    arrayPtr = nullptr;

    return 0;
}
