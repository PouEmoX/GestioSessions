#include "pch.h"
#include "CercadoraEstudiant.h"
#include "Database.h"
#include "conversorString.h"

using namespace System;

CercadoraEstudiant::CercadoraEstudiant(){}

PassarelaEstudiant CercadoraEstudiant::cercar(string estudiant, string contrasenya) {

    conversorString cs;
    Database^ db = Database::getInstance();
    string sql = "SELECT * FROM estudiants WHERE TRIM(username) = '" + estudiant + "' AND TRIM(password) = '" + contrasenya + "'";

    try {
        MySqlDataReader^ reader = db->executarReader(sql);

        PassarelaEstudiant pe = PassarelaEstudiant();

        if (reader->Read()) {
            string username = cs.convertirString(reader["username"]->ToString());
            string password = cs.convertirString(reader["password"]->ToString());
            pe = PassarelaEstudiant(username, password);
        }

        reader->Close();
        db->~Database();

        return pe;
    }
    catch (Exception^ ex) {
        throw(ex); 
    }

    db->~Database();
}