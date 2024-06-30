#include "pch.h"
#include "PassarelaSessio.h"
#include "Database.h"

using namespace System;

PassarelaSessio::PassarelaSessio() {
    estudiant = "";
    tema = "";
    dia = "";
}

PassarelaSessio::PassarelaSessio(string e,  string t, string d) {
    estudiant = e;
    tema = t;
    dia = d;
}
string PassarelaSessio::obteEstudiant() const{
    return estudiant;
}
string PassarelaSessio::obteTema() const{
    return tema;
}
string PassarelaSessio::obteDia() const{
    return dia;
}

void PassarelaSessio::posaEstudiant(string e) {
    estudiant = e;
}
void PassarelaSessio::posaTema(string t) {
    tema = t;
}
void PassarelaSessio::posaDia(string d) {
    dia = d;
}

void PassarelaSessio::inserta() {
    // Aplicar TRIM() al username
    string username = estudiant;
    string trimmedUsername = username.substr(username.find_first_not_of(' '), username.find_last_not_of(' ') - username.find_first_not_of(' ') + 1);

    try {
        Database^ db = Database::getInstance();

        string sql = "INSERT INTO sessions(creador, tema, dia) VALUES(@username, @tema, @dia)";
        db->executarNonQuery(sql, { {"@username", trimmedUsername}, {"@tema", tema}, {"@dia", dia} });

        sql = "SELECT LAST_INSERT_ID()";
        int id = db->executarScalar(sql);

        sql = "INSERT INTO participants (sessioId, estudiantUsername) VALUES (@sessioId, @username)";
        db->executarNonQuery(sql, { {"@sessioId", to_string(id)}, {"@username", trimmedUsername} });

        db->~Database();
    }
    catch (Exception^ ex) {
        throw gcnew Exception("Dades introduïdes no vàlides");
    }
}

void PassarelaSessio::insertaUnica() {
    string username = estudiant;
    string trimmedUsername = username.substr(username.find_first_not_of(' '), username.find_last_not_of(' ') - username.find_first_not_of(' ') + 1);

    Database^ db = Database::getInstance();
    MySqlTransaction^ transaccio = nullptr;

    try {
        // Iniciar la transacció
        db->beginTransaction(transaccio, db->conn);

        // Insertar la nova sessió
        string sql = "INSERT INTO sessions(creador, tema, dia) VALUES(@username, @tema, @dia)";
        db->executarNonQuery(sql, { {"@username", trimmedUsername}, {"@tema", tema}, {"@dia", dia} });

        // Verificar si ja hi existeix una sessió amb el mateix dia i hora
        sql = "SELECT COUNT(*) FROM sessions WHERE creador = @username AND dia = @dia";
        int count = db->executarScalar(sql);

        if (count > 1) {
            // Si hi existeix, realitzar un rollback
            db->rollbackTransaction(transaccio);
            throw gcnew Exception("Ja existeix una sessió per aquest dia i hora");
        }
        else {
            // Si no, realitzar commit
            db->commitTransaction(transaccio);

            // Obtindre el ID de la sessió insertada
            sql = "SELECT LAST_INSERT_ID()";
            int id = db->executarScalar(sql);

            // Insertar a la tabla participants
            sql = "INSERT INTO participants (sessioId, estudiantUsername) VALUES (@sessioId, @username)";
            db->executarNonQuery(sql, { {"@sessioId", to_string(id)}, {"@username", trimmedUsername} });
        }

        db->~Database();
    }
    catch (Exception^ ex) {
        if (transaccio != nullptr) {
            db->rollbackTransaction(transaccio);
        }
        throw gcnew Exception("Dades introduïdes no vàlides: " + ex->Message);
    }
}



