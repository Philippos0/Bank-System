#include "FixedDepositAccount.h"

FixedDepositAccount::FixedDepositAccount(int number, const std::string& holder, double rate, int period, const std::string& password)
    : BankAccount(number, holder, password), interestRate(rate), lockPeriod(period) {}

void FixedDepositAccount::display() const {
    std::cout << "Fixed Deposit Account Number: " << accountNumber << ", Holder: " << accountHolder
        << ", Balance: " << balance << ", Interest Rate: " << interestRate
        << ", Lock Period: " << lockPeriod << " months" << std::endl;
}
