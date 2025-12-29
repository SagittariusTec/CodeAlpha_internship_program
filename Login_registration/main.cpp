#include <iostream>
#include <string>
#include "AuthSystem.hpp"

void showMenu() {
    std::cout << "\n===== LOGIN & REGISTRATION SYSTEM =====\n";
    std::cout << "1. Register\n";
    std::cout << "2. Login\n";
    std::cout << "3. Exit\n";
    std::cout << "Choose an option: ";
}

int main() {
    AuthSystem auth;
    int choice;
    std::string username, password;

    while (true) {
        showMenu();
        std::cin >> choice;

        switch (choice) {
        case 1:  // Registration
            std::cout << "\nEnter a username: ";
            std::cin >> username;
            std::cout << "Enter a password: ";
            std::cin >> password;

            if (auth.registerUser(username, password)) {
                std::cout << "Registration successful!\n";
            } else {
                std::cout << "Registration failed! Username already exists.\n";
            }
            break;

        case 2:  // Login
            std::cout << "\nEnter your username: ";
            std::cin >> username;
            std::cout << "Enter your password: ";
            std::cin >> password;

            if (auth.login(username, password)) {
                std::cout << "Login successful! Welcome, " << username << "!\n";
            } else {
                std::cout << "Login failed! Incorrect username or password.\n";
            }
            break;

        case 3:
            std::cout << "Goodbye!\n";
            return 0;

        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
