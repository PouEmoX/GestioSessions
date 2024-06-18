#pragma once
#include "PassarelaSessio.h"
#include <vector>
#include <string>

struct SessioData {
    string username;
    string tema;
    string dia;
};

class TxVeureSessions {
public:
    TxVeureSessions();

    std::vector<SessioData> Executa();
};
