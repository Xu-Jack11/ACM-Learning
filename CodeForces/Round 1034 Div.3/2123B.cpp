#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, j, k, maxn, x;
    cin >> n >> j >> k;
    for (int i = 1; i <= n; i++)
    {
        int tmp;
        cin >> tmp;
        maxn = max(maxn, tmp);
        if (j == i)
            x = tmp;
    }
    if (k == 1)
    {
        if (maxn ==x)
            cout << "YES\n";
        else
            cout << "NO\n";
        return;
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
