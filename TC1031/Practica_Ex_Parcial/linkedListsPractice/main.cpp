#include "list.h"

int main() {
	LinkedList<int> lista;
	int answer = 0;
    while(answer != 10){
        std::cout << "Elige una opción para el sort: " << std::endl;
        std::cout << "1. Insertar dato al inicio" << std::endl;
		std::cout << "2. Insertar dato al final" << std::endl;
        std::cout << "3. Insertar dato en una posicion" << std::endl;
        std::cout << "4. Eliminar dato al inicio" << std::endl;
        std::cout << "5. Eliminar dato al final" << std::endl;
        std::cout << "6. ELiminar dato por búsqueda" << std::endl;
        std::cout << "7. Obtener dato central" << std::endl;
        std::cout << "8. Imprimir la lista" << std::endl;
        std::cout << "9. Limpiar la lista" << std::endl;
        std::cout << "10. Salir del programa" << std::endl;
		std::cout << "Respuesta: ";
        std::cin >> answer;
        switch(answer){
            case 1: {
                std::cout << "Ingrese el valor que desee agregar al inicio de la lista: ";
                int data = 0;
                std::cin >> data;
				std::cout << "Se tratara de agregar el valor a la lista ..."<< std::endl;
				if(lista.insertHead(data)){
					std::cout << "Se insertó el valor a la lista!" << std::endl;
				} else{
					std::cout << "No se pudo insertar el valor a la lista!" << std::endl;
				}
            }
            break;
			case 2: {
                std::cout << "Ingrese el valor que desee agregar al final de la lista: ";
                int data = 0;
                std::cin >> data;
				std::cout << "Se tratara de agregar el valor a la lista ..."<< std::endl;
				if(lista.insertTail(data)){
					std::cout << "Se insertó el valor a la lista!" << std::endl;
				} else{
					std::cout << "No se pudo insertar el valor a la lista!" << std::endl;
				}
            }
            break;
            case 3: {
                std::cout << "Ingrese el valor que desee agregar a la lista: ";
                int data = 0;
                std::cin >> data;
                std::cout << "Ahora ingrese la posicion en la que desea agregar el valor a la lista: ";
                int pos = 0;
                std::cin >> pos;
				std::cout << "Se tratara de agregar el valor a la lista ..."<< std::endl;
				if(lista.insertNode(data, pos)){
					std::cout << "Se insertó el valor a la lista!" << std::endl;
				} else{
					std::cout << "No se pudo insertar el valor a la lista!" << std::endl;
				}
            }
            break;
			case 4: {
				std::cout << "Se tratara de eliminar head..." << std::endl;
				if(lista.removeHead()){
					std::cout << "Se eliminó head!" << std::endl;
				} else{
					std::cout << "No se pudo eliminar head!" << std::endl;
				}
			}
			break;
			case 5: {
				std::cout << "Se tratara de eliminar tail..." << std::endl;
				if(lista.removeTail()){
					std::cout << "Se eliminó tail!" << std::endl;
				} else{
					std::cout << "No se pudo eliminar tail!" << std::endl;
				}
			}
			break;
			case 6: {
				std::cout << "Que valor desea borrar: " << std::endl;
				int value = 0;
				std::cin >> value;
				std::cout << "Se tratara de eliminar " << value << "..."<< std::endl;
				if(lista.removeNode(value)){
					std::cout << "Se eliminó " << value << "!" << std::endl;
				} else{
					std::cout << "No se pudo eliminar "<< value << "!" << std::endl;
				}
			}
			break;
            case 7: {
			}
			break;
            case 8: {				
				std::cout << "Se tratara de imprimir la lista ..."<< std::endl;
				if(!lista.printList()){
					std::cout << "No se pudo imprimir la lista!" << std::endl;
				}
			}
			break;
			case 9: {				
				std::cout << "Se tratara de limpiar la lista ..."<< std::endl;
				if(lista.clear()){
					std::cout << "Se limpió la lista!" << std::endl;
				} else{
					std::cout << "No se pudo limpiar la lista!" << std::endl;
				}
			}
			break;
		}
	}
	return 0;
}