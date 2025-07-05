#include <stdio.h>
#include <cs50.h>


int factorial(int n)
{
    if (n==0)
    {
        return 1;
    }
    return n * factorial(n-1);
}

int fibonacci(int n)
{
    if (n==0)
    {
        return 0;
    }
    else if (n==1)
    {
        return 1;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}

int count_digits(int n)
// using converting to string or loop is not allowed 
{
    if (n < 10)
    {
        return 1;
    }
    return count_digits(n/10) + 1; 
}


int display_binary(int n)
// bin() funtion is not allowed
{
    if (n==0)
    {
        return 0;
    }
    display_binary(n/2) ;
    printf("%i", n%2);
    return 0;
}


int main(void)
{
    int n = get_int("Your number: ");
    printf("factorial of %i is %i\n", n, factorial(n));
    printf("count of digits in %i is %i\n", n, count_digits(n));
    printf("fibonacci of %i is %i\n", n, fibonacci(n));
    printf("binary of %i is ", n);
    display_binary(n);
    printf("\n");

}