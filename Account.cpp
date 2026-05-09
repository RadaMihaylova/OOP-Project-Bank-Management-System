#include "Account.h"
#include <iostream>

Account::Account(int id, std::string name, double initialDeposit) 
    : accountID(id), ownerName(name), balance(initialDeposit), isActive(true) {
    addTransaction("Initial Deposit", initialDeposit);
}

Account::~Account() {
    for (Transaction* t : history) {
        delete t;
    }
    history.clear();
}

void Account::addTransaction(std::string type, double amt) {
    history.push_back(new Transaction(type, amt));
}

void Account::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
        addTransaction("Deposit", amount);
        std::cout << "Successfully deposited " << amount << " lv." << std::endl;
    }
}

void Account::setStatus(bool status) { isActive = status; }
bool Account::getStatus() const { return isActive; }
int Account::getID() const { return accountID; }
double Account::getBalance() const { return balance; }
std::string Account::getName() const { return ownerName; }

void Account::display() const {
    std::cout << "ID: " << accountID << " | Owner: " << ownerName 
              << " | Balance: " << balance << " lv. | Status: " 
              << (isActive ? "Active" : "Frozen") << std::endl;
}

void Account::showHistory() const {
    std::cout << "Transaction History for Account #" << accountID << ":" << std::endl;
    if (history.empty()) std::cout << "  No transactions yet." << std::endl;
    for (const auto& t : history) t->display();
}
