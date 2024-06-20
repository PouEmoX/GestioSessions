#pragma once

#include <string>

class DadesUsuari {
private:
    std::string username;

    // Constructor privado para prevenir la instanciación desde fuera de la clase
    DadesUsuari() {}

public:
    // Función estática para obtener la instancia única de la clase
    static DadesUsuari& getInstance() {
        // Declaración de la instancia estática
        static DadesUsuari instance;
        return instance;
    }

    // Métodos para establecer y obtener el nombre de usuario
    void setUsername(const std::string& name);
    std::string getUsername() const;

    // Puedes agregar más métodos para manejar otros datos del usuario si es necesario
};
