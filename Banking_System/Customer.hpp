#ifndef CUSTOMER_HPP
#define CUSTOMER_HPP

#include <string>
#include <vector>

class Account; // Forward declaration

class Customer {
private:
    std::string customerID;
    std::string name;
    std::string phoneNumber;
    std::vector<Account*> accounts;

public:
    Customer(const std::string& id, const std::string& name,
             const std::string& phoneNumber);

    std::string getCustomerID() const;
    std::string getName() const;
    std::string getPhoneNumber() const;

    void addAccount(Account* acc);
    const std::vector<Account*>& getAccounts() const;

    void displayCustomerInfo() const;
};

#endif
