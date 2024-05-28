#include "pch.h"
#include "TxLogin.h"
#include "AuthSys.h"

TxLogin::TxLogin(string e, string c) {
    estudiant = e;
    contrasenya = c;
}

bool TxLogin::Executa() {
    try {
        // Realitza la búsqueda de l'estudiant
        CercadoraEstudiant ce = CercadoraEstudiant();
        PassarelaEstudiant estudiante = ce.cercar(estudiant, contrasenya);

        // Tractem el cas en que hi ha cap error d'execució peró no es troba l'estudiant
        if (estudiante.obteEstudiant().empty() || estudiante.obteContrasenya().empty())
        {
            return false;
        }

        AuthSys& auth = AuthSys::getInstance();
        auth.setUsername(estudiant);
        // Si la búsqueda te exit retornem vertader
        return true;
    }
    catch (Exception^ ex) {
        throw ex;
        return false;
    }
}

