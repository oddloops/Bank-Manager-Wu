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
        std::cout << "Welcome back" << std::endl;
    } else {
        Account newAccount("New", 1234, 10);
        newAccount.getPin();
    }
    std::cout << bank.fileExists("bank.csv") << std::endl;
    return 0;
}
