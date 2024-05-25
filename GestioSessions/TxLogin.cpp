#include "pch.h"
#include "TxLogin.h"

TxLogin::TxLogin(string e, string c) {
    estudiant = e;
    contrasenya = c;
}

bool TxLogin::Executa() {
    try {
        // Realiza la b�squeda del estudiante
        CercadoraEstudiant ce = CercadoraEstudiant();
        PassarelaEstudiant estudiante = ce.cercar(estudiant, contrasenya);

        // Tractem el cas en que hi ha cap error d'execuci� pero no es troba l'estudiant
        if (estudiante.obteEstudiant().empty() || estudiante.obteContrasenya().empty())
        {
            return false;
        }

        // Si la b�squeda tiene �xito, devuelve verdadero
        return true;
    }
    catch (Exception^ ex) {
        throw ex;
        return false;
    }
}

