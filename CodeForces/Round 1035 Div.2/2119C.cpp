#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll n, l, r, k;
    cin >> n >> l >> r >> k;
    if (n == 2)
    {
        cout << "-1\n";
        return;
    }
    if (n & 1)
        cout << l << '\n';
    else
    {
        // find minimal i in [l, r] with (i & l) == 0 by next power of two > l
        ll p = 1;
        while (p <= l) p <<= 1;
        if (p <= r) {
            if (k <= n - 2)
                cout << l << '\n';
            else
                cout << p << '\n';
        } else {
            cout << "-1\n";
        }
        return;
    }
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
