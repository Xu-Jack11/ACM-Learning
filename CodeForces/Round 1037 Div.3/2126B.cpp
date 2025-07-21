#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n,k;
    cin>>n>>k;
    int cnt=0,ans=0;
    while(n--)
    {
        int x;
        cin>>x;
        if(x==0)cnt++;
        else cnt=0;
        if(cnt==k)ans++;
        if(cnt>k)cnt=0;
    }    
    cout<<ans<<'\n';
}
int main()
{
#if !LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
#endif
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
#if LOCAL
    system("pause");
#endif
    return 0;
}
