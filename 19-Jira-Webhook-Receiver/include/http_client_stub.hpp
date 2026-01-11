
#ifndef HTTP_CLIENT_STUB_HPP
#define HTTP_CLIENT_STUB_HPP
#include <string>
#include <thread>
#include <chrono>
#include <stdexcept>

// Itin supaprastintas HTTP kliento stubas su dirbtiniu vėlinimu ir rate limiting.
class HttpClient {
    std::string base_url_;
    int rate_per_sec_;
public:
    explicit HttpClient(std::string base_url, int rate_per_sec = 5)
        : base_url_(std::move(base_url)), rate_per_sec_(rate_per_sec) {}

    std::string get(const std::string& path, const std::string& bearer_token) const {
        throttle();
        (void)bearer_token; // nenaudojama stub’e
        // Grąžiname JSON tekstą – realybėje būtų atsakymas iš API
        return std::string("{\"status\":\"ok\",\"method\":\"GET\",\"url\":\"") + base_url_ + path + "\"}";
    }

    std::string post(const std::string& path, const std::string& body_json, const std::string& bearer_token) const {
        throttle();
        (void)bearer_token;
        (void)body_json;
        return std::string("{\"status\":\"created\",\"method\":\"POST\",\"url\":\"") + base_url_ + path + "\"}";
    }
private:
    void throttle() const {
        // labai paprastas rate limiting: sleep ~ 1/rate_per_sec
        using namespace std::chrono;
        if(rate_per_sec_ > 0){
            std::this_thread::sleep_for(milliseconds(1000 / rate_per_sec_));
        }
    }
};

#endif // HTTP_CLIENT_STUB_HPP
