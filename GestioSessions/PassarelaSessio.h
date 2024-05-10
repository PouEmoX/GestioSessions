#pragma once
#include "Sessio.h"
#include "Database.h"

class PassarelaSessio
{
private:
    Sessio sessio; // Utiliza un puntero inteligente para gestionar la vida útil de Sessio
public:
    PassarelaSessio();
};