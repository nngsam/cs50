// Take any positive integer n. Repeat the following steps:

// If n is even, divide it by 2 → n = n / 2
// If n is odd, multiply it by 3 and add 1 → n = 3n + 1
// Repeat the process with the new value of n.

// No matter what positive integer you start with, you will always eventually reach 1.

#include <stdio.h>
#include <cs50.h>


int collatz_step(int n);

int main(void)
{
    int n = get_int("Your number: ");
    if (n < 1)
    {
        printf("Error: n must be a positive integer greater than 0.\n");
        printf("Usage: Enter a positive number like 1, 2, 3, ...\n");
        return 1;
    }

    int counter = collatz_step(n);

    // while (n != 1)
    // {
    //     n = ( n % 2 == 0 ) ? n /2 : 3*n+1;
    //     counter ++;
    //     printf(" -> %i", n);
    // }

    printf("\n");
    printf("Step taken: %i \n", counter);
    return 0;
}


int collatz_step(int n)
{
    printf ("%i", n);
    if (n==1)
        return 0;

    printf (" -> ");
    n = (n % 2 == 0) ? n / 2 : 3 * n +1;
    return 1 + collatz_step(n);

}

// in case just see the collatz process 
void print_collatz(int n)
{
    printf ("%i", n);
    if (n==1)
    {
        printf ("\n");
        return;
    }

    printf (" -> ");
    n = (n % 2 == 0) ? n / 2 : 3 * n +1;
    print_collatz(n);
}
