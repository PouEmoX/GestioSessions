#include "pch.h"
#include "TxAltaSessio.h"

TxAltaSessio::TxAltaSessio() {};

void TxAltaSessio::AltaSessio(string tema, string dia) {
	PassarelaSessio ps(tema, dia);
	ps.guardarSessio();
}

