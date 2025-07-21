#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int h=a[k-1],t=1;
    sort(a.begin(),a.end());
    while(h!=a.back())
    {
        int tmp=*upper_bound(a.begin(),a.end(),h);
        if(tmp-h<=h-t+1)
        {
            t+=tmp-h;
            h=tmp;
        }
        else{
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
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
