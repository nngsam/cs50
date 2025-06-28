#include <stdio.h>
#include <cs50.h>
#include <string.h>


int main(void)
{
    string names[] = {"bill", "charles", "fred", "george", "ginny", "percy", "ron"};
    string numbers[] = {"4", "6", "8", "2", "7", "5", "0"};

    for (int i=0; i<7; i++)
    {
        if (strcmp(names[i], "ron") == 0) 
        {
            printf("found that person with phonenumber %s\n", numbers[i]);
            return 0;
        }
    }
    printf("not found\n");
    return 1; 
}