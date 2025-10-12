/*
Instrucción: Escribe un programa que pida al usuario un numero entero entre 100 y 5000
 y cree un arreglo en el heap del tamaño que haya pedido, 
llenandolo con numeros consecutivos de 0 al numero elegido.
Autor: Diego Martínez Orrante A01661338
Última fecha de modificación: 04:50 PM, 13/08/2025
*/

#include <iostream>
int main(){
    int total = 0;
    do{
    std::cout << "Por favor ingrese un numero entre 100 y 5000: ";
    std::cin >> total;
    }while(total > 5000|| total < 100);
    int *arrayOfNums = new int[total];
    for (int i = 0; i < total; i++){
        arrayOfNums[i] = i;
    }
    for (int i = 0; i < total; i++){
        std::cout << arrayOfNums[i] << std::endl;
    }
    delete[] arrayOfNums;
    return 0;
}
