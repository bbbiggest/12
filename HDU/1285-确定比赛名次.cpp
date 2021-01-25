// 邻接表实现方法
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
const int MAX_V = 510;

vector<int> G[MAX_V];
int V, E;
int in[MAX_V]; // 记录顶点的入度

void toposort()
{
    for (int cnt = 0; cnt < V; ++cnt)
    {
        int i;
        for (i = 1; in[i] != 0; ++i) // 找到当前入度为0的最小序号
            ;
        if (cnt == 0) // 要注意这道题输出最后面没有空格
            cout << i;
        else
            cout << " " << i;
        in[i] = -1;
        for (int j = 0; j < G[i].size(); ++j) // 将相邻的顶点入度减1
            in[G[i][j]]--;
    }
    cout << "\n";
}

int main()
{
    while (cin >> V >> E)
    {
        memset(G, false, sizeof(G));
        memset(in, 0, sizeof(in));
        for (int i = 0; i < E; ++i) // 邻接表储存
        {
            int a, b;
            cin >> a >> b;
            G[a].push_back(b);
            in[b]++;
        }
        toposort();
    }
    return 0;
}


/*
// 邻接矩阵实现方法1：
#include <iostream>
#include <cstring>
using namespace std;
const int MAX_V = 510;

bool G[MAX_V][MAX_V];
int V, E;
int in[MAX_V];

void toposort()
{
    for (int cnt = 1; cnt <= V; ++cnt)
    {
        int i;
        for (i = 1; in[i] != 0; ++i)
            ;
        if (cnt == 1)
            cout << i;
        else
            cout << " " << i;
        in[i] = -1;
        for (int j = 1; j <= V; ++j)
        {
            if (G[i][j])
                in[j]--;
        }
    }
    cout << "\n";
}

int main()
{
    while (cin >> V >> E)
    {
        memset(G, 0, sizeof(G));
        memset(in, 0, sizeof(in));

        for (int i = 0; i < E; ++i)
        {
            int a, b;
            cin >> a >> b;
            if (G[a][b] == false)
            {
                G[a][b] = true;
                in[b]++;
            }
        }
        toposort();
    }
    return 0;
}
*/


/*
//邻接矩阵实现方法2：
#include <iostream>
#include <cstring>
using namespace std;
const int MAX_V = 510;

int G[MAX_V][MAX_V];
int V, E;
int in[MAX_V];

void toposort()
{
    for (int cnt = 1; cnt <= V; ++cnt)
    {
        int i;
        for (i = 1; in[i] != 0; ++i)
            ;
        if (cnt == 1)
            cout << i;
        else
            cout << " " << i;
        in[i] = -1;
        for (int j = 1; j <= V; ++j)
        {
            if (G[i][j])
                in[j] -= G[i][j];
        }
    }
    cout << "\n";
}

int main()
{
    while (cin >> V >> E)
    {
        memset(G, 0, sizeof(G));
        memset(in, 0, sizeof(in));

        for (int i = 0; i < E; ++i)
        {
            int a, b;
            cin >> a >> b;
            G[a][b]++;
            in[b]++;
        }
        toposort();
    }
    return 0;
}
*/
