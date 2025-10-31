#include <stdio.h>

#define PADDING 2
#define CHAR_LIMIT 94
#define LOWER_BOUND 33
#define UPPER_BOUND 126

int main()
{
    int frequencies[CHAR_LIMIT] = {0};
    int c;

    while ((c = getchar()) != EOF)
    {
        // only consider characters from 33-126 ASCII
        if (c >=LOWER_BOUND && c <= UPPER_BOUND)
        {
            ++frequencies[c-LOWER_BOUND];
        }
    }

    int longest = frequencies[0];
    for (int i = 1; i < CHAR_LIMIT; ++i)
    {
        if ((frequencies[i] + PADDING)> longest)
            longest = frequencies[i] + PADDING;
    }

    for (int i = 0; i < CHAR_LIMIT; ++i)
    {
        printf("%c: ", i + LOWER_BOUND);

        for (int j = 0; j < frequencies[i]; ++j)
        {
            putchar('#');
        }
        for (int j = 0; j < longest - frequencies[i]; ++j)
        {
            putchar('-');
        }

        putchar('\n');
    }

    return 0;
}
