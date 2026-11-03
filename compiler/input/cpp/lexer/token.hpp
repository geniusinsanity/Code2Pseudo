#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <string>
#include "tokenType.hpp"

struct Token {

    TokenType type;

    std::string lexeme;

    int line;
    int column;
};

#endif
