#include <stdio.h>

#define MAXLENGTH 1000
#define OUT_CONTENT 0
#define IN_CONTENT 1

void print_line(char line[MAXLENGTH], int last_char);

int main()
{
    char line[MAXLENGTH] = {0};
    int i, c, last_char, char_count = 0;
    int status = OUT_CONTENT;

    for (i = 0; (i < MAXLENGTH)
            && ((c = getchar()) != EOF);
            ++i)
    {
        if (status == IN_CONTENT)
        {
            line[char_count] = c;
            ++char_count;
        }
        // only start counting chars from when content starts
        // checking for \n means we avoid printing empty lines by default      
        else if (status == OUT_CONTENT && (c != '\t' && c != ' ' && c != '\n'))
        {
            status = IN_CONTENT;
            line[char_count] = c;
            ++char_count;
        }

        // keep track of last non-whitespace char
        if (status == IN_CONTENT && (c != '\t' && c != ' ' && c != '\n'))
        {
            last_char = char_count - 1;
        }

        // print line once at the end
        if (c == '\n')
        {
            if (status == IN_CONTENT)
            {
                if (char_count < (MAXLENGTH - 1))
                {
                    line[char_count + 1] = '\0';
                }
                else
                {
                    line[MAXLENGTH - 1] = '\0';
                }

                print_line(line, last_char);
            }

            // reset for next loop
            i = -1;
            status = OUT_CONTENT;
            last_char = char_count = 0;
        }
    }
}

void print_line(char line[MAXLENGTH], int last_char)
{
    int i = 0;
    while (line[i] != '\0' && i <= last_char)
    {
        putchar(line[i]);
        ++i;
    }
    putchar('\n');

    return;
}
