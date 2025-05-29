#include <bits/stdc++.h>
using namespace std;

void solve()
{
    map<int,double,greater<int>> mp;
    for (int _ = 0; _ < 2; _++)
    {
        int n;
        cin >> n;
        while(n--)
        {
            int x;
            double y;
            cin>>x>>y;
            mp[x]+=y;
            if(mp[x]==0)mp.erase(x);
        }
    }
    cout<<mp.size();
    for(auto [x,y]:mp)
    {
        cout<<' '<<x<<' '<<fixed<<setprecision(1)<<y;
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
