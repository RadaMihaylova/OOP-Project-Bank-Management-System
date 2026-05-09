#include "SavingsAccount.h"
#include <iostream>

SavingsAccount::SavingsAccount(int id, std::string name, double bal, double rate) 
    : Account(id, name, bal), interestRate(rate) {}

void SavingsAccount::calculateInterest() {
    double interest = balance * (interestRate / 100);
    balance += interest;
    addTransaction("Interest Applied", interest);
}

void SavingsAccount::withdraw(double amount) {
    if (!isActive) { std::cout << "Error: Account is frozen!" << std::endl; return; }
    if (amount > 0 && balance >= amount) {
        balance -= amount;
        addTransaction("Withdrawal", amount);
        std::cout << "Withdrawal successful." << std::endl;
    } else {
        std::cout << "Error: Insufficient funds." << std::endl;
    }
}

void SavingsAccount::display() const {
    std::cout << "[Savings] ";
    Account::display();
}
