#include "Account.hpp"
#include "Transaction.hpp"
#include "Customer.hpp"
#include <iostream>
#include <chrono>
#include <ctime>

static std::string currentDateTime() {
    time_t now = time(0);
    char buf[26];
    ctime_s(buf, sizeof(buf), &now);
    buf[24] = '\0';
    return std::string(buf);
}

Account::Account(const std::string& accountNumber, double balance, Customer* owner)
    : accountNumber(accountNumber), balance(balance), owner(owner) {}

std::string Account::getAccountNumber() const { return accountNumber; }
double Account::getBalance() const { return balance; }
Customer* Account::getOwner() const { return owner; }

void Account::deposit(double amount) {
    if (amount <= 0) {
        std::cout << "Invalid deposit amount.\n";
        return;
    }
    balance += amount;

    transactionHistory.push_back(
        std::make_shared<Transaction>("Deposit", amount, currentDateTime(), this));
}

bool Account::withdraw(double amount) {
    if (amount <= 0 || amount > balance) {
        std::cout << "Insufficient funds or invalid amount.\n";
        return false;
    }
    balance -= amount;

    transactionHistory.push_back(
        std::make_shared<Transaction>("Withdraw", amount, currentDateTime(), this));
    return true;
}

bool Account::transfer(Account* destination, double amount) {
    if (!destination) {
        std::cout << "Invalid destination account.\n";
        return false;
    }
    if (!withdraw(amount)) return false;

    destination->balance += amount;

    std::shared_ptr<Transaction> t =
        std::make_shared<Transaction>("Transfer", amount,
                                      currentDateTime(), this, destination);

    transactionHistory.push_back(t);
    destination->transactionHistory.push_back(t);

    return true;
}

const std::vector<std::shared_ptr<Transaction>>& Account::getTransactionHistory() const {
    return transactionHistory;
}

void Account::showTransactionHistory() const {
    for (const auto& t : transactionHistory) {
        t->displayTransactionDetails();
    }
}

void Account::displayAccountInfo() const {
    std::cout << "Account: " << accountNumber
              << " | Balance: " << balance
              << " | Owner: " << owner->getName() << std::endl;
}
