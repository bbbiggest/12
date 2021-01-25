#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
const int MAX_N = 30000;
int n, m;
vector<int> G[MAX_N + 10];
int in[MAX_N + 10];
vector<int> topo;

bool toposort()
{
    priority_queue<int> que;
    for (int i = 1; i <= n; ++i)
        if (in[i] == 0)
            que.push(i);

    while (!que.empty())
    {
        int u = que.top();
        que.pop();
        topo.push_back(u);
        for (int i = 0; i < G[u].size(); ++i)
        {
            int vv = G[u][i];
            if (--in[vv] == 0)
            {
                que.push(vv);
            }
        }
    }
    if (topo.size() != n)
        return false;
    return true;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &m);
        memset(in, 0, sizeof(in));
        for (int i = 0; i <= n; ++i)
            G[i].clear();
        topo.clear();
        for (int i = 0; i < m; ++i)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            G[b].push_back(a);
            in[a]++;
        }
        if (toposort())
        {
            for (int i = n - 1; i >= 0; --i)
            {
                if (i != n - 1)
                    printf(" ");
                printf("%d", topo[i]);
            }
            printf("\n");
        }
    }
    return 0;
}
