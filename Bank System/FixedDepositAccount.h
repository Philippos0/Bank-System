#ifndef FIXEDDEPOSITACCOUNT_H
#define FIXEDDEPOSITACCOUNT_H

#include "BankAccount.h"

class FixedDepositAccount : public BankAccount {
private:
    double interestRate;
    int lockPeriod;

public:
    FixedDepositAccount(int number, const std::string& holder, double rate, int period, const std::string& password);
    void display() const override;
};

#endif // FIXEDDEPOSITACCOUNT_H
