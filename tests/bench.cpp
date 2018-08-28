#include <benchmark/benchmark.h>

#include <CirDeVec/CirDeVec.hpp>
#include <vector>

static void CIRDEVEC_ctor (benchmark::State& state) 
{
  for (auto _ : state)
    cirdevec <int> cdv;
}
// Register the function as a benchmark
BENCHMARK (CIRDEVEC_ctor);

static void VECTOR_ctor (benchmark::State& state)
{
  for (auto _ : state)
    std::vector <int> vec;
}
// Register the function as a benchmark
BENCHMARK (VECTOR_ctor);

BENCHMARK_MAIN();