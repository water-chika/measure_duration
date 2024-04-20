#pragma once

#include <chrono>

namespace water {
    template<class F, class... Args>
        requires std::invocable<F, Args...>
    auto measure_duration(F&& f, Args&&... args) {
        auto get_now_time = []() {return std::chrono::high_resolution_clock::now(); };
        auto begin_time = get_now_time();
        f(args...);
        auto end_time = get_now_time();
        return end_time - begin_time;
    }
    template<size_t COUNT, class F, class... Args>
    auto measure_duration_average(F&& f, Args&&... args) {
        auto get_now_time = []() {return std::chrono::high_resolution_clock::now(); };
        auto begin_time = get_now_time();
        for (int i = 0; i < COUNT; i++) {
            f(args...);
        }
        auto end_time = get_now_time();
        return (end_time - begin_time) / COUNT;
    }
}
