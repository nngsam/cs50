#include <stdio.h>
#include <cs50.h>


float average(int length, int array[]); 

int main(void)
{
    int num = get_int("how many num: \n");

    int scores[num];
    for (int i=0; i < num; i++)
    {
        scores[i] = get_int("score[%i]: \n", i);
    }
    printf("average: %.1f\n", average(num, scores));
}


float average(int length, int array[])
{ 
    int sum = 0; 
    for (int i=0; i < length; i++)
    {
        sum += array[i];
    }

    return sum / (float) length;
}