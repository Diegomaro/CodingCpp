/*
 * Ejemplos secuenciales de uso de memoria
 *
 * Ejemplo 5 de uso de memoria dinámica
 *
 * Este ejemplo tiene la intención de
 * demostrar como se comportan los
 * constructores y destructores de las
 * clases con new y delete
 * 
 * La guía de estilo no se sigue con las declaraciones
 * para mantener la brevedad y simpleza en los ejemplos
 * 
 */

#include <iostream>

using namespace std;

// Definimos una clase de manera breve en el main como ejemplo
class Persona {
public:
    Persona() { cout << "En el constructor de Persona\n"; }
    ~Persona() { cout << "En el destructor de Persona\n"; }
};

int main() {
    Persona* ptr = nullptr;

	cout << "En el main, antes del new\n";
    ptr = new(nothrow) Persona();
    if (!ptr) {
        cout << "No hay memoria\n";
        return 0;
    }

    cout << "En el main, antes del delete\n";

    delete ptr;
    ptr = nullptr;

	cout << "En el main, antes del return 0\n";
    return 0;
}
