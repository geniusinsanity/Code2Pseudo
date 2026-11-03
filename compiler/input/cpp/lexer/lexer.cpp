#include "lexer.hpp"

bool isAtEnd(const Lexer &lexer) {

    return lexer.current >= lexer.source.length();
}


char currentChar(const Lexer &lexer) {

    // if (isAtEnd(lexer)) {
    //     return '\0';
    // }

    // return lexer.source[lexer.current];

    //*ternary operator version
    return (isAtEnd(lexer))?'\0':lexer.source[lexer.current];
}

char nextChar(const Lexer &lexer) {

    // if (isAtEnd(lexer)) {
    //     return '\0';
    // }

    // if (lexer.current + 1 >= lexer.source.length()) {
    //     return '\0';
    // }

    // return lexer.source[lexer.current + 1];

    //* ternary operator version
    return ((isAtEnd(lexer)||(lexer.current +1 >= lexer.source.length())))?'\0':lexer.source[lexer.current +1];
}

char readchar(Lexer &lexer) {

    if (isAtEnd(lexer)) {
        return '\0';
    }

    char c = lexer.source[lexer.current];

    lexer.current++;

    return c;

    //*ternory operator versionb
    // return (isAtEnd(lexer))?'\0':c; //! I think it cuze an issue like the current will move automaticly
}


bool isIdfStart(char c) {
    // 'a'=87 'b'=88 ...
    return (c >= 'a' && c <= 'z') ||
           (c >= 'A' && c <= 'Z') ||
           c == '_';
}

bool isIdfPart(char c) {
    //affter the first character in the identefire we can use numbers as well
    return isIdfStart(c)|| c >= '0' && c <= '9'; 
}

std::string readIdf(Lexer  &lexer){

}
