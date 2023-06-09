#ifndef BANKCSV_H
#define BANKCSV_H

#include <fstream>
#include <string>
#include "Account.h"

class BankCsv {
private:
    std::string filename = "bank.csv";

public:
    bool fileExists(std::string name) {
        std::ifstream file(filename);
        return file.is_open();
    }

    void addToBank(Account client) {
    
    }
};

#endif
