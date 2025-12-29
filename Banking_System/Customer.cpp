#include "Customer.hpp"
#include "Account.hpp"
#include <iostream>

Customer::Customer(const std::string& id, const std::string& name,
                   const std::string& phoneNumber)
    : customerID(id), name(name), phoneNumber(phoneNumber) {}

std::string Customer::getCustomerID() const { return customerID; }
std::string Customer::getName() const { return name; }
std::string Customer::getPhoneNumber() const { return phoneNumber; }

void Customer::addAccount(Account* acc) {
    accounts.push_back(acc);
}

const std::vector<Account*>& Customer::getAccounts() const {
    return accounts;
}

void Customer::displayCustomerInfo() const {
    std::cout << "Customer ID: " << customerID
              << " | Name: " << name
              << " | Phone: " << phoneNumber << std::endl;
}
