#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n,m,c1,c2,ans=0;
    cin >> n >> m >> c1 >> c2;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> b(n);
    b[c1] = a[c1];
    vector<pair<int,int>> mp[n+1];
    for (int i = 0; i < m; i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        mp[a].push_back({b,c});
        mp[b].push_back({a,c});
    }
    if(c1==c2)
    {
        cout<<1<<' '<<a[c1];
        return;
    }
    vector<int> dis(n+1,INT_MAX);
    dis[c1] = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,c1});
    while(!pq.empty())
    {
        auto [d,u] = pq.top();
        pq.pop();
        if (d > dis[u])
            continue;
        for (auto [v,c] : mp[u])
        {
            if (dis[v] > d + c)
            {
                dis[v] = d + c;
                pq.push({dis[v],v});
                b[v] = b[u] + a[v];
                if(v == c2)
                    ans = 1;
            }
            else if (dis[v] == d + c)
            {
                b[v]=max(b[v],b[u] + a[v]);
                pq.push({dis[v],v});
                if(v == c2)
                    ans++;
            }
        }
    }
    cout<<ans<<' '<<b[c2];
}
signed main()
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
