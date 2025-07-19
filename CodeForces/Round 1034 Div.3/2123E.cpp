#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> b(n);
    for (int i = 0; i < n; i++)
        cin >> b[i];
    vector<int> freq(n + 1);
    for (int x : b)
        if (0 <= x && x <= n)
            freq[x]++;
    int mex = 0;
    while (mex <= n && freq[mex] > 0)
        mex++;
    vector<int> diff(n + 2);
    for (int m = 0; m <= mex; m++)
    {
        int L = freq[m];
        int U = n - m;
        diff[L]++;
        diff[U + 1]--;
    }
    vector<int> ans(n + 1);
    int cur = 0;
    for (int k = 0; k <= n; k++)
    {
        cur += diff[k];
        ans[k] = cur;
    }
    for (int k = 0; k <= n; k++)
        cout << ans[k] << ' ';
    cout << '\n';
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
