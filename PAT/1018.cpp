#include <bits/stdc++.h>
using namespace std;
int c, n, s, m;
vector<vector<pair<int, int>>> G(501);
vector<vector<int>> parents(501);
vector<int> bikes(501);
vector<vector<int>> path;
vector<int> path_tmp;
void dfs(int u)
{
    path_tmp.push_back(u);
    if (u == 0)
    {
        auto p = path_tmp;
        reverse(p.begin(), p.end());
        path.push_back(p);
    }
    else
    {
        for (int pre : parents[u])
            dfs(pre);
    }
    path_tmp.pop_back();
}
int cal(const vector<int> &p)
{
    int ret = c/2*(p.size()-1);
    for (const auto &i : p)
    {
        ret -= bikes[i];
    }
    return ret;
}
void solve()
{
    cin >> c >> n >> s >> m;

    for (int i = 1; i <= n; i++)
        cin >> bikes[i];
    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].emplace_back(v, w);
        G[v].emplace_back(u, w);
    }
    vector<int> dis(n + 1, INT_MAX);
    dis[0] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});
    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dis[u])
            continue;
        for (auto [v, w] : G[u])
        {
            if (dis[v] > d + w)
            {
                dis[v] = d + w;
                pq.push({dis[v], v});
                parents[v].clear();
                parents[v].emplace_back(u);
                pq.emplace(dis[v], v);
            }
            else if (dis[v] == d + w)
            {
                parents[v].emplace_back(u);
            }
        }
    }
    dfs(s);
    int ans = 0, minb = INT_MAX;
    for (int i = 0; i < path.size(); i++)
    {
        int tmp = cal(path[i]);
        if (abs(tmp) < abs(minb))
        {
            ans = i;
            minb = tmp;
        }
    }
    if(minb<0)
    {
        cout<<"0 ";
        for (int i = 0; i < path[ans].size(); i++)
        {
            cout << path[ans][i];
            if (i != path[ans].size() - 1)
                cout << "->";
        }
        cout<<" "<<abs(minb)<<'\n';
    }
    else{
        cout<<minb<<' ';
        for (int i = 0; i < path[ans].size(); i++)
        {
            cout << path[ans][i];
            if (i != path[ans].size() - 1)
                cout << "->";
        }
        cout<<" 0\n";
    }
}
int main()
{
#if !LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
#endif
    int tt = 1;
    // cin >> tt;
    while (tt--)
        solve();
#if LOCAL
    system("pause");
#endif
    return 0;
}
