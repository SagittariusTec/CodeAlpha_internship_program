#include "User.hpp"

User::User(const std::string& username, const std::string& hashedPassword)
    : username(username), passwordHash(hashedPassword) {}

std::string User::getUsername() const {
    return username;
}

std::string User::getPasswordHash() const {
    return passwordHash;
}

bool User::verifyPassword(const std::string& hashedEnteredPassword) const {
    return passwordHash == hashedEnteredPassword;
}
