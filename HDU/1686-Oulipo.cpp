#include <iostream>
#include <cstring>
using namespace std;
const int MAX_T = 1000000;
char WORD[MAX_T + 10];
char TEST[MAX_T + 10];
int NN[MAX_T];

void buildNext(char *ptr, int plen)
{
    int i = 0, j = -1;
    NN[0] = -1;
    while (i < plen)
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
    int i = 0, plen = strlen(ptr);
    int j = 0, slen = strlen(str);
    buildNext(ptr, plen);
    while (i < plen && j < slen)
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
    int t;
    cin >> t;
    while (t--)
    {
        cin >> WORD >> TEST;
        cout << KMP(WORD, TEST) << endl;
    }
    return 0;
}
