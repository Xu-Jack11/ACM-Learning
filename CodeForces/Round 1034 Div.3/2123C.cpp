#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), pref(n + 1, 0x3f3f3f3f), suf(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        pref[i + 1] = min(pref[i], a[i]);
        suf[n - i - 1] = max(suf[n - i], a[n - i - 1]);
    }
    for (int i = 0; i < n; i++)
    {
        if (pref[i] >= a[i] || a[i] >= suf[i+1])
        {
            cout << "1";
        }
        else
            cout << "0";
    }
    cout << "\n";
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
