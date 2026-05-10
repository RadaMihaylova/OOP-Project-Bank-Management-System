#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H

#include "Account.h"

class CheckingAccount : public Account {
private:
    double overdraftLimit;
    double transactionFee;
public:
    CheckingAccount(int id, std::string name, double bal, double limit, double fee);
    void withdraw(double amount) override;
    void display() const override;
};

#endif
