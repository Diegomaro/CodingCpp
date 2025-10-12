#include "stack.h"
#include <iostream>
#include <string>
#include <fstream>

bool verificaParentesis (const std::string& expresion){
    Stack<char> stackParentesis;
    for(int i = 0; i < expresion.length(); i++){
      if(expresion[i]=='('){
         stackParentesis.push('(');
      } else if(expresion[i]==')'){
         if(!stackParentesis.pop()){
            return false;
         }
      }
    }
    if(stackParentesis.isEmpty()){
      return true;
    }
    return false;
}

bool LeerArchivo(Stack<std::string>& stack, const std::string& filename){
   std::ifstream file;
   std::string line;
   file.open(filename);
   if(!file.is_open()){
      std::cout << "Error al cargar el archivo!" << std::endl;
      return false;
   }
   while(std::getline(file, line)){
      stack.push(line);
   }
   file.close();
   return true;
}

int main(){
   Stack<std::string> stack;
   if(LeerArchivo(stack, "crab.txt")){
      while(!stack.isEmpty()){
         std::cout << *stack.getTop() << std::endl;
         stack.pop();
      }
   }
   
   
   /*
   Stack<int> stack;
   int answer = 0;

   std::string expresion;
   */
   /*
   do {
      std::cout << "Ingrese una expresión con paréntesis[\"q\" para salir]: ";
      std::cin >> expresion;
    
      if(expresion != "q") {
         if (verificaParentesis(expresion))
            std::cout << "Los paréntesis están balanceados." << std::endl;
         else
            std::cout << "Los paréntesis no están balanceados." << std::endl;
      }
   } while(expresion != "q");
   */
   /*
   while(answer != 8){
      std::cout << "Menu." << std::endl;
      std::cout << "1. Ingresar dato al stack." << std::endl;
      std::cout << "2. Quitar dato del stack." << std::endl;
      std::cout << "3. Revisar dato top del stack." << std::endl;
      std::cout << "4. Limpiar lista." << std::endl;
      std::cout << "5. Revisar si la lista esta vacia." << std::endl;
      std::cout << "6. Imprimir la lista." << std::endl;
      std::cout << "7. Salir." << std::endl;
      std::cin >> answer;
      switch(answer){
         case 1:{
            std::cout << "Ingrese el valor que desee agregar al stack: ";
            int data = 0;
            std::cin >> data;
			   if(stack.push(data)){
				   std::cout << "Se insertó el valor a la lista!" << std::endl;
			   } else{
				   std::cout << "No se pudo insertar el valor a la lista!" << std::endl;
				}
         } break;
         case 2:{
			   if(stack.pop()){
				   std::cout << "Se quito el valor del stack!" << std::endl;
				} else{
			   	std::cout << "No se pudo quitar el valor al stack!" << std::endl;
			   }
         } break;
         case 3:{
				if(!stack.isEmpty()){
               std::cout << *stack.getTop() << std::endl;
			   } else{
				   std::cout << "El stack esta vacio!" << std::endl;
			   }
         } break;
         case 4:{
			   if(!stack.isEmpty()){
              stack.clear();
				} else{
				   std::cout << "No queda ningun valor en el stack!" << std::endl;
			   }
         } break;
         case 5:{
			   if(stack.isEmpty()){
				   std::cout << "EL stack esta vacio!" << std::endl;
			   } else{
					std::cout << "El stack no esta vacio!" << std::endl;
				}
         } break;
         case 6:{
			   if(!stack.isEmpty()){
               std::cout << "EL stack:";
               stack.printList();
				} else{
				   std::cout << "No se pudo imprimir el stack!" << std::endl;
				}
         } break;
      }
   }
   */
   return 0;
}