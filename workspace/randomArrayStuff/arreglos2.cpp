#include<iostream>

int main(){
    int x1, x2, x3, x4, x5, x6, x7, x8;
    std::cout << &x1 << std::endl;
    std::cout << &x2 << std::endl;
    std::cout << &x3 << std::endl;
    std::cout << &x4 << std::endl;
    std::cout << &x5 << std::endl;
    std::cout << &x6 << std::endl;
    std::cout << &x7 << std::endl;
    std::cout << &x8 << std::endl;

    int* ptr = &x1;
    return 0;
}


