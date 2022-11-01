#include <iostream>
#include "List.h"
#include <stdexcept>

int main() {
    List list1=List();
    list1.insertFirst(12);
    list1.print();
    if (list1.exists(14)){
        std::cout<<"YUP\n";
    }
    else {
        std::cout<<"NOPE\n";
    }
    try{
        std::cout<<list1.removeFirst()<<" deleted\n";
        list1.removeFirst();
    }catch (std::invalid_argument e){
        e.what();
    }
    list1.print();
    return 0;
}
