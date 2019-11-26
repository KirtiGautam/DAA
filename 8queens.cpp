#include <iostream>
using namespace std;

bool isSafe(int board[8][8], int row, int col)
{
    int i, j;

    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    for (i = row, j = col; j >= 0 && i < 8; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

bool solveNQUtil(int board[8][8], int col)
{
    if (col >= 8)
        return true;

    for (int i = 0; i < 8; i++)
    {
        if (isSafe(board, i, col))
        {
            board[i][col] = 1;

            if (solveNQUtil(board, col + 1))
                return true;

            board[i][col] = 0;
        }
    }

    return false;
}

int main()
{
    cout << "Solution to the problem of 8 queen is \n(1 represents the queen position):\n";
    int board[8][8];
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
            board[i][j] = 0;
    }

    if (!solveNQUtil(board, 0))
        cout << "Cannot find a solution";

    for (int i = 0; i < 8; i++)
    {
        cout << "\t";
        for (int j = 0; j < 8; j++)
            cout << board[i][j] << " ";
        cout << "\n";
    }
    return 0;
}