#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include "BankAccount.h"

class SavingsAccount : public BankAccount {
private:
    double interestRate;

public:
    SavingsAccount(int number, const std::string& holder, double rate, const std::string& password);
    void display() const override;
    void applyInterest();
};

#endif // SAVINGSACCOUNT_H
