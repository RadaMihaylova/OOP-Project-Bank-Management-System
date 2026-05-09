#include "Bank.h"
#include "SavingsAccount.h"
#include <iostream>

Bank::~Bank() {
    for (Account* acc : accounts) {
        delete acc;
    }
    accounts.clear();
}

void Bank::addAccount(Account* acc) {
    accounts.push_back(acc);
    std::cout << "Account created." << std::endl;
}

void Bank::removeAccount(int id) {
    for (auto it = accounts.begin(); it != accounts.end(); ++it) {
        if ((*it)->getID() == id) {
            delete *it;
            accounts.erase(it);
            std::cout << "Account closed." << std::endl;
            return;
        }
    }
}

Account* Bank::findAccount(int id) {
    for (Account* acc : accounts) {
        if (acc->getID() == id) return acc;
    }
    return nullptr;
}

void Bank::transfer(int fromId, int toId, double amount) {
    Account* from = findAccount(fromId);
    Account* to = findAccount(toId);
    if (from && to && from->getStatus()) {
        double oldBal = from->getBalance();
        from->withdraw(amount);
        if (from->getBalance() < oldBal) to->deposit(amount);
    }
}

void Bank::applyInterestToAll() {
    for (Account* acc : accounts) {
        SavingsAccount* sa = dynamic_cast<SavingsAccount*>(acc);
        if (sa) sa->calculateInterest();
    }
}

void Bank::showStatistics() const {
    double total = 0;
    for (Account* acc : accounts) {
        acc->display();
        total += acc->getBalance();
    }
    std::cout << "Total Capital: " << total << " lv." << std::endl;
}
