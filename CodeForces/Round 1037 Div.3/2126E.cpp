#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    vector<ll> p(n), s(n), ans(n);
    for (int i = 0; i < n; i++)
        cin >> p[i];
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        ans[i] = lcm(p[i], s[i]);
    }
    if(ans[0]!=p[0]|| ans[n - 1] != s[n - 1])
    {
        cout << "NO\n";
        return;
    }
    for (int i = 1; i < n; i++)
    {
        if (gcd(ans[i], p[i - 1]) != p[i])
        {
            cout << "NO\n";
            return;
        }
    }
    for (int i = n - 1; i >= 1; i--)
    {
        if (gcd(s[i], ans[i - 1]) != s[i - 1])
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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
