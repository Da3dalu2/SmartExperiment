#include <iostream>
#include <typeinfo>
#include "Subject.h"

int main() {
    std::cout << typeid(Subject).name();
    return 0;
}
