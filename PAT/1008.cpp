#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    int a=0,b,ans=0;
    while(n--)
    {
        cin>>b;
        if(b>a)
        {
            ans+=6*(b-a);
        }
        else if(b<a)
        {
            ans+=4*(a-b);
        }
        ans+=5;
        a=b;
    }
    cout<<ans;
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
