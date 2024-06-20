#include "pch.h"
#include "DadesUsuari.h"

void DadesUsuari::setUsername(const std::string& name) {
    username = name;
}

std::string DadesUsuari::getUsername() const {
    return username;
}
