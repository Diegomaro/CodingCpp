#include "queue.h"
#include <iostream>

int main() {
    Queue<int> queue;
	int answer = 0;
    while(answer != 7){
        std::cout << "Menu." << std::endl;
        std::cout << "1. Ingresar dato a la fila." << std::endl;
        std::cout << "2. Quitar dato de la fila." << std::endl;
        std::cout << "3. Revisar dato top de la fila." << std::endl;
        std::cout << "4. Revisar si la fila esta vacia." << std::endl;
        std::cout << "5. Imprimir la lista." << std::endl;
        std::cout << "6. Limpiar lista." << std::endl;
        std::cout << "7. Salir." << std::endl;
        std::cin >> answer;
        switch(answer){
        case 1:{
            std::cout << "Ingrese el valor que desee agregar a la fila: ";
            int data = 0;
            std::cin >> data;
			if(queue.enqueue(data)){
				std::cout << "Se insertó el valor a la fila!" << std::endl;
			} else{
				std::cout << "No se pudo insertar el valor a la fila!" << std::endl;
				}
        } break;
        case 2:{
			if(queue.dequeue()){
				std::cout << "Se quito el valor de la fila!" << std::endl;
			} else{
				std::cout << "No se pudo quitar el valor de la fila!" << std::endl;
			}
        } break;
        case 3:{
			if(!queue.isEmpty()){
                std::cout << "Valor al frente: " << *queue.getFront() << std::endl;
			} else{
				std::cout << "La fila esta vacia!" << std::endl;
			}
        } break;
        case 4:{ 
			if(!queue.isEmpty()){
                std::cout << "La fila no esta vacia!" << std::endl;
			} else{
				std::cout << "No queda ningun valor en la fila!" << std::endl;
			}
        } break;
        case 5:{ 
			if(!queue.isEmpty()){
               std::cout << "La fila:";
               queue.printAll();
				} else{
				   std::cout << "No se pudo imprimir la fila!" << std::endl;
				}
        } break;
        case 6:{ 
			if(queue.clear()){
                std::cout << "Se limpio la fila!" << std::endl;
			} else{
				std::cout << "No se pudo limpiar la fila!" << std::endl;
			}
        } break;
        } 
    }
	return 0;
}

