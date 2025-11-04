#include <stdio.h>

#define MAXLENGTH 1000

void htoi(char s[], int length);
int mkhex(char c);

int main()
{
    int i, c;
    char s[MAXLENGTH] = {0};

    for (i = 0; i < MAXLENGTH
            && (c = getchar()) != EOF
            && c != '\0';
            ++i
            )
    {
        s[i] = c;
    }

    s[i] = '\0';

    htoi(s, i);
}

void htoi(char s[], int length)
{
    int i = 2;
    char last_char;

    do
    {
        if (s[i] == '\0' || s[i + 1] == '\0') break;

        printf("%c", (mkhex(s[i]) * 16) + mkhex(s[i + 1]));

        i+=2;
    } while (1);

    putchar('\n');

    return;
}

int mkhex(char c)
{
    /* function to convert hex (char type) to int */

    if (c >= '0' && c <= '9') return c - '0';
    else if (c >= 'a' && c <= 'f') return c - 'a' + 10;
    else if (c >= 'A' && c <= 'F') return c - 'A' + 10;
    // 0 = '\0'
    else if (c == 0) return 0;
    // 120 = 'x' from the start of the hex string '0x'
    else return 120;
}
