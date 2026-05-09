#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <iostream>
#include <iomanip>

class Transaction {
private:
    std::string type;
    double amount;

public:
    Transaction(std::string t, double amt) : type(t), amount(amt) {}
    void display() const {
        std::cout << "  - [" << type << "]: " << std::fixed << std::setprecision(2) << amount << " lv." << std::endl;
    }
};

<<<<<<< HEAD
#endif
=======
#endif
>>>>>>> c985e5434af46c4f22b02a45d54cbea26bd0504d
