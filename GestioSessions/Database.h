#pragma once
#include <string>
#include <iostream>
#include <map>

using namespace System;
using namespace System::Windows::Forms;
using namespace std;
using namespace MySql::Data::MySqlClient;

ref class Database
{
private:
    static Database^ instance;
    String^ connectionString;
    MySqlConnection^ conn;

    Database();

public:
    ~Database();

    static Database^ getInstance();

    MySqlDataReader^ executarReader(string comanda_sql);
    void executarNonQuery(string comanda_sql, map<string, string> parametros);
    int executarScalar(string comanda_sql);

    void beginTransaction(MySqlTransaction^ transaccio, MySqlConnection^ conn);
    void commitTransaction(MySqlTransaction^ transaccio);
    void rollbackTransaction(MySqlTransaction^ transaccio);
};
