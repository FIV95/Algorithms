#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool exist(char **board, int boardSize, int boardColSize, char *word);
bool checkLeftRight(char **board, int *i, int *j, int boardColSize, char targetChar);
bool checkUpDown(char **board, int *i, int *j, int boardSize, char targetChar);

int main()
{
    char boardTest[3][4] = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}};
    int boardSizeTest = 3;
    int boardColSize = 4;
    char wordTest[] = "ABCCE";

    char **board = malloc(boardSizeTest * sizeof(char *));
    for (int i = 0; i < boardSizeTest; i++)
    {
        board[i] = malloc(boardColSize * sizeof(char));
        for (int j = 0; j < boardColSize; j++)
        {
            board[i][j] = boardTest[i][j];
        }
    }

    bool results = exist(board, boardSizeTest, boardColSize, wordTest);
    printf("%i", results);
}

bool exist(char **board, int boardSize, int boardColSize, char *word)
{
    char currentChar;
    int matchedChars = 0;

    for (int i = 0; i < boardSize; i++)
    {
        if (matchedChars == strlen(word))
        {
            break;
        }
        for (int j = 0; j < boardColSize; j++)
        {
            if (matchedChars == strlen(word))
            {
                break;
            }
            currentChar = board[i][j];
            printf("%c", word[0]);

            if (currentChar == word[0])
            {
                matchedChars++;
            }

            while (matchedChars != strlen(word))
            {
                int new_i = i, new_j = j;
                if (checkLeftRight(board, &new_i, &new_j, boardColSize, word[matchedChars]) ||
                    checkUpDown(board, &new_i, &new_j, boardSize, word[matchedChars]))
                {
                    matchedChars++;
                    i = new_i;
                    j = new_j;
                    currentChar = board[i][j];
                }
                else
                {
                    break;
                }
            }
        }
    }
    if (matchedChars == strlen(word))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool checkLeftRight(char **board, int *i, int *j, int boardColSize, char targetChar)
{
    // checks to the left
    if (*j > 0 && board[*i][*j-1] == targetChar)
    {
        (*j)--;
        return true;
    }

    // checks to the right
    if (*j < boardColSize - 1 && board[*i][*j + 1] == targetChar)
    {
        (*j)++;
        return true;
    }
    return false;
}

bool checkUpDown(char **board, int *i, int *j, int boardSize, char targetChar)
{
    // checks up
    if (*i > boardSize && board[*i - 1][*j] == targetChar)
    {
        (*i)--;
    }

    // checks down
    if (*i < boardSize -1 && board[*i + 1][*j] == targetChar)
    {
        (*i)++;
        return true;
    }
    return false;
}
