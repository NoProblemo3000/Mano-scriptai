
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>

#include "logger.hpp"
#include "metrics.hpp"
#include "retry.hpp"
#include "oauth_stub.hpp"
#include "http_client_stub.hpp"

// === Projekto kontekstas ===
// Našumo metrikų surinkimas
// Šis stubas demonstruoja architektūrą: Config → OAuth → HTTP klientas → Pseudo API kvietimai → KPI.

struct Config {
    std::string base_url;
    std::string token_url;
    std::string client_id;
    std::string client_secret;
    std::string default_scope;
};

// Minimalus JSON laukų ištraukimui (naivus, tik demonstracijai)
static std::string find_json_value(const std::string& json, const std::string& key){
    auto k = std::string("\"") + key + "\"";
    auto pos = json.find(k);
    if(pos == std::string::npos) return {};
    pos = json.find(':', pos);
    if(pos == std::string::npos) return {};
    pos = json.find('"', pos);
    if(pos == std::string::npos) return {};
    auto end = json.find('"', pos+1);
    if(end == std::string::npos) return {};
    return json.substr(pos+1, end-pos-1);
}

static Config load_config(const std::string& path){
    std::ifstream f(path);
    std::stringstream buffer; buffer << f.rdbuf();
    std::string j = buffer.str();
    Config c{};
    c.base_url = std::getenv("BASE_URL") ? std::getenv("BASE_URL") : find_json_value(j, "base_url");
    c.token_url = std::getenv("TOKEN_URL") ? std::getenv("TOKEN_URL") : find_json_value(j, "token_url");
    c.client_id = std::getenv("CLIENT_ID") ? std::getenv("CLIENT_ID") : find_json_value(j, "client_id");
    c.client_secret = std::getenv("CLIENT_SECRET") ? std::getenv("CLIENT_SECRET") : find_json_value(j, "client_secret");
    c.default_scope = std::getenv("SCOPE") ? std::getenv("SCOPE") : find_json_value(j, "scope");
    return c;
}

static std::string scenario_demo(HttpClient& http, const std::string& token){
    // Čia įsivaizduojame konkretų API kelią šiam projektui
    const std::string path = "/api/demo/40"; // pritaikykite realiam endpoint’ui
    return retry_with_backoff([&](){
        return http.get(path, token);
    }, 3, 100);
}

int main(int argc, char** argv){
    bool dry_run = false;
    for(int i=1;i<argc;++i){ if(std::string(argv[i]) == "--dry-run") dry_run = true; }

    LOG_INFO("Startuojame: 40-SolarWinds-Perfstat-Collector");
    Timer total("total");

    // 1) Konfigūracija
    auto cfg = load_config("config.json");
    LOG_INFO(std::string("Base URL: ") + cfg.base_url);

    // 2) OAuth stubas
    OAuthClient oauth(cfg.client_id, cfg.client_secret, cfg.token_url);
    auto token = oauth.get_token_stub(cfg.default_scope);
    LOG_DEBUG(std::string("Tokenas: ") + token);

    // 3) HTTP kliento stubas
    HttpClient http(cfg.base_url, /*rate_per_sec*/5);

    // 4) Scenarijaus demonstracija
    if(!dry_run){
        auto json_resp = scenario_demo(http, token);
        LOG_INFO(std::string("Atsakymas: ") + json_resp);
    } else {
        LOG_INFO("Dry-run režimas – API kvietimai praleidžiami.");
    }

    // 5) KPI išvedimas
    LOG_INFO(std::string("KPI.total_ms=") + std::to_string(total.elapsed_ms()));
    return 0;
}
