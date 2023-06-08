#include <iostream>
#include <string>
using namespace std;

class Account {
private:
    string name;
    int pin;
    double amount;
public:
    Account (string username, int pinNumber, double initialAmount) {
        name = username;
        pin = pinNumber;
        amount = initialAmount;
    }

    void getName() {
        cout << name << endl;
    }

    void getPin() {
        cout << pin << endl;
    }

    void getCurrentAmount() {
        cout << amount << endl;
    }

    void deposit(double depositAmount) {
        amount += depositAmount;
    }

    void withdraw(double withdrawAmount) {
        if (amount - withdrawAmount >= 0) {
            cout << "Current: " << amount << endl;
            amount -= withdrawAmount;
            cout << "After: " << amount << endl;
        } else {
            cout << "Cannot withdraw ammount!" << endl;
        }
    }
};
