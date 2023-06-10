#include "BankCsv.h"

int main() {
    std::string accountExist;
    BankCsv bank;
    Account test("test", 9876, 100);
    do {
        std::cout << "Existing member? (yes/no): ";
        std::cin >> accountExist;
    } while (accountExist != "yes" &&  accountExist != "no");

    // Account exists
    if (accountExist == "yes") {
        bank.accountOptions(test);
    } else {
        bank.addToBank(test);
    }
    return 0;
}
