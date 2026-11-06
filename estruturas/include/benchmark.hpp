#ifndef BENCHMARK_HPP
#define BENCHMARK_HPP

#include <chrono>

template <typename F>
double medir_ms(F f) {
    auto ini = std::chrono::steady_clock::now();
    f();
    auto fim = std::chrono::steady_clock::now();
    return std::chrono::duration<double, std::milli>(fim - ini).count();
}

#endif
