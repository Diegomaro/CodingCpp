/*
 * Ejemplos secuenciales de uso de memoria
 *
 * Ejemplo 11 de uso de memoria dinámica
 *
 * Este ejemplo tiene la intención de
 * mostrar el uso INCORRECTO de new
 * al asignar dos objetos nuevos al
 * mismo apuntador.
 * Esto genera un memory leak, ya que
 * sobreescibimos la referencia al
 * primer objeto en el heap.
 */
#include <iostream>

using namespace std;

class Persona {
public:
    Persona() { cout << "Persona creada" << endl; }
    ~Persona() { cout << "Persona " << nombre << " destruida" << endl; }

    string nombre;
};

Persona* crearPersona(string nombre) {
    Persona* p = new(nothrow) Persona();

    if (!p) {
        cout << "Not enough memory" << endl;
        return nullptr;
    }

    p->nombre = nombre;

    return p;
}

int main() {
    Persona* p1  = nullptr;
    Persona* p2  = nullptr;

    p1 = crearPersona("Juan");  // primera asignación
    p2 = crearPersona("Pedro");  // segunda asignación

    if (p1) {
        cout << "(main) Nombre: " << p1->nombre << endl;
    }
    if (p2) {
        cout << "(main) Nombre: " << p2->nombre << endl;
    }
    if (p1) {
        delete p1;
        p1 = nullptr;
    }
    if (p2) {
        delete p2;
        p2 = nullptr;
    }
    cout << "terminando programa" << endl;
    // Nunca se liberó la primera asignación, memory leak
    return 0;
}
