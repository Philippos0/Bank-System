#ifndef BANK_H
#define BANK_H

#include "BankAccount.h"
#include <vector>
#include <memory>
#include <iostream>
#include <fstream>

class Bank {
private:
    std::vector<std::shared_ptr<BankAccount>> accounts;

public:
    void createAccount();
    void deposit();
    void withdraw();
    void transfer();
    void displayAccounts() const;
    void saveAccountsToFile(const std::string& filename) const;
    void loadAccountsFromFile(const std::string& filename);
    void closeAccount();
    void printTransactionHistory() const; // New method for transaction history
    void applyInterest(); // New method to apply interest
    bool authenticateAccount(int accountNumber, const std::string& password); // New method for authentication
};

#endif // BANK_H
