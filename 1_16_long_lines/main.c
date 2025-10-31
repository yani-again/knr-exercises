#include <stdio.h>

#define THRESHOLD 30
#define MAXLENGTH 1000

void printLine(char line[MAXLENGTH]);

int main()
{
    char line[MAXLENGTH] = {0};
    int c, i;

    for (i = 0; i < MAXLENGTH
            && ((c = getchar()) != EOF);
            ++i)
    {
        line[i] = c;
        if (c == '\n')
        {
            if (i < (MAXLENGTH - 1))
            {
                line[i + 1] = '\0';
            }
            else
            {
                line[i - 1] = '\n';
                line[i] = '\0';
            }

            if (i >= THRESHOLD) printLine(line);
            i = -1;
        }
    }
}

void printLine(char line[MAXLENGTH])
{
    int i = 0;
    while (line[i] != '\0')
    {
        putchar(line[i]);
        ++i;
    }
    return;
}
