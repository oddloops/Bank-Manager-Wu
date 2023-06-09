#ifndef BANKCSV_H
#define BANKCSV_H

#include <fstream>
#include <string>
#include "Account.h"

class BankCsv {
private:
    std::string bank = "bank.csv";

public:
    void addToBank(Account& client) {
        // file pointer
        std::fstream fout;

        // opens an existing csv file or creates a new file.
        fout.open(bank, std::ios::out | std::ios::app);

         // Insert the data to file
        fout << "name,pin\n";
        
    }
};

#endif
