#include "pch.h"
#include "PassarelaSessio.h"
#include "AuthSys.h"
#include "Database.h"

PassarelaSessio::PassarelaSessio() {
    sessio = Sessio();
}

PassarelaSessio::PassarelaSessio(string tema, string dia) {
    AuthSys& authInstance = AuthSys::getInstance();
    sessio = Sessio(authInstance.getUsername(), tema, dia);
}

void PassarelaSessio::guardarSessio() {
    //Aplicar TRIM()
    AuthSys& authInstance = AuthSys::getInstance();
    string username = authInstance.getUsername();
    string trimmedUsername = "'" + username.substr(username.find_first_not_of(' '), username.find_last_not_of(' ') + 1) + "'";

    // Crear la consulta SQL con el username limpio
    string sql = "INSERT INTO sessions(estudiant, tema, dia) VALUES(" + trimmedUsername + ", '" + sessio.get_tema() + "', '" + sessio.get_dia() + "')";

    Database db;
    db.executarReader(sql);
}
