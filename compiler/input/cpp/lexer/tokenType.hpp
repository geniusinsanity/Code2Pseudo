#ifndef TOKEN_TYPE_HPP
#define TOKEN_TYPE_HPP

enum TokenType {

    // Keywords
    KeywordInt,
    KeywordFloat,
    KeywordReturn,

    // Names and values
    Identifier,
    Number,

    // Operators
    Equal,
    Plus,
    Minus,
    Assign,
    Multiply,
    Div,
    Mod,

    // Symbols
    LeftParen,
    RightParen,
    LeftBrace,
    RightBrace,
    Semicolon,

    // End of file
    EndOfFile,

     // Unknown character
    Unknown
};

#endif