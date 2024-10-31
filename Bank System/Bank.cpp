#include "Bank.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"
#include "FixedDepositAccount.h"

void Bank::createAccount() {
    int number;
    std::string holder;
    bool isSavings;
    double rate;
    int lockPeriod;
    std::string password;

    std::cout << "Enter account number: ";
    std::cin >> number;
    std::cout << "Enter account holder's name: ";
    std::cin.ignore();
    std::getline(std::cin, holder);
    std::cout << "Enter password for account: ";
    std::cin >> password; // Password input
    std::cout << "Is it a savings account? (1: Yes, 0: No): ";
    std::cin >> isSavings;

    if (isSavings) {
        std::cout << "Enter interest rate: ";
        std::cin >> rate;
        accounts.push_back(std::make_shared<SavingsAccount>(number, holder, rate, password)); // Pass password
    }
    else {
        std::cout << "Is it a fixed deposit account? (1: Yes, 0: No): ";
        std::cin >> isSavings;
        if (isSavings) {
            std::cout << "Enter interest rate: ";
            std::cin >> rate;
            std::cout << "Enter lock period (in months): ";
            std::cin >> lockPeriod;
            accounts.push_back(std::make_shared<FixedDepositAccount>(number, holder, rate, lockPeriod, password)); // Pass password
        }
        else {
            double limit;
            std::cout << "Enter overdraft limit: ";
            std::cin >> limit;
            accounts.push_back(std::make_shared<CheckingAccount>(number, holder, limit, password)); // Pass password
        }
    }

    std::cout << "Account created successfully!" << std::endl;
}

void Bank::deposit()
{
}

void Bank::withdraw()
{
}

// ... Other methods remain the same ...

void Bank::transfer() {
    int fromAccountNumber, toAccountNumber;
    double amount;

    std::cout << "Enter source account number: ";
    std::cin >> fromAccountNumber;
    std::cout << "Enter destination account number: ";
    std::cin >> toAccountNumber;
    std::cout << "Enter amount to transfer: ";
    std::cin >> amount;

    auto fromAccount = std::find_if(accounts.begin(), accounts.end(),
        [&fromAccountNumber](const std::shared_ptr<BankAccount>& account) {
            return account->getAccountNumber() == fromAccountNumber;
        });

    auto toAccount = std::find_if(accounts.begin(), accounts.end(),
        [&toAccountNumber](const std::shared_ptr<BankAccount>& account) {
            return account->getAccountNumber() == toAccountNumber;
        });

    if (fromAccount != accounts.end() && toAccount != accounts.end()) {
        (*fromAccount)->withdraw(amount);
        (*toAccount)->deposit(amount);
        std::cout << "Transfer successful!" << std::endl;
    }
    else {
        std::cout << "One or both accounts not found!" << std::endl;
    }
}

void Bank::displayAccounts() const
{
    for (const auto& account : accounts) {
        account->display();
        std::cout << std::endl;
    }
}



void Bank::saveAccountsToFile(const std::string& filename) const
{
    std::ofstream outFile(filename);
    if (!outFile) {
        std::cout << "Error saving accounts to file." << std::endl;
        return;
    }
}

void Bank::loadAccountsFromFile(const std::string& filename)
{
    std::ifstream inFile(filename);
    if (!inFile) {
        std::cout << "Error loading accounts from file." << std::endl;
        return;
    }
}


   

    void Bank::closeAccount() {
    int number;
    std::cout << "Enter account number to close: ";
    std::cin >> number;

    auto it = std::remove_if(accounts.begin(), accounts.end(),
        [&number](const std::shared_ptr<BankAccount>& account) {
            return account->getAccountNumber() == number;
        });

    if (it != accounts.end()) {
        accounts.erase(it, accounts.end());
        std::cout << "Account closed successfully!" << std::endl;
    }
    else {
        std::cout << "Account not found!" << std::endl;
    }
}

void Bank::printTransactionHistory() const {
    for (const auto& account : accounts) {
        std::cout << "Transaction history for account " << account->getAccountNumber() << ":" << std::endl;
        account->printTransactions(); // Assuming printTransactions is implemented in BankAccount
        std::cout << std::endl;
    }
}

void Bank::applyInterest() {
    for (const auto& account : accounts) {
        if (auto savingsAccount = dynamic_cast<SavingsAccount*>(account.get())) {
            savingsAccount->applyInterest();
        }
    }
}

bool Bank::authenticateAccount(int accountNumber, const std::string& password) {
    for (const auto& account : accounts) {
        if (account->getAccountNumber() == accountNumber) {
            return account->checkPassword(password); // Assuming checkPassword is implemented in BankAccount
        }
    }
    return false;
}
