#include <stdio.h>

int main (void)
{   
    int count = 0;
    for (int i = 0; i <=4; i+=1)
    {
        printf("wor wor\n");
        count = i;
    }

    printf("your dog bark %i times\n", count);
}