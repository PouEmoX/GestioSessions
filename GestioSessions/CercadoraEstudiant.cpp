#include "pch.h"
#include "CercadoraEstudiant.h"
#include "Database.h"
#include <vcclr.h>

using namespace System;

std::string convertirString(System::String^ str) {
    if (str == nullptr) {
        return "";
    }
  
    IntPtr p = System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(str);
    std::string os = static_cast<const char*>(p.ToPointer());
    System::Runtime::InteropServices::Marshal::FreeHGlobal(p);
    return os;
}

System::String^ convertirString(const std::string& str) {
    return gcnew System::String(str.c_str());
}

CercadoraEstudiant::CercadoraEstudiant(){}

PassarelaEstudiant CercadoraEstudiant::cercar(string estudiant, string contrasenya) {

    
    Database db;
    string sql = "SELECT * FROM estudiants WHERE TRIM(username) = '" + estudiant + "' AND TRIM(password) = '" + contrasenya + "'";

    try {
        MySqlDataReader^ reader = db.executarReader(sql);

        PassarelaEstudiant pe = PassarelaEstudiant();

        if (reader->Read()) {
            string username = convertirString(reader["username"]->ToString());
            string password = convertirString(reader["password"]->ToString());
            pe = PassarelaEstudiant(username, password);
        }

        return pe;
    }
    catch (Exception^ ex) {
        throw; // Re-lanzar la excepción para que la capa de presentación la maneje
    }
    

}