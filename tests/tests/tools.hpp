#pragma once

#include <random>
#include <string>

#include "context.hpp"

using namespace number_interpreter;

class NumberGenerator {
public:
    NumberGenerator():
        gen( std::random_device{}() ),
        prob_dist( 0.0, 1.0 ),
        digit_dist( 0, 9 ),
        small_int_dist( 1, 6 ),
        large_int_dist( 1, 999 ) {}

    std::string generate_special_value();

    std::string generate_sign();

    std::string generate_integer_part();
    std::string generate_decimal_part();
    std::string generate_exponent_sign();

    char generate_exponent_char();
    std::string generate_exponent_value();
    std::string generate_exponent();
    std::string generate_number();

private:
    std::mt19937 gen;
    std::uniform_real_distribution<double> prob_dist;
    std::uniform_int_distribution<int> digit_dist;
    std::uniform_int_distribution<int> small_int_dist;
    std::uniform_int_distribution<int> large_int_dist;
};

std::vector<Token> tokenize( const std::string& str );

Context get_context( std::string str );
