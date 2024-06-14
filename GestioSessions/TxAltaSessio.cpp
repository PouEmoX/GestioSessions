#include "pch.h"
#include "TxAltaSessio.h"
#include "AuthSys.h"

using namespace System;

TxAltaSessio::TxAltaSessio(string t, string d) {
	dia = d;
	tema = t;
};

void TxAltaSessio::Executa() {
	AuthSys& auth = AuthSys::getInstance();
	PassarelaSessio ps(auth.getUsername(), tema, dia);

	try {
		ps.inserta();
	}
	catch(Exception^ ex) {
		throw(ex);
	}
}

