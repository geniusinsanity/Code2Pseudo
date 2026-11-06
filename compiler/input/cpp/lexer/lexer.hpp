#ifndef LEXER_HPP
#define LEXER_HPP

#include <string>
#include <cstddef>
#include "tokenType.hpp"

struct Lexer {

    std::string source;

    std::size_t current = 0;
};

// struct SymbolType {
//     char symbol;
//     TokenType type;
// };

// static const SymbolType symbols[]={
//         {'+', Plus},
//         {'-', Minus},
//         {'*', Multiply},
//         {'/', Div},
//         {'%', Mod},
//         {'==', Equal},
//         {'=', Assign},
//         {';', Semicolon},
//         {'(', LeftParen},
//         {')', RightParen},
//         {'{', LeftBrace},
//         {'}', RightBrace}
//     };

bool isAtEnd(const Lexer &lexer);

char currentChar(const Lexer &lexer);

char nextChar(const Lexer &lexer);


char readChar(Lexer &lexer);

bool isDigit(char digit);

bool isIdfStart(char c);

bool isIdfPart(char c);

std::string readIdf(Lexer  &lexer);

TokenType classifyTokns(const std::string &token);

TokenType classifySymbol(char symbol);

std::string readNumber(Lexer &lexer);


#endif