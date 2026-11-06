
#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>

#include "input/cpp/lexer/lexer.hpp"

// Test digit recognition
TEST_CASE("isDigit recognizes decimal digits", "[lexer]") {

    CHECK(isDigit('0'));
    CHECK(isDigit('5'));
    CHECK(isDigit('9'));

    CHECK_FALSE(isDigit('a'));
    CHECK_FALSE(isDigit('+'));
    CHECK_FALSE(isDigit(' '));
}

TEST_CASE("isIdfStart recognizes valid first characters", "[lexer]") {

    CHECK(isIdfStart('a'));
    CHECK(isIdfStart('Z'));
    CHECK(isIdfStart('_'));

    CHECK_FALSE(isIdfStart('5'));
    CHECK_FALSE(isIdfStart('+'));
}

TEST_CASE("isIdfPart recognizes valid identifier characters", "[lexer]") {

    CHECK(isIdfPart('a'));
    CHECK(isIdfPart('Z'));
    CHECK(isIdfPart('_'));
    CHECK(isIdfPart('5'));

    CHECK_FALSE(isIdfPart('+'));
}