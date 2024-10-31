#include "CheckingAccount.h"

CheckingAccount::CheckingAccount(int number, const std::string& holder, double limit, const std::string& password)
    : BankAccount(number, holder, password), overdraftLimit(limit) {}

void CheckingAccount::display() const {
    std::cout << "Checking Account Number: " << accountNumber << ", Holder: " << accountHolder
        << ", Balance: " << balance << ", Overdraft Limit: " << overdraftLimit << std::endl;
}
