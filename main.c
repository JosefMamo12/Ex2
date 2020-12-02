#include <stdio.h>
#include "myBank.h"

int main()
{
    char ta;

    do
    {
        printf("\nPlease choose transaction type:\nO-Open Account\nB-Balance Inquiry\nD-Deposit\nW-Withdrawal\nC-Close Account\nI-Interest\nP-Print\nE-Exit\n");
        scanf(" %c", &ta);
        switch (ta)
        {
        case 'O':
            initial_deposit();
            break;
        case 'B':
            return_amount();
            break;
        case 'D':
            add_balance_amount();
            break;
        case 'W':
            sub_balance_amount();
            break;
        case 'C':
            close_bank_account();
            break;
        case 'I':
            interest_effect();
            break;
        case 'P':
            print_all_acitve_bank_accounts();
            break;
        case 'E':
            close_all_the_bank_accounts();
            break;
        default:
            printf("Invalid transaction type\n");
            break;
        }
    } while (ta != 'E');

    return 0;
}