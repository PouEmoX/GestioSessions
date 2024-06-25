#include "pch.h"
#include "TxTransaccio.h"
#include "DadesUsuari.h"

using namespace System;

TxTransaccio::TxTransaccio(string t, string d) {
	dia = d;
	tema = t;
};

void TxTransaccio::Executa() {
	DadesUsuari& auth = DadesUsuari::getInstance();
	PassarelaSessio ps(auth.getUsername(), tema, dia);

	try {
		ps.insertaUnica();
	}
	catch (Exception^ ex) {
		throw gcnew Exception("Ja hi existeix una sessió d'estudi per aquest dia i aquesta hora");
	}
}

