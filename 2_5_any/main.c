#include <stdio.h>

#define MAXLENGTH 500

int any(char s1[MAXLENGTH], char s2[MAXLENGTH]);
int is_in(char c, char s[MAXLENGTH]);

int main()
{
    char s1[MAXLENGTH] = {0};
    char s2[MAXLENGTH] = {0};
    int i, c;

    for (i = 0; i < MAXLENGTH
            && (c = getchar()) != '\n';
            ++i)
    {
        s1[i] = c;
    }
    s1[i] = '\0';

    for (i = 0; i < MAXLENGTH
            && (c = getchar()) != EOF
            && c != '\n';
            ++i)
    {
        s2[i] = c;
    }
    s2[i] = '\0';

    int result = any(s1, s2);
    printf("%d\n", result);

    return 0;
}

int any(char s1[MAXLENGTH], char s2[MAXLENGTH])
{
    int i = 0;
    while (s1[i] != '\0')
    {
        if (is_in(s1[i], s2)) return i;
        ++i;
    }

    // fallback
    return -1;
}

int is_in(char c, char s[MAXLENGTH])
{
    int i = 0;
    while (s[i] != '\0')
    {
        if (c == s[i]) return 1;
        ++i;
    }

    // fallback
    return 0;
}
