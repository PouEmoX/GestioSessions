#pragma once
#include "Sessio.h"
#include "Database.h"

class PassarelaSessio
{
private:
    Sessio sessio; // Utiliza un puntero inteligente para gestionar la vida �til de Sessio
public:
    PassarelaSessio();
};