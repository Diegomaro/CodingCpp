#pragma once
#include <string>
#include "BinaryTree.hpp"
#include "Monster.hpp"
class Catalogue{
    public:
        Catalogue();
        ~Catalogue();
        bool loadFromCSV(const std::string& filename);
        
        //Monster getRandomMonster();
    private:
        void loadCurrentAttribute(Monster *&monster, std::stringstream &ss, std::string cell, int ctr);
    //BinaryTree tree;
};