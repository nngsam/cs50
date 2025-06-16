#include <stdio.h>
#include <cs50.h>


int main(void)
{
    int num;
    num = get_int("how many num: \n");

    int scores[num];
    float sum;
    for (int i=0; i < num; i++)
    {
        scores[i] = get_int("score[%i]: \n", i);
        sum += scores[i];
    }
    printf("sum = %.1f\n", sum);
    printf("average: %.1f\n", sum/num);
}