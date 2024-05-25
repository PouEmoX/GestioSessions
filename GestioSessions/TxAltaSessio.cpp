#include "pch.h"
#include "TxAltaSessio.h"
#include "AuthSys.h"

TxAltaSessio::TxAltaSessio(string t, string d) {
	dia = d;
	tema = t;

};

void TxAltaSessio::Executa() {
	AuthSys& auth = AuthSys::getInstance();
	PassarelaSessio ps(auth.getUsername(), tema, dia);
	ps.inserta();
}

