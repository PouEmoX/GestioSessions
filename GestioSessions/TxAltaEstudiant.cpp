#include "pch.h"
#include "TxAltaEstudiant.h"
#include "PassarelaEstudiant.h"

TxAltaEstudiant::TxAltaEstudiant(string u, string c) {
	username = u;
	contrasenya = c;
}

void TxAltaEstudiant::Executa() {
	PassarelaEstudiant pe = PassarelaEstudiant(username, contrasenya);
	pe.inserta();
}
