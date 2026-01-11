
# 45-SolarWinds-Maintenance-Window

**Aprašymas:** Maintenance window planavimas

⚠️ Tai **stub** projektas demonstracijai – jokių tinklo kvietimų (saugus portfoliui). 

## Struktūra
```
.
├── CMakeLists.txt
├── README.md
├── config.json
├── include/
│   ├── http_client_stub.hpp
│   ├── logger.hpp
│   ├── metrics.hpp
│   ├── oauth_stub.hpp
│   └── retry.hpp
├── src/
│   ├── http_client_stub.cpp
│   ├── oauth_stub.cpp
│   └── main.cpp
└── tests/
    └── test_main.cpp
```

## Kaip paleisti (lokaliai)
```bash
cmake -S . -B build
cmake --build build -j
./build/45-SolarWinds-Maintenance-Window
```

### Konfigūracija
`config.json` (stub reikšmės):
```json
{
  "base_url": "https://api.example.local",
  "token_url": "https://auth.example.local/oauth/token",
  "client_id": "demo-client",
  "client_secret": "demo-secret",
  "scope": "read write"
}
```
Galima naudoti ir aplinkos kintamuosius: `BASE_URL`, `TOKEN_URL`, `CLIENT_ID`, `CLIENT_SECRET`, `SCOPE`.

## CI/CD (GitHub Actions)
Failas: `.github/workflows/ci-cd-pipeline.yml` – sukompiliuoja ir paleidžia testus.

## KPI (demonstraciniai)
- **MTTR**: -20% dėl greito incidento sukūrimo
- **Response time**: < 2 s (stub)
- **Pipeline**: < 2 min
- **Anotacijos**: < 500 ms

## Pastabos realiai aplinkai
- Pakeiskite `OAuthClient::get_token_stub` į realų `client_credentials` srautą.
- `HttpClient` pakeiskite į realų HTTP klientą (curl/cpr/Boost.Beast).
- Pridėkite `retry`, `rate limiting`, `structured logging`, `secrets manager`. 
