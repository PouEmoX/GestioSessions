#pragma once
#include "PassarelaSessio.h"
#include <vector>

class CercadoraSessio
{
public:
	CercadoraSessio();
	vector<PassarelaSessio> cercarSessionsEstudiant(string estudiant);
	vector<PassarelaSessio> cercarSessionsDisponibles(string estudiant);
	int cercarId(string estudiant, string tema, string dia);
};

