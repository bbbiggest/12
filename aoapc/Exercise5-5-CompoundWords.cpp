// Compound Words, UVa10391
// aoapc - Exercise 5-5.
// https://vjudge.net/problem/UVA-10391

#include <iostream>
#include <string>
#include <set>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string w;
    set<string> words;
    while (cin >> w)
        words.insert(w);
    for (set<string>::const_iterator p = words.begin(); p != words.end(); ++p)
    {
        string temp = *p;
        for (int i = 1; i < temp.size() - 1; ++i)
        {
            if (words.find(temp.substr(0, i)) != words.end())
                if (words.find(temp.substr(i)) != words.end())
                {
                    cout << temp << "\n";
                    break;
                }
        }
    }
    return 0;
}
