#include <stdio.h>

#define MAXLENGTH 1000

void squeeze(char in[MAXLENGTH], char comparison[MAXLENGTH]);
int is_in(char c, char list[MAXLENGTH]);

int main()
{
    char s[MAXLENGTH] = {0};
    char compare[MAXLENGTH] = {0};
    int i, c;

    for (i = 0; i < MAXLENGTH
            && (c = getchar()) != '\n';
            ++i)
    {
        s[i] = c;
    }
    s[i] = '\0';

    for (i = 0; i < MAXLENGTH
            && (c = getchar()) != EOF;
            ++i)
    {
        compare[i] = c;
    }
    compare[i] = '\0';

    squeeze(s, compare);
}

void squeeze(char in[MAXLENGTH], char comparison[MAXLENGTH])
{
    int i = 0;
    while (in[i] != '\0')
    {
        if (!is_in(in[i], comparison))
        {
            printf("%c", in[i]);
        }
        ++i;
    }

    putchar('\n');

    return;
}

int is_in(char c, char list[MAXLENGTH])
{
    int i = 0;
    while (list[i] != '\n')
    {
        if (c == list[i]) return 1;
        ++i;
    }

    // fallback
    return 0;
}
