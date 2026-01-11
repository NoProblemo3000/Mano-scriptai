
#include <cassert>
#include <string>
#include "oauth_stub.hpp"
#include "http_client_stub.hpp"

int main(){
    OAuthClient oauth("id","secret","https://auth.example");
    auto t = oauth.get_token_stub("scope");
    assert(t.find("stub_token_") == 0);

    HttpClient http("https://api.example", 1000);
    auto r = http.get("/health", t);
    assert(r.find("\"status\":\"ok\"") != std::string::npos);
    return 0;
}
