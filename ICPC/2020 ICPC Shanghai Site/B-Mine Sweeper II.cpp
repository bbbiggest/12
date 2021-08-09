// 2020 ICPC Shanghai Site - B. Mine Sweeper II
#include <iostream>
using namespace std;
const int MAX_N = 1010;
char A[MAX_N][MAX_N], B[MAX_N][MAX_N];

int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        for (int i = 0; i < n; ++i)
            cin >> A[i];
        int cnt = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> B[i];
            for (int j = 0; j < m; ++j)
                if (A[i][j] != B[i][j])
                    cnt++;
        }
        if (cnt <= n * m / 2)
        {
            for (int i = 0; i < n; ++i)
                cout << A[i] << "\n";
            continue;
        }
        cnt = 0;
        // 将A中的'X'和'.'互换，总雷数不变
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
            {
                if (A[i][j] == 'X')
                    A[i][j] = '.';
                else if (A[i][j] == '.')
                    A[i][j] = 'X';
                if (A[i][j] != B[i][j])
                    cnt++;
            }
        if (cnt <= n * m / 2)
        {
            for (int i = 0; i < n; ++i)
                cout << A[i] << "\n";
            continue;
        }
        cout << "-1\n";
    }
    return 0;
}