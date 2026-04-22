//Bank Simulation code








#include <stdio.h>

struct account {
    int acc_num;
    char name[25];
    float balance;
    int pin;
};
int main() {
    struct account acc;
    int choice;
    float amount;
    float total_deposit = 0;
    float total_withdraw = 0;
    float last_transaction = 0;
    int last_type = 0; 
    int entered_pin;
    /*create account */
    printf("Enter your account number (3 digits): ");
    scanf("%d", &acc.acc_num);

    if (acc.acc_num < 100 || acc.acc_num > 999) {
        printf("Invalid account number.\n");
        return 0;
    }

    printf("Enter your name: ");
    scanf("%s", acc.name);

    printf("Set a 4-digit PIN: ");
    scanf("%d", &acc.pin);

    printf("Enter initial balance: ");
    scanf("%f", &acc.balance);

    /* choices */
    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Display Account Details\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Transaction History\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("\n---Account Details---\n");
                printf("Account Number : %d\n", acc.acc_num);
                printf("Name           : %s\n", acc.name);
                printf("Balance        : %.2f\n", acc.balance);
                break;

            case 2:
                printf("Enter amount to deposit: ");
                scanf("%f", &amount);

                if (amount > 0) {
                    acc.balance += amount;
                    total_deposit += amount;
                    last_transaction = amount;
                    last_type = 1;
                    printf("Deposit successful!\n");
                } else {
                    printf("Invalid amount.\n");
                }
                break;

            case 3:
                printf("Enter PIN: ");
                scanf("%d", &entered_pin);

                if (entered_pin != acc.pin) {
                    printf("Incorrect PIN.\n");
                    break;
                }

                printf("Enter amount to withdraw: ");
                scanf("%f", &amount);

                if (amount > 0 && amount <= acc.balance) {
                    acc.balance -= amount;
                    total_withdraw += amount;
                    last_transaction = amount;
                    last_type = 2;
                    printf("Withdrawal successful!\n");
                } else {
                    printf("Insufficient balance or invalid amount.\n");
                }
                break;

            case 4:
                printf("Enter PIN: ");
                scanf("%d", &entered_pin);

                if (entered_pin != acc.pin) {
                    printf("Incorrect PIN.\n");
                    break;
                }

                printf("\n---Transaction History---\n");
                printf("Total Deposited : %.2f\n", total_deposit);
                printf("Total Withdrawn : %.2f\n", total_withdraw);

                if (last_type == 1)
                    printf("Last Transaction: Deposited %.2f\n", last_transaction);
                else if (last_type == 2)
                    printf("Last Transaction: Withdrawn %.2f\n", last_transaction);
                else
                    printf("No transactions yet.\n");

                break;

            case 5:
                printf("Thank you!\n");
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }
}