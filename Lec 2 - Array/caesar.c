#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


int check_non_negative_integer(char* k);
char rotate_letter(char s, int k);

int main(int argc, char *argv[])
{
    // Check for exactly one command-line argument (excluding program name)
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Check if the argument is a non-negative integer
    if (!check_non_negative_integer(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Convert the argument to an integer
    int k = atoi(argv[1]);


    // caesar
    char* plaintext = get_string("plaintext: ");
    int n = strlen(plaintext);
    char* ciphertext = malloc(n+1);
    for (int i=0; i < n; i++)
    {
        ciphertext[i] = rotate_letter(plaintext[i], k);
    }
    ciphertext[n] = '\0';

    printf("ciphertext: %s \n", ciphertext);
    free(ciphertext);
    return 0;
}


int check_non_negative_integer(char* k)
{
    for (int i = 0; k[i] != '\0'; i++)
    {
        if (!isdigit(k[i]))
        {
            return 0; 
        }
    }
    return 1;
}

char rotate_letter(char s, int k)
{   
    if (islower(s))
        return 'a' + (s - 'a' + k) % 26;
    else if (isupper(s))
        return 'A' + (s - 'A' + k) % 26;
    else
        return s;
}
