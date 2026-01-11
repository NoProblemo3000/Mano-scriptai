
#ifndef OAUTH_STUB_HPP
#define OAUTH_STUB_HPP
#include <string>

// OAuth 2.0 stubas demonstracijai – ne siunčia užklausų į tinklą.
class OAuthClient {
    std::string client_id_;
    std::string client_secret_;
    std::string token_url_;
public:
    OAuthClient(std::string client_id, std::string client_secret, std::string token_url)
        : client_id_(std::move(client_id)), client_secret_(std::move(client_secret)), token_url_(std::move(token_url)) {}

    std::string get_token_stub(const std::string& scope) const; // Sugeneruoja pseudo tokeną.
};

#endif // OAUTH_STUB_HPP
