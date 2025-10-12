/*
Instrucción: Crea una clase "Rectangulo" con atributos "base2 y "altura". 
Define un consturctor con valores por defecto "base" = 1 y "altura" = 1. 
Incluye un método "area()" que devuelva el área del rectángulo. 
En el "main", crea dos rectángulos: uno usando los valores por defecto,
y otro con valores personalizados. 
Muestra el área de ambos.
Autor: Diego Martínez Orrante A01661338
Última fecha de modificación: 05:25 PM, 13/08/2025
*/

#include <iostream>

class Rectangulo{
private:
    int base;
    int altura;
public:
    Rectangulo();
    Rectangulo(int base, int altura);
    int area();
};

Rectangulo::Rectangulo(){
    base = 1;
    altura = 1;
}

Rectangulo::Rectangulo(int base, int altura){
    this -> base = base;
    this -> altura = altura;
}

int Rectangulo::area(){
    return base * altura;
}

int main(){
    Rectangulo rectanguloNoDefinido = Rectangulo();
    Rectangulo rectanguloDefinido = Rectangulo(5, 9);
    std::cout << "El area del rectangulo no definido es: \n" << rectanguloNoDefinido.area() << std::endl;
    std::cout << "El area del rectangulo definido es: \n" << rectanguloDefinido.area() << std::endl;;
    return 0;
}
