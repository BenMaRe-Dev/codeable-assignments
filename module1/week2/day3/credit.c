#include <cs50.h>
#include <stdio.h>

int main(void)
{
    bool is_even = false;
    int sum_odds = 0;
    int sum_evens = 0;
    int lenght = 0;
    string card_type = "";
    long long ocard = 0;
    int last = 0;
    int dlast = 0;
    int total_sum = 0;
    long long number = 0;

    do
    {
        number = get_long_long("please insert yout card number: ");
    } while (number < 0);
    ocard = number;
    while (number != 0)
    {
        last = (number % 10);
        lenght = lenght + 1;
        if (is_even)
        {
            dlast = last * 2;
            while (dlast != 0)
            {
                sum_evens = sum_evens + (dlast % 10);
                dlast = dlast / 10;
            }
            is_even = false;
        }
        else
        {
            sum_odds = sum_odds + last;
            is_even = true;
        }
        number = number / 10;
    }
    total_sum = sum_odds + sum_evens;
    if (total_sum % 10 == 0)
    {
        if (lenght == 15)
        {
            if ((ocard / (long long)10E12) == 34 ||
                (ocard / (long long)10E12) == 37)
            {
                card_type = "AMEX";
            }
            else
            {
                card_type = "INVALID";
            }
        }
        else if (lenght == 16)
        {
            if ((ocard / (long long)10E13) >= 51 &&
                (ocard / (long long)10E13) <= 55)
            {
                card_type = "MASTERCARD";
            }
            else if ((ocard / (long long)10E14) == 4)
            {
                card_type = "VISA";
            }
            else
            {
                card_type = "INVALID";
            }
        }
        else if (lenght == 13)
        {
            if ((ocard / (long long)10E11) == 4)
            {
                card_type = "VISA";
            }
            else
            {
                card_type = "INVALID";
            }
        }
        else
        {
            card_type = "INVALID";
        }
    }
    else
    {
        card_type = "INVALID";
    }
    printf("%s\n", card_type);
    return 0;
}
