#include <iostream>
#include <vector>
#include <string>
using namespace std;

// class Solution     // OG Answer

// {

// public:
//     bool isValidSudoku(vector<vector<char>> &board)

//     {

//         int used1[9][9] = {0}, used2[9][9] = {0}, used3[9][9] = {0};

//         for (int i = 0; i < board.size(); ++i)

//             for (int j = 0; j < board[i].size(); ++j)

//                 if (board[i][j] != '.')

//                 {

//                     int num = board[i][j] - '0' - 1, k = i / 3 * 3 + j / 3;

//                     if (used1[i][num] || used2[j][num] || used3[k][num])

//                         return false;

//                     used1[i][num] = used2[j][num] = used3[k][num] = 1;
//                 }

//         return true;
//     }
// };
class Solution
{
public:
    bool checkSquareValid(int i, int end, int j, int end2, vector<vector<char>> board)
    {
        vector<char> temp;
        for (int x = i; x <= end; x++)
        {
            for (int y = j; y <= end2; y++)
            {
                if (board[x][y] != '.')
                {
                    for (int m = 0; m < temp.size(); m++)
                    {
                        if (board[x][y] == temp[m])
                            return false;
                    }
                    temp.push_back(board[x][y]);
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; i++)
        {

            vector<char> row;
            vector<char> col;
            for (int j = 0; j < 9; j++)
            {
                // check col
                if (board[j][i] != '.')
                {
                    for (int x = 0; x < col.size(); x++)
                    {
                        if (board[j][i] == col[x])
                            return false;
                    }
                    col.push_back(board[j][i]);
                }

                // check row
                if (board[i][j] != '.')
                {
                    for (int x = 0; x < row.size(); x++)
                    {
                        if (board[i][j] == row[x])
                            return false;
                    }
                    row.push_back(board[i][j]);
                }
            }
        }
        if (!checkSquareValid(0, 2, 0, 2, board))
            return false;
        if (!checkSquareValid(3, 5, 0, 2, board))
            return false;
        if (!checkSquareValid(6, 8, 0, 2, board))
            return false;
        if (!checkSquareValid(0, 2, 3, 5, board))
            return false;
        if (!checkSquareValid(0, 2, 6, 8, board))
            return false;
        if (!checkSquareValid(3, 5, 3, 5, board))
            return false;
        if (!checkSquareValid(3, 5, 6, 8, board))
            return false;
        if (!checkSquareValid(6, 8, 3, 5, board))
            return false;
        if (!checkSquareValid(6, 8, 6, 8, board))
            return false;

        return true;
    }
};

int main()
{
    Solution s;
    vector<vector<char>> board = {
        {'5', '3', '5', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    bool ans = s.isValidSudoku(board);
    cout << ans << endl;

    return 0;
}