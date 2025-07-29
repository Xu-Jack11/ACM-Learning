#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    if (a == b)
    {
        cout << "0\n";
        return;
    }
    if (a > b)
    {
        if ((a ^ 1) == b)
        {
            cout << y << '\n';
        }
        else
            cout << "-1\n";
    }
    else
    {
        if (x <= y)
            cout << (b - a) * x << '\n';
        else
        {
            int ans = 0;
            if (a & 1)
            {
                ans += x;
                a++;
            }
            if (b & 1)
            {
                ans += y;
                b--;
            }
            ans += (b - a) / 2 * (x + y);
            cout << ans << '\n';
        }
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
