#include <iostream>
#include <string>
#include "Account.h"
using namespace std;

int main() {
    string accountExist;
    do {
        cout << "Existing member? (yes/no): ";
        cin >> accountExist;
    } while (accountExist != "yes" &&  accountExist != "no");

    // Account exists
    if (accountExist == "yes") {
        cout << "Welcome back" << endl;
    } else {
        Account newAccount("New", 1234, 10);
        newAccount.getPin();
    }
    return 0;
}
