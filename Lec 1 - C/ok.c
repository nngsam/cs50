#include <cs50.h>
#include <stdio.h>

int main (void)
{
    char c = get_char("Are u ok? ");
    if (c == 'y' || c == 'Y')
    {
        printf("fine.\n");
    }
    else if (c == 'n' || c == 'N')
    {
        printf("not fine.\n");
    }
}