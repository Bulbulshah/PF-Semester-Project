#include <iostream>
#include <limits>
using namespace std;

int main() {
    int option, pin, account_option, amount, deposit, withdraw;
    int balance = 1000; // Default balance
    bool exit_program = false;

    // PIN for security
    const int correct_pin = 1234;
    bool pin_verified = false;

    // Program loop
    while (!exit_program) {
        // Verify PIN
        while (!pin_verified) {
            cout << "\nWelcome to the ATM and Bank Management System\n";
            cout << "Enter your 4-digit PIN: ";
            cin >> pin;

            if (pin == correct_pin) {
                cout << "PIN Verified! Access Granted.\n";
                pin_verified = true;
            } else {
                cout << "Incorrect PIN. Try again!\n";
                continue; // Retry entering the PIN
            }
        }

        // Main Menu
        cout << "\n--- Main Menu ---\n";
        cout << "1. ATM Services\n";
        cout << "2. Bank Management Services\n";
        cout << "3. Exit\n";
        cout << "Enter your option: ";
        cin >> option;

        switch (option) {
            case 1: { // ATM Services
                bool exit_atm = false;
                while (!exit_atm) {
                    cout << "\n--- ATM Services ---\n";
                    cout << "1. Check Balance\n";
                    cout << "2. Deposit Money\n";
                    cout << "3. Withdraw Money\n";
                    cout << "4. Return to Main Menu\n";
                    cout << "Enter your choice: ";
                    cin >> account_option;

                    switch (account_option) {
                        case 1: // Check Balance
                            cout << "Your Current Balance is: $" << balance << "\n";
                            break;

                        case 2: { // Deposit Money
                            cout << "Enter the amount to deposit: ";
                            cin >> deposit;

                            if (deposit > 0) {
                                balance += deposit;
                                cout << "Deposit Successful. New Balance: $" << balance << "\n";
                            } else {
                                cout << "Invalid Amount. Deposit Failed!\n";
                            }
                            break;
                        }

                        case 3: { // Withdraw Money
                            cout << "Enter the amount to withdraw: ";
                            cin >> withdraw;

                            if (withdraw > balance) {
                                cout << "Insufficient Balance!\n";
                            } else if (withdraw <= 0) {
                                cout << "Invalid Amount. Withdraw Failed!\n";
                            } else {
                                balance -= withdraw;
                                cout << "Withdrawal Successful. Remaining Balance: $" << balance << "\n";
                            }
                            break;
                        }

                        case 4: // Return to Main Menu
                            exit_atm = true;
                            break;

                        default:
                            cout << "Invalid Option. Try Again!\n";
                            break;
                    }
                }
                break;
            }

            case 2: { // Bank Management Services
                bool exit_bank = false;
                while (!exit_bank) {
                    cout << "\n--- Bank Management Services ---\n";
                    cout << "1. View Account Details\n";
                    cout << "2. Update Account PIN\n";
                    cout << "3. Return to Main Menu\n";
                    cout << "Enter your choice: ";
                    cin >> account_option;

                    switch (account_option) {
                        case 1: { // View Account Details
                            cout << "\n--- Account Details ---\n";
                            cout << "Account Holder: Bulbul shah \n";
                            cout << "Account Number: 123456789\n";
                            cout << "Account Balance: $" << balance << "\n";
                            break;
                        }

                        case 2: { // Update PIN
                            int old_pin, new_pin;
                            cout << "Enter Old PIN: ";
                            cin >> old_pin;

                            if (old_pin == correct_pin) {
                                cout << "Enter New PIN: ";
                                cin >> new_pin;

                                if (new_pin >= 1000 && new_pin <= 9999) {
                                    cout << "PIN Updated Successfully!\n";
                                    pin_verified = false; // Reset PIN verification
                                    exit_bank = true; // Return to main menu
                                } else {
                                    cout << "Invalid PIN. Must be 4 digits.\n";
                                }
                            } else {
                                cout << "Incorrect Old PIN!\n";
                            }
                            break;
                        }

                        case 3: // Return to Main Menu
                            exit_bank = true;
                            break;

                        default:
                            cout << "Invalid Option. Try Again!\n";
                            break;
                    }
                }
                break;
            }

            case 3: // Exit
                cout << "Thank you for using the system. Goodbye!\n";
                exit_program = true;
                break;

            default:
                cout << "Invalid Option. Please try again!\n";
                break;
        }
    }

    return 0;
}
