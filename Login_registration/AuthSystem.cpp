#include "AuthSystem.hpp"
#include <iostream>
#include <fstream>
#include <functional>
#include <stdexcept>

const std::string USERS_FILE = "users.txt";

// Check if username already exists
bool AuthSystem::userExists(const std::string& username) const {
    std::ifstream file(USERS_FILE);
    if (!file.is_open()) return false; // No users registered yet

    std::string storedUser, storedHash;
    while (file >> storedUser >> storedHash) {
        if (storedUser == username) {
            return true;
        }
    }
    return false;
}

// Hashing function (only used on plain passwords)
std::string AuthSystem::hashPassword(const std::string& password) const {
    std::hash<std::string> hasher;
    return std::to_string(hasher(password));
}

// Load user from file (returns user with already hashed password)
User AuthSystem::loadUser(const std::string& username) const {
    std::ifstream file(USERS_FILE);
    if (!file.is_open()) {
        throw std::runtime_error("Error: user file not found.");
    }

    std::string storedUser, storedHash;
    while (file >> storedUser >> storedHash) {
        if (storedUser == username) {
            return User(storedUser, storedHash);
        }
    }

    throw std::runtime_error("Error: username not found.");
}

// Save a new user
void AuthSystem::saveUserToFile(const User& user) const {
    std::ofstream file(USERS_FILE, std::ios::app);
    if (!file.is_open()) {
        std::cerr << "Error opening users.txt for writing." << std::endl;
        return;
    }

    file << user.getUsername() << " " << user.getPasswordHash() << std::endl;
}

// Registration
bool AuthSystem::registerUser(const std::string& username, const std::string& password) {
    if (userExists(username)) {
        std::cout << "Registration failed: user already exists.\n";
        return false;
    }

    std::string hashedPass = hashPassword(password);
    User newUser(username, hashedPass);
    saveUserToFile(newUser);

    std::cout << "User registered successfully.\n";
    return true;
}

// Login
bool AuthSystem::login(const std::string& username, const std::string& password) {
    if (!userExists(username)) {
        std::cout << "Login failed: user does not exist.\n";
        return false;
    }

    User user = loadUser(username);
    std::string hashedInput = hashPassword(password);

    if (user.verifyPassword(hashedInput)) {
        std::cout << "Login successful.\n";
        return true;
    }

    std::cout << "Login failed: incorrect password.\n";
    return false;
}
