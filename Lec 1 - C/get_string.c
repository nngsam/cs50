#include <cs50.h>
#include <stdio.h>
int main(void)
{
    /* code */
    string answer = get_string("What's your name? ");
    printf ("hello, %s", answer); 
    fflush(stdout);
}
