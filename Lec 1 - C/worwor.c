#include <stdio.h>


// there will exist the function called worwor, but just not yet
void worwor(void);

int main (void)
{   
    int count = 0;
    for (int i = -1; i <=4; i+=1)
    {
        worwor();
        count += 1;
    }

    printf("your dog bark %i times\n", count);
}

void worwor(void)
{
    printf("wor wor\n");
}