#include <stdio.h>
#include <stdlib.h>

// Customer structure
typedef struct customer {
    char name[50];
    int account_number;
    float balance;
} Customer;

// Function prototypes
void create_account(Customer *customer);
void deposit(Customer *customer);
void withdraw(Customer *customer);
void view_balance(Customer *customer);

int main() {
    // Declare customer variable
    Customer customer;
    int choice;

    // Infinite loop until user exits
    while (1) {
        printf("\nBank Management System\n");
        printf("1. Create account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. View balance\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create_account(&customer);
                break;
            case 2:
                deposit(&customer);
                break;
            case 3:
                withdraw(&customer);
                break;
            case 4:
                view_balance(&customer);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

// Function to create account
void create_account(Customer *customer) {
    printf("\nEnter your name: ");
    scanf("%s", customer->name);
    printf("Enter account number: ");
    scanf("%d", &customer->account_number);
    printf("Enter initial balance: ");
    scanf("%f", &customer->balance);
    printf("Account created successfully!\n");
}

// Function to deposit money
void deposit(Customer *customer) {
    float amount;
    printf("\nEnter amount to deposit: ");
    scanf("%f", &amount);
    customer->balance += amount;
    printf("Deposit successful!\n");
}

// Function to withdraw money
void withdraw(Customer *customer) {
    float amount;
    printf("\nEnter amount to withdraw: ");
    scanf("%f", &amount);
    if (amount > customer->balance) {
        printf("Insufficient balance!\n");
    } else {
        customer->balance -= amount;
        printf("Withdrawal successful!\n");
    }
}

// Function to view balance
void view_balance(Customer *customer) {
    printf("\nName: %s\n", customer->name);
    printf("Account number: %d\n", customer->account_number);
    printf("Balance: %.2f\n", customer->balance);
}