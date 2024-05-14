#pragma once
#include<iostream>

using namespace std;
class Sessio
{
private:
	string estudiant_creador;
	string tema;
	string dia;

public:
	Sessio(string estudiant, string tema, string dia);

	Sessio();

	string get_estudiant();
	string get_tema();
	string get_dia();
};

