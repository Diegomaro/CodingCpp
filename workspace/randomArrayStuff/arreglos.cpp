#include <iostream>

int main(){

    int x = 200;
    int* ptr1 = &x;
    int** ptr2 = &ptr1;
    int*** ptr3 = &ptr2;
    int**** ptr4 = &ptr3;
    int***** ptr5 = &ptr4;
    int****** ptr6 = &ptr5;

    std::cout << ******ptr6 << std::endl;
    return 0;
}