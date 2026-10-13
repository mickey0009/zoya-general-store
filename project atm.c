#include <stdio.h>
#include <string.h>

#define MAX_TRANSACTIONS 20

struct Account {
    char name[50];
    int accountNumber;
    int pin;
    float balance;
    char transactions[MAX_TRANSACTIONS][100];
    int transactionCount;
};

void addTransaction(struct Account *acc, const char *transaction) {
    if (acc->transactionCount < MAX_TRANSACTIONS) {
        strcpy(acc->transactions[acc->transactionCount], transaction);
        acc->transactionCount++;
    }
}

void checkBalance(struct Account *acc) {
    printf("\nCurrent Balance: Rs. %.2f\n", acc->balance);
}

void withdraw(struct Account *acc) {
    float amount;
    char transaction[100];

    printf("\nEnter amount to withdraw: Rs. ");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Invalid amount.\n");
    } else if (amount > acc->balance) {
        printf("Insufficient balance.\n");
    } else {
        acc->balance -= amount;

        printf("Please collect your cash.\n");
        printf("Withdrawal successful.\n");
        printf("Remaining Balance: Rs. %.2f\n", acc->balance);

        sprintf(transaction, "Withdrawn: Rs. %.2f", amount);
        addTransaction(acc, transaction);
    }
}

void deposit(struct Account *acc) {
    float amount;
    char transaction[100];

    printf("\nEnter amount to deposit: Rs. ");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Invalid amount.\n");
    } else {
        acc->balance += amount;

        printf("Deposit successful.\n");
        printf("Updated Balance: Rs. %.2f\n", acc->balance);

        sprintf(transaction, "Deposited: Rs. %.2f", amount);
        addTransaction(acc, transaction);
    }
}

void transfer(struct Account *acc) {
    int receiverAccount;
    float amount;
    char transaction[100];

    printf("\nEnter receiver account number: ");
    scanf("%d", &receiverAccount);

    printf("Enter amount to transfer: Rs. ");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Invalid amount.\n");
    } else if (amount > acc->balance) {
        printf("Insufficient balance.\n");
    } else {
        acc->balance -= amount;

        printf("Transfer successful.\n");
        printf("Rs. %.2f transferred to account %d.\n",
               amount, receiverAccount);

        sprintf(transaction, "Transferred Rs. %.2f to A/C %d",
                amount, receiverAccount);
        addTransaction(acc, transaction);
    }
}

void changePIN(struct Account *acc) {
    int oldPin, newPin, confirmPin;

    printf("\nEnter current PIN: ");
    scanf("%d", &oldPin);

    if (oldPin != acc->pin) {
        printf("Incorrect PIN.\n");
        return;
    }

    printf("Enter new PIN: ");
    scanf("%d", &newPin);

    printf("Confirm new PIN: ");
    scanf("%d", &confirmPin);

    if (newPin != confirmPin) {
        printf("PINs do not match.\n");
    } else if (newPin < 1000 || newPin > 9999) {
        printf("PIN must contain exactly 4 digits.\n");
    } else {
        acc->pin = newPin;
        printf("PIN changed successfully.\n");
    }
}

void miniStatement(struct Account *acc) {
    int i;

    printf("\n========== MINI STATEMENT ==========\n");
    printf("Account Holder : %s\n", acc->name);
    printf("Account Number : %d\n", acc->accountNumber);
    printf("------------------------------------\n");

    if (acc->transactionCount == 0) {
        printf("No transactions available.\n");
    } else {
        for (i = 0; i < acc->transactionCount; i++) {
            printf("%d. %s\n", i + 1, acc->transactions[i]);
        }
    }

    printf("------------------------------------\n");
    printf("Balance: Rs. %.2f\n", acc->balance);
    printf("====================================\n");
}

int main() {
    struct Account account = {
        "Rahul Sharma",
        123456789,
        1234,
        10000.00,
        {0},
        0
    };

    int enteredPIN;
    int choice;
    int attempts = 0;

    printf("====================================\n");
    printf("       ATM BANKING SYSTEM\n");
    printf("====================================\n");

    /* PIN verification */
    while (attempts < 3) {
        printf("\nEnter your 4-digit PIN: ");
        scanf("%d", &enteredPIN);

        if (enteredPIN == account.pin) {
            printf("\nLogin successful. Welcome, %s!\n",
                   account.name);
            break;
        } else {
            attempts++;
            printf("Incorrect PIN. Attempts remaining: %d\n",
                   3 - attempts);
        }
    }

    if (attempts == 3) {
        printf("\nToo many incorrect attempts.\n");
        printf("Your account has been temporarily blocked.\n");
        return 0;
    }

    /* Main ATM menu */
    do {
        printf("\n========== ATM MENU ==========\n");
        printf("1. Balance Inquiry\n");
        printf("2. Cash Withdrawal\n");
        printf("3. Cash Deposit\n");
        printf("4. Money Transfer\n");
        printf("5. Change PIN\n");
        printf("6. Mini Statement\n");
        printf("7. Exit\n");
        printf("==============================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                checkBalance(&account);
                break;

            case 2:
                withdraw(&account);
                break;

            case 3:
                deposit(&account);
                break;

            case 4:
                transfer(&account);
                break;

            case 5:
                changePIN(&account);
                break;

            case 6:
                miniStatement(&account);
                break;

            case 7:
                printf("\nThank you for using our ATM.\n");
                printf("Have a nice day!\n");
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
        }

    } while (choice != 7);

    return 0;
}

