#include <bits/stdc++.h>
using namespace std;
vector<int> vis(1000);
vector<vector<int>> G(1000);
int ign=0;
void dfs(int u,int color)
{
    if(ign == u)
        return;
    vis[u] = color;
    for (auto v : G[u])
    {
        if (vis[v] == 0)
            dfs(v, color);
    }
}
void solve()
{
    int n,m,k;
    cin>> n >> m >> k;
    while(m--)
    {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    while(k--)
    {
        cin>>ign;
        int ans=0;
        vis.assign(1000, 0);
        for (int i = 1; i <= n; i++)
        {
            if (vis[i] == 0&&i!=ign)
            {
                dfs(i, ++ans);
            }
        }
        cout<<ans-1<<'\n';
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
