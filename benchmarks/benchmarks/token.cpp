#include <string>

#include <benchmark/benchmark.h>

#include "abstract_expression.hpp"

using namespace number_interpreter;

constexpr size_t MAX_LEN = 100000;

namespace {
void benchToken(benchmark::State& state) {
    auto length = static_cast<size_t>(state.range(0));
    std::string str(length, '9');

    for (auto length : state) {
        Token token = Token(str);
        [[maybe_unused]] bool isEmpty = token.isEmpty();
        [[maybe_unused]] string value = token.getValue();
        [[maybe_unused]] Token newToken = token.merge(token);
    }
}
}  // namespace

BENCHMARK(benchToken)->Range(1, MAX_LEN);  // NOLINT
