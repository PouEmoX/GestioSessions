#include "pch.h"
#include "TxVeureSessions.h"
#include "CercadoraSessio.h"
#include "AuthSys.h"

TxVeureSessions::TxVeureSessions() {}

std::vector<SessioData> TxVeureSessions::Executa() {
    CercadoraSessio cercadora;
    AuthSys& auth = AuthSys::getInstance();
    std::vector<PassarelaSessio> sessions = cercadora.cercarSessionsEstudiant(auth.getUsername());

    std::vector<SessioData> sessioData;
    for (const auto& sessio : sessions) {
        sessioData.push_back({
            sessio.obteEstudiant(),
            sessio.obteTema(),
            sessio.obteDia()
            });
    }
    return sessioData;
}
