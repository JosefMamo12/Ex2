#include "myBank.h"
#include <stdio.h>
#include <float.h>

int const accountsLength = 50, FIRSTBANKACCOUNT = 901, LASTBANKACCOUNTS = 950, usedAccounts = 1;
int k = 0;
double accounts[50][2];

void init()
{
    for (size_t i = 0; i < accountsLength; i++)
    {
        accounts[i][usedAccounts] = 0; //Intialize all the bank accounts to be zero means account not open.
    }
}

void initial_deposit(double amount)
{
    for (size_t i = 0; i < 50; i++)
    {
        if (accounts[i][usedAccounts] == 0)
        {
            accounts[i][0] = amount;
            accounts[i][1] = 1;
            k = i;
            break;
        }
    }
    printf("The bank new bank account number is %d\n", k + FIRSTBANKACCOUNT);
}
void return_amount(int bank_account)
{
    if (bank_account > LASTBANKACCOUNTS || bank_account < FIRSTBANKACCOUNT)
    {
        printf("The bank account does not exit in our system\n");
    }
    if (accounts[bank_account - FIRSTBANKACCOUNT][usedAccounts] == 1)
    {
        printf("The account %d have balance of %0.2lf\n", bank_account, accounts[bank_account - FIRSTBANKACCOUNT][0]);
    }
}
void add_balance_amount(int bank_account, double amount)
{
    if (bank_account > LASTBANKACCOUNTS || bank_account < FIRSTBANKACCOUNT)
    {
        printf("The bank account does not exit in our system\n");
    }
    else if (accounts[bank_account - FIRSTBANKACCOUNT][usedAccounts] == 1)
    {
        accounts[bank_account - FIRSTBANKACCOUNT][0] += amount;
        printf("The balance of the account %d is now %0.2lf\n", bank_account, accounts[bank_account - FIRSTBANKACCOUNT][0]);
    }
    else
    {
        printf("he bank account %d is closed\n", bank_account);
    }
}
void sub_balance_amount(int bank_account, double amount)
{
    if (bank_account > LASTBANKACCOUNTS || bank_account < FIRSTBANKACCOUNT)
    {
        printf("The bank account does not exit in our system\n");
    }
    else if (accounts[bank_account - FIRSTBANKACCOUNT][usedAccounts] == 0)
    {
        printf("The account %d is closed\n", bank_account);
    }
    else if (accounts[bank_account - FIRSTBANKACCOUNT][0] < amount)
    {
        printf("The balance of the account %d is less than the amount you would like to withdraw\n", bank_account);
    }

    else
    {
        accounts[bank_account - FIRSTBANKACCOUNT][0] -= amount;
        printf("The balance of the account %d after the transaction is %0.2lf\n", bank_account, accounts[bank_account - FIRSTBANKACCOUNT][0]);
    }
}

void close_bank_account(int bank_account)
{
    if (bank_account > LASTBANKACCOUNTS || bank_account < FIRSTBANKACCOUNT)
    {
        printf("The bank account does not exit in our system\n");
    }
    if (accounts[bank_account - FIRSTBANKACCOUNT][usedAccounts] == 0)
    {
        printf("The bank account %d is already closed\n", bank_account);
    }
    accounts[bank_account - FIRSTBANKACCOUNT][0] = 0;
    accounts[bank_account - FIRSTBANKACCOUNT][usedAccounts] = 0;
    printf("The bank account %d is now closed\n", bank_account);
}
void interest_effect(double interest)
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
void print_all_acitve_bank_accounts()
{
    for (size_t i = 0; i < 50 ; i++)
    {
        if (accounts[i][usedAccounts] == 1)
        {
            printf("The balance of the account %ld is %0.2lf\n", i + FIRSTBANKACCOUNT, accounts[i][0]);
        }
    }
}
void close_all_the_bank_accounts()
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
