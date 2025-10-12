#include <iostream>

/*
Instrucción: Escribe una función llamada "suma" que
 reciba dos enteros como parametros y devuelva la suma. 
Luego llama a esta función desde el "main" y muestra el resultado.
Autor: Diego Martínez Orrante A01661338
Última fecha de modificación: 04:50 PM, 13/08/2025
*/

int suma(int x, int y);

int main(){
    int x = 5;
    int y = 7;
    int sumaDeDosNumeros = suma(x,y);
    std::cout << "EL resultado de la suma entre " << x << " y " << y << ", es: " << sumaDeDosNumeros << std::endl;
    return 0;
}

int suma(int x, int y){
   int resultado = x + y;
   return resultado; 
}