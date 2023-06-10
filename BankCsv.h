#ifndef BANKCSV_H
#define BANKCSV_H

#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "Account.h"

class BankCsv {
private:
    std::string bank = "bank.csv";

public:
    // add an account's information to the bank
    void addToBank(Account& client) {
        // file pointer
        std::fstream fout;

        // opens an existing csv file or creates a new file.
        fout.open(bank, std::ios::out | std::ios::app);

         // Insert the account data into the bank if it's not already in
        if (!findAccount(client)) {
            fout << client.getName() << "," << client.getPin() << "," << client.getCurrentBalance() << "\n";
        } else {
            std::cout << "Account already exist!" << std::endl;
        }
    }

    // checks if the accoutn is already in the bank
    bool findAccount(Account& client) {
        std::fstream accounts;
        accounts.open(bank, std::ios::in);
        std::vector<std::string> acc;
        std::string line, info;
        while (getline(accounts, line)) {
            std::stringstream str(line);
            std::vector<std::string> acc;
            while (std::getline(str, info, ',')) {
                acc.push_back(info);
            }
            if (acc[0] == client.getName() && stoi(acc[1]) == client.getPin()) {
                return true;
            }
        }
        return false;
    }

    void accountOptions(Account& client) {
        int option, amount;
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
            std::cout << "Amount to deposit: ";
            std::cin >> amount;
            client.deposit(amount);
            break;
        case 2:
            std::cout << "Amount to withdraw: ";
            std::cin >> amount;
            client.deposit(amount);
            break;
        case 3:
            std::cout << "Name: " << client.getName() << std::endl;
            std::cout << "Pin: " << client.getPin() << std::endl;
            std::cout << "Current Balance: " << client.getCurrentBalance() << std::endl;
            break;
        case 4:
            break;
        }
    }
};

#endif
