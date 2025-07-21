#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    int l[n], r[n], real[n];
    for (int i = 0; i < n; i++)
    {
        cin >> l[i] >> r[i] >> real[i];
    }
    vector<int> lst(n);
    iota(lst.begin(), lst.end(), 0);
    sort(lst.begin(), lst.end(), [&](int i, int j) {return real[i] < real[j];});
    for(int i:lst)
    {
        if(l[i]<=k&&k<=real[i])
        k=real[i];
    }
    cout<<k<<'\n';
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
