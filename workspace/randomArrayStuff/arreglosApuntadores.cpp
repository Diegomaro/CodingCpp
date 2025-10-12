#include <iostream>

int main(){


    int arreglo [10] = {0,1,2,3,4,15,6,7,8,9};
    for(int i = 0; i < 10; i++){
        //std::cout << &arreglo[i] << std::endl;
    }

    int* ptr = &arreglo[0];
    ptr = ptr +5;
    std::cout << *ptr << std::endl;


    
    return 0;
}