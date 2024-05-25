#include "pch.h"
#include "PassarelaSessio.h"
#include "Database.h"

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
string PassarelaSessio::obteEstudiant() {
    return estudiant;
}
string PassarelaSessio::obteTema() {
    return tema;
}
string PassarelaSessio::obteDia() {
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

    Database db;

    string sql = "INSERT INTO sessions(creador, tema, dia) VALUES(@username, @tema, @dia)";
    db.executarNonQuery(sql, { {"@username", trimmedUsername}, {"@tema", tema}, {"@dia", dia} });

    sql = "SELECT LAST_INSERT_ID()";
    int id = db.executarScalar(sql);

    sql = "INSERT INTO participants (sessioId, estudiantUsername) VALUES (@sessioId, @username)";
    db.executarNonQuery(sql, { {"@sessioId", to_string(id)}, {"@username", trimmedUsername} });
}



