#include <bits/stdc++.h>
using namespace std;
int maxd=0;
vector<vector<short>> a(100);
vector<short> depth(100, 0);
void dfs(int u, int d)
{
    maxd = max(maxd, d);
    if (a[u].empty())
    {
        depth[d]++;
        return;
    }
    for (int v : a[u])
    {
        dfs(v, d + 1);
    }
    return;
};
void solve()
{
    int n, m;
    int root, k, x;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> root >> k;
        while (k--)
        {
            cin >> x;
            a[root].push_back(x);
        }
    }
    dfs(1, 0);
    for (int i = 0; i <= maxd; i++)
    {
        if (i == maxd)
            cout << depth[i];
        else
            cout << depth[i] << ' ';
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
