#include <benchmark/benchmark.h>

#include "interpreter.hpp"

using namespace number_interpreter;

static void FromString( benchmark::State& state ) {
    std::string str( state.range( 0 ), '1' );
    Interpreter interpreter = Interpreter();
    for ( auto _ : state ) {
        bool is_interpreted = interpreter.interpret( str );
    }
}
BENCHMARK( FromString )->Range( 1, 1 << 20 );
