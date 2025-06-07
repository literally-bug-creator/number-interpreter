#include <iostream>

#include "interpreter.hpp"

using namespace number_interpreter;

int main() {
    Interpreter interpreter = Interpreter();
    std::string str;
    std::cin >> str;

    std::cout << interpreter.interpret( str ) << std::endl;
    return 0;
}
