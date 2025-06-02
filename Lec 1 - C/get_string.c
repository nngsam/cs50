#include <cs50.h>
#include <stdio.h> /* standard input output dot h, is ta famous file in c TO get input & output from user */

int main(void)
{
    string answer = get_string("What's your name? \n");
    printf ("hello, %s\n", answer);
}
