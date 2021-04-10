#include <iostream>
#include <cstring>
using namespace std;
const int MAX_N = 1000000;
char WORD[MAX_N + 10];
char TEST[MAX_N + 10];
int NN[MAX_N];

void buildNext(char *ptr, int plen)
{
    NN[0] = -1;
    for (int i = 0, j = -1; i < plen;)
    {
        if (j < 0 || ptr[i] == ptr[j])
        {
            i++;
            j++;
            NN[i] = (ptr[i] != ptr[j]) ? j : NN[j];
        }
        else
            j = NN[j];
    }
}

int KMP(char *ptr, char *str)
{
    int cnt = 0;
    int plen = strlen(ptr);
    buildNext(ptr, plen);
    for (int i = 0, j = 0; i < plen && str[j];)
    {
        if (i < 0 || ptr[i] == str[j])
        {
            i++;
            j++;
        }
        else
            i = NN[i];
        if (i == plen)
        {
            cnt++;
            i = NN[i];
        }
    }
    return cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> WORD >> TEST;
        cout << KMP(WORD, TEST) << endl;
    }
    cout.flush();
    return 0;
}