#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string accountHolder;
   long int accountNumber;
    double balance;
    double miniStatement[10];
    int statementIndex;

public:
    BankAccount(const string, double initialDeposit) {
        accountHolder = "SAHIL BAGAT";
        accountNumber = 7499181876;
        balance = initialDeposit;
        statementIndex = 0;
        miniStatement[statementIndex++] = initialDeposit;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            miniStatement[statementIndex++] = amount;
            cout << amount <<" rupees deposited successfully " << endl;
            if (statementIndex >= 10) statementIndex = 9;
        } else {
            cout << "Deposit amount must be positive." << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            miniStatement[statementIndex++] = -amount;
            cout << amount <<" rupees withdrawn successfully " << endl;
            if (statementIndex >= 10) statementIndex = 9;
        } else if (amount > balance) {
            cout << "Insufficient balance." << endl;
        } else {
            cout << "Invalid withdrawal amount." << endl;
        }
    }

    void printMiniStatement() {
        cout << "\nMini Statement for Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Balance: " << balance << endl;
        cout << "\nTransaction History:" << endl;
    
        for (int i = 0; i < statementIndex; ++i) {
            if (miniStatement[i] > 0) {
                cout << "Deposited: " << miniStatement[i] << endl;
            } else {
                cout << "Withdrawn: " << -miniStatement[i] << endl;
            }
        }
        cout << "left Balance: " << balance << endl;
    }

    void showAccountDetails() {
        cout << "\nAccount Details:" << endl;
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }
};

int main() {
    string accNo;
    double initialDeposit;
    int choice;
    cout << "Enter Initial Deposit: ";
    cin >> initialDeposit;

    BankAccount account(accNo, initialDeposit);

    do {
        cout << "\n * Bank Mini Statement Menu *" << endl;
        cout << "1. View Account Details" << endl;
        cout << "2. Deposit Money" << endl;
        cout << "3. Withdraw Money" << endl;
        cout << "4. View Mini Statement" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                account.showAccountDetails();
                break;
            case 2:
                {
                    double depositAmount;
                    cout << "Enter Deposit Amount: ";
                    cin >> depositAmount;
                    account.deposit(depositAmount);
                }
                break;
            case 3:
                {
                    double withdrawAmount;
                    cout << "Enter Withdrawal Amount: ";
                    cin >> withdrawAmount;
                    account.withdraw(withdrawAmount);
                }
                break;
            case 4:
                account.printMiniStatement();
                break;
            case 5:
                cout << "Thank you !" << endl;
                break;
            default:
                cout << "Invalid choice Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
