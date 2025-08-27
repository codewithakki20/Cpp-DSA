#include <iostream>
using namespace std;

class BankAccount {
private:
    int accountNumber;
    double balance;

public:
    BankAccount(int accNum, double bal) {
        accountNumber = accNum;
        balance = bal;
    }

    void deposit(double amount) {
        balance += amount;
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
        } else {
            cout << "No sufficient balance for this withdrawal.\n";
        }
    }

    double getBalance() {
        return balance;
    }
};

int main() {
    BankAccount myAccount(123456789, 500.00);
    myAccount.deposit(150.0);
    myAccount.withdraw(100.0);
    cout << "Current Balance: Rs. " << myAccount.getBalance() << endl;
    return 0;
}
