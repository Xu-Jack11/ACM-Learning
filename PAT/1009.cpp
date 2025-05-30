#include <bits/stdc++.h>
using namespace std;

void solve()
{
    map<int,double,greater<int>> ans,a,b;
    int n;
    cin>>n;
    while(n--)
    {
        int x;
        double y;
        cin>>x>>y;
        a[x]+=y;
    }
    cin>>n;
    while(n--)
    {
        int x;
        double y;
        cin>>x>>y;
        b[x]+=y;
    }
    for(auto &[x,y]:a)
    for(auto &[i,j]:b)
    {
        ans[x+i] += y*j;
        if(ans[x+i]==0)ans.erase(x+i);
    }
    cout<<ans.size();
    for(auto&[a,b]:ans)
    {
        cout<<" "<<a<<" "<<fixed<<setprecision(1)<<b;
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
