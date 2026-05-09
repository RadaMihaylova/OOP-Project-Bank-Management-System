#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <vector>
#include "Transaction.h"

class Account {
protected:
    int accountID;
    std::string ownerName;
    double balance;
    bool isActive;
    std::vector<Transaction*> history;

public:
    Account(int id, std::string name, double initialDeposit);
    virtual ~Account(); // Виртуален деструктор

    void addTransaction(std::string type, double amt);
    void deposit(double amount);
    virtual void withdraw(double amount) = 0; // Чисто виртуална

    void setStatus(bool status);
    bool getStatus() const;
    int getID() const;
    double getBalance() const;
    std::string getName() const;

    virtual void display() const;
    void showHistory() const;
};

#endif
