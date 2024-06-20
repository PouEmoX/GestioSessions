#include "pch.h"
#include "TxAltaSessio.h"
#include "DadesUsuari.h"

using namespace System;

TxAltaSessio::TxAltaSessio(string t, string d) {
	dia = d;
	tema = t;
};

void TxAltaSessio::Executa() {
	DadesUsuari& auth = DadesUsuari::getInstance();
	PassarelaSessio ps(auth.getUsername(), tema, dia);

	try {
		ps.inserta();
	}
	catch(Exception^ ex) {
		throw gcnew Exception ("No s'ha pogut crear la sessió d'estudi");
	}
}

