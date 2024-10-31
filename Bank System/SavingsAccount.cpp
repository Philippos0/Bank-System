#include "SavingsAccount.h"

SavingsAccount::SavingsAccount(int number, const std::string& holder, double rate, const std::string& password)
    : BankAccount(number, holder, password), interestRate(rate) {}

void SavingsAccount::display() const {
    std::cout << "Savings Account Number: " << accountNumber << ", Holder: " << accountHolder
        << ", Balance: " << balance << ", Interest Rate: " << interestRate << std::endl;
}

void SavingsAccount::applyInterest() {
    double interest = balance * (interestRate / 100);
    deposit(interest);
}
