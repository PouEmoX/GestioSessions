#pragma once
#include "CercadoraEstudiant.h"
#include "PassarelaEstudiant.h"
#include "Database.h"

class TxLogin
{
private:
	string estudiant;
	string contrasenya;
public:
	TxLogin(string e, string c);
	bool Executa();

};

