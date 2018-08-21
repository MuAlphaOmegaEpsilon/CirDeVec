#include <benchmark/benchmark.h>

#include <CirDeVec/CirDeVec.hpp>
#include <vector>


static void HelloWorld1 (benchmark::State& state) 
{
  for (auto _ : state)
    std::string empty_string;
}
// Register the function as a benchmark
BENCHMARK(HelloWorld1);

// Define another benchmark
static void HelloWorld2 (benchmark::State& state) 
{
  std::string x = "hello";
  for (auto _ : state)
    std::string copy(x);
}
BENCHMARK(HelloWorld2);

BENCHMARK_MAIN ();