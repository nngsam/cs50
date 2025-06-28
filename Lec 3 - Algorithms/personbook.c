#include <stdio.h>
#include <cs50.h>
#include <string.h>


typedef struct
{
    string name;
    string number;
}person;

const int NUMBER = 2;

int main(void)
{
    // string names[] = {"bill", "charles", "fred", "george", "ginny", "percy", "ron"};
    // string numbers[] = {"4", "6", "8", "2", "7", "5", "0"};

    person people[NUMBER];

    people[0].name = "bill"; 
    people[1].name = "charles"; 

    people[0].number = "4"; 
    people[1].number = "6"; 


    for (int i=0; i<NUMBER; i++)
    {
        if (strcmp(people[i].name, "bill") == 0) 
        {
            printf("found that person with phonenumber %s\n", people[i].number);
            return 0;
        }
    }
    printf("not found\n");
    return 1; 
}