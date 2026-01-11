
#ifndef LOGGER_HPP
#define LOGGER_HPP
#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <mutex>
#include <sstream>
#include <string>

namespace log {
    enum class Level { Debug, Info, Warn, Error };

    inline std::mutex &mutex() { static std::mutex m; return m; }

    inline const char* to_cstr(Level l){
        switch(l){
            case Level::Debug: return "DEBUG";
            case Level::Info:  return "INFO";
            case Level::Warn:  return "WARN";
            case Level::Error: return "ERROR";
        }
        return "INFO";
    }

    inline std::string now(){
        using namespace std::chrono;
        auto t = system_clock::now();
        auto tt = system_clock::to_time_t(t);
        auto ms = duration_cast<milliseconds>(t.time_since_epoch()) % 1000;
        std::tm tm{};
        #ifdef _WIN32
            localtime_s(&tm, &tt);
        #else
            localtime_r(&tt, &tm);
        #endif
        std::ostringstream oss;
        oss << std::put_time(&tm, "%Y-%m-%d %H:%M:%S") << '.' << std::setw(3) << std::setfill('0') << ms.count();
        return oss.str();
    }

    inline void write(Level lvl, const std::string& msg){
        std::lock_guard<std::mutex> _{mutex()};
        std::ostream& out = (lvl == Level::Error || lvl == Level::Warn) ? std::cerr : std::cout;
        out << now() << " [" << to_cstr(lvl) << "] " << msg << '\n';
    }
}

#define LOG_DEBUG(msg) ::log::write(::log::Level::Debug, msg)
#define LOG_INFO(msg)  ::log::write(::log::Level::Info,  msg)
#define LOG_WARN(msg)  ::log::write(::log::Level::Warn,  msg)
#define LOG_ERROR(msg) ::log::write(::log::Level::Error, msg)

#endif // LOGGER_HPP
