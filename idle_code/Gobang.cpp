#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;
const int N = 15;

int chessboard[N + 1][N + 1] = {0};
int whoseTurn = 0;

void initGame();
void printChessboard();
void playChess();
bool judge(int x, int y);

int main()
{
    initGame();
    while (1)
    {
        whoseTurn++;
        playChess();
    }
    return 0;
}

void initGame()
{
    cout << "Please input \'y\' to enter the game:\n";
    char c;
    cin >> c;
    if (c != 'y' && c != 'Y')
    {
        cout << "Bye!\n";
        system("pause");
        exit(0);
    }
    system("cls");
    printChessboard();
}

void printChessboard()
{
    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= N; j++)
        {
            if (i == 0)
                cout << setw(3) << j;
            else if (j == 0)
                cout << setw(3) << i;
            else if (chessboard[i][j] == 1)
                cout << "  O";
            else if (chessboard[i][j] == 2)
                cout << "  X";
            else
                cout << "  *";
        }
        cout << "\n";
    }
}

void playChess()
{
    if (whoseTurn % 2)
        cout << "Turn to player 0, please input the position:\n";
    else
        cout << "Turn to player X, please input the position:\n";
    int i, j;
    int k = 0;
    while (1)
    {
        cin >> i >> j;
        if (cin.good() == 0)
        {
            cout << "Please enter two numeric coordinates.\n";
            cin.clear();
            cin.sync();
            continue;
        }
        if (i < 1 || j < 1 || i > N || j > N)
        {
            cout << "The pieces are out of the board.\n";
            cout << "Please drop the chess again.\n";
            continue;
        }
        else
        {
            break;
        }
        if (chessboard[i][j] != 0)
        {
            cout << "This position has been occupied, please input the position again:\n";
            continue;
        }
    }
    if (whoseTurn % 2)
        chessboard[i][j] = 1;
    else
        chessboard[i][j] = 2;
    system("cls");
    printChessboard();
    if (judge(i, j))
    {
        if (whoseTurn % 2)
        {
            cout << "Winner is player 0!\nCongratulations!\n";
            system("pause");
            exit(0);
        }
        else
        {
            cout << "Winner is player X!\nCongratulations!\n";
            system("pause");
            exit(0);
        }
    }
}

bool judge(int x, int y)
{
    int t = 2 - whoseTurn % 2;
    const int step[4][2] = {{-1, 0}, {0, -1}, {1, 1}, {1, 0}};
    for (int i = 0; i < 4; ++i)
    {
        const int d[2] = {-1, 1};
        int count = 1;
        for (int j = 0; j < 2; ++j)
            for (int k = 1; k <= 4; ++k)
            {
                int row = x + k * d[j] * step[i][0];
                int col = y + k * d[j] * step[i][1];
                if (row >= 1 && row <= N &&
                    col >= 1 && col <= N &&
                    chessboard[x][y] == chessboard[row][col])
                    count += 1;
                else
                    break;
            }
        if (count >= 5)
            return true;
    }
    return false;
}
