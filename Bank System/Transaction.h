#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

class Transaction {
private:
    std::string type; // "Deposit" or "Withdrawal"
    double amount;

public:
    Transaction(const std::string& type, double amount);
    void display() const;
};

#endif // TRANSACTION_H
