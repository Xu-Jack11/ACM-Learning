#include <bits/stdc++.h>
using namespace std;
using ll=long long;
void solve()
{
    ll a,b,k;
    cin>>a>>b>>k;
    ll g=gcd(a,b);
    ll dx=a/g, dy=b/g;
    if(dx<=k && dy<=k){
        cout<<"1\n";
    }
    else cout<<"2\n";
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
