#include <stdio.h>
#include "myBank.h"

int main()
{

    double amount, interest;
    int clientCounter = 0, bank_account = 0;
    char ta;
    init();
    {
        do
        {
            printf("Please choose transaction type:\nO-Open Account\nB-Balance Inquiry\nD-Deposit\nW-Withdrawal\nC-Close Account\nI-Interest\nP-Print\nE-Exit\n");
            if (scanf("%c", &ta) != 1)
            {
                printf("Failed to read the type of transaction\n");
            }
            else
            {
                switch (ta)
                {
                case 'O':
                    if (clientCounter < 50)
                    {

                        printf("amount?\n");
                        if (scanf("%lf", &amount) == 1)
                        {
                            initial_deposit(amount);
                            clientCounter++;
                        }
                        else
                        {
                            printf("Failed to read the amount\n");
                        }
                    }
                    else
                    {
                        printf("Our bank apolgize there is no more room for a new bank account.\n");
                    }
                    break;
                case 'B':
                    printf("Please type a bank account:\n");
                    if (scanf("%d", &bank_account) == 1)
                    {
                        return_amount(bank_account);
                    }
                    else
                    {
                        printf("Failed to read the bank account\n");
                    }

                    break;
                case 'D':
                    printf("Please type a bank account:\n");
                    printf("amount?\n");
                    if (scanf("%d", &bank_account) == 1 && scanf("%lf", &amount) == 1)
                    {
                        add_balance_amount(bank_account, amount);
                    }
                    else
                    {
                        printf("Failed to read the bank acoount or the amount\n");
                    }

                case 'W':
                    printf("Please type a bank account:\n");
                    printf("amount?\n");
                    if (scanf("%d", &bank_account) == 1 && scanf("%lf", &amount) == 1)
                    {
                        sub_balance_amount(bank_account, amount);
                    }
                    else
                    {
                        printf("Failed to read the bank acoount or the amount\n");
                    }

                    break;
                case 'C':
                    printf("Please enter bank account that you would like to close:\n");
                    if (scanf("%d", &bank_account) == 1)
                    {
                        close_bank_account(bank_account);
                    }
                    else
                    {
                        printf("Failed to read the bank account number\n");
                    }

                    break;
                case 'I':
                    printf("Please enter interest rate: \n");
                    if (scanf("%lf", &interest) == 1)
                    {
                        if (clientCounter > 0)
                        {
                            interest_effect(interest);
                        }
                        else
                        {
                            printf("All bank accounts are closed\n");
                        }
                    }
                    else
                    {
                        printf("Failed to read the interest\n");
                    }

                    break;
                case 'P':
                    if (clientCounter > 0)
                    {
                        print_all_acitve_bank_accounts();
                    }
                    else
                    {
                        printf("All bank accounts are closed\n");
                    }

                    break;
                case 'E':
                    close_all_the_bank_accounts();
                    break;
                default:
                    printf("You typed invaild key please press a valid key\n");
                }
            }
        } while (ta != 'E');
    }
    return 0;
}