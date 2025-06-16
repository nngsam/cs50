#include <stdio.h>
#include <cs50.h>


typedef char *string;

int main(void)
{
    string s = get_string("input: \n");
    int counter = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        printf("%c ", s[i]);
        counter += 1;
    }
    
    printf("\nstring length: %i\n", counter);
}