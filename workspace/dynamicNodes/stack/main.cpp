#include "stack_impl.h"

int main(){
    Stack<int> stack;
    stack.push(5);
    stack.push(10);
    std ::cout << "peeking: " << stack.peek() << std::endl;
    stack.pop();
    std ::cout << "peeking: " << stack.peek() << std::endl;   
    stack.push(51);
    stack.push(35);
    stack.push(45);
    std ::cout << "searching: " << stack.search(51) << std::endl;    
    return 0;
}