#ifndef LEXER_HPP
#define LEXER_HPP

#include <string>
#include <cstddef>

struct Lexer {

    std::string source;

    std::size_t current = 0;
};

bool isAtEnd(const Lexer &lexer);

char currentChar(const Lexer &lexer);

char nextChar(const Lexer &lexer);


char readChar(Lexer &lexer);



bool isIdfStart(char c);

bool isIdfPart(char c);

std::string readIdf(Lexer  &lexer);

#endif