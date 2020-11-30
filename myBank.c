#include "myBank.h"
#include <stdio.h>
#include <float.h>

int const accountsLength = 50, FIRSTBANKACCOUNT = 901, LASTBANKACCOUNTS = 950, usedAccounts = 1;
int k = 0, clientCounter = 0, bank_account = 0;
double accounts[50][2] ={0} , amount = 0, interest = 0;

void initial_deposit()
{
    if (clientCounter < accountsLength)
    {
        printf("Please enter amount for deposit\n");
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
                        printf("The bank new bank account number is %d\n", k + FIRSTBANKACCOUNT);
                        break;
                    }
                }
            }
            else
            {
                printf("The amount is less than 0\n");
            }
        }
        else
        {
            printf("Failed to read this ammount\n");
        }
    }
    else
    {
        printf("The bank is full\n");
    }
}
void return_amount()
{
    printf("Please type bank account number to see the balance\n");
    if (scanf("%d", &bank_account) == 1)
    {
        if (bank_account <= LASTBANKACCOUNTS && bank_account >= FIRSTBANKACCOUNT)
        {
            if (accounts[bank_account - FIRSTBANKACCOUNT][usedAccounts] == 1)
            {
                printf("The account %d have balance of %0.2lf\n", bank_account, accounts[bank_account - FIRSTBANKACCOUNT][0]);
            }
            else
            {
                printf("This bank account is closed\n");
            }
        }
        else
        {
            printf("This bank account is not exist in our system\n");
        }
    }
    else
    {
        printf("Failed to read this bank account\n");
    }
}
void add_balance_amount()
{
    printf("Please type bank account number\n");
    if (scanf("%d", &bank_account) == 1)
    {
        if (bank_account <= LASTBANKACCOUNTS && bank_account >= FIRSTBANKACCOUNT)
        {
            printf("Please enter amount for deposit\n");
            if (scanf("%lf", &amount) == 1)
            {
                if (amount > 0)
                {
                    if (accounts[bank_account - FIRSTBANKACCOUNT][usedAccounts] == 1)
                    {
                        accounts[bank_account - FIRSTBANKACCOUNT][0] += amount;
                        printf("The balance of the account %d is now %0.2lf\n", bank_account, accounts[bank_account - FIRSTBANKACCOUNT][0]);
                    }
                    else
                    {
                        printf("The bank account %d is closed\n", bank_account);
                    }
                }
                else
                {
                    printf("The amount is less than 0");
                }
            }
            else
            {
                printf("Failed to read this ammount\n");
            }
        }
        else
        {
            printf("This bank account is not exist in our system\n");
        }
    }
    else
    {
        printf("Failed to read this bank account\n");
    }
}
void sub_balance_amount()
{
    printf("Please type bank account number\n");
    if (scanf("%d", &bank_account) == 1)
    {
        if (bank_account <= LASTBANKACCOUNTS && bank_account >= FIRSTBANKACCOUNT)
        {
            printf("Please enter amount for deposit\n");
            if (scanf("%lf", &amount) == 1)
            {
                if (amount > 0)
                {
                    if (accounts[bank_account - FIRSTBANKACCOUNT][0] > amount)
                    {
                        if (accounts[bank_account - FIRSTBANKACCOUNT][usedAccounts] == 1)
                        {
                            accounts[bank_account - FIRSTBANKACCOUNT][0] -= amount;
                            printf("The balance of the account %d after the transaction is %0.2lf\n", bank_account, accounts[bank_account - FIRSTBANKACCOUNT][0]);
                        }
                        else
                        {
                            printf("This bank account is closed\n");
                        }
                    }
                    else
                    {
                        printf("The amount is more than the balance\n");
                    }
                }
                else
                {
                    printf("The amount is less than 0\n");
                }
            }
            else
            {
                printf("Failed to read this ammount\n");
            }
        }
        else
        {
            printf("This bank account is not exist in our system\n");
        }
    }
    else
    {
        printf("Failed to read this bank account\n");
    }
}
void close_bank_account()
{
    printf("Please type bank account number:");
    if (scanf("%d", &bank_account) == 1)
    {
        if (bank_account <= LASTBANKACCOUNTS && bank_account >= FIRSTBANKACCOUNT)
        {
            if (accounts[bank_account - FIRSTBANKACCOUNT][usedAccounts] == 1)
            {
                accounts[bank_account - FIRSTBANKACCOUNT][0] = 0;
                accounts[bank_account - FIRSTBANKACCOUNT][usedAccounts] = 0;
                clientCounter--;
                printf("The bank account %d is now closed\n", bank_account);
            }
            else
            {
                printf("This bank account is already closed \n");
            }
        }
        else
        {
            printf("This bank account is not exist in our system\n");
        }
    }
    else
    {
        printf("Failed to read this bank account\n");
    }
}
void interest_effect()
{
    if (clientCounter > 0)
    {
        printf("Please enter interest rate:");
        if (scanf("%lf", &interest) == 1)
        {
            if (interest > -100 && interest < 100)
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
                printf("The interest %0.2lf is out of our scale please type new one between to -99 to 99\n", interest);
            }
        }
        else
        {
            printf("Failed to read the interest rate\n");
        }
    }
    else
    {
        printf("All bank accounts are closed.\n");
    }
}
void print_all_acitve_bank_accounts()
{
    if (clientCounter > 0)
    {
        for (size_t i = 0; i < 50; i++)
        {
            if (accounts[i][usedAccounts] == 1)
            {
                printf("The balance of the account %ld is %0.2lf\n", i + FIRSTBANKACCOUNT, accounts[i][0]);
            }
        }
    }
    else
    {
        printf("All bank accounts are closed.\n");
    }
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
}
