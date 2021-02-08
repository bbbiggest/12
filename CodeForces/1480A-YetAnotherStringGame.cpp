#include <iostream>
#include <string>
using namespace std;
string s;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> s;
        int l = s.size();
        for (int i = 0; i < l; ++i)
        {
            if (!(i % 2))
            {
                if (s[i] == 'a')
                    cout << 'b';
                else
                    cout << 'a';
            }
            else
            {
                if (s[i] == 'z')
                    cout << 'y';
                else
                    cout << 'z';
            }
        }
        cout << "\n";
    }
    cout.flush();
    return 0;
}
