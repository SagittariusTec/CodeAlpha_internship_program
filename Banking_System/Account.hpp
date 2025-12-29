#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <string>
#include <vector>
#include <memory>

class Customer;     // Forward declaration
class Transaction;  // Forward declaration

class Account {
private:
    std::string accountNumber;
    double balance;
    Customer* owner;

    std::vector<std::shared_ptr<Transaction>> transactionHistory;

public:
    Account(const std::string& accountNumber, double balance, Customer* owner);

    // Disable copy and assign (prevents shallow memory issues)
    Account(const Account&) = delete;
    Account& operator=(const Account&) = delete;

    ~Account() = default;

    std::string getAccountNumber() const;
    double getBalance() const;
    Customer* getOwner() const;

    void deposit(double amount);
    bool withdraw(double amount);
    bool transfer(Account* destination, double amount);

    const std::vector<std::shared_ptr<Transaction>>& getTransactionHistory() const;
    void showTransactionHistory() const;
    void displayAccountInfo() const;
};

#endif
