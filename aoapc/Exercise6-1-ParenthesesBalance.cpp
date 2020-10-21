// Parentheses Balance, UVa673
// aoapc - Exercise 6-1.
// https://vjudge.net/problem/UVA-673

#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main()
{
    int t;
    cin >> t;
    getchar();
    while (t--)
    {
        string s;
        getline(cin, s);
        int n = s.size();
        if (n == 0)
        {
            cout << "Yes\n";
            continue;
        }
        stack<char> b;
        bool flag = true;
        for (int i = 0; i < n; ++i)
        {
            if (s[i] == '(' || s[i] == '[')
                b.push(s[i]);
            else if (s[i] == ')' || s[i] == ']')
            {
                if (!b.empty())
                {
                    if (s[i] == ')' && b.top() == '(' || s[i] == ']' && b.top() == '[')
                        b.pop();
                    else
                    {
                        flag = false;
                        break;
                    }
                }
                else
                {
                    flag = false;
                    break;
                }
            }
        }
        if (flag && b.empty())
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}
