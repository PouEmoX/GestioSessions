#include "pch.h"
#include "TxLogin.h"
#include "DadesUsuari.h"

TxLogin::TxLogin(string e, string c) {
    estudiant = e;
    contrasenya = c;
}

bool TxLogin::Executa() {
    try {
        // Realitza la b�squeda de l'estudiant
        CercadoraEstudiant ce = CercadoraEstudiant();
        PassarelaEstudiant estudiante = ce.cercar(estudiant, contrasenya);

        // Tractem el cas en que hi ha cap error d'execuci� per� no es troba l'estudiant
        if (estudiante.obteEstudiant().empty() || estudiante.obteContrasenya().empty())
        {
            return false;
        }

        DadesUsuari& auth = DadesUsuari::getInstance();
        auth.setUsername(estudiant);
        // Si la b�squeda te exit retornem vertader
        return true;
    }
    catch (Exception^ ex) {
        throw gcnew Exception ("No s'ha pogut iniciar sess��");
        return false;
    }
}

