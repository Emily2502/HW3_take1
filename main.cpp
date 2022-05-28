
#include <sstream>

#include "HealthPoints.h"
#include "Queue.h"

int main(){

    Queue<int> one;
    //one.print_linked();

    //one.front() = 5;
    std::cout << one.size();
    one.popFront();
    std::cout << one.size();


}
