#pragma once
#include <string>
#include <iostream>

using namespace System;
using namespace System::Windows::Forms;
using namespace std;

using namespace MySql::Data::MySqlClient;

ref class Database
{
protected:

private:

public:
    String^ connectionString;
    MySqlConnection^ conn;
    // Constructor
    Database();

    MySqlDataReader^ executarReader(string comanda_sql);

    int executarScalar(string comanda_sql);

    void beginTransaction(MySqlTransaction^ transaccio, MySqlConnection^ conn);
    void commitTransaction(MySqlTransaction^ transaccio);
    void roolbackTransaction(MySqlTransaction^ transaccio);
};
