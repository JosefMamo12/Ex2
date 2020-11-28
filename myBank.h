#ifndef MYBANK
#define MYBANK


void init();
void initial_deposit(double amount);
void return_amount(int bank_account);
void add_balance_amount(int bank_account, double amount);
void sub_balance_amount(int bank_account, double amount);
void close_bank_account(int bank_account);
void interest_effect(double interest);
void print_all_acitve_bank_accounts();
void close_all_the_bank_accounts();

#endif