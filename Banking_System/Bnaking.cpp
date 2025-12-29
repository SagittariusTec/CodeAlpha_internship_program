#include <iostream>
#include "Customer.hpp"
#include "Account.hpp"
#include "Transaction.hpp"

int main() {
    // Create Customers
    Customer c1("C001", "Alice", "123456");
    Customer c2("C002", "Bob", "987654");

    // Create Accounts and assign them to customers
    Account a1("A001", 500.0, &c1);
    Account a2("A002", 1000.0, &c2);

    c1.addAccount(&a1);
    c2.addAccount(&a2);

    std::cout << "=== Initial Account Info ===" << std::endl;
    a1.displayAccountInfo();
    a2.displayAccountInfo();
    std::cout << std::endl;

    // Deposit Test
    std::cout << "=== Deposit 200 into A001 ===" << std::endl;
    a1.deposit(200);
    a1.displayAccountInfo();
    std::cout << std::endl;

    // Withdraw Test
    std::cout << "=== Withdraw 50 from A002 ===" << std::endl;
    a2.withdraw(50);
    a2.displayAccountInfo();
    std::cout << std::endl;

    // Transfer Test
    std::cout << "=== Transfer 300 from A001 to A002 ===" << std::endl;
    a1.transfer(&a2, 300);
    a1.displayAccountInfo();
    a2.displayAccountInfo();
    std::cout << std::endl;

    // Show transaction history for both accounts
    std::cout << "=== Transaction History for A001 ===" << std::endl;
    a1.showTransactionHistory();
    std::cout << std::endl;

    std::cout << "=== Transaction History for A002 ===" << std::endl;
    a2.showTransactionHistory();
    std::cout << std::endl;

    std::cout << "=== Customer Information ===" << std::endl;
    c1.displayCustomerInfo();
    c2.displayCustomerInfo();
    return 0;
}
