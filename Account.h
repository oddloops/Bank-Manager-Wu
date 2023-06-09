#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>

class Account {
private:
    std::string name;
    int pin;
    double amount;
public:
    Account (std::string username, int pinNumber, double initialAmount) {
        name = username;
        pin = pinNumber;
        amount = initialAmount;
    }

    void getName() {
        std::cout << name << std::endl;
    }

    void getPin() {
        std::cout << pin << std::endl;
    }

    void getCurrentAmount() {
        std::cout << amount << std::endl;
    }

    void deposit(double depositAmount) {
        amount += depositAmount;
    }

    void withdraw(double withdrawAmount) {
        if (amount - withdrawAmount >= 0) {
            std::cout << "Current: " << amount << std::endl;
            amount -= withdrawAmount;
            std::cout << "After: " << amount << std::endl;
        } else {
            std::cout << "Cannot withdraw ammount!" << std::endl;
        }
    }
};

#endif
