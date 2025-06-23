#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// index = 0.0588 * L - 0.296 * S - 15.8
//    where 
//        L is the average number of letters per 100 words in the text, 
//        S is the average number of sentences per 100 words in the text.
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int count_word(char* s);

int count_letter(char* s);

int count_sentence(char* s);

int main(void)
{
    char* text = get_string("Input Text:  \n");
    printf("%i letters\n", count_letter(text));
    printf("%i words\n", count_word(text));
    printf("%i sentence\n", count_sentence(text));

    int index;

    float L = (float) 100 / count_word(text) * count_letter(text);
    printf("L: %.2f\n", L);
    float S = (float) 100 / count_word(text) * count_sentence(text);
    printf("S: %.2f\n", S);

    index = round((float) 0.0588 * L - 0.296 * S - 15.8);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else 
    {
        printf("Grade: %i\n", index);
    }
}

// helper functions
int sentence_to_grade(char* sentence)
{
    return 0;
}


int count_word(char* s)
{
    int word = 0;
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (!isspace(s[i]) && (i == 0 || isspace(s[i - 1])))
        {
            word++;
        }
    }
    return word;
}


int count_letter(char* s)
{
    int letter = 0;

    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (s[i] >= 65 && s[i]<= 90 || s[i] >= 97 && s[i] <= 122)
        {
            letter += 1;
        }
        else
        {
            letter += 0;
        }
    } 

    return letter;
}

int count_sentence(char* s)
{
    int sentence = 0;

    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (s[i] == '.' || s[i] == '!' || s[i] == ';' || s[i] == '?')
        {
            sentence += 1;
        }
    }
    
    return sentence;
}





// Your program should count the number of letters, words, and sentences in the text. 
// You may assume that a letter is any lowercase character from a to z or any uppercase character from A to Z, 
// any sequence of characters separated by spaces should count as a word, and that 
// any occurrence of a period, exclamation point, or question mark indicates the end of a sentence.