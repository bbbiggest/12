#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        long long a,b;
        cin >> a >> b;
        long long sum;
        int x;
        sum = a>b?a-b:b-a;
        if (sum == 0)
            cout << "0" << endl;
        else
        {
            x = 1-!(sum%10);
            cout << sum/10+x << endl;
        }
    }
    return 0;
}

//https://codeforces.com/problemset/problem/1409/A
