#include "context.hpp"

#include <limits>
#include <string>

#include <benchmark/benchmark.h>

using namespace number_interpreter;

constexpr size_t MAX_LEN = 100000;

namespace {
void benchContext(benchmark::State& state) {
    auto length = static_cast<size_t>(state.range(0));
    std::string input(length, '1');
    std::string sign = "-";
    std::string beforeDot(length, '9');
    std::string afterDot(length, '9');
    std::string exp = std::to_string(std::numeric_limits<Exponent>::max());

    for (auto length : state) {
        Context context(input);

        context.setSign(sign);
        context.setBeforeDot(beforeDot);
        context.setAfterDot(afterDot);
        context.setExp(exp);

        std::string result = context.get(1);  // NOLINT
        ContextImage backup = context.backup();
        context.next(1);
        context.restore(backup);
    }
}
}  // namespace

BENCHMARK(benchContext)->Range(1, MAX_LEN);  // NOLINT
