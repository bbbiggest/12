// P4822 - 冻结
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;
using P = pair<int, int>;
const int INF = 0x3fffffff;
const int MAX_K = 50 + 1;
const int MAX_V = 50 * MAX_K + 10;

struct edge
{
    int to, cost;
    edge() {}
    edge(int _to, int _cost) : to(_to), cost(_cost) {}
};

int V;
vector<edge> G[MAX_V];
int d[MAX_V];

void dijkstra(int s)
{
    priority_queue<P, vector<P>, greater<P> > que;
    fill(d, d + V, INF);
    d[s] = 0;
    que.push(P(0, s));

    while (!que.empty())
    {
        P p = que.top();
        que.pop();
        int v = p.second;
        if (d[v] < p.first)
            continue;
        for (int i = 0; i < G[v].size(); ++i)
        {
            edge e = G[v][i];
            if (d[e.to] > d[v] + e.cost)
            {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}

void add_edge(int from, int to, int cost)
{
    G[from].push_back(edge(to, cost));
    G[to].push_back(edge(from, cost));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k;
    while (cin >> n >> m >> k)
    {
        V = n * (k + 1) + 1;
        int s = 1, t = n;
        for (int i = 0; i <= V; ++i)
            G[i].clear();

        for (int i = 0; i < m; ++i)
        {
            int a, b, c;
            cin >> a >> b >> c;
            add_edge(a, b, c);
            for (int j = 0; j < k; ++j)
            {
                add_edge(a + (j + 1) * n, b + (j + 1) * n, c);
                G[a + j * n].push_back(edge(b + (j + 1) * n, c / 2));
                G[b + j * n].push_back(edge(a + (j + 1) * n, c / 2));
            }
        }
        for (int i = 0; i < k; ++i)
            G[t + i * n].push_back(edge(t + (i + 1) * n, 0));
        dijkstra(s);
        cout << d[t + n * k] << '\n';
    }
    cout.flush();
    return 0;
}