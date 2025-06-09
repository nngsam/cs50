#include <stdio.h>
#include <cs50.h>

int get_positive_int(void);


int main (void)
{
    int num = get_positive_int();
    printf("%i is a positive number\n", num);
}


int get_positive_int(void)
{
    int n;
    do
    {
        n = get_int("enter your number: ");
    } 
    while (n<1);
    return n;
}