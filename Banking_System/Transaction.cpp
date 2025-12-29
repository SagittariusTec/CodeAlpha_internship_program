#include "Transaction.hpp"
#include "Account.hpp"
#include <iostream>
#include <ctime>

static int transactionCounter = 1;

Transaction::Transaction(const std::string& type, double amount,
                         const std::string& timeStamp,
                         const Account* source,
                         const Account* destination)
    : type(type), amount(amount), dateTime(timeStamp)
{
    transactionID = "TX" + std::to_string(transactionCounter++);
    sourceAccNumber = source ? source->getAccountNumber() : "N/A";
    destinationAccNumber = destination ? destination->getAccountNumber() : "N/A";
}

std::string Transaction::getTransactionID() const { return transactionID; }
std::string Transaction::getType() const { return type; }
double Transaction::getAmount() const { return amount; }
std::string Transaction::getDateTime() const { return dateTime; }
std::string Transaction::getSourceAccount() const { return sourceAccNumber; }
std::string Transaction::getDestinationAccount() const { return destinationAccNumber; }

void Transaction::displayTransactionDetails() const {
    std::cout << transactionID << " | " << type
              << " | Amount: " << amount
              << " | Date: " << dateTime
              << " | From: " << sourceAccNumber
              << " | To: " << destinationAccNumber << std::endl;
}
