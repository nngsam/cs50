#include <stdio.h>
#include <cs50.h>
#include <string.h>


int main(void)
{
    string names[] = {"bill", "charles", "fred", "george", "ginny", "percy", "ron"};

    for (int i=0; i<7; i++)
    {
        if (strcmp(names[i], "ron")) 
        {
            printf("found\n");
            return 0;
        }
    }
    printf("not found\n");
    return 1; 
}