#include <stdio.h>
#include <cs50.h>
#include <string.h>


int main(void)
{
    string s = get_string("Input: ");
    printf("Uppercase:  \n");

    for (int i=0, n=strlen(s); i < n; i++)
    {
        if (s[i] >= 97 && s[i] <= 122) // lowercase
        {
            printf("%c ", s[i]-32);
        }
        else 
        {
            printf("%c", s[i]);
        }
    }
}