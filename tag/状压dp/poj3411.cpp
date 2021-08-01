#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
const int MAX_N = 11;
using namespace std;

class Road
{
public:
    int a, b, c, P, R;

    Road(int a, int b, int c, int P, int R) : a(a), b(b), c(c), P(P), R(R)
    {
    }
};

class State
{
public:
    int current, cost, S;
    State(int current, int cost, int S) : current(current), cost(cost), S(S) {}
    bool operator>(const State &other) const
    {
        return cost > other.cost;
    }
};

vector<Road> edge[MAX_N];
bool visited[MAX_N][1 << MAX_N];

int main()
{
    int N, m;
    cin >> N >> m;
    for (int i = 0; i < m; ++i)
    {
        int a, b, c, P, R;
        cin >> a >> b >> c >> P >> R;
        edge[a].push_back(Road(a, b, c, P, R));
    }
    priority_queue<State, vector<State>, greater<State>> que;
    que.push(State(1, 0, 1 << 1));
    memset(visited, 0, sizeof(visited));
    State result(-1, -1, -1);
    while (!que.empty())
    {
        State p = que.top();
        que.pop();
        if (visited[p.current][p.S])
            continue;

        visited[p.current][p.S] = true;
        if (p.current == N)
        {
            result = p;
            break;
        }
        for (vector<Road>::iterator it = edge[p.current].begin(); it != edge[p.current].end(); ++it)
        {
            Road e = *it;
            int cost = p.cost;
            if (p.S & (1 << e.c))
            {
                cost += min(e.P, e.R);
            }
            else
            {
                cost += e.R;
            }
            que.push(State(e.b, cost, p.S | (1 << e.b)));
        }
    }

    if (result.current == -1)
        cout << "impossible\n";
    else
        cout << result.cost << '\n';
    return 0;
}