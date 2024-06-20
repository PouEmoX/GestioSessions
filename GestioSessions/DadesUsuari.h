#pragma once

#include <string>

class DadesUsuari {
private:
    std::string username;

    // Constructor privado para prevenir la instanciaci�n desde fuera de la clase
    DadesUsuari() {}

public:
    // Funci�n est�tica para obtener la instancia �nica de la clase
    static DadesUsuari& getInstance() {
        // Declaraci�n de la instancia est�tica
        static DadesUsuari instance;
        return instance;
    }

    // M�todos para establecer y obtener el nombre de usuario
    void setUsername(const std::string& name);
    std::string getUsername() const;

    // Puedes agregar m�s m�todos para manejar otros datos del usuario si es necesario
};
