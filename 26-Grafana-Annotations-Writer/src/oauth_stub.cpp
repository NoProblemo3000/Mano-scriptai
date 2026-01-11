
#include "oauth_stub.hpp"
#include <string>

std::string OAuthClient::get_token_stub(const std::string& scope) const {
    // Pastaba: realybėje čia būtų HTTP POST į token_url_ su client_credentials.
    // Demonstracijoje grąžiname deterministinį pseudo-tokeną.
    return std::string("stub_token_") + scope + "_" + client_id_;
}
