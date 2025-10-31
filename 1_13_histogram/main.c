#include <stdio.h>

#define OUT 0
#define IN 1
#define MAXLENGTH 10
#define FLOATING_PLACEHOLDERS 2

int main()
{
    int lengths[MAXLENGTH] = {0};
    int state = OUT;
    int c, nc = 0;

    while ((c = getchar()) != EOF)
    {
        if (c != ' ' && c != '\n' && c != '\t')
        {
            if (state == OUT)
            {
                state = IN;
            }
            ++nc;
        }
        else
        {
            state = OUT;

            if (nc > 0 && nc < MAXLENGTH)
            {
                ++lengths[nc];
            }
            else if (nc >= MAXLENGTH)
            {
                ++lengths[0];
            }

            nc = 0;
        }
    }

    int longest = lengths[0] + FLOATING_PLACEHOLDERS;
    for (int i = 1; i < MAXLENGTH; ++i)
    {
        if (lengths[i] + FLOATING_PLACEHOLDERS > longest)
            longest = (lengths[i] + FLOATING_PLACEHOLDERS);
    }

    for (int i = 0; i < MAXLENGTH; ++i)
    {
        printf("%d: ", i);

        for (int j = 0; j < lengths[i]; ++j)
        {
            putchar('#');
        }
        for (int j = 0; j < longest - lengths[i]; ++j)
        {
            putchar('-');
        }

        putchar('\n');
    }
}
