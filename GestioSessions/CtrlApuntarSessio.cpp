#include "pch.h"
#include "CtrlApuntarSessio.h"
#include "CercadoraSessio.h"
#include "AuthSys.h"
#include "PassarelaParticipants.h"

CtrlApuntarSessio::CtrlApuntarSessio(){}

vector<PassarelaSessio> CtrlApuntarSessio::visualitza(){
	CercadoraSessio cercadora;
	AuthSys& auth = AuthSys::getInstance();
	vector<PassarelaSessio> sessions = cercadora.cercarSessionsDisponibles(auth.getUsername());
	return sessions;
}

void CtrlApuntarSessio::apunta(string creador, string tema, string dia) {
	CercadoraSessio cercadora;
	AuthSys& auth = AuthSys::getInstance();
	int id = cercadora.cercarId(creador, tema, dia);

	PassarelaParticipants pp = PassarelaParticipants(id, auth.getUsername());
	pp.inserta();
}
