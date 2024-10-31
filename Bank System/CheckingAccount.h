#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H

#include "BankAccount.h"

class CheckingAccount : public BankAccount {
private:
    double overdraftLimit;

public:
    CheckingAccount(int number, const std::string& holder, double limit, const std::string& password);
    void display() const override;
};

#endif // CHECKINGACCOUNT_H
