#ifndef AUTHSYSTEM_HPP
#define AUTHSYSTEM_HPP

#include <string>
#include "User.hpp"

class AuthSystem
{
private:
    bool userExists(const std::string& username) const;
    std::string hashPassword(const std::string& password) const;
    User loadUser(const std::string& username) const;

public:
    bool registerUser(const std::string& username, const std::string& password);
    bool login(const std::string& username, const std::string& password);
    void saveUserToFile(const User& user) const;
};

#endif
