#pragma clang diagnostic ignored "-Wunused-result"

#include "number_parts.hpp"

#include <limits>
#include <string>

#include <benchmark/benchmark.h>

using namespace number_interpreter;

constexpr size_t MAX_LEN = 100000;

namespace {
void benchNumberParts(benchmark::State& state) {
    auto length = static_cast<size_t>(state.range(0));
    std::string sign = "-";
    std::string beforeDot(length, '9');
    std::string afterDot(length, '9');
    std::string exp = std::to_string(std::numeric_limits<Exponent>::max());

    for (auto length : state) {
        NumberParts parts(sign, beforeDot, afterDot, exp);
    }
}
}  // namespace

BENCHMARK(benchNumberParts)->Range(1, MAX_LEN);  // NOLINT
