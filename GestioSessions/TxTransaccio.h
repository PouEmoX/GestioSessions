#pragma once
#include "PassarelaSessio.h"
#include<iostream>

using namespace std;

class TxTransaccio
{
private:
	string tema;
	string dia;
public:
	TxTransaccio(string t, string d);
	void Executa();
};