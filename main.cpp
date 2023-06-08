#include <iostream>
#include "Account.h"
using namespace std;

int main() {
    Account newAccount("New", 1234, 10);
    newAccount.getPin();
    return 0;
}
