#include "BankAccount.h"

// Constructor for the BankAccount class
BankAccount::BankAccount(int number, const std::string& holder, const std::string& password)
    : accountNumber(number), accountHolder(holder), balance(0.0), password(password) {}

// Method to deposit money into the account
void BankAccount::deposit(double amount) {
    balance += amount;
    transactions.push_back("Deposited: " + std::to_string(amount));
}

// Method to withdraw money from the account
void BankAccount::withdraw(double amount) {
    if (balance >= amount) {
        balance -= amount;
        transactions.push_back("Withdrew: " + std::to_string(amount));
    }
    else {
        std::cout << "Insufficient funds!" << std::endl;
    }
}

// Save the account details to a file
void BankAccount::saveToFile(std::ofstream& outFile) const {
    outFile << "Account," << accountNumber << "," << accountHolder << "," << balance << std::endl;
}

// Print the transaction history of the account
void BankAccount::printTransactions() const {
    for (const auto& transaction : transactions) {
        std::cout << transaction << std::endl;
    }
}

// Check if the provided password matches the account's password
bool BankAccount::checkPassword(const std::string& password) const {
    return this->password == password;
}
