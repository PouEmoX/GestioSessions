#include "pch.h"
#include "PassarelaParticipants.h"
#include "Database.h"

PassarelaParticipants::PassarelaParticipants() {}

PassarelaParticipants::PassarelaParticipants(int id, string e) {
	idSessio = id;
	estudiant = e;
}

void PassarelaParticipants::inserta() {

	string username = estudiant;
	string trimmedUsername = username.substr(username.find_first_not_of(' '), username.find_last_not_of(' ') - username.find_first_not_of(' ') + 1);

	Database^ db = Database::getInstance();
	string sql = "INSERT INTO participants (sessioId, estudiantUsername) VALUES (@sessioId, @username)";
	db->executarNonQuery(sql, { {"@sessioId", to_string(idSessio)}, {"@username", trimmedUsername} });

	db->~Database();

}

int PassarelaParticipants::obteId() {
	return idSessio;
}
string PassarelaParticipants::obteEstudiant() {
	return estudiant;
}

void PassarelaParticipants::posaId(int id) {
	idSessio = id;
}
void PassarelaParticipants::posaEstudiant(string e) {
	estudiant = e;
}
