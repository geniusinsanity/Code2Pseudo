#include "lexer.hpp"
#include "tokenType.hpp"

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

char readChar(Lexer &lexer) {

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
    return isIdfStart(c)|| (c >= '0' && c <= '9'); 
}

std::string readIdf(Lexer& lexer) {

    std::string identifier = "";

    //add another reading condition to handle edge cases 
    if (isAtEnd(lexer)||
        isIdfStart(currentChar(lexer)) == false){
        return identifier;
    }

    while (isAtEnd(lexer) == false &&
           isIdfPart(currentChar(lexer))) {

        identifier += readChar(lexer);
    }

    return identifier;
}

TokenType classifyWord(const std::string &word) {

    if (word == "int") {
        return KeywordInt;
    }
    if (word == "float") {
        return KeywordFloat;
    }

    if (word == "return") {
        return KeywordReturn;
    }

    return Identifier;
}

TokenType classifySymbol(char symbol) {

    if (symbol == '=')return Assign;

    if (symbol == '*')return Multiply;
    if (symbol == '%')return Mod;
    if (symbol == '/')return Div;

    if (symbol == '+')return Plus;
    if (symbol == '-')return Minus;

    if (symbol == '(')return LeftParen;

    if (symbol == ')')return RightParen;

    if (symbol == '{')return LeftBrace;

    if (symbol == '}')return RightBrace;

    if (symbol == ';')return Semicolon;

    return Unknown;

};


std::string readNumber(Lexer &lexer) {

    std::string number = "";

    // Checking if the current character can start a number
    if (isAtEnd(lexer) ||
        isDigit(!currentChar(lexer))) {

        return number;
    }

    // read consecutive digits
    while (!isAtEnd(lexer) &&
           isDigit(currentChar(lexer))) {

        number += readChar(lexer);
    }

    return number;
}

bool isDigit(char c){
    return c >= '0' && c <= '9';
}