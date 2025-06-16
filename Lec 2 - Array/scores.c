#include <stdio.h>
#include <cs50.h>


const int TOTAL=2;
float average(int length, int array[]); 

int main(void)
{
    //int num = get_int("how many num: \n");

    int scores[TOTAL];
    for (int i=0; i < TOTAL; i++)
    {
        scores[i] = get_int("score[%i]: \n", i);
    }
    printf("average: %.1f\n", average(TOTAL, scores));
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