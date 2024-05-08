#pragma once
#include "Sessio.h"
#include <string>
#include <memory> // Incluye la cabecera para trabajar con punteros inteligentes

using namespace std;
using namespace MySql::Data::MySqlClient;

class PassarelaSessio
{
private:
    unique_ptr<Sessio> sessio; // Utiliza un puntero inteligente para gestionar la vida útil de Sessio
public:
    string connectionString;
    PassarelaSessio();
    PassarelaSessio(string estudiant);
};