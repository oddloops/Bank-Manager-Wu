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
         fout << client.getName() << "," << client.getPin() << "," << client.getCurrentBalance() << "\n";
    }

    // checks if the accoutn is already in the bank
    Account findAccount(std::string name, std::string pin) {
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
            if (acc[0] == name && acc[1] == pin) {
                return Account(acc[0], acc[1], std::stod(acc[2]));
            }
        }
        return Account("", "", -1.0);
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
        std::cout << "\n";
        switch(option) {
        case 1:
            std::cout << "Amount to deposit: ";
            std::cin >> amount;
            client.deposit(amount);
            break;
        case 2:
            std::cout << "Amount to withdraw: ";
            std::cin >> amount;
            client.withdraw(amount);
            break;
        case 3:
            std::cout << "Name: " << client.getName() << std::endl;
            std::cout << "Pin: " << client.getPin() << std::endl;
            std::cout << "Current Balance: " << client.getCurrentBalance() << std::endl;
            break;
        case 4:
            exit(EXIT_SUCCESS);
            break;
        }
        updateInformation(client);
        std::cout << "\n";
        accountOptions(client);
    }

    void updateInformation(Account& client) {
        std::fstream fin, fout;
        fin.open(bank, std::ios::in);
        fout.open("bankUpdate.csv", std::ios::out);

        std::string line, word;
        std::vector<std::string> row;

        int i;
        while  (!fin.eof()) {
            row.clear();
            getline(fin, line);
            std::stringstream str(line);

            while (getline(str, word, ',')) {
                row.push_back(word);
            }

            int rowSize = row.size();
            if (row[0] == client.getName() && row[1] == client.getPin()) {
                 fout << client.getName() << "," << client.getPin() << "," << client.getCurrentBalance() << "\n";
            }
            else {
                if (!fin.eof()) {
                    for (i = 0; i < rowSize - 1; i++) {
                        fout << row[i] << ",";
                    }
                    fout << row[rowSize - 1] << "\n";
                }
            }
            if (fin.eof()) {
                break;
            }
        }
        fin.close();
        fout.close();
        remove("bank.csv");
        rename("bankUpdate.csv", "bank.csv");
    }
};

#endif
