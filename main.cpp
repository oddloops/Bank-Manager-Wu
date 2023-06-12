#include "BankCsv.h"

int main() {
    std::string accountExist;
    BankCsv bank;
    std::string name, pin;
    double initialBalance;
    do {
        std::cout << "Existing member? (yes/no): ";
        std::cin >> accountExist;
    } while (accountExist != "yes" &&  accountExist != "no");

    // Account exists
    if (accountExist == "yes") {
        std::cout << "Enter username: ";
        std::cin >> name;
        std::cout << "Enter pin: ";
        std::cin >> pin;
        Account acc = bank.findAccount(name, pin);
        if (acc.getName() != "") {
            bank.accountOptions(acc);
        }
        else {
            std::cout << "No such account" << std::endl;
        }
    } else {
        std::cout << "Enter username: ";
        std::cin >> name;
        std::cout << "Enter pin: ";
        std::cin >> pin;
        std::cout << "Enter initial balance: ";
        std::cin >> initialBalance;
        Account accCheck = bank.findAccount(name, pin);
        if ((name == accCheck.getName() && pin == accCheck.getPin()) || initialBalance < 0) {
            std::cout << "Error making account" << std::endl;
        }
        else {
            Account newAcc(name, pin, initialBalance);
            bank.addToBank(newAcc);
        }
    }
    return 0;
}
