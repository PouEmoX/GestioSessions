#pragma once
#include "PassarelaSessio.h"
#include<iostream>

using namespace std;

class TxAltaSessio
{
private: 
	string tema;
	string dia;
public:
	TxAltaSessio(string t, string d);
	void Executa();
};

