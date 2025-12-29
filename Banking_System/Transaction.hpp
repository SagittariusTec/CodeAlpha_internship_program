#ifndef TRANSACTION_HPP
#define TRANSACTION_HPP

#include <string>
#include <memory>

class Account; // Forward declaration

class Transaction {
private:
    std::string transactionID;
    std::string type;
    double amount;
    std::string dateTime;
    std::string sourceAccNumber;
    std::string destinationAccNumber;

public:
    Transaction(const std::string& type, double amount,
                const std::string& timeStamp,
                const Account* source,
                const Account* destination = nullptr);

    std::string getTransactionID() const;
    std::string getType() const;
    double getAmount() const;
    std::string getDateTime() const;
    std::string getSourceAccount() const;
    std::string getDestinationAccount() const;
    void displayTransactionDetails() const;
};

#endif
