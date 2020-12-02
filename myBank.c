#include "myBank.h"
#include <stdio.h>
#include <float.h>

int const accountsLength = 50, FIRSTBANKACCOUNT = 901, LASTBANKACCOUNTS = 950, usedAccounts = 1;
int k = 0, clientCounter = 0, bank_account = 0, interest = 0;
double accounts[50][2] = {0}, amount = 0;

void initial_deposit()
{
    if (clientCounter < accountsLength)
    {
        printf("Please enter amount for deposit: ");
        if (scanf("%lf", &amount) == 1)
        {
            if (amount > 0)
            {
                for (size_t i = 0; i < 50; i++)
                {
                    if (accounts[i][usedAccounts] == 0)
                    {
                        accounts[i][0] = amount;
                        accounts[i][1] = 1;
                        k = i;
                        clientCounter++;
                        printf("New account number is: %d\n", k + FIRSTBANKACCOUNT);
                        break;
                    }
                }
            }
            else
            {
                printf("Invalid Amount\n");
            }
        }
        else
        {
            printf("Failed to read the ammount\n");
        }
    }
    else
    {
        printf("The bank is full\n");
    }
    return;
}
void return_amount()
{
    printf("Please enter account number: ");
    if (scanf("%d", &bank_account) == 1)
    {
        if (bank_account <= LASTBANKACCOUNTS && bank_account >= FIRSTBANKACCOUNT)
        {
            if (accounts[bank_account - FIRSTBANKACCOUNT][usedAccounts] == 1)
            {
                printf("The balance of account number %d is:  %0.2lf\n", bank_account, accounts[bank_account - FIRSTBANKACCOUNT][0]);
            }
            else
            {
                printf("This account is closed\n");
            }
        }
        else
        {
            printf("This account is not exist in our system\n");
        }
    }
    else
    {
        printf("Failed to read the account number\n");
    }
    return;
}
void add_balance_amount()
{
    printf("Please enter account number: ");
    if (scanf("%d", &bank_account) == 1)
    {
        if (bank_account <= LASTBANKACCOUNTS && bank_account >= FIRSTBANKACCOUNT)
        {
            if (accounts[bank_account - FIRSTBANKACCOUNT][usedAccounts] == 1)
            {
                printf("Please enter the amount to deposit: ");
                if (scanf("%lf", &amount) == 1)
                {
                    if (amount > 0)
                    {

                        accounts[bank_account - FIRSTBANKACCOUNT][0] += amount;
                        printf("The new balance is: %0.2lf\n", accounts[bank_account - FIRSTBANKACCOUNT][0]);
                    }
                    else
                    {
                        printf("Cannot deposit a negative amount\n");
                    }
                }
                else
                {
                    printf("Failed to read the amount\n");
                }
            }
            else
            {
                printf("This account is closed\n");
            }
        }
        else
        {
            printf("Invalid account number\n");
        }
    }
    else
    {

        printf("Failed to read the account number\n");
    }
    return;
}
void sub_balance_amount()
{
    printf("Please enter account number: ");
    double amountForThisProgram;
    if (scanf("%d", &bank_account) == 1)
    {
        if (bank_account <= LASTBANKACCOUNTS && bank_account >= FIRSTBANKACCOUNT)
        {
            if (accounts[bank_account - FIRSTBANKACCOUNT][usedAccounts] == 1)
            {
                printf("Please enter amount to withdraw: ");
                if (scanf("%lf", &amountForThisProgram) == 1)
                {
                    if (amountForThisProgram < 0)
                    {
                        if (accounts[bank_account - FIRSTBANKACCOUNT][0] > amountForThisProgram)
                        {

                            accounts[bank_account - FIRSTBANKACCOUNT][0] -= amountForThisProgram;
                            printf("The new balance is: %0.2lf\n", accounts[bank_account - FIRSTBANKACCOUNT][0]);
                        }
                        else
                        {
                            printf("Cannot withdraw more than the balance\n");
                        }
                    }
                    else
                    {
                        printf("Cannot withdraw negative amount\n");
                    }
                }
                else
                {
                    printf("Failed to read this ammount\n");
                }
            }
            else
            {
                printf("This account is closed\n");
            }
        }
        else
        {
            printf("Invalid account number\n");
        }
    }
    else
    {
        printf("Failed to read the account number\n");
    }
    return;
}
void close_bank_account()
{
    printf("Please enter account number: ");
    if (scanf("%d", &bank_account) == 1)
    {
        if (bank_account <= LASTBANKACCOUNTS && bank_account >= FIRSTBANKACCOUNT)
        {
            if (accounts[bank_account - FIRSTBANKACCOUNT][usedAccounts] == 1)
            {
                accounts[bank_account - FIRSTBANKACCOUNT][0] = 0;
                accounts[bank_account - FIRSTBANKACCOUNT][usedAccounts] = 0;
                clientCounter--;
                printf("Closed account number %d\n", bank_account);
            }
            else
            {
                printf("This account is already closed \n");
            }
        }
        else
        {
            printf("This bank account is not exist in our system\n");
        }
    }
    else
    {
        printf("Failed to read the account number\n");
    }
    return;
}
void interest_effect()
{

    printf("Please enter interest rate: ");
    if (scanf("%d", &interest) == 1)
    {
        if (interest > 0)
        {

            for (size_t i = 0; i < 50; i++)
            {
                if (accounts[i][usedAccounts] == 1)
                {
                    accounts[i][0] += accounts[i][0] * interest / 100;
                }
            }
        }
        else
        {
            printf("Invalid interest rate\n");
        }
    }
    else
    {
        printf("Failed to read the interest rate\n");
    }

    return;
}
void print_all_acitve_bank_accounts()
{
    if (clientCounter > 0)
    {
        for (size_t i = 0; i < 50; i++)
        {
            if (accounts[i][usedAccounts] == 1)
            {
                printf("The balance of account number %ld is:  %0.2lf\n", i + FIRSTBANKACCOUNT, accounts[i][0]);
            }
        }
       
    }
     return;
}
void close_all_the_bank_accounts()
{
    if (clientCounter > 0)
    {
        for (size_t i = 0; i < 50; i++)
        {
            if (accounts[i][usedAccounts] == 1)
            {
                accounts[i][0] = 0;
                accounts[i][usedAccounts] = 0;
            }
        }
    }
    else
    {
        printf("All bank accounts are already closed.\n");
    }

    return;
}
