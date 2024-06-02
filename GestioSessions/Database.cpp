#include "pch.h"
#include "DataBase.h"

#include<fstream>
#include <vcclr.h>


Database::Database() {

    // Inicializar la cadena de conexión
    String^ connection = "";

    ifstream config;
    String^ configPath = "..\\config.txt";

    config.open("..\\config.txt", ios::in);

    if (config.fail()) {
        MessageBox::Show("Imposible acceder a la información de la base de datos");
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
}

MySqlDataReader^ Database::executarReader(string comanda_sql) {
    String^ sql = gcnew String(comanda_sql.c_str());
    MySqlCommand^ cursor = gcnew MySqlCommand(sql, conn);
    MySqlDataReader^ dataReader;

    try {
        this->conn->Open();
        dataReader = cursor->ExecuteReader();
    }
    catch (Exception^ x) {
        conn->Close();
        throw; // Re-lanzar la excepción para que la capa superior la maneje
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
        conn->Open();
        cmd->ExecuteNonQuery();
    }
    catch (Exception^ ex) {
        Console::WriteLine(ex->Message);
    }
    finally {
        conn->Close();
    }
}

int Database::executarScalar(std::string comanda_sql) {
    int value = 0;
    String^ sql = gcnew String(comanda_sql.c_str());
    MySqlCommand^ cmd = gcnew MySqlCommand(sql, conn);

    try {
        conn->Open();
        Object^ result = cmd->ExecuteScalar();
        if (result != nullptr) {
            value = Convert::ToInt32(result);
        } else {
        }
    }
    catch (Exception^ ex) {
        throw(ex);
    }
    finally {
        conn->Close();
    }

    return value;
}


void Database::beginTransaction(MySqlTransaction^ transaccio, MySqlConnection^ conn) {
    transaccio = conn->BeginTransaction();
}

void Database::commitTransaction(MySqlTransaction^ transaccio) {
    transaccio->Commit();
}

void Database::roolbackTransaction(MySqlTransaction^ transaccio) {
    transaccio->Rollback();
}






