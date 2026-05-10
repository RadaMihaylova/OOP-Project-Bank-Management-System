#include <iostream>
#include "Bank.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"

using namespace std;

int main() {
    Bank myBank;
    int choice;

    while (true) {
        cout << "\n--- SYSTEM MENU ---\n1. Open Savings\n2. Open Checking\n3. Deposit\n4. Withdraw\n"
             << "5. Transfer\n6. Apply Interest\n7. History\n8. Stats\n9. Freeze\n10. Close\n0. Exit\nChoice: ";
        cin >> choice;

        if (choice == 0) break;

        int id, id2; string name; double amt;
        switch (choice) {
            case 1:
                cout << "ID, Name, Deposit, Interest: ";
                cin >> id >> name >> amt >> id2;
                myBank.addAccount(new SavingsAccount(id, name, amt, id2));
                break;
            case 2:
                cout << "ID, Name, Deposit, Overdraft, Fee: ";
                double limit, fee;
                cin >> id >> name >> amt >> limit >> fee;
                myBank.addAccount(new CheckingAccount(id, name, amt, limit, fee));
                break;
            case 3:
                cout << "ID & Amount: "; cin >> id >> amt;
                if (Account* acc = myBank.findAccount(id)) acc->deposit(amt);
                break;
            case 4:
                cout << "ID & Amount: "; cin >> id >> amt;
                if (Account* acc = myBank.findAccount(id)) acc->withdraw(amt);
                break;
            case 5:
                cout << "From ID, To ID, Amount: "; cin >> id >> id2 >> amt;
                myBank.transfer(id, id2, amt);
                break;
            case 6: myBank.applyInterestToAll(); break;
            case 7:
                cout << "ID: "; cin >> id;
                if (Account* acc = myBank.findAccount(id)) acc->showHistory();
                break;
            case 8: myBank.showStatistics(); break;
            case 9:
                cout << "ID & Status (1/0): "; cin >> id >> id2;
                if (Account* acc = myBank.findAccount(id)) acc->setStatus(id2);
                break;
            case 10:
                cout << "ID: "; cin >> id;
                myBank.removeAccount(id);
                break;
        }
    }
    return 0;
}
