#pragma once
#include<iostream>

using namespace std;
class Sessio
{
private:
	string estudiant_creador;
	string tema;
	string dia;
	string hora;

public:
	Sessio(string estudiant, string tema, string dia, string hora);

	Sessio();
};

