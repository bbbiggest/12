#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        long long a, b, c;
        cin >> a >> b >> c;
        cout << a + b + c - 1 << endl;
    }
    return 0;
}

//https://codeforces.com/problemset/problem/1422/A
