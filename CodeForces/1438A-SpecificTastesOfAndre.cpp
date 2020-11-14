#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << "1";
        for (int i = 1; i < n; ++i)
            cout << " 1";
        cout << "\n";
    }
    return 0;
}
