#include "Catalogue.hpp"
#include <iostream>

int main(){
    Catalogue catalogue;
    if(!catalogue.loadFromCSV("media/monsters.csv")){
        std::cout << "not able to load!" << std::endl;
    }
}