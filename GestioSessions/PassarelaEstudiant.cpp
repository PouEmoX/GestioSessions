#include "pch.h"
#include "PassarelaEstudiant.h"
#include "Database.h"

PassarelaEstudiant::PassarelaEstudiant() {
	estudiant = "";
	contrasenya = "";
}

PassarelaEstudiant::PassarelaEstudiant(string e, string c) {
	estudiant = e;
	contrasenya = c;
}

void PassarelaEstudiant::inserta() {
	//Código sin probar
	// Aplicar TRIM() al username
	string trimmedUsername = estudiant.substr(estudiant.find_first_not_of(' '), estudiant.find_last_not_of(' ') - estudiant.find_first_not_of(' ') + 1);
	string trimmedPassword = contrasenya.substr(contrasenya.find_first_not_of(' '), contrasenya.find_last_not_of(' ') - contrasenya.find_first_not_of(' ') + 1);

	Database db;

	string sql = "INSERT INTO estudiants(username, password) VALUES(@username, @password)";
	db.executarNonQuery(sql, { {"@username", trimmedUsername}, {"@password", trimmedPassword}});
}

string PassarelaEstudiant::obteEstudiant() {
	return estudiant;
}
string PassarelaEstudiant::obteContrasenya() {
	return contrasenya;
}

void PassarelaEstudiant::posaEstudiant(string e) {
	estudiant = e;
}
void PassarelaEstudiant::posaContrasenya(string c) {
	contrasenya = c;
}