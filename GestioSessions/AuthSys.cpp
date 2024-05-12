#include "pch.h"
#include "AuthSys.h"

void AuthSys::setUsername(const std::string& name) {
    username = name;
}

std::string AuthSys::getUsername() const {
    return username;
}
