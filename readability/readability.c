#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    int letters, words, sentences, index;
    float L, S;
    string text = get_string("Text: ");

    letters = count_letters(text);
    words = count_words(text);
    sentences = count_sentences(text);
    L = (float) letters / words * 100;
    S = (float) sentences / words * 100;
    index = round(0.0588 * L - 0.296 * S - 15.8);

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
        printf("Grade %d\n", index);
    }

}

int count_letters(string text)
{
    int count = 0;
    for (int i = 0, t = strlen(text); i < t; i++)
    {
        if (isalpha(text[i]))
        {
            count = count + 1;
        }
    }
    return count;
}

int count_words(string text)
{
    int count = 0;
    for (int i = 0, t = strlen(text); i < t; i++)
    {
        if (isspace(text[i]))
        {
            count = count + 1;
        }
    }
    count = count + 1;
    return count;
}

int count_sentences(string text)
{
    int count = 0;
    for (int i = 0, t = strlen(text); i < t; i++)
    {
        if (text[i] == '?' || text[i] == '!' || text[i] == '.')
        {
            count = count + 1;
        }
    }
    return count;
}