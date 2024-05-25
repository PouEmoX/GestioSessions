#pragma once
#include<iostream>

using namespace std;

class PassarelaEstudiant
{
private:
	string estudiant;
	string contrasenya;
public:
    PassarelaEstudiant();
    PassarelaEstudiant(string e, string c);

    void inserta();

    string obteEstudiant();
    string obteContrasenya();

    void posaEstudiant(string e);
    void posaContrasenya(string c);
};

