#include <stdio.h>

/* This program takes a user input where \t (tab) characters
 may be present, and replaces them with blanks until the
 next tabstop. */

#define TABSTOP 2
#define MAXLEN 100

int getLine(char msg[]);
void replaceTabs(char msg[], int length);

int main()
{
    int length = 0;
    char msg[MAXLEN];

    length = getLine(msg);

    replaceTabs(msg, length);
}

int getLine(char msg[])
{
    int current_char;
    int i;

    for (i = 0; i < MAXLEN - 1 
            && (current_char = getchar()) != EOF
            && current_char != '\n';
            ++i)
    {
        msg[i] = current_char;
    }

    // if i < MAXLEN, we can safely set msg[i] to be \n
    // Necessary as for loop terminates without adding \n
    if (current_char == '\n')
    {
        msg[i] = '\n';
        ++i;
    }
    // add null-terminator in any case
    msg[i] = '\0';

    return i + 1;
}

void replaceTabs(char msg[], int length)
{
    for (int i = 0; i < length; ++i)
    {
        if (msg[i] == '\t')
        {
            for (int j = 0; j < TABSTOP; ++j)
            {
                printf(" ");
            }
        }
        else putchar(msg[i]);
    }
    printf(" ");
}
