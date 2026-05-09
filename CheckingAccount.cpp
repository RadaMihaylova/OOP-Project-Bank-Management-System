#include "CheckingAccount.h"
#include <iostream>

CheckingAccount::CheckingAccount(int id, std::string name, double bal, double limit, double fee) 
    : Account(id, name, bal), overdraftLimit(limit), transactionFee(fee) {}

void CheckingAccount::withdraw(double amount) {
    if (!isActive) { std::cout << "Error: Account is frozen!" << std::endl; return; }
    double totalToDeduct = amount + transactionFee;
    if (amount > 0 && (balance + overdraftLimit) >= totalToDeduct) {
        balance -= totalToDeduct;
        addTransaction("Withdrawal (Fee incl.)", totalToDeduct);
        std::cout << "Withdrawal successful (Fee: " << transactionFee << " lv.)." << std::endl;
    } else {
        std::cout << "Error: Overdraft limit exceeded." << std::endl;
    }
}

void CheckingAccount::display() const {
    std::cout << "[Checking] ";
    Account::display();
}
