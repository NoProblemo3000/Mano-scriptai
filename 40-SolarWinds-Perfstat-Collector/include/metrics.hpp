
#ifndef METRICS_HPP
#define METRICS_HPP
#include <chrono>
#include <string>
#include <utility>

struct Timer {
    using clock = std::chrono::steady_clock;
    clock::time_point start;
    std::string name;
    explicit Timer(std::string name_): start(clock::now()), name(std::move(name_)){}
    ~Timer(){ /* Destructor intentionally empty. */ }
    long elapsed_ms() const {
        return std::chrono::duration_cast<std::chrono::milliseconds>(clock::now() - start).count();
    }
};

#endif // METRICS_HPP
