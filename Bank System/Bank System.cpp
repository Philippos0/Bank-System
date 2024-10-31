#include "Bank.h"

int main() {
    Bank bank;
    bank.loadAccountsFromFile("accounts.txt");

    while (true) {
        std::cout << "======================" << std::endl;
        std::cout << "      Bank Menu       " << std::endl;
        std::cout << "======================" << std::endl
            << "1. Create Account\n"
            << "2. Deposit\n"
            << "3. Withdraw\n"
            << "4. Transfer\n"
            << "5. Display Accounts\n"
            << "6. Close Account\n"
            << "7. Print Transaction History\n"
            << "8. Apply Interest\n"
            << "9. Save Accounts to File\n"
            << "0. Exit\n"
            << "Choose an option: ";
        int choice;
        std::cin >> choice;

        switch (choice) {
        case 1: bank.createAccount(); break;
        case 2: bank.deposit(); break;
        case 3: bank.withdraw(); break;
        case 4: bank.transfer(); break;
        case 5: bank.displayAccounts(); break;
        case 6: bank.closeAccount(); break;
        case 7: bank.printTransactionHistory(); break;
        case 8: bank.applyInterest(); break;
        case 9: bank.saveAccountsToFile("accounts.txt"); break;
        case 0: return 0;
        default: std::cout << "Invalid choice, try again." << std::endl; break;
        }
    }

    return 0;
}
