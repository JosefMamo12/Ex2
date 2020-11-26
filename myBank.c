#include <myBank.h>
#include <stdio.h>
#include <stdbool.h>


int const accountsLength = 50, FIRSTBANKACCOUNT = 901, LASTBANKACCOUNTS = 950, usedAccounts = 1;
int k = 0, z = 0;
double accounts[50][2];

init()
{
    for (size_t i = 0; i < accountsLength; i++)
    {
        for (size_t j = 0; j < 2; i++)
        {
            accounts[i][usedAccounts] = 0; //Intialize all the bank accounts to be zero means account not open.
        }
    }
}
int initial_deposit(double amount)
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
    return k + FIRSTBANKACCOUNT;
}
double return_amount(int bank_account)
{
    if (accounts[LASTBANKACCOUNTS - bank_account][usedAccounts] == 1)
    {
        return accounts[LASTBANKACCOUNTS - bank_account][0];
    }

    return __DBL_MAX__;
}
double add_balance_amount(int bank_account, double amount)
{
    if (accounts[LASTBANKACCOUNTS - bank_account][usedAccounts] == 1)
    {
        accounts[LASTBANKACCOUNTS - bank_account][0] += amount;
        return accounts[LASTBANKACCOUNTS - bank_account][0];
    }
    return __DBL_MAX__;
}
double add_balance_amount(int bank_account, double amount)
{
    if (accounts[LASTBANKACCOUNTS - bank_account][usedAccounts] == 0)
    {
        return __DBL_MAX__;
    }
    else if (accounts[LASTBANKACCOUNTS - bank_account][0] < amount)
    {
        return __DBL_MIN__;
    }
    else
    {
        accounts[LASTBANKACCOUNTS - bank_account][0] -= amount;
    }
    return accounts[LASTBANKACCOUNTS - bank_account][0];
}
bool close_bank_account(int bank_account)
{
    if (accounts[LASTBANKACCOUNTS - bank_account][usedAccounts] == 0)
    {
        return false;
    }
    accounts[LASTBANKACCOUNTS - bank_account][0] = 0;
    accounts[LASTBANKACCOUNTS - bank_account][usedAccounts] = 0;
    return true;
}
void interest_effect(double interest, int clientCounter)
{
    z = 0;
    for (size_t i = 0; i < 50 || z < clientCounter; i++)
    {
        if (accounts[i][usedAccounts] == 1)
        {
            accounts[i][0] += accounts[i][0] * interest / 100;
            z++;
        }
    }
}
void print_all_acitve_bank_accounts(int clientCounter)
{
    z = 0;
    for (size_t i = 0; i < 50 || z < clientCounter; i++)
    {
        if (accounts[i][usedAccounts] == 1)
        {
            z++;
            printf("The balance of the account %d is %0.2lf/n", i + FIRSTBANKACCOUNT, accounts[i][0]);
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
