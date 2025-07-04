// Take any positive integer n. Repeat the following steps:

// If n is even, divide it by 2 → n = n / 2
// If n is odd, multiply it by 3 and add 1 → n = 3n + 1
// Repeat the process with the new value of n.

// No matter what positive integer you start with, you will always eventually reach 1.

#include <stdio.h>
#include <cs50.h>
#include <time.h>


#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n = get_int("Your number: ");

    if (n < 1)
    {
        printf("Error: n must be a positive integer greater than 0.\n");
        printf("Usage: Enter a positive number like 1, 2, 3, ...\n");
        return 1;
    }

    printf("%i", n);

    while (n != 1)
    {
        if (n % 2 == 0)
        {
            n = n / 2;
        }
        else 
        {
            n = 3 * n + 1;
        }
        printf(" -> %i", n);
    }

    printf("\n");
    return 0;
}
