#include "pch.h"
#include "CtrlApuntarSessio.h"
#include "CercadoraSessio.h"
#include "AuthSys.h"
#include "PassarelaParticipants.h"

CtrlApuntarSessio::CtrlApuntarSessio(){}

vector<SessioInfo> CtrlApuntarSessio::visualitza(){
	CercadoraSessio cercadora;
	AuthSys& auth = AuthSys::getInstance();
	vector<PassarelaSessio> sessions = cercadora.cercarSessionsDisponibles(auth.getUsername());
	std::vector<SessioInfo> sessioInfo;
	for (const auto& sessio : sessions) {
		sessioInfo.push_back({
			sessio.obteEstudiant(),
			sessio.obteTema(),
			sessio.obteDia()
			});
	}
	return sessioInfo;
}

void CtrlApuntarSessio::apunta(string creador, string tema, string dia) {
	CercadoraSessio cercadora;
	AuthSys& auth = AuthSys::getInstance();
	int id = cercadora.cercarId(creador, tema, dia);

	PassarelaParticipants pp = PassarelaParticipants(id, auth.getUsername());
	pp.inserta();
}
