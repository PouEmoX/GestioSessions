#pragma once
#include "PassarelaSessio.h"

class TxAltaSessio
{
private: 
	string tema;
	string dia;
public:
	TxAltaSessio(string t, string d);
	void Executa();
};

