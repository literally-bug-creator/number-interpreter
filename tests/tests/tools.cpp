#include "tools.hpp"

#include <random>
#include <string>
#include <vector>

using namespace number_interpreter;

std::string NumberGenerator::generate_special_value() {
    std::vector<std::string> special_values = {
        "nan", "+nan", "-nan", "inf", "+inf", "-inf" };

    std::uniform_int_distribution<size_t> index_dist(
        0, special_values.size() - 1 );
    return special_values[index_dist( gen )];
}

std::string NumberGenerator::generate_sign() {
    double prob = prob_dist( gen );
    if ( prob < 0.3 ) {
        return "+";
    } else if ( prob < 0.6 ) {
        return "-";
    } else {
        return "";
    }
}

std::string NumberGenerator::generate_integer_part() {
    return std::to_string( large_int_dist( gen ) );
}

std::string NumberGenerator::generate_decimal_part() {
    if ( prob_dist( gen ) < 0.5 ) { return ""; }

    int decimal_digits = small_int_dist( gen );
    std::string decimal_part = ".";

    for ( int i = 0; i < decimal_digits; ++i ) {
        decimal_part += std::to_string( digit_dist( gen ) );
    }

    return decimal_part;
}

std::string NumberGenerator::generate_exponent_sign() {
    double prob = prob_dist( gen );
    if ( prob < 0.3 ) {
        return "+";
    } else if ( prob < 0.6 ) {
        return "-";
    } else {
        return "";
    }
}

char NumberGenerator::generate_exponent_char() {
    return ( prob_dist( gen ) < 0.5 ) ? 'e' : 'E';
}

std::string NumberGenerator::generate_exponent_value() {
    return std::to_string( large_int_dist( gen ) );
}

std::string NumberGenerator::generate_exponent() {
    if ( prob_dist( gen ) < 0.4 ) {
        return std::string( 1, generate_exponent_char() ) +
               generate_exponent_sign() + generate_exponent_value();
    }
    return "";
}

std::string NumberGenerator::generate_number() {
    if ( prob_dist( gen ) < 0.1 ) { return generate_special_value(); }

    std::string result;
    result += generate_sign();
    result += generate_integer_part();
    result += generate_decimal_part();
    result += generate_exponent();

    return result;
}

std::vector<Token> tokenize( const std::string& str ) {
    std::vector<Token> tokens( str.size() );

    for ( size_t index = 0; index < str.size(); index++ ) {
        tokens[index] = make_token( std::tolower( str[index] ) );
    }

    return tokens;
}

Context get_context( std::string str ) { return Context( tokenize( str ) ); }
