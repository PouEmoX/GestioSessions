#include "pch.h"
#include "Database.h"
#include <fstream>
#include <vcclr.h>

// Constructor privado
Database::Database() {
    // Inicializar la cadena de conexión
    String^ connection = "";

    ifstream config;

    config.open("..\\config.txt", ios::in);

    if (config.fail()) {
        throw gcnew Exception ("Imposible accedir a l'informació de la base de dades");
    }
    else {
        while (!config.eof()) {
            string line;
            getline(config, line);

            // Convertir std::string a String^
            String^ managedString = gcnew String(line.c_str());

            connection = String::Concat(connection, managedString);
        }
        config.close();
    }

    connectionString = connection;
    conn = gcnew MySqlConnection(connectionString);

    try {
        conn->Open(); // Abrir la conexión una vez
    }
    catch (Exception^ ex) {
        throw gcnew Exception ("No es pot obrir la conexió amb la base de dades: " + ex);
    }
}

// Destructor
Database::~Database() {
    if (conn != nullptr) {
        conn->Close();
        conn = nullptr;
    }
    instance = nullptr;
}

// Método estático para obtener la instancia de la clase
Database^ Database::getInstance() {
    if (instance == nullptr) {
        instance = gcnew Database();
    }
    return instance;
}

MySqlDataReader^ Database::executarReader(string comanda_sql) {
    String^ sql = gcnew String(comanda_sql.c_str());
    MySqlCommand^ cursor = gcnew MySqlCommand(sql, conn);
    MySqlDataReader^ dataReader;

    try {
        dataReader = cursor->ExecuteReader();
    }
    catch (Exception^ x) {
        throw(x); 
    }

    return dataReader;
}

void Database::executarNonQuery(string comanda_sql, map<string, string> parametros) {
    String^ sql = gcnew String(comanda_sql.c_str());
    MySqlCommand^ cmd = gcnew MySqlCommand(sql, conn);

    // Añadir parámetros
    for (auto const& param : parametros) {
        String^ paramName = gcnew String(param.first.c_str());
        String^ paramValue = gcnew String(param.second.c_str());
        cmd->Parameters->AddWithValue(paramName, paramValue);
    }

    try {
        cmd->ExecuteNonQuery();
    }
    catch (Exception^ ex) {
        throw(ex);
    }
}

int Database::executarScalar(std::string comanda_sql) {
    int value = 0;
    String^ sql = gcnew String(comanda_sql.c_str());
    MySqlCommand^ cmd = gcnew MySqlCommand(sql, conn);

    try {
        Object^ result = cmd->ExecuteScalar();
        if (result != nullptr) {
            value = Convert::ToInt32(result);
        }
    }
    catch (Exception^ ex) {
        throw(ex);
    }

    return value;
}

void Database::beginTransaction(MySqlTransaction^ transaccio, MySqlConnection^ conn) {
    transaccio = conn->BeginTransaction();
}

void Database::commitTransaction(MySqlTransaction^ transaccio) {
    transaccio->Commit();
}

void Database::rollbackTransaction(MySqlTransaction^ transaccio) {
    transaccio->Rollback();
}
