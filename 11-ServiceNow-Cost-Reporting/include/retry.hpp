
#ifndef RETRY_HPP
#define RETRY_HPP
#include <chrono>
#include <thread>
#include <functional>
#include <stdexcept>

// Paprastas exponential backoff retry utilitas.
template<typename F>
auto retry_with_backoff(F&& fn, int max_attempts = 3, int base_delay_ms = 100){
    int attempt = 0;
    while(true){
        try {
            return fn();
        } catch(const std::exception& ex){
            attempt++;
            if(attempt >= max_attempts) throw;
            int delay = base_delay_ms * (1 << (attempt-1));
            std::this_thread::sleep_for(std::chrono::milliseconds(delay));
        }
    }
}

#endif // RETRY_HPP
