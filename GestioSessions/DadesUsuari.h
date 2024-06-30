#pragma once

#include <string>

class DadesUsuari {
private:
    std::string username;

    DadesUsuari() {}

public:
    static DadesUsuari& getInstance() {
        static DadesUsuari instance;
        return instance;
    }

    void setUsername(const std::string& name);
    std::string getUsername() const;
};
