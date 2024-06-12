#include "pch.h"
#include "CercadoraSessio.h"
#include "Database.h"
#include "Aux.h"
#include "AuthSys.h"

CercadoraSessio::CercadoraSessio() {}

vector<PassarelaSessio> fetchSessionsFromReader(MySqlDataReader^ reader) {
    vector<PassarelaSessio> sessions;

    conversorString cs;
    while (reader->Read()) {
        string username = cs.convertirString(reader["creador"]->ToString());
        string tema = cs.convertirString(reader["tema"]->ToString());
        string dia = cs.convertirString(reader["dia"]->ToString());

        PassarelaSessio session(username, tema, dia);
        sessions.push_back(session);
    }

    reader->Close();

    return sessions;
}

vector<PassarelaSessio> CercadoraSessio::cercarSessionsEstudiant(string estudiant) {
    vector<PassarelaSessio> sessions;
    Database^ db = Database::getInstance();

    try {
        string query = "select creador, tema, dia from sessions s join participants p on p.sessioId = s.id where  p.estudiantUsername = '" + estudiant + "'";
        MySqlDataReader^ reader = db->executarReader(query);
        sessions = fetchSessionsFromReader(reader);
    }
    catch (Exception^ ex) {
        throw(ex);
    }

    return sessions;
}

vector<PassarelaSessio> CercadoraSessio::cercarSessionsDisponibles(string estudiant) {
    vector<PassarelaSessio> sessions;
    Database^ db = Database::getInstance();

    try {
        string query = "select s.creador, s.tema, s.dia from sessions s join participants p ON p.sessioId = s.id "
            "where p.estudiantUsername <> '" + estudiant + "' and not exists ("
            "    select 1 from participants p2 where p2.sessioId = s.id and p2.estudiantUsername = '" + estudiant + "'"
            ") group by p.sessioId;";
        MySqlDataReader^ reader = db->executarReader(query);
        sessions = fetchSessionsFromReader(reader);
    }
    catch (Exception^ ex) {
        throw(ex);
    }

    return sessions;
}


int CercadoraSessio::cercarId(string estudiant, string tema, string dia) {
	Database^ db = Database::getInstance();

	string query = "select id from sessions where creador = '" + estudiant + "' and tema = '" + tema + "' and dia = '" + dia + "'";

	int id = db->executarScalar(query);
	db->~Database();

	return id;
}
