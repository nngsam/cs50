#include <stdio.h>


// type alias string
// 1 
// typedef char *string;
// 2 
typedef char* string;

int main(void)
{
    char *s = "huhuh";
  
    printf("%i %i %i %i %i %i %i\n", s[0], s[1], s[2], s[3], s[4], s[5], s[6000]);
  
} 

