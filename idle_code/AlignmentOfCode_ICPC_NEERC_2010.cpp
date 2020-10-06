// Alignment of Code, ACM/ICPC NEERC 2010, UVa1593
// aoapc - Exercise 5-1.
// https://vjudge.net/problem/UVA-1593

#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxrow = 1000 + 10;
const int maxcol = 180 + 10;
string str[maxrow][maxcol];
string s, tem;
int len[maxcol], colnum[maxrow];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    memset(len, 0, sizeof(len));
    int rows = 0;
    while (getline(cin, s))
    {
        int cols = 0;
        stringstream ss(s);
        while (ss >> tem)
        {
            str[rows][cols] = tem;
            len[cols] = max(len[cols], (int)tem.size());
            cols++;
        }
        colnum[rows] = cols;
        rows++;
    }
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < colnum[i]; ++j)
        {
            cout << str[i][j];
            if (j == colnum[i] - 1)
                break;
            int leng = len[j] + 1 - str[i][j].size();
            for (int k = 0; k < leng; ++k)
                cout << " ";
        }
        cout << "\n";
    }
    return 0;
}
