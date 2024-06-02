#pragma once
#include<iostream>

using namespace std;

class PassarelaParticipants
{
private:
	int idSessio;
	string estudiant;

public:
	PassarelaParticipants();
	PassarelaParticipants(int id, string e);

	void inserta();

	int obteId();
	string obteEstudiant();

	void posaId(int id);
	void posaEstudiant(string e);
};

