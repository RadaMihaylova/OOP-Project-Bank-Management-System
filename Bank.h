#ifndef BANK_H
#define BANK_H

#include <vector>
#include "Account.h"

class Bank {
private:
    std::vector<Account*> accounts;
public:
    ~Bank();
    void addAccount(Account* acc);
    void removeAccount(int id);
    Account* findAccount(int id);
    void transfer(int fromId, int toId, double amount);
    void applyInterestToAll();
    void showStatistics() const;
};

#endif
