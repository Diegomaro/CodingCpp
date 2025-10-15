#include "binaryTree.hpp"

int main() {
	BinaryTree tree;
	int answer = 0;
    while(answer != 7){
        std::cout << "Elige una opción: " << std::endl;
        std::cout << "1. Insertar nodo" << std::endl;
        std::cout << "2. Insertar varios nodos" << std::endl;
        std::cout << "3. Eliminar nodo" << std::endl;
        std::cout << "4. Buscar nodo" << std::endl;
        std::cout << "5. Imprimir la lista" << std::endl;
        std::cout << "6. Limpiar la lista" << std::endl;
        std::cout << "7. Salir del programa" << std::endl;
		std::cout << "Respuesta: ";
        std::cin >> answer;
        switch(answer){
            case 1: {
                std::cout << "Ingrese el valor que desee agregar al arbol: ";
                int data = 0;
                std::cin >> data;
				if(tree.insertNode(data)){
					std::cout << "Se insertó el valor a la lista!" << std::endl;
				} else{
					std::cout << "No se pudo insertar el valor a la lista!" << std::endl;
				}
            } break;
            case 2: {
                std::cout << "Cuantos valores desea agregar?: ";
                int count = 0;
                std::cin >> count;
                while(count > 0){
                    std::cout << "Ingrese el valor que desee agregar al arbol: ";
                    int data = 0;
                    std::cin >> data;
                    if(tree.insertNode(data)){
                        std::cout << "Se insertó el valor a la lista!" << std::endl;
                    } else{
                        std::cout << "No se pudo insertar el valor a la lista!" << std::endl;
                    }
                    count--;
                }
            } break;
			case 3: {
				std::cout << "Que valor desea borrar: " << std::endl;
				int value = 0;
				std::cin >> value;
				if(tree.deleteNode(value)){
					std::cout << "Se eliminó " << value << "!" << std::endl;
				} else{
					std::cout << "No se pudo eliminar "<< value << "!" << std::endl;
				}
			} break;
            case 4: {
                std::cout << "Que valor desea buscar: " << std::endl;
                int value = 0;
                std::cin >> value;
                if(tree.searchNode(value)){
                    std::cout << "EL valor esta en el arbol!" << std::endl;
                } else {
                    std::cout << "El valor no esta en el arbol!" << std::endl;
                }
            } break;
            case 5: {				
				if(!tree.printAll()){
					std::cout << "No se pudo imprimir el arbol!" << std::endl;
				}
			}
			break;
			case 6: {				
				if(tree.clear()){
					std::cout << "Se limpió el arbol!" << std::endl;
				} else{
					std::cout << "No se pudo limpiar el arbol!" << std::endl;
				}
			}
			break;
		}
	}
	return 0;
}