#ifndef MYBANK
#define MYBANK


void init();
int initial_deposit(double amount);
double return_amount(int bank_account);
double add_balance_amount(int bank_account, double amount);
double sub_balance_amount(int bank_account, double amount);
int close_bank_account(int bank_account);
void interest_effect(double interest, int clientCounter);
void print_all_acitve_bank_accounts(int clientCounter);
 void close_all_the_bank_accounts();

#endif