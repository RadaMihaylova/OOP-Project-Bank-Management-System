#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include "Account.h"

class SavingsAccount : public Account {
private:
    double interestRate;
public:
    SavingsAccount(int id, std::string name, double bal, double rate);
    void calculateInterest();
    void withdraw(double amount) override;
    void display() const override;
};

#endif
