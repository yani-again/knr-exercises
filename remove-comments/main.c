#include <stdio.h>

/* Program to remove all comments from C programs */

#define MAXLEN 100
#define MAXLINES 50

int getLine(char msg[MAXLINES][MAXLEN]);
void findSingleComments(char msg[MAXLINES][MAXLEN], int length);
void deleteRegularComment(char msg[MAXLINES][MAXLEN], int row, int column);
void findMultiComments(char msg[MAXLINES][MAXLEN], int length);
void deleteMultiComment(char msg[MAXLINES][MAXLEN], int from_row, 
        int from_column, int to_row, int to_column);

int main()
{
    char msg[MAXLINES][MAXLEN];
    int length;

    length = getLine(msg);
    findSingleComments(msg, length);
    findMultiComments(msg, length);

    for (int i = 0; i < length; ++i)
    {
        for (int j = 0; j < MAXLEN; ++j)
        {
            if (msg[i][j] == '\0')
            {
                break;
            }
            putchar(msg[i][j]);
        }
    }
}

int getLine(char msg[MAXLINES][MAXLEN])
{
    int current_char;
    int current_line = 0;
    int i;

    while (1)
    {
        for (i = 0; i < MAXLEN - 1
                && (current_char = getchar()) != EOF
                && current_char != '\n';
                ++i)
        {
            msg[current_line][i] = current_char;
        }

        // break loop if special character is found
        if (msg[current_line][i - 1] == '#')
        {
            msg[current_line][i - 1] = '\n';
            return current_line + 1;
        }
        else if (current_char == '\n')
        {
            msg[current_line][i] = '\n';
            ++i;
        }
        msg[current_line][i] = '\0';
        ++current_line;
    }
}

void findSingleComments(char msg[MAXLINES][MAXLEN], int length)
{
    char previous_char = ' ';
    int in_string = 0;

    for (int i = 0; i < length; ++i)
    {
        for (int j = 0; j < MAXLEN; ++j)
        {
            // check for double '/' and make sure we're not in a string
            if (msg[i][j] == '/' && previous_char == '/' && in_string == 0)
            {
                deleteRegularComment(msg, i, j - 1);
                break; // no need to continue with this line
            }
            // entering string
            else if (msg[i][j] == '"' && in_string == 0)
            {
                in_string = 1;
            }
            // exiting string
            else if (msg[i][j] == '"' && in_string == 1)
            {
                in_string = 0;
            }
            /* necessary to keep track of strings as there can be
             * comments that are at the end of a line */
            
            previous_char = msg[i][j];
        }
    }
}

void deleteRegularComment(char msg[MAXLINES][MAXLEN], int row, int column)
{
    char current_char;
    int column_copy = column; // for replacing the removed comment with a '\n'

    while (msg[row][column] != '\0')
    {
        msg[row][column] = '\0';
        ++column;
    }

    msg[row][column_copy] = '\n';
}

void findMultiComments(char msg[MAXLINES][MAXLEN], int length)
{
    char previous_char = ' ';
    int in_string = 0;
    int in_comment = 0;

    int from_row;
    int from_column;
    int to_row;
    int to_column;

    for (int i = 0; i < length; ++i)
    {
        for (int j = 0; j < MAXLEN; ++j)
        {
            // check for '/*' and make sure we're not in a string
            if (msg[i][j] == '*' && previous_char == '/'
                    && in_string == 0 && in_comment == 0)
            {
                from_row = i;
                from_column = j - 1;
                in_comment = 1;
            }
            // ending pattern & in comment
            else if (msg[i][j] == '/' && previous_char == '*' && in_comment)
            {
                to_row = i;
                to_column = j;

                deleteMultiComment(msg, from_row, from_column, to_row, to_column);
                break;
            }
            // entering string (disallowed if in comment)
            else if (msg[i][j] == '"' && in_string == 0 && in_comment == 0)
            {
                in_string = 1;
            }
            // exiting string - taking into account escape sequences
            else if (msg[i][j] == '"' && in_string == 1)
            {
                in_string = 0;
            }
            /* necessary to keep track of strings as there can be
             * comments that are at the end of a line */
            
            previous_char = msg[i][j];
        }
    }
}

void deleteMultiComment(char msg[MAXLINES][MAXLEN], int from_row, 
        int from_column, int to_row, int to_column)
{
    int starting_row = from_row;
    int starting_column = from_column; // keep track to add '\n'
    
    /* keep going until past the end point - it's more
       readable than while(1) */
    while (from_row <= to_row)
    {
        while (msg[from_row][from_column] != '\0'
                && from_row != (to_row + 1)
                && from_column != (to_column + 1))
        {
            /* TODO: improve this logic. Currently, it replaces
               removed characters with spaces and it can get ugly */
            if (from_row == to_row) msg[from_row][from_column] = ' ';
            else msg[from_row][from_column] = '\0';
            ++from_column;
        }
        
        // reset to start of next line
        from_column = 0; 
        ++from_row;
    }

    msg[starting_row][starting_column] = '\n';
}
