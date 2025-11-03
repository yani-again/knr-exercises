#include <stdio.h>

#define MAXLENGTH 1000

void reverse(char line[], int length);

int main()
{
    char line[MAXLENGTH] = {0};
    int c, length = 0;

    while ((c = getchar()) != EOF)
    {
        if (length == MAXLENGTH)
        {
            reverse(line, length - 1);

            length = 1;
            line[0] = c;
            continue;
        }

        if (c != '\n')
        {
            line[length] = c;
        }
        else
        {
            if (length == 0)
            {
                putchar('\n');
                continue;
            }

            reverse(line, length);
            
            length = 0;
            continue;
        }

        ++length;
    }
}

void reverse(char line[], int length)
{
    while (length >= 0)
    {
        putchar(line[length]);
        --length;
    }
    putchar('\n');

    return;
}
