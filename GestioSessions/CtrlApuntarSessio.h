#pragma once
#include "PassarelaSessio.h"

#include<vector>

struct SessioInfo {
	string username;
	string tema;
	string dia;
};

class CtrlApuntarSessio
{
public:
	CtrlApuntarSessio();

	vector<SessioInfo> visualitza();

	void apunta(string creador, string tema, string dia);
};

