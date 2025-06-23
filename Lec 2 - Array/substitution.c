#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int check_character(char* rule);
int has_duplicate_letters(char* rule);    
char revert_char(char letter, char* rule);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    char* rule = argv[1];

    if (strlen(rule) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    if (!check_character(rule))
    {
        printf("Key must only contain alphabetic characters.\n");
        return 1;
    }

    if (has_duplicate_letters(rule))
    {
        printf("Key must not contain repeated characters.\n");
        return 1;
    }


    // Substitution
    char* plaintext = get_string("plaintext: ");
    int n = strlen(plaintext);
    char* ciphertext = malloc(n+1);
    for (int i=0; i < n; i++)
    {
        ciphertext[i] = revert_char(plaintext[i], rule);
    }
    ciphertext[n] = '\0';

    printf("ciphertext: %s \n", ciphertext);
    free(ciphertext);
    return 0;
}


int check_character(char* rule)
{
    for (int i = 0; rule[i] != '\0'; i++)
        {
            if (!isalpha(rule[i]))
            {
                return 0; 
            }
        }
        return 1;
}

int has_duplicate_letters(char* rule)
{
    int seen[26] = {0};

    for (int i = 0; i < 26; i++)
    {
        char c = tolower(rule[i]);
        if (seen[c - 'a'])
            return 1;
        seen[c - 'a'] = 1;
    }
    return 0; 
}


char revert_char(char letter, char* rule)
{ 
    if (islower(letter))
        return tolower(rule[(letter - 'a')]); 

    else if (isupper(letter))
        return toupper(rule[(letter - 'A')]);

    else 
        return letter;
}
    


//   V  C  H  P  R  Z  G  J  N  T   L   S   K   F   B   D   Q   W   A   X   E   U   Y   M   O   I  --> rule
//   0  1  2  3  4  5  6  7  8  9  10  11  12  13  14  15  16  17  18  19  20  21  22  23  24  25 
//   a  b  c  == v  c  h
//   0  1  2 

//   ====

// a = 97, b =98, c =99 --> remain: a = 0, b = 1, c =2 
//   rule[0] rule[1] rule [2]
//   v  c  h