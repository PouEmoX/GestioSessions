#include "pch.h"
#include "TxVeureSessions.h"
#include "CercadoraSessio.h"
#include "AuthSys.h"

TxVeureSessions::TxVeureSessions(){}

vector<PassarelaSessio> TxVeureSessions::Executa() {
	CercadoraSessio cercadora;
	AuthSys& auth = AuthSys::getInstance();
	vector<PassarelaSessio> sessions = cercadora.cercarSessionsEstudiant(auth.getUsername());
	return sessions;
}