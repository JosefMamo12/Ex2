#include <stdio.h>
#include "myBank.h"

int main()
{

    double amount, interest, operate;
    int clientCounter = 0, bank_account = 0, flag = 0, bexit = 0;
    char ta;
    init();
    {
        printf("Please choose transaction type:\nO-Open Account\nB-Balance Inquiry\nD-Deposit\nW-Withdrawal\nC-Close Account\nI-Interest\nP-Print\nE-Exit\n");
        if (scanf("%c", &ta) != 1)
        {
    
        }
        else
        {
            switch (ta)
            {
            case 'O':
                if (clientCounter < 50)
                {
                    printf("Please enter the amount of money you would like to despoit?\n");
                    if (scanf("%lf", &amount) != 1)
                    {
                        printf("\n Failed to read this transaction");
                    }
                    else
                    {
                        clientCounter++;
                        bank_account = initial_deposit(amount);
                        printf("The new account number is: %d\n", bank_account);
                    }
                }
                else
                {
                    printf("Our bank apolgize there is no more room for a new bank account.\n");
                }
                break;
            case 'B':
                printf("Please type a bank account:\n");
                if (scanf("%d", &bank_account) != 1)
                {
                    printf("\n Failed to read this transaction");
                }
                else if (clientCounter > 0 && bank_account >= 901 && bank_account <= 950)
                {
                    amount = return_amount(bank_account);
                    if (amount == __DBL_MAX__)
                    {
                        printf("The bank account %d is closed\n", bank_account);
                    }
                    else
                    {
                        printf("The depsoit of the bank account %d is: %0.2lf\n", bank_account, amount);
                    }
                }
                else
                {
                    printf("There is no any open bank accounts or you typed invalid bank account number\n");
                }
                break;
            case 'D':
                printf("Please type a bank account: \n");
                if (scanf("%d", &bank_account) != 1)
                {
                    printf("\n Failed to read this transaction");
                }
                else if (clientCounter > 0 && bank_account >= 901 && bank_account <= 950)
                {
                    printf("Please type the amount of money that you would like to despoit:\n");
                    if (scanf("%lf", &amount) != 1)
                    {
                    }
                    operate = add_balance_amount(bank_account, amount);
                    if (operate == __DBL_MAX__)
                    {
                        printf("The bank account %d is closed\n", bank_account);
                    }
                    else
                    {
                        printf("The deposit of the bank account %d after this transaction is %0.2lf\n", bank_account, operate);
                    }
                }
                else
                {
                    printf("There is no any open bank accounts or you typed invalid bank account number\n");
                }
                break;
            case 'W':
                printf("Please type a bank account:\n");
                scanf("%d", &bank_account);
                printf("Please type the amount of money that you would like to withdraw:\n");
                scanf("%lf,", &amount);
                if (clientCounter > 0 && bank_account >= 901 && bank_account <= 950)
                {
                    operate = sub_balance_amount(bank_account, amount);
                    if (operate == __DBL_MAX__)
                    {
                        printf("The bank account %d is closed\n", bank_account);
                    }
                    else if (operate == __DBL_MIN__)
                    {
                        printf("The balance of this bank account less then the amount that you would like to withdraw\n");
                    }
                    else
                    {
                        printf("The deposit of the bank account %d after this transaction is %0.2lf\n", bank_account, operate);
                    }
                }
                else
                {
                    printf("There is no any open bank accounts or you typed invalid bank account number\n");
                }
                break;
            case 'C':
                printf("Please enter bank account that you would like to close:\n");
                scanf("%d", &bank_account);

                if (clientCounter > 0 && bank_account >= 901 && bank_account <= 950)
                {
                    flag = close_bank_account(bank_account);
                    if (flag == 1)
                    {
                        printf("The bank account %d is now closed.\n", bank_account);
                        clientCounter--;
                    }
                    else
                    {
                        printf("The bank account %d was already closed\n", bank_account);
                    }
                }
                else
                {
                    printf("There is no any open bank accounts or you typed invalid bank account number\n");
                }
                break;
            case 'I':
                printf("Please enter interest rate: \n");
                scanf("%lf", &interest);
                if (clientCounter > 0)
                {
                    if (interest > -100 && interest < 100)
                        interest_effect(interest, clientCounter);
                }
                else
                {
                    printf("All bank accounts are closed\n");
                }

                break;
            case 'P':
                if (clientCounter > 0)
                {
                    print_all_acitve_bank_accounts(clientCounter);
                }
                else
                {
                    printf("All bank accounts are closed\n");
                }

                break;
            case 'E':
                close_all_the_bank_accounts();
                bexit = 1;
                break;
            default:
                printf("You typed invaild key please press a valid key\n");
            }
            while ((getchar() != '\n'))
                ;
        }
        while (!bexit)
            ;
        return 0;
    }
}