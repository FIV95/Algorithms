#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool exist(char **board, int boardSize, int boardColSize, char *word);
bool dfs(char **board, int numberOfArrays, int numberOfElements, int i, int j, char *target, int targetIndex );


bool exist(char **board, int boardSize, int boardColSize, char *word)
{
    // this loop passes through each array in the board
    for (int i = 0; i < boardSize; i++)
    {
        // this second loop passes through the each character in each array
        for (int j = 0; j < boardColSize; j++)
        {
            // we want to run our function against each character
            // were looking for the first character in word index[0]
            if (dfs(board, boardSize, boardColSize, i, j , word, 0))
            {
                return true;
            }
        }
    }
    return false;
}

bool dfs(char **board, int numberOfArrays, int numberOfElements, int i, int j, char *target, int targetIndex )
{
    if (targetIndex == strlen(target))
    {
        return true;
    }

    // if the number of arrays is less than zero
    // OR I == numberOfArrays ||
    // OR J - number of elements in an array is less than 0 ||
    // OR j is == equal to the numberOfElements in each array ||
    // OR # MOST IMPORTANTLY #
    // OR if the board's position at [i] and [j] != the target at the TargetIndex
    if (i < 0 || i == numberOfArrays || j < 0 || j == numberOfElements || board[i][j] != target[targetIndex]){
        return false;
    }

    char temp = board[i][j];
    board[i][j] = '*'; //

    int rowChecks[] = {-1, 1, 0, 0};
    int columnChecks[] = {0, 0, -1, 1};

    for (int c = 0; c < 4; c++)
    {
        if (dfs(board, numberOfArrays, numberOfElements, i + rowChecks[c], j + columnChecks[c], target, target[targetIndex + 1]))
        {
            return true;
        }
    }
    board[i][j] = temp;
    return false;
}
