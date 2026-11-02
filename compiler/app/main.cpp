
#include <iostream>
#include <string>

int main(int argc, char* argv[]) {

    if (argc != 2) {
        std::cerr << "Usage: code2pseudo <input.cpp>\n";
        return 1;
    }

    std::string inputFile = argv[1];

    std::cout << "Code2Pseudo Compiler\n";
    std::cout << "Input file: " << inputFile << '\n';

    return 0;
}
