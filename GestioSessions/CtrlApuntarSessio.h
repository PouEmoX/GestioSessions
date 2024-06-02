#pragma once
#include "PassarelaSessio.h"

#include<vector>

class CtrlApuntarSessio
{
public:
	CtrlApuntarSessio();

	vector<PassarelaSessio> visualitza();

	void apunta(string creador, string tema, string dia);
};

