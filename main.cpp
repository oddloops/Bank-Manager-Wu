#include "BankCsv.h"

int main() {
    std::string accountExist;
    BankCsv bank;
    do {
        std::cout << "Existing member? (yes/no): ";
        std::cin >> accountExist;
    } while (accountExist != "yes" &&  accountExist != "no");

    // Account exists
    if (accountExist == "yes") {
        int option;
        std::cout << "Welcome back" << std::endl;
        do {
            std::cout << "(1) Deposit" << std::endl;
            std::cout << "(2) Withdraw" << std::endl;
            std::cout << "(3) Information" << std::endl;
            std::cout << "(4) Exit" << std::endl;
            std::cout << "Option: ";
            std::cin >> option;
        } while (option < 1 || option > 4);
        switch(option) {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        }
    } else {
        Account newAccount("New", 1234, 10);
        std::cout << newAccount.getPin() << std::endl;
        bank.addToBank(newAccount);
    }
    return 0;
}
