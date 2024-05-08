#include "pch.h"
#include "PassarelaSessio.h"
#include <fstream>
#include <msclr/marshal_cppstd.h>

using namespace System;
using namespace System::Windows::Forms;

PassarelaSessio::PassarelaSessio() {
    // Inicializar la cadena de conexión
    string connection = "";

    ifstream config("..\\config.txt"); // Abre el archivo de configuración

    if (config.fail()) {
        MessageBox::Show("Imposible acceder a la información de la base de datos");
    }
    else {
        while (!config.eof()) {
            string line;
            getline(config, line);

            connection += line;
        }
        config.close();
    }

    connectionString = connection;
    String^ dotNetConS = gcnew String(connectionString.c_str());
    MySqlConnection^ conn = gcnew MySqlConnection(dotNetConS);

    sessio = make_unique<Sessio>(); // Inicializa Sessio utilizando un puntero inteligente
}

PassarelaSessio::PassarelaSessio(string estudiant) {
    // Inicializar la cadena de conexión
    string connection = "";

    ifstream config("..\\config.txt"); // Abre el archivo de configuración

    if (config.fail()) {
        MessageBox::Show("Imposible acceder a la información de la base de datos");
    }
    else {
        while (!config.eof()) {
            string line;
            getline(config, line);

            connection += line;
        }
        config.close();
    }

    connectionString = connection;
    String^ dotNetConS = gcnew String(connectionString.c_str());
    MySqlConnection^ conn = gcnew MySqlConnection(dotNetConS);


    sessio = make_unique<Sessio>(estudiant, "", "", ""); // Inicializa Sessio utilizando un puntero inteligente
}