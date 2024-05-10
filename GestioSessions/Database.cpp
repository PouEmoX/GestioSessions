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

int filasSesiones(MySqlConnection^ conn) {
    int numeroFilas = 0;
    MySqlCommand^ cmd = gcnew MySqlCommand("SELECT COUNT(*) FROM sesiones", conn);

    try {
        conn->Open();
        numeroFilas = Convert::ToInt32(cmd->ExecuteScalar());
    }
    catch (Exception^ ex) {
        Console::WriteLine(ex->Message);
    }
    finally {
        conn->Close();
    }

    return numeroFilas;
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
        MessageBox::Show(x->Message);
    }
    finally {
        conn->Close();
    }
    
    return dataReader;
}

int Database::executarScalar(string comanda_sql) {
    int value;
    String^ sql = gcnew String(comanda_sql.c_str());
    MySqlCommand^ cmd = gcnew MySqlCommand(sql, conn);

    try {
        conn->Open();
        value = Convert::ToInt32(cmd->ExecuteScalar());
    }
    catch (Exception^ ex) {
        Console::WriteLine(ex->Message);
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






