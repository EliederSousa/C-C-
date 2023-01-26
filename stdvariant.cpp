#include <iostream>
#include <string.h>
#include <variant>

int main( int argc, char* argv[] ) {
    
    std::variant<int, float, std::string> teste;

    teste = 4000;
    std::cout << "Oi, sou um int: " << std::get<int>(teste) << std::endl;

    teste = 3.1415f;
    std::cout << "Tambem sou um float: " << std::get<float>(teste) << std::endl;

    teste = "Devia ter aprendido isso antes!";
    std::cout << "E tambem uma string: " << std::get<std::string>(teste) << std::endl;
    
    return 0;
}