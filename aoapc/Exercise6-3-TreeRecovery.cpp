// Tree Recovery, ULM 1997, UVa536
// aoapc - Exercise 6-3.
// https://vjudge.net/problem/UVA-536

#include <iostream>
#include <string>
using namespace std;
void build(int left, int right);
string pre, in;
int n = 0;

int main()
{
    while (cin >> pre >> in)
    {
        n = 0;
        build(0, pre.size() - 1);
        cout << "\n";
    }
    return 0;
}

void build(int left, int right)
{
    if (left > right)
        return;
    int root = in.find(pre[n]);
    n++;
    build(left, root - 1);
    build(root + 1, right);
    cout << in[root];
}
