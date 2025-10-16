#pragma once
#include <string>
#include "BinaryTree.hpp"
class Catalogue{
    public:
        Catalogue();
        ~Catalogue();
        bool loadFromCSV(const std::string& filename);
        BinaryTree tree; // hacer privado
        //Monster getRandomMonster();
    private:
        void loadCurrentAttribute(Monster &monster, std::stringstream &ss, std::string cell, int ctr);
};