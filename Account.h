#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>

class Account {
private:
    std::string name, pin;
    double balance;
public:
    Account (std::string username, std::string pinNumber, double initialBalance) {
        name = username;
        pin = pinNumber;
        balance = initialBalance;
    }

    std::string getName() {
        return name;
    }

    std::string getPin() {
        return pin;
    }

    double getCurrentBalance() {
        return balance;
    }

    void deposit(double depositAmount) {
        std::cout << "Current: " << balance << std::endl;
        balance += depositAmount;
        std::cout << "After: " << balance << std::endl; 
    }

    void withdraw(double withdrawAmount) {
        if (balance - withdrawAmount >= 0) {
            std::cout << "Current: " << balance << std::endl;
            balance -= withdrawAmount;
            std::cout << "After: " << balance << std::endl;
        } else {
            std::cout << "Cannot withdraw ammount!" << std::endl;
        }
    }
};

#endif
