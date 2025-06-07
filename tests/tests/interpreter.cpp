#include "interpreter.hpp"

#include <gtest/gtest.h>

#include "tools.hpp"

using namespace number_interpreter;

const int TESTS_AMOUNT = 10000;

TEST( TestInterpreter, RandomNumberOrConstant ) {
    NumberGenerator generator = NumberGenerator();

    for ( int i = 0; i < TESTS_AMOUNT; i++ ) {
        Interpreter interpreter = Interpreter();
        std::string number = generator.generate_number();

        bool is_interpreted = interpreter.interpret( number );

        EXPECT_EQ( is_interpreted, true );
    }
}

TEST( TestInterpreter, RandomConstant ) {
    NumberGenerator generator = NumberGenerator();

    for ( int i = 0; i < TESTS_AMOUNT; i++ ) {
        Interpreter interpreter = Interpreter();
        std::string special_val = generator.generate_special_value();

        bool is_interpreted = interpreter.interpret( special_val );

        EXPECT_EQ( is_interpreted, true );
    }
}

TEST( TestInterpreter, RandomUnsignedInt ) {
    NumberGenerator generator = NumberGenerator();

    for ( int i = 0; i < TESTS_AMOUNT; i++ ) {
        Interpreter interpreter = Interpreter();
        std::string integer = generator.generate_integer_part();
        std::string number = integer;

        bool is_interpreted = interpreter.interpret( number );

        EXPECT_EQ( is_interpreted, true );
    }
}

TEST( TestInterpreter, RandomSignedInt ) {
    NumberGenerator generator = NumberGenerator();

    for ( int i = 0; i < TESTS_AMOUNT; i++ ) {
        Interpreter interpreter = Interpreter();
        std::string sign = generator.generate_sign();
        std::string integer = generator.generate_integer_part();
        std::string number = sign + integer;

        bool is_interpreted = interpreter.interpret( number );

        EXPECT_EQ( is_interpreted, true );
    }
}

TEST( TestInterpreter, RandomSignedIntWithExp ) {
    NumberGenerator generator = NumberGenerator();

    for ( int i = 0; i < TESTS_AMOUNT; i++ ) {
        Interpreter interpreter = Interpreter();
        std::string sign = generator.generate_sign();
        std::string integer = generator.generate_integer_part();
        std::string exponent = generator.generate_exponent();
        std::string number = sign + integer + exponent;

        bool is_interpreted = interpreter.interpret( number );

        EXPECT_EQ( is_interpreted, true );
    }
}

TEST( TestInterpreter, RandomSignedDecimal ) {
    NumberGenerator generator = NumberGenerator();

    for ( int i = 0; i < TESTS_AMOUNT; i++ ) {
        Interpreter interpreter = Interpreter();
        std::string sign = generator.generate_sign();
        std::string integer = generator.generate_integer_part();
        std::string decimal = generator.generate_decimal_part();
        std::string number = sign + integer + decimal;

        bool is_interpreted = interpreter.interpret( number );

        EXPECT_EQ( is_interpreted, true );
    }
}

TEST( TestInterpreter, RandomUnsignedDecimal ) {
    NumberGenerator generator = NumberGenerator();

    for ( int i = 0; i < TESTS_AMOUNT; i++ ) {
        Interpreter interpreter = Interpreter();
        std::string integer = generator.generate_integer_part();
        std::string decimal = generator.generate_decimal_part();
        std::string number = integer + decimal;

        bool is_interpreted = interpreter.interpret( number );

        EXPECT_EQ( is_interpreted, true );
    }
}

TEST( TestInterpreter, RandomSignedDecimalWithExponentButNoInteger ) {
    NumberGenerator generator = NumberGenerator();

    for ( int i = 0; i < TESTS_AMOUNT; i++ ) {
        Interpreter interpreter = Interpreter();
        std::string sign = generator.generate_sign();
        std::string decimal = generator.generate_decimal_part();
        std::string exponent = generator.generate_exponent();
        std::string number = sign + decimal + exponent;

        bool is_interpreted = interpreter.interpret( number );

        EXPECT_EQ( is_interpreted, false );
    }
}

TEST( TestInterpreter, RandomUnsignedDecimalWithExponentButNoInteger ) {
    NumberGenerator generator = NumberGenerator();

    for ( int i = 0; i < TESTS_AMOUNT; i++ ) {
        Interpreter interpreter = Interpreter();
        std::string decimal = generator.generate_decimal_part();
        std::string exponent = generator.generate_exponent();
        std::string number = decimal + exponent;

        bool is_interpreted = interpreter.interpret( number );

        EXPECT_EQ( is_interpreted, false );
    }
}

TEST( TestInterpreter, RandomUnsignedDecimalNoIntegerNoExponent ) {
    NumberGenerator generator = NumberGenerator();

    for ( int i = 0; i < TESTS_AMOUNT; i++ ) {
        Interpreter interpreter = Interpreter();
        std::string decimal = generator.generate_decimal_part();
        std::string number = decimal;

        bool is_interpreted = interpreter.interpret( number );

        EXPECT_EQ( is_interpreted, false );
    }
}
