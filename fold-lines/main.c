#include <stdio.h>

/* This program turns long lines into shorter ones by
 * cutting each line off on/before a set amout of characters */

#define CUTOFF 8
#define MAXLEN 100

int getLine(char msg[]);
void foldLine(char msg[], int length);
void printLine(char msg[], int length);

int main()
{
    char msg[MAXLEN];
    int length;

    length = getLine(msg);

    foldLine(msg, length);
    printLine(msg, length);
}

int getLine(char msg[])
{
    int i;
    int length = 0;
    char current_char;

    for (i = 0; i < MAXLEN - 1
            && (current_char = getchar()) != EOF
            && current_char != '\n';
            ++i)
    {
        msg[i] = current_char;
    }

    if (current_char == '\n')
    {
        msg[i] = '\n';
        ++i;
    }
    msg[i] = '\0';

    return i + 1;
}

void foldLine(char msg[], int length)
{
    int cutoff_tracker = 0;
    int latest_space;

    for (int i = 0; i < length; ++i)
    {
        if (msg[i] == ' ') latest_space = i;

        ++cutoff_tracker;
        if (cutoff_tracker == CUTOFF)
        {
            if ((i - latest_space) >= 7)
            {
                --cutoff_tracker;
                continue;
            }

            if (msg[i] != ' ') i = latest_space;
            msg[i] = '\n';
            cutoff_tracker = 0;
        }
    }
}

void printLine(char msg[], int length)
{
    for (int i = 0; i < length; ++i)
    {
        putchar(msg[i]);
    }
}
