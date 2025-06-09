#include <stdio.h>


// Declare the function and say it returns an int
int worwor(int n);


int main (void)
{   
    int count = worwor(3);
    printf("your dog bark %i times\n", count);
}


// Define worwor to return the number of barks
int worwor(int n)
{   
    int bark_count = 0;
    for (int i = -1; i <=n; i+=1)
    {
        printf ("worwor\n");
        bark_count += 1;
    }
    return bark_count;
}