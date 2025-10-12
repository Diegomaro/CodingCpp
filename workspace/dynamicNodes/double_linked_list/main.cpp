#include "doubleLinkedList_impl.h"


int main(){
    LinkedList<int> list;
    list.add(5);
    list.add(15);
    list.add(20);
    list.add(21);
    list.add(23);
    list.add(28);

    list.remove(20);

    list.add(3);
    list.add(6,61111);
    int index = 4;
    std::cout << "the value at index "  << index << " is:";
    std::cout << list.get(index) << std::endl;
    int value = 28;
    std::cout << "the value "  << value << " is found at index:";
    std::cout << list.lastIndexOf(value) << std::endl;
    //list.addFirst(311);

    std::cout << "length list: ";
    std::cout << list.length() << std::endl;
    
    //int findX = 9871;
    //std::cout << "item " <<  findX << " is located at index: ";
    //std::cout << list.contains(findX) << std::endl;
    list.printAll();
    list.clear();
    return 0;
}