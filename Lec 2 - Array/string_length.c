#include <stdio.h>
#include <cs50.h>
#include <string.h>


typedef char *string;

int main(void)
{
    string s = get_string("input: \n");
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        printf("%c ", s[i]);
    }
    
    printf("\nstring length: %zu\n", strlen(s));
}