#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    ll px, py, qx, qy;
    cin >> px >> py >> qx >> qy;
    vector<double> a(n + 1);
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        a[i] = x;
    }
    a[n] = sqrt((px - qx) * (px - qx) + (py - qy) * (py - qy));
    sort(a.begin(), a.end());
    if (accumulate(a.begin(), a.end() - 1, 0.0) < a[n])
    {
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
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
