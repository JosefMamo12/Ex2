#include <stdio.h>
#include <stdbool.h>
#include <myBank.h>

int main()
{
    bool flag = false;
    double amount, operate, interest;
    int clientCounter = 0, bexit = 0, bank_account;
    char ta;
    init();
    do
    {
        printf("Welcome to Mamo-Josef Bank/n");
        printf("Please choose transaction type /n  O-Open Account /n  B-Balance Inquiry/n D-Deposit/n W-Withdrawal /n C-Close Account /n  I-Interest /n P-Print /n E-Exit /n");
        scanf("%d", ta);
        switch (ta)
        {
        case 'O':
            if (clientCounter < 50)
            {
                printf("Please enter the amount of money you would like to despoit?/n");
                scanf("%0.2lf", &amount);
                clientCounter++;
                bank_account = intial_deposit(amount);
                printf("The new account number is: %d/n", bank_account);
            }
            else
            {
                printf("Our bank apolgize there is no more room for a new bank account./n");
            }
            break;
        case 'B':
            printf("Please type a bank account between 901 to 950: /n");
            scanf("%d", &bank_account);
            if (clientCounter > 0 && bank_account >= 901 && bank_account <= 950)
            {
                amount = return_amount(bank_account);
                if (amount == __DBL_MAX__)
                {
                    printf("The bank account %d is closed/n", bank_account);
                }
                else
                {
                    printf("The depsoit of the bank account %d is: %0.2lf/n", bank_account, amount);
                }
            }
            else
            {
                printf("There is no any open bank accounts or you typed invalid bank account number/n");
            }
            break;
        case 'D':
            printf("Please type a bank account between 901 to 950: /n");
            scanf("%d", &bank_account);
            printf("Please type the amount of money that you would like to despoit:/n");
            scnaf("%0.2lf,", &amount);
            if (clientCounter > 0 && bank_account >= 901 && bank_account <= 950)
            {
                operate = add_balance_amount(bank_account, amount);
                if (operate = __DBL_MAX__)
                {
                    printf("The bank account %d is closed/n", bank_account);
                }
                else
                {
                    printf("The deposit of the bank account %d after this transaction is %0.2lf", bank_account, operate);
                }
            }
            else
            {
                printf("There is no any open bank accounts or you typed invalid bank account number/n");
            }
            break;
        case 'W':
            printf("Please type a bank account: /n");
            scanf("%d", &bank_account);
            printf("Please type the amount of money that you would like to withdraw:/n");
            scnaf("%0.2lf,", &amount);
            if (clientCounter > 0 && bank_account >= 901 && bank_account <= 950)
            {
                operate = sub_balance_amount(bank_account, amount);
                if (operate == __DBL_MAX__)
                {
                    printf("The bank account %d is closed/n", bank_account);
                }
                else if (operate == __DBL_MIN__)
                {
                    printf("The balance of this bank account less then the amount that you would like to withdraw/n");
                }
                else
                {
                    printf("The deposit of the bank account %d after this transaction is %0.2lf", bank_account, operate);
                }
            }
            else
            {
                printf("There is no any open bank accounts or you typed invalid bank account number/n");
            }
            break;
        case 'C':
            printf("Please enter bank account that you would like to close: /n");
            scanf("%d", &bank_account);
            if (clientCounter > 0 && bank_account >= 901 && bank_account <= 950)
            {
                flag = close_bank_account(bank_account);
                if (flag == true)
                {
                    printf("The bank account %d is now closed.", bank_account);
                    clientCounter--;
                }
                else
                {
                    printf("The bank account %d was already closed", bank_account);
                }
            }
            else
            {
                printf("There is no any open bank accounts or you typed invalid bank account number/n");
            }
            break;
        case 'I':
            printf("Please enter interest rate: /n");
            scanf("%0.2lf", &interest);
            if (clientCounter > 0)
            {
                if (interest > -100 && interest < 100)
                    interest_effect(interest, clientCounter);
            }
            else
            {
                printf("All bank accounts are closed");
            }

            break;
        case 'P':
            if (clientCounter > 0)
            {
                print_all_acitve_bank_accounts(clientCounter);
            }
            else
            {
                printf("All bank accounts are closed");
            }

            break;
        case 'E':
            close_all_bank_accounts();
            bexit = 1;
            break;
        default:
            printf("You typed invaild key/n");
            break;
        }
        flushall(); //clearing the buffer.

    } while (!bexit);

    return 0;
}