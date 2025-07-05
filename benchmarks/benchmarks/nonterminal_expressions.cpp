#include <string>

#include <benchmark/benchmark.h>

#include "abstract_expression.hpp"
#include "nonterminal_expressions/decimal.hpp"
#include "nonterminal_expressions/digit.hpp"
#include "nonterminal_expressions/exponent.hpp"
#include "nonterminal_expressions/extended_decimal.hpp"
#include "nonterminal_expressions/fractional_part.hpp"
#include "nonterminal_expressions/signed_integer.hpp"
#include "nonterminal_expressions/special.hpp"
#include "nonterminal_expressions/unsigned_integer.hpp"

using namespace number_interpreter;

constexpr size_t MAX_LEN = 100000;

namespace {
void benchDecimalExpression(benchmark::State& state) {
    auto length = static_cast<size_t>(state.range(0));
    std::string input(length, '9');

    DecimalExpression expr;

    for (auto length : state) {
        Context context(input);
        Token result = expr.interpret(context);
    }
}

void benchDigitExpression(benchmark::State& state) {
    auto length = static_cast<size_t>(state.range(0));
    std::string input(length, '9');

    DigitExpression expr;

    for (auto length : state) {
        Context context(input);
        Token result = expr.interpret(context);
    }
}

void benchExponentExpression(benchmark::State& state) {
    auto length = static_cast<size_t>(state.range(0));
    std::string input(length, '9');

    ExponentExpression expr;

    for (auto length : state) {
        Context context(input);
        Token result = expr.interpret(context);
    }
}

void benchExtendedDecimalExpression(benchmark::State& state) {
    auto length = static_cast<size_t>(state.range(0));
    std::string input(length, '9');

    ExtendedDecimalExpression expr;

    for (auto length : state) {
        Context context(input);
        Token result = expr.interpret(context);
    }
}

void benchFractionalPartExpression(benchmark::State& state) {
    auto length = static_cast<size_t>(state.range(0));
    std::string input(length, '9');

    FractionalPartExpression expr;

    for (auto length : state) {
        Context context(input);
        Token result = expr.interpret(context);
    }
}

void benchSignedIntegerExpression(benchmark::State& state) {
    auto length = static_cast<size_t>(state.range(0));
    std::string input(length, '9');

    SignedIntegerExpression expr;

    for (auto length : state) {
        Context context(input);
        Token result = expr.interpret(context);
    }
}

void benchSpecialExpression(benchmark::State& state) {
    auto length = static_cast<size_t>(state.range(0));
    std::string input(length, '9');

    SpecialExpression expr;

    for (auto length : state) {
        Context context(input);
        Token result = expr.interpret(context);
    }
}

void benchUnsignedIntegerExpression(benchmark::State& state) {
    auto length = static_cast<size_t>(state.range(0));
    std::string input(length, '9');

    UnsignedIntegerExpression expr;

    for (auto length : state) {
        Context context(input);
        Token result = expr.interpret(context);
    }
}
}  // namespace

BENCHMARK(benchDecimalExpression)->Range(1, MAX_LEN);          // NOLINT
BENCHMARK(benchDigitExpression)->Range(1, MAX_LEN);            // NOLINT
BENCHMARK(benchExponentExpression)->Range(1, MAX_LEN);         // NOLINT
BENCHMARK(benchExtendedDecimalExpression)->Range(1, MAX_LEN);  // NOLINT
BENCHMARK(benchFractionalPartExpression)->Range(1, MAX_LEN);   // NOLINT
BENCHMARK(benchSignedIntegerExpression)->Range(1, MAX_LEN);    // NOLINT
BENCHMARK(benchSpecialExpression)->Range(1, MAX_LEN);          // NOLINT
BENCHMARK(benchUnsignedIntegerExpression)->Range(1, MAX_LEN);  // NOLINT
