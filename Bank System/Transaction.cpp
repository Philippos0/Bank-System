#include "Transaction.h"
#include <iostream>

Transaction::Transaction(const std::string& type, double amount)
    : type(type), amount(amount) {}

void Transaction::display() const {
    std::cout << "Transaction: " << type << ", Amount: " << amount << std::endl;
}