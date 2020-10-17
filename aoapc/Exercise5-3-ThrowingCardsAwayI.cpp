// Throwing cards away I, UVa19035
// aoapc - Exercise 5-3.
// https://vjudge.net/problem/UVA-10935

#include <iostream>
#include <queue>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    while (cin >> n && n)
    {
        queue<int> card;
        for (int i = 1; i <= n; ++i)
            card.push(i);
        cout << "Discarded cards:";
        int s = card.size();
        while (s > 1)
        {
            cout << " " << card.front() << (s == 2 ? "" : ",");
            card.pop();
            card.push(card.front());
            card.pop();
            s = card.size();
        }
        cout << "\n" << "Remaining card: " << card.front() << "\n";
    }
    return 0;
}
