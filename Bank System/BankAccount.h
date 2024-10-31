#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class BankAccount {
protected:
    int accountNumber;
    std::string accountHolder;
    double balance;
    std::string password; // Added password attribute
    std::vector<std::string> transactions; // Added transaction history

public:
    BankAccount(int number, const std::string& holder, const std::string& password);
    virtual void deposit(double amount);
    virtual void withdraw(double amount);
    virtual void display() const = 0; // Pure virtual function
    virtual void saveToFile(std::ofstream& outFile) const;
    virtual ~BankAccount() {}

    int getAccountNumber() const { return accountNumber; }
    double getBalance() const { return balance; }

    void printTransactions() const; // New method to print transaction history
    bool checkPassword(const std::string& password) const; // New method to check password
};

#endif // BANKACCOUNT_H
