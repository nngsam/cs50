#include <stdio.h>
#include <cs50.h>

int main(void)
{
    long x = get_long("x: ");

    long y = get_long("y: ");

    printf("x+y = %li\n", x+y);
    
}