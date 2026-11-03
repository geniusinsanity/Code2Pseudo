
#include <iostream>
#include <string>
#include "core/source/sourceFile.hpp"
#include "input/cpp/lexer/lexer.hpp"

int main(int argc, char *argv[])
{

    if (argc != 2)
    {
        std::cerr << "Usage: code2pseudo <path.cpp> eg[test.cpp]\n";
        return 1;
    }

    SourceFile file;

    file.path = argv[1];

    std::cout << "\033[32m";
    std::cout << "Code2Pseudo Compiler\n";
    std::cout << "\033[0m";
    std::cout << "Input file: " << file.path << '\n';

    if (!readSourceFile(file))
    {
        std::cout << "can not open " << file.path;
        return 1;
    }
    std::cout << "file content: " << '\n'
              << file.content;

    // creating lexer object
    Lexer lexer;

lexer.source = file.content;

    std::cout << "All the idfs of this program are: "<< '\n';

//print all the idfs
while (isAtEnd(lexer) == false) {

    char c = currentChar(lexer);

    if (isIdfStart(c)) {

        std::string word = readIdf(lexer);

        std::cout << "Word: " << word << '\n';
    }
    else {
        readChar(lexer);
    }
}

    return 0;
}
