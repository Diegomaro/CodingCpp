#include <iostream>

int main(){
    int x = rand() %(3);
    for(int i = 0; i < 1000; i++){
        std::cout << x;
        x = rand() %(3);
    }
    return 0;
}