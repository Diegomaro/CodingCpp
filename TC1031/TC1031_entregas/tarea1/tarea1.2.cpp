/*
Instrucción: Crea una clase "CuentaBancaria" con el atributo saldo. 
Recuerda elegir los tipos de datos adecuados.
Luego, en el "main", crea una arreglo con 5 objetos de dicha clase, 
y utiliza un ciclo para asignar valores ascendientes de 1 a 5 a cada 
elemento del arreglo.
Autor: Diego Martínez Orrante A01661338
Última fecha de modificación: 04:06 PM, 13/08/2025
*/

#include <iostream>

class CuentaBancaria {
private:
    int saldo;
public:
    void setSaldo(int x);
    int getSaldo();
};

void CuentaBancaria::setSaldo(int x){
    this -> saldo = x;
}

int CuentaBancaria::getSaldo(){
    return saldo;
}

int main(){
    CuentaBancaria cuentas[5] = {};
    for (int i = 0; i < 5; i++){
        cuentas[i].setSaldo(i+1);
        std::cout << "EL valor en el indice " << i << " es: " << cuentas[i].getSaldo() << std::endl;
    }
    return 0;
}