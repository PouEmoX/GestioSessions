#pragma once
#include<iostream>

using namespace std;

class PassarelaSessio
{
private:
    string estudiant;
    string tema;
    string dia;
public:
    PassarelaSessio();
    PassarelaSessio(string e, string t,string d);

    void inserta();

    string obteEstudiant();
    string obteTema();
    string obteDia();

    void posaEstudiant(string e);
    void posaTema(string t);
    void posaDia(string d);
};