#include <benchmark/benchmark.h>
#include <set>
#include "headers/MultiSet.hpp"

// ========================= Custom MultiSet vs std::set ==========================

// Insert
static void BM_CustomMultiSet_Insert(benchmark::State& state) {
    for (auto _ : state) {
        MultiSet<int> s;
        for (int i = 0; i < state.range(0); ++i) {
            s.insert(i);
        }
        benchmark::DoNotOptimize(s);
    }
}
BENCHMARK(BM_CustomMultiSet_Insert)->Range(1 << 10, 1 << 18); // 1K – 256K

static void BM_StdMultiSet_Insert(benchmark::State& state) {
    for (auto _ : state) {
        std::set<int> s;
        for (int i = 0; i < state.range(0); ++i) {
            s.insert(i);
        }
        benchmark::DoNotOptimize(s);
    }
}
BENCHMARK(BM_StdMultiSet_Insert)->Range(1 << 10, 1 << 18);

// Find
static void BM_CustomMultiSet_Find(benchmark::State& state) {
    MultiSet<int> s;
    for (int i = 0; i < state.range(0); ++i) s.insert(i);

    for (auto _ : state) {
        for (int i = 0; i < state.range(0); ++i) {
            s.find(i);
        }
    }
}
BENCHMARK(BM_CustomMultiSet_Find)->Range(1 << 10, 1 << 18);

static void BM_StdMultiSet_Find(benchmark::State& state) {
    std::set<int> s;
    for (int i = 0; i < state.range(0); ++i) s.insert(i);

    for (auto _ : state) {
        for (int i = 0; i < state.range(0); ++i) {
            s.find(i);
        }
    }
}
BENCHMARK(BM_StdMultiSet_Find)->Range(1 << 10, 1 << 18);

// Erase
static void BM_CustomMultiSet_Erase(benchmark::State& state) {
    for (auto _ : state) {
        MultiSet<int> s;
        for (int i = 0; i < state.range(0); ++i) s.insert(i);

        for (int i = 0; i < state.range(0); ++i) {
            s.erase(i);
        }
        benchmark::DoNotOptimize(s);
    }
}
BENCHMARK(BM_CustomMultiSet_Erase)->Range(1 << 10, 1 << 18);

static void BM_StdMultiSet_Erase(benchmark::State& state) {
    for (auto _ : state) {
        std::set<int> s;
        for (int i = 0; i < state.range(0); ++i) s.insert(i);

        for (int i = 0; i < state.range(0); ++i) {
            s.erase(i);
        }
        benchmark::DoNotOptimize(s);
    }
}
BENCHMARK(BM_StdMultiSet_Erase)->Range(1 << 10, 1 << 18);

// ========================= Main ==========================
BENCHMARK_MAIN();
