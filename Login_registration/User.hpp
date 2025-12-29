#ifndef USER_HPP
#define USER_HPP

#include <string>

class User {
private:
    std::string username;
    std::string passwordHash;

public:
    User(const std::string& username, const std::string& hashedPassword);

    std::string getUsername() const;
    std::string getPasswordHash() const;

    bool verifyPassword(const std::string& hashedEnteredPassword) const;
};

#endif
