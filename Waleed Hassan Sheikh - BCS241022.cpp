#include <iostream>
#include <string>
using namespace std;
class BankAccount {
private:
    static int totalAccounts;
    int accountNumber;
    string accountHolder;
    double balance;
public:
    BankAccount(string holderName) {
        accountHolder = holderName;
        balance = 0.0;
        accountNumber = ++totalAccounts;
    }
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: $" << amount << endl;
        }
        else {
            cout << "Invalid deposit amount." << endl;
        }
    }
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: $" << amount << endl;
        }
        else {
            cout << "Insufficient funds or invalid amount." << endl;
        }
    }
    double checkBalance() const {
        return balance;
    }
    int getAccountNumber() const {
        return accountNumber;
    }
    int getTotalAccounts() {
        return totalAccounts;
    }
};
int BankAccount::totalAccounts = 0;
void displayMenu() {
    cout << "\nBank Management System Menu:\n";
    cout << "1. Create Account\n";
    cout << "2. Deposit\n";
    cout << "3. Withdraw\n";
    cout << "4. Check Balance\n";
    cout << "5. Total Accounts\n";
    cout << "6. Exit\n";
}
int main() {
    BankAccount account1("Alice");
    BankAccount account2("Bob");
    BankAccount account3("Charlie");
    int choice;
    while (true) {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1: {
            string holderName;
            cout << "Enter account holder's name: ";
            cin.ignore();
            getline(cin, holderName);
            BankAccount newAccount(holderName);
            cout << "Account created successfully. Account Number: " << newAccount.getAccountNumber() << endl;
            break;
        }
        case 2: {
            double amount;
            cout << "Enter amount to deposit for Alice (Account 1): ";
            cin >> amount;
            account1.deposit(amount);
            break;
        }
        case 3: {
            double amount;
            cout << "Enter amount to withdraw for Alice (Account 1): ";
            cin >> amount;
            account1.withdraw(amount);
            break;
        }
        case 4: {
            cout << "Alice's current balance: $" << account1.checkBalance() << endl;
            break;
        }
        case 5: {
            cout << "Total accounts created: " << account1.getTotalAccounts() << endl;
            break;
        }
        case 6: {
            cout << "Exiting the system." << endl;
            return 0;
        }
        default: {
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
        }
    }
}